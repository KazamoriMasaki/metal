// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_COMPARISON_EQUAL_TO_HPP
#define METAL_NUMBER_COMPARISON_EQUAL_TO_HPP

#include <metal/number/number.hpp>

namespace metal
{
    /// \ingroup comparison
    /// \brief ...
    template<typename x, typename y>
    struct equal_to;

    /// \ingroup comparison
    /// \brief Eager adaptor for \ref equal_to.
    template<typename x, typename y>
    using equal_to_t = typename equal_to<x, y>::type;

    template<typename x, x xv, typename y, y yv>
    struct equal_to<number<x, xv>, number<y, yv>> :
            boolean<(xv == yv)>
    {};
}

#endif
