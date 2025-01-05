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

using b8 = u8; // Boolean (unsigned 8-bit integer)

using ovrsdkResult = s32; // OVRSDK result (signed 32-bit integer)

// Forward-declare some internal types.

class IOVRString;

/* Enums */

typedef enum ovrsdkErrorType_ {
  ovrsdkError_InvalidParameter = -1005,
  ovrsdkError_Unsupported = -1009,
  ovrsdkError_InsufficientArraySize = -1016
} ovrsdkErrorType;

typedef enum ovrsdkLogLevelType_ {
  ovrsdkLogLevel_Disabled = 0,
  ovrsdkLogLevel_Trace = 1,
  ovrsdkLogLevel_Debug = 2,
  ovrsdkLogLevel_Info = 3,
  ovrsdkLogLevel_Warning = 4,
  ovrsdkLogLevel_Error = 5,
  ovrsdkLogLevel_EnumSize = 0x7fffffff
} ovrsdkLogLevelType;

typedef enum ovrsdkPluginMode_ {
  ovrsdkPlugin_Off = 0, // Turns off the headset plugin.
  ovrsdkPlugin_Detect = 1, // Detects headsets and/or other devices, etc.
  ovrsdkPlugin_On = 2, // Turns on the headset plugin.
  ovrsdkPlugin_EnumSize = 0x7fffffff
} ovrsdkPluginMode;

typedef enum ovrsdkTrackingCaps_ {
  ovrsdkTrackingCap_Orientation = 0x10, // Orientation tracking (IMU).
  ovrsdkTrackingCap_MagYawCorrection = 0x20, // Yaw drift correction.
  ovrsdkTrackingCap_Position = 0x40, // Positional tracking.
  ovrsdkTrackingCap_EnumSize = 0x7fffffff
} ovrsdkTrackingCaps;

typedef enum ovrsdkHandType_ {
  ovrsdkHand_Left = 0,
  ovrsdkHand_Right = 1,
  ovrsdkHand_Count = 2,
  ovrsdkHand_EnumSize = 0x7fffffff
} ovrsdkHandType;

typedef enum ovrsdkCapsenseType_ {
  ovrsdkCapsense_Thumbstick = 0,
  ovrsdkCapsense_Button0 = 1, // Y button on Left touch, B button on Right touch
  ovrsdkCapsense_IndexTrigger = 2,
  ovrsdkCapsense_Button1 = 3, // X button on Left touch, A button on Right touch
  ovrsdkCapsense_Reserved0 = 4,
  ovrsdkCapsense_Reserved1 = 5,
  ovrsdkCapsense_Reserved2 = 6,
  ovrsdkCapsense_Thumbrest = 7,
  ovrsdkCapsense_Reserved4 = 8,
  ovrsdkCapsense_Reserved5 = 9,
  ovrsdkCapsense_Count = 10,
  ovrsdkCapsense_EnumSize = 0x7fffffff
} ovrsdkCapsenseType;

/* Structs */

template <typename T>
struct ovrsdkSize {
  T w, h;
};
static_assert(sizeof(ovrsdkSize<s32>) == 0x8, "sizeof(ovrsdkSize<s32>) is not correct");
static_assert(sizeof(ovrsdkSize<f32>) == 0x8, "sizeof(ovrsdkSize<f32>) is not correct");

template <typename T>
struct ovrsdkQuat {
  T x, y, z, w;
};
static_assert(sizeof(ovrsdkQuat<f32>) == 0x10, "sizeof(ovrsdkQuat<f32>) is not correct");
static_assert(sizeof(ovrsdkQuat<f64>) == 0x20, "sizeof(ovrsdkQuat<f64>) is not correct");

template <typename T>
struct ovrsdkVector3 {
  T x, y, z;
};
static_assert(sizeof(ovrsdkVector3<f32>) == 0xC, "sizeof(ovrsdkVector3<f32>) is not correct");
static_assert(sizeof(ovrsdkVector3<f64>) == 0x18, "sizeof(ovrsdkVector3<f64>) is not correct");

template <typename T>
struct ovrsdkVector2 {
  T x, y;
};
static_assert(sizeof(ovrsdkVector2<f32>) == 0x8, "sizeof(ovrsdkVector2<f32>) is not correct");
static_assert(sizeof(ovrsdkVector2<f64>) == 0x10, "sizeof(ovrsdkVector2<f64>) is not correct");

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
  u16 Capsense[ovrsdkCapsense_Count];
  f32 IndexTrigger;
  f32 HandTrigger;
  ovrsdkVector2<f32> Thumbstick;
  u32 ovrControllerState_UnkData0030[7];
  f32 IndexTriggerNoDeadzone;
  f32 HandTriggerNoDeadzone;
  ovrsdkVector2<f32> ThumbstickNoDeadzone;
  u32 ovrControllerState_UnkData005C[7];
  f32 IndexTriggerRaw;
  f32 HandTriggerRaw;
  ovrsdkVector2<f32> ThumbstickRaw;
  u32 ovrControllerState_UnkData0088[7];
  u32 ovrControllerState_UnkVar00A4;
} ovrControllerState;
// TODO(whatdahopper): assert sizeof

typedef struct OVRSDK_ALIGNAS(8) ovrCombinedControllerState_ {
  u64 ovrLeftRightControllerState_UnkData[2];
  ovrControllerState Controllers[ovrsdkHand_Count];
} ovrCombinedControllerState;
// TODO(whatdahopper): assert sizeof

typedef struct OVRSDK_ALIGNAS(4) ovrsdkDisplayInfo_ {
  char DeviceName[0x100];
  u16 EdidVendorId; // Usually 0xD23E
  char EdidSerial[0x40];
  u16 ovrDisplayInfo_UnkVar0142;
  ovrsdkSize<s32> NativeResolution;
  ovrsdkSize<s32> Resolution;
  DXGI_RATIONAL RefreshRate;
  b8 ApplicationOnlyMode;
  b8 ovrDisplayInfo_UnkVar015D;
  u32 ovrDisplayInfo_UnkVar0160;
  LUID AdapterLuid;
  u32 ovrDisplayInfo_UnkVar016C;
  u8 Edid[0x100];
  u32 ovrDisplayInfo_UnkVar0270;
} ovrsdkDisplayInfo;
static_assert(sizeof(ovrsdkDisplayInfo) == 0x274, "sizeof(ovrsdkDisplayInfo) is not correct");

typedef struct OVRSDK_ALIGNAS(4) ovrScreenInfo_ {
  ovrsdkSize<s32> ResolutionInPixels;
  ovrsdkSize<s32> SizeInMeters;
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
  ovrsdkSize<s32> ResolutionInPixels;
  ovrsdkSize<f32> ScreenSizeInMeters;
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
  ovrsdkSize<s32> FixedFovResolution;
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
  ovrsdkQuat<f64> Orientation;
  ovrsdkVector3<f64> Position;
} ovrPosed;

typedef class ovrPoseStated_ {
  ovrPosed ThePose;
  ovrsdkVector3<f64> AngularVelocity;
  ovrsdkVector3<f64> LinearVelocity;
  ovrsdkVector3<f64> AngularAcceleration;
  ovrsdkVector3<f64> LinearAcceleration;
  f64 TimeInSeconds;
} ovrPoseStated;
