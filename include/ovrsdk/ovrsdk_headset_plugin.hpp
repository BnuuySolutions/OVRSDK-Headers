#pragma once

#include "ovrsdk_types.hpp"
#include "ovrsdk_interface.hpp"

namespace OVR {
namespace HeadsetPlugin {

typedef enum ovrDeviceType_ {
  OVR_DEVICE_TYPE_HMD = 0,
  OVR_DEVICE_TYPE_LEFT_TOUCH = 1,
  OVR_DEVICE_TYPE_RIGHT_TOUCH = 2,
  OVR_DEVICE_TYPE_TRACKED_OBJECT_0 = 3
} ovrDeviceType;

typedef enum ovrHMDEventType_ {
  OVR_HMD_EVENT_TYPE_DISPLAY_ATTACHED = 1,
  OVR_HMD_EVENT_TYPE_DISPLAY_DETACHED = 2,

  OVR_HMD_EVENT_TYPE_HMD_ATTACHED = 3,
  OVR_HMD_EVENT_TYPE_HMD_AVAILABLE = 4, // TODO(Kaitlyn): Is this correct?
  OVR_HMD_EVENT_TYPE_HMD_DETACHED = 5,

  OVR_HMD_EVENT_TYPE_IAD_CHANGED = 9 // Fired when IPD is changed.
} ovrHMDEventType;

typedef struct ovrDisplay_ {
  char UniqueId[0x100];
  uint16_t PnpId;
  char DisplaySerial[0x40];
  uint16_t Unk0142;
  ovrSizei Resolution1;
  ovrSizei Resolution2; // Wtf? Why 2?
  DXGI_RATIONAL RefreshRate;
  uint8_t Unk015C;
  uint8_t Reserved1;
  uint16_t Reserved2;
  uint64_t Luid;
  uint32_t Unk0168;
  uint8_t Unk016C;
} ovrDisplay;

typedef struct ovrDisplayList_ {
  int Count;
  char Reserved[0x2C]; // TODO(Kaitlyn): Actually reserved or not?
  ovrDisplay* Display; // Fix hardcoded single display at some point.
} ovrDisplayList;

class IHeadsetToRuntimeInterface : public OVRInterface::IUnknown {
public:
  virtual void IHeadsetToRuntimeInterface_Unk05() {} // nullsub
  virtual void IHeadsetToRuntimeInterface_Unk06() {} // nullsub
  virtual void IHeadsetToRuntimeInterface_Unk07() {} // nullsub (but has an implementation that returns 0 in OVRService)
  virtual void IHeadsetToRuntimeInterface_Unk08() {} // nullsub

  // TODO: Figure this out, both appear to do some input thing?
  virtual void IHeadsetToRuntimeInterface_Unk09(uint32_t a2, const char* serialNumber, uint32_t a4) {
  }
  virtual void IHeadsetToRuntimeInterface_Unk10(uint32_t a2, const char* serialNumber, __int64 a4) {
  }

  // Appears to be related to HMDEvent?
  virtual void IHeadsetToRuntimeInterface_Unk11(uint32_t a2, const char* serialNumber, uint32_t eventType, void* a5) = 0;

  // Appears to be related to FirmwareVersionEvent?
  virtual void IHeadsetToRuntimeInterface_Unk12(int a2, const char* serialNumber, __int64 a4) {}

  // Reports both controller and HMD firmware versions.
  virtual void FirmwareVersionEvent(int a2, const char* serialNumber, uint8_t a4, __int64 a5, const char* firmwareVersion) {}
  virtual void FirmwareUpdateEvent(int a2, const char* serialNumber, uint32_t* a4) {} // Also reports sensor firmware updates?

  // Maps roughly to the same OAF event, AFAIK.
  // No clue what a2 or a5 is.
  virtual void HMDEvent(unsigned int a2, const char* serialNumber, ovrHMDEventType eventType, void* a5) {
  }

  virtual void IHeadsetToRuntimeInterface_Unk16() {}
  virtual void IHeadsetToRuntimeInterface_Unk17() {}
  virtual void IHeadsetToRuntimeInterface_Unk18() {}
  virtual void IHeadsetToRuntimeInterface_Unk19() {}
  virtual void IHeadsetToRuntimeInterface_Unk20() {}
  virtual void IHeadsetToRuntimeInterface_Unk21() {}
  virtual void IHeadsetToRuntimeInterface_Unk22() {}
  virtual void IHeadsetToRuntimeInterface_Unk23() {}
  virtual void IHeadsetToRuntimeInterface_Unk24() {}
  virtual void IHeadsetToRuntimeInterface_Unk25() {}
  virtual void IHeadsetToRuntimeInterface_Unk26() {}
  virtual void IHeadsetToRuntimeInterface_Unk27() {}
  virtual void IHeadsetToRuntimeInterface_Unk28() {}
  virtual void IHeadsetToRuntimeInterface_Unk29() {}
  virtual void IHeadsetToRuntimeInterface_Unk30() {}
  virtual void IHeadsetToRuntimeInterface_Unk31() {}

