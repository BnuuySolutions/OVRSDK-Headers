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

#include "OVRSDK_IInterfaceFactory.h"

namespace OVRInterface {

class IAggregateInterfaceFactory : public IInterfaceFactory {
public:
  /* Gets interface descriptors by an interface ID.
   * You must pass in an array and its size which will be outputted to for its final result.
   */
  virtual bool GetInterfaceDescriptors(u64* desc_arr_size, OvrInterfaceDesc desc_arr[], u64 iid) = 0; /* hint(reverse-engineering): function name guessed */
  virtual void RegisterInterfaceFactory(IInterfaceFactory* factory, OvrInterfaceDesc* desc) = 0; /* hint(reverse-engineering): function name guessed */
  
  /* todo(whatdahopper): stubbed for now */

  virtual void IAggregateInterfaceFactory_Unk08() {}
  virtual void IAggregateInterfaceFactory_Unk09() {}
  virtual void IAggregateInterfaceFactory_Unk10() {}
  virtual void IAggregateInterfaceFactory_Unk11() {}
};

} // OVRInterface
