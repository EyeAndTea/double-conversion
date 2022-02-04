// Copyright 2012 the V8 project authors. All rights reserved.
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
//       copyright notice, this list of conditions and the following
//       disclaimer in the documentation and/or other materials provided
//       with the distribution.
//     * Neither the name of Google Inc. nor the names of its
//       contributors may be used to endorse or promote products derived
//       from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include "ieee.h"

namespace double_conversion {
  const uint64_t Double::kSignMask = DOUBLE_CONVERSION_UINT64_2PART_C(0x80000000, 00000000);
  const uint64_t Double::kExponentMask = DOUBLE_CONVERSION_UINT64_2PART_C(0x7FF00000, 00000000);
  const uint64_t Double::kSignificandMask = DOUBLE_CONVERSION_UINT64_2PART_C(0x000FFFFF, FFFFFFFF);
  const uint64_t Double::kHiddenBit = DOUBLE_CONVERSION_UINT64_2PART_C(0x00100000, 00000000);
  const uint64_t Double::kQuietNanBit = DOUBLE_CONVERSION_UINT64_2PART_C(0x00080000, 00000000);
  const int Double::kPhysicalSignificandSize = 52;  // Excludes the hidden bit.
  const int Double::kSignificandSize = 53;
  const int Double::kExponentBias = 0x3FF + kPhysicalSignificandSize;
  const int Double::kMaxExponent = 0x7FF - kExponentBias;
  const int Double::kDenormalExponent = -kExponentBias + 1;
  const uint64_t Double::kInfinity = DOUBLE_CONVERSION_UINT64_2PART_C(0x7FF00000, 00000000);
#if (defined(__mips__) && !defined(__mips_nan2008)) || defined(__hppa__)
  const uint64_t Double::kNaN = DOUBLE_CONVERSION_UINT64_2PART_C(0x7FF7FFFF, FFFFFFFF);
#else
  const uint64_t Double::kNaN = DOUBLE_CONVERSION_UINT64_2PART_C(0x7FF80000, 00000000);
#endif



  const uint32_t Single::kSignMask = 0x80000000;
  const uint32_t Single::kExponentMask = 0x7F800000;
  const uint32_t Single::kSignificandMask = 0x007FFFFF;
  const uint32_t Single::kHiddenBit = 0x00800000;
  const uint32_t Single::kQuietNanBit = 0x00400000;
  const int Single::kPhysicalSignificandSize = 23;  // Excludes the hidden bit.
  const int Single::kSignificandSize = 24;  
  
  const int Single::kExponentBias = 0x7F + kPhysicalSignificandSize;
  const int Single::kDenormalExponent = -kExponentBias + 1;
  const int Single::kMaxExponent = 0xFF - kExponentBias;
  const uint32_t Single::kInfinity = 0x7F800000;
#if (defined(__mips__) && !defined(__mips_nan2008)) || defined(__hppa__)
  const uint32_t Single::kNaN = 0x7FBFFFFF;
#else
  const uint32_t Single::kNaN = 0x7FC00000;
#endif
}  // namespace double_conversion