  // a2 has the following values, likely device ID?
  // 0 = HMD
  // 1 = Left touch
  // 2 = Right touch
  // Also, the function name is a guess.
  virtual void DevicePoseEvent(ovrDeviceType deviceType, ovrPoseStated* devicePose, uint32_t a4) = 0;

  virtual void IHeadsetToRuntimeInterface_Unk33() {}
  virtual void IHeadsetToRuntimeInterface_Unk34() {}
  virtual void IHeadsetToRuntimeInterface_Unk35() {}
  virtual void IHeadsetToRuntimeInterface_Unk36() {}
  virtual void IHeadsetToRuntimeInterface_Unk37() {}
  virtual void IHeadsetToRuntimeInterface_Unk38() {}
  virtual void IHeadsetToRuntimeInterface_Unk39() {}
  virtual void IHeadsetToRuntimeInterface_Unk40() {}

  // TODO
  virtual void TrackerEvent(const char* serialNumber, uint32_t eventType, void* a5) {}

  virtual void IHeadsetToRuntimeInterface_Unk42() {}
  virtual void IHeadsetToRuntimeInterface_Unk43() {}
  virtual void IHeadsetToRuntimeInterface_Unk44() {}
  virtual void IHeadsetToRuntimeInterface_Unk45() {}
  virtual void IHeadsetToRuntimeInterface_Unk46() {}
  virtual void IHeadsetToRuntimeInterface_Unk47() {}
  virtual void IHeadsetToRuntimeInterface_Unk48() {}
  virtual void IHeadsetToRuntimeInterface_Unk49() {}
  virtual void IHeadsetToRuntimeInterface_Unk50() {}
  virtual int IHeadsetToRuntimeInterface_Unk51() { return 1; }
  virtual int IHeadsetToRuntimeInterface_Unk52() { return 1; }
  virtual void IHeadsetToRuntimeInterface_Unk53() {}
  virtual void IHeadsetToRuntimeInterface_Unk54() {}
  virtual void IHeadsetToRuntimeInterface_Unk55() {}
  virtual void IHeadsetToRuntimeInterface_Unk56() {}
  virtual void IHeadsetToRuntimeInterface_Unk57() {}
  virtual void IHeadsetToRuntimeInterface_Unk58() {}
  virtual void IHeadsetToRuntimeInterface_Unk59() {}
  virtual void IHeadsetToRuntimeInterface_Unk60() {}
  virtual void IHeadsetToRuntimeInterface_Unk61() {}
  virtual void IHeadsetToRuntimeInterface_Unk62(int a2, char a3, char a4) {
    //printf("a2 = %i, a3 = %i, a4 = %i\n", a2, a3, a4);
  }
  virtual void IHeadsetToRuntimeInterface_Unk63() {}
  virtual void IHeadsetToRuntimeInterface_Unk64() {}
  virtual void IHeadsetToRuntimeInterface_Unk65() {}
  virtual void IHeadsetToRuntimeInterface_Unk66() {}
  virtual void IHeadsetToRuntimeInterface_Unk67() {}
  virtual void IHeadsetToRuntimeInterface_Unk68() {}
  virtual void IHeadsetToRuntimeInterface_Unk69() {}
  virtual void IHeadsetToRuntimeInterface_Unk70() {}
  virtual void IHeadsetToRuntimeInterface_Unk71() {}
  virtual void IHeadsetToRuntimeInterface_Unk72() {}

  virtual int IHeadsetToRuntimeInterface_Unk73() { return 1; } // Display count?
  virtual ovrResult GetDisplayList(int a2, ovrDisplayList* displays) = 0;

