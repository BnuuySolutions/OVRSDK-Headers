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

// fixme(whatdahopper): this class is poorly RE'd and barely works
  
class OVRAggregateInterfaceFactory : public IAggregateInterfaceFactory {
  OVRSDK_IREFCOUNTED_IMPL

private:
  struct OvrInterfaceDesc2 {
    IInterfaceFactory* factory;
    OvrInterfaceDesc desc;
  };
  std::vector<OvrInterfaceDesc2> _desc_vec{};

public:
  void* QueryInterface(u64 iid) override {
    if (iid - 1 <= 3) {
      return this;
    }
    return nullptr;
  }

  void* CreateInterface(void** out_interface, u64 clsid) override {
    for (auto it = _desc_vec.begin(); it != _desc_vec.end(); it++) {
      if (it->desc.class_id == clsid) {
        it->factory->CreateInterface(&*out_interface, clsid);
        return out_interface;
      }
    }

    *out_interface = 0;
    return out_interface;
  }

  bool GetInterfaceDescriptors(u64* desc_arr_size, OvrInterfaceDesc desc_arr[], u64 iid) override {
    u64 initial_arr_size = *desc_arr_size;
    *desc_arr_size = 0;

    auto it = _desc_vec.begin();
    if (it == _desc_vec.end()) return true;

    while (true) {
      if (iid != -1 &&
          (*it).desc.interface_id_0 != iid &&
          (*it).desc.interface_id_1 != iid &&
          (*it).desc.interface_id_2 != iid &&
          (*it).desc.interface_id_3 != iid) {
        goto iterate_vector;
      }

      if (desc_arr) {
        break;
      }

    increment_arr_count:
      ++*desc_arr_size;

    iterate_vector:
      if (++it == _desc_vec.end()) return true;
    }

    if (*desc_arr_size != initial_arr_size) {
      desc_arr[*desc_arr_size] = (*it).desc;
      goto increment_arr_count;
    }
    return false;
  }

  void RegisterInterfaceFactory(IInterfaceFactory* factory, OvrInterfaceDesc* desc) override {
    OvrInterfaceDesc2 new_desc{};
    new_desc.factory = factory;
    new_desc.desc = *desc;
    _desc_vec.push_back(new_desc);
  }
};

} // OVRInterface
