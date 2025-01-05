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

#include <dxgicommon.h>
#include <cstdint>
#include <cmath>

#if defined(_WIN32)
#define OVRSDK_EXPORT extern "C" __declspec(dllexport)
#define OVRSDK_ALIGNAS(n) __declspec(align(n))
#define OVRSDK_FORCEINLINE __forceinline
#else
#error "Unsupported Platform."
#endif

/* Types */

using s8 = std::int8_t; // Signed 8-bit integer
using s16 = std::int16_t; // Signed 16-bit integer
using s32 = std::int32_t; // Signed 32-bit integer
using s64 = std::int64_t; // Signed 64-bit integer

using u8 = std::uint8_t; // Unsigned 8-bit integer
using u16 = std::uint16_t; // Unsigned 16-bit integer
using u32 = std::uint32_t; // Unsigned 32-bit integer
using u64 = std::uint64_t; // Unsigned 64-bit integer

using f32 = std::float_t; // 32-bit floating-point
using f64 = std::double_t; // 64-bit floating-point

using b8 = u8; // Boolean (8-bit)

// Forward-declare some internal types.

class IOVRString;

/* Enums */

typedef enum ovrErrorType_ {
  ovrError_InvalidParameter = -1005,
  ovrError_Unsupported = -1009,
  ovrError_InsufficientArraySize = -1016
} ovrErrorType;

typedef enum ovrLogLevelType_ {
  ovrLogLevel_Disabled = 0,
  ovrLogLevel_Trace = 1,
  ovrLogLevel_Debug = 2,
  ovrLogLevel_Info = 3,
  ovrLogLevel_Warning = 4,
  ovrLogLevel_Error = 5,
  ovrLogLevel_EnumSize = 0x7fffffff
} ovrLogLevelType;

typedef enum ovrPluginMode_ {
  ovrPlugin_Off = 0, // Turns off the headset plugin.
  ovrPlugin_Detect = 1, // Detects headsets and/or other devices, etc.
  ovrPlugin_On = 2, // Turns on the headset plugin.
  ovrPlugin_EnumSize = 0x7fffffff
} ovrPluginMode;

typedef enum ovrTrackingCaps_ {
  ovrTrackingCap_Orientation = 0x10, // Orientation tracking (IMU).
  ovrTrackingCap_MagYawCorrection = 0x20, // Yaw drift correction.
  ovrTrackingCap_Position = 0x40, // Positional tracking.
  ovrTrackingCap_EnumSize = 0x7fffffff
} ovrTrackingCaps;

typedef enum ovrHandType_ {
  ovrHand_Left = 0,
  ovrHand_Right = 1,
  ovrHand_Count = 2,
  ovrHand_EnumSize = 0x7fffffff
} ovrHandType;

typedef enum ovrCapsenseType_ {
  ovrCapsense_Thumbstick = 0,
  ovrCapsense_Button0 = 1, // Y button on Left touch, B button on Right touch
  ovrCapsense_IndexTrigger = 2,
  ovrCapsense_Button1 = 3, // X button on Left touch, A button on Right touch
  ovrCapsense_Reserved0 = 4,
  ovrCapsense_Reserved1 = 5,
  ovrCapsense_Reserved2 = 6,
  ovrCapsense_Thumbrest = 7,
  ovrCapsense_Reserved4 = 8,
  ovrCapsense_Reserved5 = 9,
  ovrCapsense_Count = 10,
  ovrCapsense_EnumSize = 0x7fffffff
} ovrCapsenseType;

/* Structs */

typedef struct OVRSDK_ALIGNAS(4) ovrSizei_ {
  s32 w, h;
} ovrSizei;
static_assert(sizeof(ovrSizei) == 0x8, "sizeof(ovrSizei) is not correct");

typedef struct OVRSDK_ALIGNAS(4) ovrSizef_ {
  f32 w, h;
} ovrSizef;
static_assert(sizeof(ovrSizef) == 0x8, "sizeof(ovrSizef) is not correct");

typedef struct OVRSDK_ALIGNAS(8) ovrQuatd_ {
  f64 x, y, z, w;
} ovrQuatd;
static_assert(sizeof(ovrQuatd) == 0x20, "sizeof(ovrQuatd) is not correct");

typedef struct OVRSDK_ALIGNAS(8) ovrVector3d_ {
  f64 x, y, z;
} ovrVector3d;
static_assert(sizeof(ovrVector3d) == 0x18, "sizeof(ovrVector3d) is not correct");

