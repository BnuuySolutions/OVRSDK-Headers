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

#include "OVRSDK_IHeadsetInterface.h"
#include "OVRSDK_IHeadsetToRuntimeInterface2.h"

namespace OVR {
namespace HeadsetPlugin {

class IOVRHeadsetPluginAddition : public OVRInterface::IUnknown {
public:
  // Creates an IHeadsetInterface from the headset plugin, allowing you to query information about connected headsets, etc.
  // You must pass in a runtime interface, which the headset plugin will use to interface with the runtime.
  // Returns "true" if successful, "false" if not.
  /* hint(reverse-engineering): function name guessed */
  virtual bool CreateHeadsetInterface(
    IHeadsetToRuntimeInterface2** runtime_interface,
    IHeadsetInterface** out_headset_interface) = 0;
};

} // HeadsetPlugin
} // OVR
