/// @copyright Bruno Dutra 2015
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_METAL_ALGORITHM_DETAIL_REF_HPP
#define BOOST_METAL_ALGORITHM_DETAIL_REF_HPP

#include <boost/metal/algorithm/detail/na.hpp>

namespace boost
{
    namespace metal
    {
        template<typename x = detail::na>
        struct ref
        {
            using type = x;
        };

        //NULL
        template<>
        struct ref<>
        {};
    }
}

#endif