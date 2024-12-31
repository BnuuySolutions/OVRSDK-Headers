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

#include "OVRSDK_Types.h"
#include "OVRSDK_IOVRString.h"
#include "OVRSDK_IGatekeeper.h"
#include "OVRSDK_IOVRCrashDump.h"
#include "OVRSDK_IOVRLogWrite.h"
#include "OVRSDK_IOVRTelemetry.h"
#include "OVRSDK_IOVRTimeCriticalTelemetry.h"

// OVRInterface
#include "OVRInterface/OVRSDK_IRefCounted.h"
#include "OVRInterface/OVRSDK_IUnknown.h"
#include "OVRInterface/OVRSDK_IInterfaceFactory.h"
#include "OVRInterface/OVRSDK_IAggregateInterfaceFactory.h"
#include "OVRInterface/OVRSDK_OVRAggregateInterfaceFactory.h"
#include "OVRInterface/OVRSDK_OVRInterfaceManager.h"

// HeadsetPlugin
#include "HeadsetPlugin/OVRSDK_IHeadsetInterface.h"
#include "HeadsetPlugin/OVRSDK_IHeadsetToRuntimeInterface.h"
#include "HeadsetPlugin/OVRSDK_IHeadsetToRuntimeInterface2.h"
#include "HeadsetPlugin/OVRSDK_IOVRHeadsetPluginAddition.h"
