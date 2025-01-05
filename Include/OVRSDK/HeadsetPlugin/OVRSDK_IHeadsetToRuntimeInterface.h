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

#include "../OVRInterface/OVRSDK_IUnknown.h"

namespace OVR {
namespace HeadsetPlugin {

// Used for headset plugin -> runtime interfacing.
class IHeadsetToRuntimeInterface : public OVRInterface::IUnknown {
public:
  virtual void IHeadsetToRuntimeInterface_NullsubFunc05() {}
  virtual void IHeadsetToRuntimeInterface_NullsubFunc06() {}
  virtual u64 IHeadsetToRuntimeInterface_NullsubFunc07() { return 0; }
  virtual void IHeadsetToRuntimeInterface_NullsubFunc08() {}

  // TODO(whatdahopper): Both call into InputEvent, but they do slightly different things.
  virtual void IHeadsetToRuntimeInterface_StubFunc09(uint32_t a2, const char* serialNumber, uint32_t a4) {}
  virtual void IHeadsetToRuntimeInterface_StubFunc10(uint32_t a2, const char* serialNumber, __int64 a4) {}

  // Appears to be related to HMDEvent?
  virtual void IHeadsetToRuntimeInterface_StubFunc11(uint32_t a2, const char* serialNumber, uint32_t eventType, void* a5) {}

  // Appears to be related to FirmwareVersionEvent?
  virtual void IHeadsetToRuntimeInterface_StubFunc12(int a2, const char* serialNumber, __int64 a4) {
  }

  // Reports both controller and HMD firmware versions.
  virtual void FirmwareVersionEvent(int a2, const char* serialNumber, uint8_t a4, __int64 a5, const char* firmwareVersion) {}
  virtual void FirmwareUpdateEvent(int a2, const char* serialNumber, uint32_t* a4) {} // Also reports sensor firmware updates?

  // Maps roughly to the same OAF event, AFAIK.
  // No clue what a2 or a5 is.
  virtual void HMDEvent(unsigned int a2, const char* serialNumber, uint8_t eventType, void* a5) {}

  virtual void IHeadsetToRuntimeInterface_StubFunc16() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc17() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc18() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc19() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc20() {}
  virtual void DeviceMotionEvent(bool active, const char* serialNumber) = 0;
  virtual void IHeadsetToRuntimeInterface_StubFunc22() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc23() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc24() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc25() {}
  virtual void IADChangeEvent(const char* serialNumber, float value, u64 a4) = 0;
  virtual void IHeadsetToRuntimeInterface_StubFunc27() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc28() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc29() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc30() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc31() {}

  // a2 has the following values, likely device ID?
  // 0 = HMD
  // 1 = Left touch
  // 2 = Right touch
  // Also, the function name is a guess.
  virtual void DevicePoseEvent(u8 deviceType, ovrPoseStated* devicePose, uint32_t a4) {
  }

  virtual void IHeadsetToRuntimeInterface_StubFunc33() {}
  virtual void CombinedControllerStateEvent(ovrCombinedControllerState* state) {
  }
  virtual void IHeadsetToRuntimeInterface_StubFunc35(void* state, void* test) {
  }
  virtual void IHeadsetToRuntimeInterface_StubFunc36() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc37() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc38() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc39() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc40() {}

  // TODO
  virtual void TrackerEvent(const char* serialNumber, uint32_t eventType, void* a4) {
  }

  virtual void HMDFirmwareVersionEvent() {}

  virtual void IHeadsetToRuntimeInterface_StubFunc43() {} // calls into oaf

  virtual void IHeadsetToRuntimeInterface_StubFunc44() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc45() {}

  virtual void IHeadsetToRuntimeInterface_StubFunc46() {} // also related to IHeadsetToRuntimeInterface_StubFunc48, uses 0x780
  virtual void IHeadsetToRuntimeInterface_StubFunc47() {} // related to IHeadsetToRuntimeInterface_StubFunc48, uses 0x780
  virtual b8 IHeadsetToRuntimeInterface_StubFunc48() { return false; } // another getter (0x780)

  // potentially some locking state??
  virtual void IHeadsetToRuntimeInterface_StubFunc49(b8 a2) {} // setting related to tracking/input (0x14D0)
  virtual void IHeadsetToRuntimeInterface_StubFunc50(b8 a2) {} // setting related to tracking/input (0x14D1)
  virtual b8 IHeadsetToRuntimeInterface_StubFunc51() { return false; } // related to tracking/input (0x14D0) (left con?)
  virtual b8 IHeadsetToRuntimeInterface_StubFunc52() { return false; } // related to tracking/input (0x14D1) (right con?)

  virtual void IHeadsetToRuntimeInterface_StubFunc53(const char* a2) {
  } // dunno

  virtual void IHeadsetToRuntimeInterface_StubFunc54() {} // another usage of 0x780
  virtual b8 IHeadsetToRuntimeInterface_StubFunc55() { return false; } // getter (0x2C)

  virtual void IHeadsetToRuntimeInterface_StubFunc56(u32 a2) {
  } // calls something with "Fake Remote"

  virtual void IHeadsetToRuntimeInterface_StubFunc57() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc58() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc59() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc60() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc61() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc62(int a2, char a3, char a4) {
    //printf("a2 = %i, a3 = %i, a4 = %i\n", a2, a3, a4);
  }
  virtual void IHeadsetToRuntimeInterface_StubFunc63() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc64(unsigned int a2, unsigned __int8 a3, unsigned __int8 a4) {
    //printf("a2 = %i, a3 = %i, a4 = %i\n", a2, a3, a4);
  }
  virtual void IHeadsetToRuntimeInterface_StubFunc65() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc66() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc67() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc68() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc69() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc70() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc71() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc72() {}

  virtual int IHeadsetToRuntimeInterface_StubFunc73() { return 1; }

  virtual ovrsdkResult GetDisplayList(ovrDisplayInfo list[], u32* out_Count) = 0;

  virtual void IHeadsetToRuntimeInterface_StubFunc75() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc76() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc77() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc78() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc79() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc80() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc81() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc82() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc83() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc84() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc85() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc86() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc87() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc88() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc89() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc90() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc91() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc92() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc93() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc94() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc95() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc96() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc97() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc98() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc99() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc100() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc101() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc102() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc103() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc104() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc105() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc106() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc107() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc108() {}
  virtual void IHeadsetToRuntimeInterface_StubFunc109() {}
};

} // HeadsetPlugin
} // OVR
