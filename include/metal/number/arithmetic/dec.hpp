// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_ARITHMETIC_DEC_HPP
#define METAL_NUMBER_ARITHMETIC_DEC_HPP

#include <metal/number/number.hpp>

namespace metal
{
    /// \ingroup arithmetic
    /// \brief ...
    template<typename n>
    struct dec;

    /// \ingroup arithmetic
    /// \brief Eager adaptor for \ref dec.
    template<typename n>
    using dec_t = typename dec<n>::type;

    template<typename n, n xv>
    struct dec<number<n, xv>> :
            number<n, static_cast<n>(xv - 1)>
    {};
}

#endif
