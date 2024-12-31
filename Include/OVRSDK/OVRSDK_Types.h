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

#include <cmath>
#include <cstdint>

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

/* Structs */

typedef struct OVRSDK_ALIGNAS(4) ovrSizei_ {
  s32 w, h;
} ovrSizei;
static_assert(sizeof(ovrSizei) == 0x8, "sizeof(ovrSizei) is not correct");

typedef struct OVRSDK_ALIGNAS(4) ovrSizef_ {
  f32 w, h;
} ovrSizef;
static_assert(sizeof(ovrSizef) == 0x8, "sizeof(ovrSizef) is not correct");

typedef struct OVRSDK_ALIGNAS(8) ovrInterfaceDesc_ {
  u64 ClassId;
  char ClassName[0x40];
  u64 InterfaceId0;
  u64 InterfaceId1;
  u64 InterfaceId2;
  u64 InterfaceId3;
} ovrInterfaceDesc;
static_assert(sizeof(ovrInterfaceDesc) == 0x68, "sizeof(ovrInterfaceDesc) is not correct");

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
  u32 ovrShutterInfo_UnkVar0018; // Related to OverdriveScale?
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
  u32 ovrHmdInfo_UnkVar032C;
  u32 ovrHmdInfo_UnkVar0330;
  ovrShutterInfo Shutter;
  ovrLensConfig LensConfigurations[6];
  u32 ovrHmdInfo_UnkVar07DC;
  u64 ovrHmdInfo_UnkData07E0[8];
  u32 ovrHmdInfo_UnkVar0820;
  u32 ovrHmdInfo_UnkVar0824;
  u32 ovrHmdInfo_UnkVar0828;
  IOVRString* DisplayUniqueId; // Actually display unique ID?
  u32 ovrHmdInfo_UnkVar0838;
  IOVRString* ovrHmdInfo_UnkVar0840;
  IOVRString* ovrHmdInfo_UnkVar0848;
  IOVRString* DisplaySerial;
  IOVRString* LeftScreenSerial;
  IOVRString* RightScreenSerial;
  IOVRString* ovrHmdInfo_UnkVar0868;
  IOVRString* ovrHmdInfo_UnkVar0870;
  u8 ovrHmdInfo_UnkVar0878;
  IOVRString* ovrHmdInfo_UnkVar0880;
  u32 USBVendorID;
  u32 USBProductID;
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
