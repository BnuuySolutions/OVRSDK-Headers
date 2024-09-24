#pragma once

#include <windows.h>
#include <dxgicommon.h>
#include <cinttypes>

#if defined(_WIN32)
#define OVR_EXPORT extern "C" __declspec(dllexport)
#define OVR_FORCE_INLINE __forceinline
#else
#error "Unsupported Platform."
#endif

typedef struct ovrSizei_ {
  int w, h;
} ovrSizei;

typedef char ovrBool;

#define ovrFalse 0
#define ovrTrue 1

typedef int32_t ovrResult;

typedef enum ovrSuccessType_ {
  ovrSuccess = 0
} ovrSuccessType;

typedef enum ovrErrorType_ {
  ovrError_InvalidParameter = -1005,
  ovrError_Unsupported = -1009,
  ovrError_InsufficientArraySize = -1016
} ovrErrorType;

typedef enum ovrTextureFormat_ {
  OVR_FORMAT_UNKNOWN = 0,
  OVR_FORMAT_B5G6R5_UNORM = 1,
  OVR_FORMAT_B5G5R5A1_UNORM = 2,
  OVR_FORMAT_B4G4R4A4_UNORM = 3,
  OVR_FORMAT_R8G8B8A8_UNORM = 4,
  OVR_FORMAT_R8G8B8A8_UNORM_SRGB = 5,
  OVR_FORMAT_B8G8R8A8_UNORM = 6,
  OVR_FORMAT_B8G8R8_UNORM = 27, // Not supported.
  OVR_FORMAT_B8G8R8A8_UNORM_SRGB = 7,
  OVR_FORMAT_B8G8R8X8_UNORM = 8,
  OVR_FORMAT_B8G8R8X8_UNORM_SRGB = 9,
  OVR_FORMAT_R16G16B16A16_FLOAT = 10,
  OVR_FORMAT_R11G11B10_FLOAT = 25,
  OVR_FORMAT_R32_FLOAT = 26,
  OVR_FORMAT_D16_UNORM = 11,
  OVR_FORMAT_D24_UNORM_S8_UINT = 12,
  OVR_FORMAT_D32_FLOAT = 13,
  OVR_FORMAT_D32_FLOAT_S8X24_UINT = 14,
  OVR_FORMAT_BC1_UNORM = 15,
  OVR_FORMAT_BC1_UNORM_SRGB = 16,
  OVR_FORMAT_BC2_UNORM = 17,
  OVR_FORMAT_BC2_UNORM_SRGB = 18,
  OVR_FORMAT_BC3_UNORM = 19,
  OVR_FORMAT_BC3_UNORM_SRGB = 20,
  OVR_FORMAT_BC6H_UF16 = 21,
  OVR_FORMAT_BC6H_SF16 = 22,
  OVR_FORMAT_BC7_UNORM = 23,
  OVR_FORMAT_BC7_UNORM_SRGB = 24,
  OVR_FORMAT_LAST,
  OVR_FORMAT_ENUMSIZE = 0x7fffffff
} ovrTextureFormat;

typedef enum ovrDisplayOutputType_ {
  ovrDisplayOutput_Unknown = 0,
  ovrDisplayOutput_DP = 1,
  ovrDisplayOutput_DVI = 2,
  ovrDisplayOutput_HDMI = 3
} ovrDisplayOutputType;

typedef enum ovrDisplayDongleType_ {
  ovrDisplayDongle_Unknown = 0,
  ovrDisplayDongle_None = 1,
  ovrDisplayDongle_PassiveDPToDVI = 2,
  ovrDisplayDongle_PassiveDPToHDMI = 3,
  ovrDisplayDongle_ActiveDPToDVI = 4,
  ovrDisplayDongle_ActiveDPToHDMI = 5,
  ovrDisplayDongle_ActiveDPToVGA = 6
} ovrDisplayDongleType;

typedef enum ovrHMDEventType_ {
  OVR_HMD_EVENT_TYPE_DISPLAY_ATTACHED = 1,
  OVR_HMD_EVENT_TYPE_DISPLAY_DETACHED = 2,

  OVR_HMD_EVENT_TYPE_HMD_ATTACHED = 3,
  OVR_HMD_EVENT_TYPE_HMD_AVAILABLE = 4, // TODO(Kaitlyn): Is this correct?
  OVR_HMD_EVENT_TYPE_HMD_DETACHED = 5,

  OVR_HMD_EVENT_TYPE_IAD_CHANGED = 9 // Fired when IPD is changed.
} ovrHMDEventType;

typedef struct ovrGraphicsLuid_ {
  char Reserved[8];
} ovrGraphicsLuid;

typedef struct ovrDisplayProperties_ {
  ovrGraphicsLuid Luid;
  ovrDisplayOutputType OutputType;
  ovrDisplayDongleType DongleType;
  uint64_t UniqueId;
  char EdidData[0x100];
} ovrDisplayProperties;

typedef struct ovrModeDesc_ {
  ovrSizei Resolution;
  DXGI_RATIONAL RefreshRate;
  ovrTextureFormat Format;
  char Reserved[4]; // TODO(Kaitlyn): Is this actually reserved?
} ovrModeDesc;

typedef struct ovrPresentStats_ {
  DXGI_RATIONAL RefreshRate;
  // TODO(Kaitlyn): Reverse all of this sometime, no clue what any of this is.
  // Maybe stuff from IDXGISwapChain::GetFrameStatistics?
  uint64_t Reserved1;
  uint64_t Reserved2;
  uint64_t Reserved3;
  uint64_t Reserved4;
  uint64_t Reserved5;
  uint64_t Reserved6;
} ovrPresentStats;

typedef struct ovrInterfaceDesc_ {
  uint64_t ClassId;
  char ClassName[0x40];
  uint64_t InterfaceId;
  // TODO(Kaitlyn): Probably not actually reserved, reverse this later.
  uint64_t Reserved1;
  uint64_t Reserved2;
  uint64_t Reserved3;
} ovrInterfaceDesc;

typedef class ovrPoseState_ {
public:
  double OrientationX;
  double OrientationY;
  double OrientationZ;
  double OrientationW;
  double PositionX;
  double PositionY;
  double PositionZ;
  double AngularVelocityX;
  double AngularVelocityY;
  double AngularVelocityZ;
  double LinearVelocityX;
  double LinearVelocityY;
  double LinearVelocityZ;
  double AngularAccelerationX;
  double AngularAccelerationY;
  double AngularAccelerationZ;
  double LinearAccelerationX;
  double LinearAccelerationY;
  double LinearAccelerationZ;
  double TimeInSeconds;
} ovrPoseState;
