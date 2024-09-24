#pragma once

namespace OVRSDK {
namespace Support {

// Oculus runtime changes can break our reverse-engineered VTables, etc.
// It is *highly* recommended (if not required) to use resources from the binary IDs we are currently targeting.
// They are intended to be downloaded via https://securecdn.oculus.com/binaries/download/?id=<BinaryId>
static const char* TargetRuntimeBinaryId = "3031299280335544";
static const char* TargetDriversBinaryId = "3653357211466543";

}
}
