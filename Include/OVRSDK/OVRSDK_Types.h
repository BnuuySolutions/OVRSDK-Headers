// MIT License
// 
// Copyright (c) 2024 Bnuuy Solutions (whatdahopper)
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
#pragma once

#include <cstdint>

#if defined(_WIN32)
#define OVRSDK_EXPORT extern "C" __declspec(dllexport)
#define OVRSDK_FORCE_INLINE __forceinline
#else
#error "Unsupported Platform."
#endif

// signed integer
using s8 = std::int8_t;
using s16 = std::int16_t;
using s32 = std::int32_t;
using s64 = std::int64_t;

// unsigned integer
using u8 = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;

enum class OvrLogLevel { Disabled, Trace, Debug, Info, Warning, Error };

struct OvrInterfaceDesc {
  u64 class_id;
  char class_name[0x40];
  u64 interface_id_0; // you should always assign to this one, regardless.
  // note(whatdahopper): no clue what these are for, but its always checked against interface id.
  u64 interface_id_1;
  u64 interface_id_2;
  u64 interface_id_3;
};
