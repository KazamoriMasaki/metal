// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/number/numbers.hpp>
#include <metal/list/list.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::numbers<ENUM(M, ID)>), (metal::list<NUMBERS(M)>)); \
/**/

GEN(MATRIX)