  virtual void IHeadsetToRuntimeInterface_Unk75() {}
  virtual void IHeadsetToRuntimeInterface_Unk76() {}
  virtual void IHeadsetToRuntimeInterface_Unk77() {}
  virtual void IHeadsetToRuntimeInterface_Unk78() {}
  virtual void IHeadsetToRuntimeInterface_Unk79() {}
  virtual void IHeadsetToRuntimeInterface_Unk80() {}
  virtual void IHeadsetToRuntimeInterface_Unk81() {}
  virtual void IHeadsetToRuntimeInterface_Unk82() {}
  virtual void IHeadsetToRuntimeInterface_Unk83() {}
  virtual void IHeadsetToRuntimeInterface_Unk84() {}
  virtual void IHeadsetToRuntimeInterface_Unk85() {}
  virtual void IHeadsetToRuntimeInterface_Unk86() {}
  virtual void IHeadsetToRuntimeInterface_Unk87() {}
  virtual void IHeadsetToRuntimeInterface_Unk88() {}
  virtual void IHeadsetToRuntimeInterface_Unk89() {}
  virtual void IHeadsetToRuntimeInterface_Unk90() {}
  virtual void IHeadsetToRuntimeInterface_Unk91() {}
  virtual void IHeadsetToRuntimeInterface_Unk92() {}
  virtual void IHeadsetToRuntimeInterface_Unk93() {}
  virtual void IHeadsetToRuntimeInterface_Unk94() {}
  virtual void IHeadsetToRuntimeInterface_Unk95() {}
  virtual void IHeadsetToRuntimeInterface_Unk96() {}
  virtual void IHeadsetToRuntimeInterface_Unk97() {}
  virtual void IHeadsetToRuntimeInterface_Unk98() {}
  virtual void IHeadsetToRuntimeInterface_Unk99() {}
  virtual void IHeadsetToRuntimeInterface_Unk100() {}
  virtual void IHeadsetToRuntimeInterface_Unk101() {}
  virtual void IHeadsetToRuntimeInterface_Unk102() {}
  virtual void IHeadsetToRuntimeInterface_Unk103() {}
  virtual void IHeadsetToRuntimeInterface_Unk104() {}
  virtual void IHeadsetToRuntimeInterface_Unk105() {}
  virtual void IHeadsetToRuntimeInterface_Unk106() {}
  virtual void IHeadsetToRuntimeInterface_Unk107() {}
  virtual void IHeadsetToRuntimeInterface_Unk108() {}
  virtual void IHeadsetToRuntimeInterface_Unk109() {}
};

class IHeadsetToRuntimeInterface2 : public IHeadsetToRuntimeInterface {
public:
  // FIXME(Kaitlyn): It's hard to determine where this vtable begins, so this is just a stub for compatibility.
};

class IHeadsetInterface : public OVRInterface::IUnknown {
public:
  virtual void IHeadsetInterface_Unk05(char* a2) = 0;
  virtual void IHeadsetInterface_Unk06(int a2) = 0;
  virtual void IHeadsetInterface_Unk07() = 0;
  virtual void IHeadsetInterface_Unk08() = 0;
  virtual void IHeadsetInterface_Unk09() = 0;
  virtual void IHeadsetInterface_Unk10() = 0;
  virtual void IHeadsetInterface_Unk11() = 0;
  virtual void IHeadsetInterface_Unk12() = 0;
  virtual void IHeadsetInterface_Unk13() = 0;
  virtual void IHeadsetInterface_Unk14() = 0;
  virtual void IHeadsetInterface_Unk15() = 0;
  virtual void IHeadsetInterface_Unk16() = 0;
  virtual void IHeadsetInterface_Unk17() = 0;
  virtual void IHeadsetInterface_Unk18() = 0;
  virtual void IHeadsetInterface_Unk19() = 0;
  virtual void IHeadsetInterface_Unk20() = 0;
  virtual void IHeadsetInterface_Unk21() = 0;
  virtual void IHeadsetInterface_Unk22() = 0;
  virtual void IHeadsetInterface_Unk23() = 0;
  virtual void IHeadsetInterface_Unk24() = 0;
  virtual void IHeadsetInterface_Unk25() = 0;
  virtual void IHeadsetInterface_Unk26() = 0;
  virtual void IHeadsetInterface_Unk27() = 0;
  virtual void IHeadsetInterface_Unk28() = 0;
  virtual void IHeadsetInterface_Unk29() = 0;
  virtual void IHeadsetInterface_Unk30() = 0;
  virtual void IHeadsetInterface_Unk31() = 0;
  virtual void IHeadsetInterface_Unk32() = 0;
  virtual void IHeadsetInterface_Unk33() = 0;
  virtual void IHeadsetInterface_Unk34() = 0;
  virtual void IHeadsetInterface_Unk35() = 0;
  virtual void IHeadsetInterface_Unk36() = 0;
  virtual void IHeadsetInterface_Unk37() = 0;
  virtual void IHeadsetInterface_Unk38() = 0;
  virtual void IHeadsetInterface_Unk39() = 0;
  virtual void IHeadsetInterface_Unk40() = 0;
  virtual void IHeadsetInterface_Unk41() = 0;
  virtual void IHeadsetInterface_Unk42() = 0;
  virtual void IHeadsetInterface_Unk43() = 0;
  virtual void IHeadsetInterface_Unk44() = 0;
  virtual void IHeadsetInterface_Unk45() = 0;
  virtual void IHeadsetInterface_Unk46() = 0;
  virtual void IHeadsetInterface_Unk47() = 0;
  virtual void IHeadsetInterface_Unk48() = 0;
  virtual void IHeadsetInterface_Unk49() = 0;
  virtual void IHeadsetInterface_Unk50() = 0;
  virtual void IHeadsetInterface_Unk51() = 0;
  virtual void IHeadsetInterface_Unk52() = 0;
  virtual void IHeadsetInterface_Unk53() = 0;
  virtual void IHeadsetInterface_Unk54() = 0;
  virtual void IHeadsetInterface_Unk55(uint32_t a2) = 0; // Some tracking thing.
};

class IOVRHeadsetPluginAddition : public OVRInterface::IUnknown {
public:
  virtual ovrBool CreateHeadsetInterface(IHeadsetToRuntimeInterface2** runtimeInterface, IHeadsetInterface** outHeadsetInterface) = 0;
};

}
}
