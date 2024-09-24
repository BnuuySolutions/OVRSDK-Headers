#pragma once

#include "OVR_Types.h"
#include "OVR_Interface.h"
#include "OVR_DirectDisplay.h"
#include "OVR_HeadsetPlugin.h"

namespace OculusSDK {
namespace Support {

// Oculus runtime changes can break our recreated vtables, etc.
// It is *highly* recommended (if not required) to use stuff from the binary IDs we are currently targeting.
// Intended to be downloaded via https://securecdn.oculus.com/binaries/download/?id=<BinaryId>
static const char* RuntimeBinaryId = "3031299280335544";
static const char* DriversBinaryId = "3653357211466543";

}
}
