// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_LOGICAL_OR_HPP
#define METAL_NUMBER_LOGICAL_OR_HPP

#include <metal/number/number.hpp>
#include <metal/number/logical/not.hpp>
#include <metal/optional/conditional.hpp>

namespace metal
{
    /// \ingroup logical
    /// \brief ...
    template<typename... nums>
    struct or_
    {};

    /// \ingroup logical
    /// \brief Eager adaptor for \ref or_.
    template<typename... nums>
    using or_t = typename or_<nums...>::type;

    template<typename head, typename... tail>
    struct or_<head, tail...> :
            conditional<
                not_t<
                    or_t<
                        not_t<is_number_t<head>>,
                        not_t<is_number_t<tail>>...
                    >
                >,
                boolean<true>
            >
    {};

    template<typename head, typename... tail>
    struct or_<number<head, false>, number<tail, false>...> :
            boolean<false>
    {};
}

#endif