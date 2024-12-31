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
  virtual void IHeadsetInterface_unk05(char* a2) = 0; // todo
  virtual void SetPluginMode(ovrPluginMode pluginMode) = 0;
  virtual ovrPluginMode GetPluginMode() = 0;
  virtual void GetPluginName(IOVRString** out_PluginName) = 0;
  virtual void GetRuntimeInterface(IHeadsetToRuntimeInterface2** out_RuntimeInterface) = 0;
  virtual void IHeadsetInterface_nullsub10() {} // not nullsub on laguna, sets a value in instance.
  virtual void IHeadsetInterface_nullsub11() {} // not nullsub on laguna, sets a global byte value for a compat info thing.
  virtual void IHeadsetInterface_unk12() = 0;
  virtual void GetInterface(u64 iid) = 0;
  virtual void IHeadsetInterface_nullsub14() {} // not nullsub on laguna
  virtual void IHeadsetInterface_unk15() = 0;
  virtual void IHeadsetInterface_unk16() = 0;
  virtual void IHeadsetInterface_nullsub17() {} // not nullsub on laguna
  virtual void IHeadsetInterface_unk18() = 0;
  virtual void IHeadsetInterface_unk19() = 0;
  virtual void IHeadsetInterface_unk20() = 0;
  virtual void IHeadsetInterface_unk21() = 0; // vibration related thing?
  virtual void IHeadsetInterface_unk22() = 0; // sends vibration frequency to controller?
  virtual void IHeadsetInterface_unk23() = 0; // sends vibration buffer to controller?
  virtual void IHeadsetInterface_nullsub24() {} // vibrates both controllers?
  virtual void WakeFromStandby() = 0;
  virtual void SetVirtualPose(char* deviceName) = 0; // TODO(whatdahopper): Rotation and position.
  virtual void IHeadsetInterface_nullsub27() {}
  virtual void IHeadsetInterface_nullsub28() {}
  virtual void IHeadsetInterface_nullsub29() {} // not nullsub on laguna, something with ipd/screen seperation?
  virtual void IHeadsetInterface_nullsub30() {} // not nullsub on laguna, sets iad?
  virtual void IHeadsetInterface_unk31() = 0;
  virtual void IHeadsetInterface_unk32() = 0;
  virtual void IHeadsetInterface_unk33() = 0;
  virtual void IHeadsetInterface_unk34() = 0;
  virtual void IHeadsetInterface_unk35() = 0;
  virtual void IHeadsetInterface_unk36() = 0;
  virtual void IHeadsetInterface_unk37() = 0;
  virtual void IHeadsetInterface_nullsub38() {}
  virtual void IHeadsetInterface_nullsub39() {}
  virtual u64 GetControllerDeviceType(u32 a2) = 0;
  virtual void IHeadsetInterface_unk41() = 0;
  virtual void IHeadsetInterface_unk42() = 0;
  virtual void IHeadsetInterface_unk43() = 0;
  virtual void IHeadsetInterface_unk44() = 0;
  virtual void IHeadsetInterface_unk45() = 0;
  virtual void IHeadsetInterface_unk46() = 0;
  virtual void IHeadsetInterface_unk47() = 0;
  virtual void GetHMDInfo(ovrHmdInfo* out_HmdInfo) = 0; // todo
  virtual void IHeadsetInterface_unk49() = 0;
  virtual void IHeadsetInterface_unk50() = 0;
  virtual void IHeadsetInterface_unk51() = 0; // latency of something? returns 0 on rift and emulation
  virtual void IHeadsetInterface_nullsub52() {} // not nullsub on laguna, sets a value in instance.
  virtual void IHeadsetInterface_unk53() = 0;
  virtual void IHeadsetInterface_unk54() = 0;
  virtual void SetTrackingCaps(u32 trackingCaps) = 0;
  virtual void IHeadsetInterface_unk56() = 0;
  virtual void IHeadsetInterface_unk57() = 0;
  virtual void IHeadsetInterface_unk58() = 0;
  virtual void IHeadsetInterface_unk59() = 0;
  virtual void IHeadsetInterface_unk60() = 0;
  virtual void IHeadsetInterface_unk61() = 0;
  virtual void IHeadsetInterface_unk62() = 0;
  virtual void IHeadsetInterface_unk63() = 0;
  virtual void SetStandby() = 0;
};

} // HeadsetPlugin
} // OVR
