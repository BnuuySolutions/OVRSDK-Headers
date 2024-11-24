#pragma once

#include "ovrsdk_interface.hpp"

typedef enum ovrlogLevel_ {
  OVRLOG_LEVEL_DISABLED = 0,
  OVRLOG_LEVEL_TRACE = 1,
  OVRLOG_LEVEL_DEBUG = 2,
  OVRLOG_LEVEL_INFO = 3,
  OVRLOG_LEVEL_WARNING = 4,
  OVRLOG_LEVEL_ERROR = 5
} ovrlogLevel;

const char* ovrlogLevel_ToString(ovrlogLevel level) {
  switch (level) {
  case OVRLOG_LEVEL_DISABLED: return " {DISABLED}";
  case OVRLOG_LEVEL_TRACE: return " {TRACE}   ";
  case OVRLOG_LEVEL_DEBUG: return " {DEBUG}   ";
  case OVRLOG_LEVEL_INFO: return " {INFO}    ";
  case OVRLOG_LEVEL_WARNING: return " {WARNING} ";
  case OVRLOG_LEVEL_ERROR: return " {!ERROR!} ";
  default: return " {???}     ";
  }
}

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

class IOVRLogWrite : public OVRInterface::IUnknown {
public:
  virtual void Log(ovrlogLevel level, const char* category, const char* msg) = 0;
};
