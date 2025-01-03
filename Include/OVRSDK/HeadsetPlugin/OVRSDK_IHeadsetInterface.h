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

#include "OVRSDK_IHeadsetToRuntimeInterface2.h"
#include "../OVRInterface/OVRSDK_IUnknown.h"
#include "../OVRSDK_IOVRString.h"

namespace OVR {
namespace HeadsetPlugin {

// Used for runtime -> headset plugin interfacing.
class IHeadsetInterface : public OVRInterface::IUnknown {
public:
  virtual void IHeadsetInterface_UnkFunc05(char* a2) = 0; // todo
  virtual void SetPluginMode(ovrPluginMode pluginMode) = 0;
  virtual ovrPluginMode GetPluginMode() = 0;
  virtual void GetPluginName(IOVRString** out_PluginName) = 0;
  virtual void GetRuntimeInterface(IHeadsetToRuntimeInterface2** out_RuntimeInterface) = 0;
  virtual void IHeadsetInterface_NullsubFunc10() {} // not nullsub on laguna, sets a value in instance.
  virtual void IHeadsetInterface_NullsubFunc11() {} // not nullsub on laguna, sets a global byte value for a compat info thing.
  virtual void IHeadsetInterface_UnkFunc12() = 0;
  virtual void GetInterface(u64 iid) = 0;
  virtual void IHeadsetInterface_NullsubFunc14() {} // not nullsub on laguna
  virtual void IHeadsetInterface_UnkFunc15() = 0;
  virtual void IHeadsetInterface_UnkFunc16() = 0;
  virtual void IHeadsetInterface_NullsubFunc17() {} // not nullsub on laguna
  virtual void IHeadsetInterface_UnkFunc18() = 0;
  virtual void IHeadsetInterface_UnkFunc19() = 0;
  virtual void IHeadsetInterface_UnkFunc20() = 0;
  virtual b8 GetControllerVibrationState(u32 deviceType, s32* out_RemainingQueueSpace, s32 out_SamplesQueued) = 0;
  virtual void SetControllerVibration(u32 deviceType, f32 frequency, f32 amplitude) = 0; // Closely matches ovr_SetControllerVibration in CAPI.
  virtual void IHeadsetInterface_UnkFunc23() = 0; // sends vibration buffer to controller?
  virtual void IHeadsetInterface_NullsubFunc24() {} // vibrates both controllers?
  virtual void WakeFromStandby() = 0;
  virtual void SetVirtualPose(char* deviceName) = 0; // TODO(whatdahopper): Rotation and position.
  virtual void IHeadsetInterface_NullsubFunc27() {}
  virtual void IHeadsetInterface_NullsubFunc28() {}
  virtual void IHeadsetInterface_NullsubFunc29() {} // not nullsub on laguna, something with ipd/screen seperation?
  virtual void IHeadsetInterface_NullsubFunc30() {} // not nullsub on laguna, sets iad?
  virtual void IHeadsetInterface_UnkFunc31() = 0;
  virtual void IHeadsetInterface_UnkFunc32() = 0;
  virtual void IHeadsetInterface_UnkFunc33() = 0;
  virtual void IHeadsetInterface_UnkFunc34() = 0;
  virtual void IHeadsetInterface_UnkFunc35() = 0;
  virtual void IHeadsetInterface_UnkFunc36() = 0;
  virtual void IHeadsetInterface_UnkFunc37() = 0;
  virtual void IHeadsetInterface_NullsubFunc38() {}
  virtual void IHeadsetInterface_NullsubFunc39() {}
  virtual u64 GetControllerDeviceType(u32 a2) = 0;
  virtual void IHeadsetInterface_UnkFunc41() = 0;
  virtual void IHeadsetInterface_UnkFunc42() = 0;
  virtual void IHeadsetInterface_UnkFunc43() = 0;
  virtual void IHeadsetInterface_UnkFunc44() = 0;
  virtual void IHeadsetInterface_UnkFunc45() = 0;
  virtual void IHeadsetInterface_UnkFunc46() = 0;
  virtual void IHeadsetInterface_UnkFunc47() = 0;
  virtual void GetHMDInfo(ovrHmdInfo* out_HmdInfo) = 0; // todo
  virtual void IHeadsetInterface_UnkFunc49() = 0;
  virtual void IHeadsetInterface_UnkFunc50() = 0;
  virtual void IHeadsetInterface_UnkFunc51() = 0; // latency of something? returns 0 on rift and emulation
  virtual void IHeadsetInterface_NullsubFunc52() {} // not nullsub on laguna, sets a value in instance.
  virtual void IHeadsetInterface_UnkFunc53() = 0;
  virtual void IHeadsetInterface_UnkFunc54() = 0;
  virtual void SetTrackingCaps(u32 trackingCaps) = 0;
  virtual void IHeadsetInterface_UnkFunc56() = 0;
  virtual void IHeadsetInterface_UnkFunc57() = 0;
  virtual void IHeadsetInterface_UnkFunc58() = 0;
  virtual void IHeadsetInterface_UnkFunc59() = 0;
  virtual void IHeadsetInterface_UnkFunc60() = 0;
  virtual void IHeadsetInterface_UnkFunc61() = 0;
  virtual void IHeadsetInterface_UnkFunc62() = 0;
  virtual void IHeadsetInterface_UnkFunc63() = 0;
  virtual void SetStandby() = 0;
};

} // HeadsetPlugin
} // OVR
