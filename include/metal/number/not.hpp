// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_NOT_HPP
#define METAL_NUMBER_NOT_HPP

#include <metal/number/number.hpp>
#include <metal/number/if.hpp>

namespace metal
{
    /// \ingroup number
    /// Computes the logical negation of a \number.
    ///
    /// ### Usage
    /// For any \number `num`
    /// \code
    ///     using result = metal::not_<num>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     \code
    ///         using result = metal::number<!val{}>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet number.cpp not_
    ///
    /// ### See Also
    /// \see number, and_, or_
    template<typename num>
    using not_ = metal::if_<num, metal::false_, metal::true_>;
}

#endif
