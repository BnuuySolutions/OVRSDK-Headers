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

#include "OVRSDK_IUnknown.h"

#define OVRSDK_INTERFACE_FACTORY(clazz, clsid_) \
  class OVRInterfaceFactory##clazz : public OVRInterface::IInterfaceFactory { \
    OVRSDK_IREFCOUNTED_IMPL \
  public: \
    void* QueryInterface(u64 iid) override { \
      if (OVRSDK_IID_LESS_THAN_OR_EQUAL(iid, 2)) return (OVRInterface::IInterfaceFactory*)this; \
      return nullptr; \
    } \
    void* CreateInterface(void** out_Interface, u64 clsid) override { \
      if (clsid == ##clsid_) { \
        *out_Interface = new clazz; \
        return out_Interface; \
      } \
      *out_Interface = 0; \
      return out_Interface; \
    } \
  }

namespace OVRInterface {

class IInterfaceFactory : public IUnknown {
public:
  virtual void* CreateInterface(void** out_Interface, u64 clsid) = 0; // hint(reverse-engineering): function name guessed
};

} // OVRInterface