typedef struct OVRSDK_ALIGNAS(4) ovrVector2f_ {
  f32 x, y;
} ovrVector2f;
static_assert(sizeof(ovrVector2f) == 0x8, "sizeof(ovrVector2f) is not correct");

typedef struct OVRSDK_ALIGNAS(8) ovrInterfaceDesc_ {
  u64 ClassId;
  char ClassName[0x40];
  u64 InterfaceId0;
  u64 InterfaceId1;
  u64 InterfaceId2;
  u64 InterfaceId3;
} ovrInterfaceDesc;
static_assert(sizeof(ovrInterfaceDesc) == 0x68, "sizeof(ovrInterfaceDesc) is not correct");

typedef struct OVRSDK_ALIGNAS(4) ovrControllerState_ {
  u32 Connected;
  u8 BatteryLevel;
  u8 ovrControllerState_UnkData0005[3];
  u32 Buttons;
  u16 Capsense[ovrCapsense_Count];
  f32 IndexTrigger;
  f32 HandTrigger;
  ovrVector2f Thumbstick;
  u32 ovrControllerState_UnkData0030[7];
  f32 IndexTriggerNoDeadzone;
  f32 HandTriggerNoDeadzone;
  ovrVector2f ThumbstickNoDeadzone;
  u32 ovrControllerState_UnkData005C[7];
  f32 IndexTriggerRaw;
  f32 HandTriggerRaw;
  ovrVector2f ThumbstickRaw;
  u32 ovrControllerState_UnkData0088[7];
  u32 ovrControllerState_UnkVar00A4;
} ovrControllerState;
// TODO(whatdahopper): assert sizeof

typedef struct OVRSDK_ALIGNAS(8) ovrCombinedControllerState_ {
  u64 ovrLeftRightControllerState_UnkData[2];
  ovrControllerState Controllers[ovrHand_Count];
} ovrCombinedControllerState;
// TODO(whatdahopper): assert sizeof

typedef struct OVRSDK_ALIGNAS(4) ovrDisplayInfo_ {
  char DeviceName[0x100];
  u16 EdidVendorId; // Usually 0xD23E
  char EdidSerial[0x40];
  u16 ovrDisplayInfo_UnkVar0142;
  ovrSizei NativeResolution;
  ovrSizei Resolution;
  DXGI_RATIONAL RefreshRate;
  b8 ApplicationOnlyMode;
  b8 ovrDisplayInfo_UnkVar015D;
  u32 ovrDisplayInfo_UnkVar0160;
  LUID AdapterLuid;
  u32 ovrDisplayInfo_UnkVar016C;
  u8 Edid[0x100];
  u32 ovrDisplayInfo_UnkVar0270;
} ovrDisplayInfo;
static_assert(sizeof(ovrDisplayInfo) == 0x274, "sizeof(ovrDisplayInfo) is not correct");

typedef struct OVRSDK_ALIGNAS(4) ovrScreenInfo_ {
  ovrSizei ResolutionInPixels;
  ovrSizef SizeInMeters;
  f32 LensToScreenOffsetInMeters[3];
  f32 ovrScreenInfo_UnkData001C[7];
} ovrScreenInfo;
static_assert(sizeof(ovrScreenInfo) == 0x38, "sizeof(ovrScreenInfo) is not correct");

typedef struct OVRSDK_ALIGNAS(4) ovrShutterInfo_ {
  u32 Type;
  f32 VsyncToNextVsync;
  f32 VsyncToFirstScanline;
  f32 FirstScanlineToLastScanline;
  f32 PixelSettleTime;
  f32 PixelPersistence;
  b8 HasOverdriveOverride;
  f32 OverdriveScale[2];
  u32 ovrShutterInfo_UnkVar0024;
} ovrShutterInfo;
static_assert(sizeof(ovrShutterInfo) == 0x28, "sizeof(ovrShutterInfo) is not correct");

typedef struct OVRSDK_ALIGNAS(4) ovrLensConfig_ {
  f32 EyeRelief;
  f32 LensToScreen;
  u32 Eqn;
  /* Typically, this is 10 parameters for Catmull-Rom, but theres some left over bytes.
   * The extra remaining bytes, instead of it being unknown data, it might be 5 more parameters.
   */
  f32 K[11];
  u32 ovrLensConfig_UnkData0038[5];
  f32 MaxR;
  f32 MetersPerTanAngleAtCenter;
  f32 ChromaticAberration[4];
  u32 ovrLensConfig_UnkData0064[0x11];
  f32 PerMMEyeShiftSwim[6];
} ovrLensConfig;
static_assert(sizeof(ovrLensConfig) == 0xC0, "sizeof(ovrLensConfig) is not correct");

