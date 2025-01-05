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
  virtual void IHeadsetInterface_NullsubFunc10() {} // Not nullsub on RiftS, sets a value in instance.
  virtual void IHeadsetInterface_NullsubFunc11() {} // Not nullsub on RiftS, sets a global byte value for compatibility info.
  virtual void IHeadsetInterface_UnkFunc12(u8 a2) = 0; // Firmware update related
  virtual void GetInterface(u64 iid) = 0;
  virtual void HmdReboot() = 0; // Not nullsub on Rift(S), sets DeviceManagement HMD mode.
  virtual void IHeadsetInterface_UnkFunc15() = 0;
  virtual u8 IHeadsetInterface_UnkFunc16(u64 a2, u8 a3) = 0; // Controller pairing related
  virtual void IHeadsetInterface_UnkFunc17() = 0; // Not nullsub on Rift(S), sets NormalApp HMD mode.
  virtual void IHeadsetInterface_UnkFunc18() = 0;
  virtual void IHeadsetInterface_UnkFunc19() = 0;
  virtual void GetTouchHapticsDesc() = 0; // Closely matches ovr_GetTouchHapticsDesc in CAPI.
  virtual b8 GetControllerVibrationState(s32 deviceType, s32* out_RemainingQueueSpace, s32 out_SamplesQueued) = 0; // True = Success, False = Failure
  virtual b8 SetControllerVibration(s32 deviceType, f32 frequency, f32 amplitude) = 0; // Closely matches ovr_SetControllerVibration in CAPI.
  virtual b8 SubmitControllerVibration(s32 deviceType, void* samples, s32 samplesCount) = 0; // Unsupported on anything other than Rift.
  virtual void IHeadsetInterface_UnkFunc24() = 0;
  virtual void WakeFromStandby() = 0;
  virtual void SetVirtualPose(char* deviceName) = 0; // TODO(whatdahopper): Rotation and position.
  virtual void IHeadsetInterface_NullsubFunc27() {}
  virtual void IHeadsetInterface_NullsubFunc28() {}
  virtual void IHeadsetInterface_UnkFunc29() = 0; // Not nullsub on Rift(S), something with IPD/screen seperation?
  virtual void IHeadsetInterface_UnkFunc30() = 0; // Not nullsub on Rift(S), sets IAD?
  virtual void IHeadsetInterface_UnkFunc31() = 0;
  virtual void IHeadsetInterface_UnkFunc32() = 0;
  virtual void IHeadsetInterface_UnkFunc33() = 0;
  virtual void IHeadsetInterface_UnkFunc34() = 0;
  virtual void GetControllerSerialNumber(IOVRString** out_SerialNumber, s32 deviceType) = 0;
  virtual void GetHmdName(IOVRString** out_HmdName) = 0;
  virtual void IHeadsetInterface_UnkFunc37(IOVRString** out_a2, s32 deviceType) = 0; // Returns HMD serial?
  virtual void IHeadsetInterface_UnkFunc38(IOVRString** out_a2) = 0; // Not nullsub on Rift, outputs JSON.
  virtual void IHeadsetInterface_UnkFunc39(IOVRString** out_a2) = 0; // Not nullsub on Rift, outputs JSON.
  virtual u64 GetControllerDeviceType(s32 controllerType) = 0;
  virtual s32 GetControllerBatteryLevel(s32 deviceType) = 0;
  virtual void IHeadsetInterface_UnkFunc42(IOVRString** out_a2) = 0; // Returns hex values with spaces and a ";" to seperate them, no clue.
  virtual void IHeadsetInterface_UnkFunc43() = 0;
  virtual void IHeadsetInterface_UnkFunc44() = 0;
  virtual void GetTrackerSerialNumber(u32 trackerIndex, IOVRString** out_SerialNumber) = 0;
  virtual void IHeadsetInterface_UnkFunc46(u32 trackerIndex, IOVRString** out_a3) = 0; // Just returns "NONE", no clue.
  virtual void IHeadsetInterface_UnkFunc47() = 0;
  virtual void GetHmdInfo(ovrHmdInfo* out_HmdInfo) = 0;
  virtual void IHeadsetInterface_UnkFunc49() = 0;
  virtual void IHeadsetInterface_UnkFunc50() = 0;
  virtual void IHeadsetInterface_UnkFunc51() = 0; // latency of something? returns 0 on rift and emulation
  virtual void IHeadsetInterface_NullsubFunc52() {} // not nullsub on laguna, sets a value in instance.
  virtual void IHeadsetInterface_UnkFunc53(u8 a2) = 0;
  virtual void IHeadsetInterface_UnkFunc54() = 0;
  virtual void SetTrackingCaps(u32 trackingCaps) = 0;
  virtual void IHeadsetInterface_UnkFunc56() = 0;
  virtual void GetDisplayInfo(ovrDisplayInfo* out_DisplayInfo) = 0;
  virtual void IHeadsetInterface_UnkFunc58() = 0;
  virtual void IHeadsetInterface_UnkFunc59(f64 a2) = 0;
  virtual f64 IHeadsetInterface_UnkFunc60() = 0;
  virtual void IHeadsetInterface_UnkFunc61() = 0;
  virtual void IHeadsetInterface_UnkFunc62() = 0;
  virtual void IHeadsetInterface_UnkFunc63() = 0;
  virtual void SetStandby() = 0;
  virtual void IHeadsetInterface_UnkFunc65() = 0;
  virtual void IHeadsetInterface_NullsubFunc66() {}
  virtual void SignalBoundaryUpdate(const char* a2) = 0;
  virtual void StartNuxTrackingMode(u32 a2, b8 a3) = 0;
  virtual void EndNuxTrackingMode() = 0;
  virtual void SetPerformingSensorPlacement(b8 a2) = 0;
};

} // HeadsetPlugin
} // OVR
