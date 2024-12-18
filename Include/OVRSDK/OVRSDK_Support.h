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

namespace OVRSDK {
namespace Support {

/* Oculus runtime changes can break our reverse-engineered vtables, etc.
 * It is *highly* recommended (if not required) to use resources from the binary IDs we are currently targeting.
 * They are intended to be downloaded via https://securecdn.oculus.com/binaries/download/?id=<BinaryId>
 */

static const char* TargetRuntimeBinaryId = "3031299280335544";
static const char* TargetDriversBinaryId = "3653357211466543";

} // Support
} // OVRSDK