typedef struct OVRSDK_ALIGNAS(8) ovrHmdInfo_ {
  IOVRString* ProductName;
  IOVRString* ManufacturerName;
  u32 Version;
  b8 DebugDevice;
  ovrSizei ResolutionInPixels;
  ovrSizef ScreenSizeInMeters;
  f32 ScreenGapSizeInMeters;
  f32 CenterFromTopInMeters;
  f32 LensSeparationInMeters;
  ovrScreenInfo LeftScreen;
  ovrScreenInfo RightScreen;
  f32 PelOffsetR[2];
  f32 PelOffsetB[2];
  u32 Rotation;
  u32 LatencyPixelPosition;
  u64 ovrHmdInfo_UnkData00C0[0x4D]; // A lot of info we're discarding here, we don't know what this is.
  b8 ovrHmdInfo_UnkVar0328;
  ovrSizei FixedFovResolution;
  ovrShutterInfo Shutter;
  ovrLensConfig LensConfigurations[6];
  u32 ovrHmdInfo_UnkVar07DC;
  u64 ovrHmdInfo_UnkData07E0[8];
  u32 ovrHmdInfo_UnkVar0820;
  u32 ovrHmdInfo_UnkVar0824;
  u32 ovrHmdInfo_UnkVar0828;
  IOVRString* DisplayUniqueId; // Actually display unique ID?
  u32 ovrHmdInfo_UnkVar0838;
  IOVRString* WindowsAudioId;
  IOVRString* ovrHmdInfo_UnkVar0848;
  IOVRString* DeviceSerial;
  IOVRString* LeftDisplaySerial;
  IOVRString* RightDisplaySerial;
  IOVRString* LeftLensSerial;
  IOVRString* RightLensSerial;
  u8 ovrHmdInfo_UnkVar0878;
  IOVRString* ovrHmdInfo_UnkVar0880;
  u32 UsbVendorId;
  u32 UsbProductId;
  u32 ovrHmdInfo_UnkVar0890;
  u32 ovrHmdInfo_UnkVar0894;
  b8 ScreenLinkedToLenses;
  b8 SupportsLowPersistence;
  b8 SupportsPositionalTracking;
  b8 SupportsProximitySensor;
  u32 CapiReportedHmdType;
  b8 SupportsIADAdjust;
  b8 SupportsGuardianOnHost;
  b8 ovrHmdInfo_UnkVar08A2;
  b8 SupportsDirectPentile;
  b8 SupportsLatencyTiming;
  b8 SupportsSPUDUniformityCorrection;
  b8 SupportsSPUDCorrection;
  b8 SupportsLofiCorrection;
  f32 DisplayGamma;
  u32 ovrHmdInfo_UnkData08AC[7];
  u32 CompositorDistortionType;
  u32 ovrHmdInfo_UnkData08CC[4];
  b8 NewerFirmwareAvailable;
  b8 SupportsMixedRealityCapture;
  b8 SupportsInsideOutTracking;
  IOVRString* WFirmware;
  b8 HDMIAttached;
  b8 ProximityActive;
  b8 IsFirmwareOutOfDate;
  b8 MFInstallRequired;
  b8 WindowsUpgradeNeeded;
  u32 MinExternalTrackersRequired;
  u32 PerformanceCheckIndex;
  u32 ovrHmdInfo_UnkData08F8[2];
  u32 LastHealthErrorNumber;
  IOVRString* LastHealthError;
  u32 MaxTrackedDevicesSupported;
  u32 ovrHmdInfo_UnkVar0914;
  b8 ovrHmdInfo_UnkVar0918;
  b8 ovrHmdInfo_UnkVar0919;
  b8 ovrHmdInfo_UnkVar091A;
  u64 ovrHmdInfo_UnkVar0920;
  u64 ovrHmdInfo_UnkVar0928;
  u8 ovrHmdInfo_UnkVar0930;
  u8 ovrHmdInfo_UnkVar0931;
} ovrHmdInfo;
static_assert(sizeof(ovrHmdInfo) == 0x938, "sizeof(ovrHmdInfo) is not correct");

typedef struct ovrPosed_ {
  ovrQuatd Orientation;
  ovrVector3d Position;
} ovrPosed;

typedef class ovrPoseStated_ {
  ovrPosed ThePose;
  ovrVector3d AngularVelocity;
  ovrVector3d LinearVelocity;
  ovrVector3d AngularAcceleration;
  ovrVector3d LinearAcceleration;
  f64 TimeInSeconds;
} ovrPoseStated;
