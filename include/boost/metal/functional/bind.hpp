// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_METAL_FUNCTIONAL_BIND_HPP
#define BOOST_METAL_FUNCTIONAL_BIND_HPP

#include <boost/metal/functional/arg.hpp>
#include <boost/metal/functional/protect.hpp>
#include <boost/metal/functional/call.hpp>

#include <cstddef>

namespace boost
{
    namespace metal
    {
        template<typename function, typename... params>
        struct bind
        {
        private:
            template<typename...>
            struct pack
            {
                using type = pack;
            };

            template<typename token, typename... args>
            struct parse :
                    pack<token>
            {};

            template<typename arg, typename... args>
            struct parse<protect<arg>, args...> :
                    pack<arg>
            {};

            template<typename... args>
            struct parse<arg<0U>, args...> :
                    pack<args...>
            {};

            template<std::size_t n, typename... args>
            struct parse<arg<n>, args...> :
                    pack<call_t<arg<n>, args...>>
            {};

            template<typename... _, typename... args>
            struct parse<bind<_...>, args...> :
                    pack<call_t<bind<_...>, args...>>
            {};

            template<typename token, typename... args>
            using parse_t = typename parse<token, args...>::type;

        public:
            using type = bind;

            template<typename... args>
            struct call :
                    call<parse_t<function, args...>, parse_t<params, args...>...>
            {};

            template<typename... xs, typename... ys, typename... tail>
            struct call<pack<xs...>, pack<ys...>, tail...> :
                    call<pack<xs..., ys...>, tail...>
            {};

            template<typename... args>
            struct call<pack<args...>> :
                    ::boost::metal::call<args...>
            {};
        };
    }
}

#endif
