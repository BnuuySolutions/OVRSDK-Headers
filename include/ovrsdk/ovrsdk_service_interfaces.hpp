#pragma once

#include "ovrsdk_interface.hpp"

class IGatekeeper : public OVRInterface::IUnknown {
public:
  virtual uint8_t FetchGatekeeper(const char* gkName) = 0;
};

class IOVRCrashDump : public OVRInterface::IUnknown {
public:
  virtual void IOVRCrashDump_Unk05() {}
};

class IOVRTelemetry : public OVRInterface::IUnknown {
public:
  virtual void IOVRTelemetry_Unk05() {}
};
