#pragma once

#include "ovrsdk_types.hpp"
#include "ovrsdk_interface.hpp"

namespace OVR {

static const uint64_t IID_IDirectDisplaySurface = 0xAD7152FE3248D8C4;
static const uint64_t IID_IDirectDisplay = 0xAD7152FE3248D8C6;
static const uint64_t IID_IDirectDisplayAPI = 0xAD7152FE3248D8C8;

class IDirectDisplaySurface : public OVRInterface::IUnknown {
public:
  virtual HANDLE GetSharedHandle() = 0;
};
class IDirectDisplay : public OVRInterface::IUnknown {
public:
  virtual ovrResult GetProperties(ovrDisplayProperties* outProperties) = 0;

  // No idea what this is, all of the IDirectDisplay implementations in OVRServer return unsupported.
  // So, we'll just follow the trend and return unsupported as well /shrug
  virtual ovrResult IDirectDisplay_Unk06() { return ovrError_Unsupported; }

  virtual ovrResult AcquireExclusive(::IUnknown* d3dPtr) = 0;
  virtual ovrResult ReleaseExclusive() = 0;

  // TODO(Kaitlyn): No clue what these 2 functions do, stubbing these. Not important.
  virtual ovrResult GetCurrentMode(void* a2) { return ovrError_Unsupported; }
  virtual ovrResult SetMode(void* a2) { return ovrSuccess; }

  virtual ovrResult CreateSurface(ovrModeDesc* modeDesc, IDirectDisplaySurface** outSurface) = 0;
  virtual ovrResult CreateFrameNotification(void* a2, void* a3) { return ovrError_Unsupported; } // Not required, so we'll just return unsupported.
  virtual ovrResult Present(IDirectDisplaySurface* surface, void* a3) = 0; // Still don't know what "a2" is, can be ignored for now I think?

  // Basically the same as GetPresentState, except the WaitForSingleObject passes in the custom timeout.
  // There is also no "outState" variable, the ovrResult is the state of the present state.
  // For example: ovrResult = ovrSuccess if the WaitForSingleObject is non-signaled.
  // Whatever else if there is a specific error when waiting for object.
  virtual ovrResult GetPresentStateTimeout(int timeoutMilliseconds) = 0;
  virtual ovrResult GetPresentStats(ovrPresentStats* outPresentStats) = 0;

  // TODO(Kaitlyn): These 2 functions have something to do with display visibility, no idea what they do.
  // Never called in practice, as far as I know... We'll just stub them, shouldn't matter.
  virtual ovrResult IDirectDisplay_Unk16(void* a2) { return ovrSuccess; }
  virtual ovrResult IDirectDisplay_Unk17() { return ovrSuccess; }

  virtual ovrResult GetPresentState(ovrBool* outState) = 0; // outValue: True = Present signaled (hangs rendering), False = Present non-signaled
  virtual ovrResult GetHdcpState(ovrBool* outState) = 0; // outValue: True = HDCP active, False = HDCP inactive
};
class IDirectDisplayAPI : public OVRInterface::IUnknown {
public:
  virtual ovrResult EnableDirectDisplay(ovrBool value) = 0;

  // TODO(Kaitlyn): Probably used for hotplugging, we'll stub this for now. Will come back to this later, hopefully.
  virtual ovrResult RegisterCallbacks(void* a2, void* a3) { return ovrSuccess; }

  // Used for getting displays by index? Never called in practice, stubbed as a result.
  virtual ovrResult IDirectDisplayAPI_Unk07(void* a2) { return ovrSuccess; }

  virtual ovrResult Enumerate(uint32_t index, IDirectDisplay** outDirectDisplay) = 0;
  virtual ovrResult GetName(char* outName) = 0;
};

} // OVR
