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

#include "OVRSDK_IAggregateInterfaceFactory.h"
#include <vector>

namespace OVRInterface {

// FIXME(whatdahopper): This class is poorly RE'd and barely works.
class OVRAggregateInterfaceFactory : public IAggregateInterfaceFactory {
  OVRSDK_IREFCOUNTED_IMPL

private:
  typedef struct ovrFactoryDesc_ {
    IInterfaceFactory* factory;
    ovrInterfaceDesc desc;
  } ovrFactoryDesc;
  std::vector<ovrFactoryDesc> m_factories = {};

public:
  void* QueryInterface(u64 iid) override {
    if (iid - 1 <= 3) return this;
    return nullptr;
  }

  void* CreateInterface(void** out_Interface, u64 clsid) override {
    for (auto it = m_factories.begin(); it != m_factories.end(); it++) {
      if (it->desc.ClassId == clsid) {
        it->factory->CreateInterface(&*out_Interface, clsid);
        return out_Interface;
      }
    }

    *out_Interface = 0;
    return out_Interface;
  }

  bool GetInterfaceDescriptors(u64* out_Length, ovrInterfaceDesc arr[], u64 iid) override {
    u64 length = *out_Length;
    *out_Length = 0;

    auto it = m_factories.begin();
    if (it == m_factories.end()) return true;

    while (true) {
      if (iid != -1 &&
          (*it).desc.InterfaceId0 != iid &&
          (*it).desc.InterfaceId1 != iid &&
          (*it).desc.InterfaceId2 != iid &&
          (*it).desc.InterfaceId3 != iid) {
        goto IterateVector;
      }

      if (arr) break;

    IncrementLength:
      ++*out_Length;

    IterateVector:
      if (++it == m_factories.end()) return true;
    }

    if (*out_Length != length) {
      arr[*out_Length] = (*it).desc;
      goto IncrementLength;
    }

    return false;
  }

  void RegisterFactory(IInterfaceFactory* factory, ovrInterfaceDesc* desc) override {
    m_factories.push_back({ .factory = factory, .desc = *desc });
  }
};

} // OVRInterface
