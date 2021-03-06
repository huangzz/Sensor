/*****************************************************************************
*                                                                            *
*  PrimeSense Sensor 5.x Alpha                                               *
*  Copyright (C) 2012 PrimeSense Ltd.                                        *
*                                                                            *
*  This file is part of PrimeSense Sensor                                    *
*                                                                            *
*  Licensed under the Apache License, Version 2.0 (the "License");           *
*  you may not use this file except in compliance with the License.          *
*  You may obtain a copy of the License at                                   *
*                                                                            *
*      http://www.apache.org/licenses/LICENSE-2.0                            *
*                                                                            *
*  Unless required by applicable law or agreed to in writing, software       *
*  distributed under the License is distributed on an "AS IS" BASIS,         *
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  *
*  See the License for the specific language governing permissions and       *
*  limitations under the License.                                            *
*                                                                            *
*****************************************************************************/
#ifndef __XN_SENSOR_FPS_H__
#define __XN_SENSOR_FPS_H__

//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------
#include <XnFPSCalculator.h>
#include <XnLog.h>

//---------------------------------------------------------------------------
// Defines
//---------------------------------------------------------------------------
#define XN_MASK_SENSOR_FPS	"FramesTimes"

//---------------------------------------------------------------------------
// XnSensorFPS class
//---------------------------------------------------------------------------
class XnSensorFPS
{
public:
	XnSensorFPS();
	~XnSensorFPS();

	inline void MarkInputDepth(XnUInt32 nFrameID, XnUInt64 nTS) { Mark(&m_InputDepth, "DepthInput", nFrameID, nTS); }
	inline void MarkInputImage(XnUInt32 nFrameID, XnUInt64 nTS) { Mark(&m_InputImage, "ImageInput", nFrameID, nTS); }
	inline void MarkReadCalled() { Mark(&m_ReadCalls, "ReadCalled", 0, 0); }
	inline void MarkOutputDepth(XnUInt32 nFrameID, XnUInt64 nTS) { Mark(&m_OutputDepth, "DepthOutput", nFrameID, nTS); }
	inline void MarkOutputImage(XnUInt32 nFrameID, XnUInt64 nTS) { Mark(&m_OutputImage, "ImageOutput", nFrameID, nTS); }

private:
	void Mark(XnFPSData* pFPS, const XnChar* csName, XnUInt32 nFrameID, XnUInt64 nTS);

	XnFPSData m_InputDepth;
	XnFPSData m_InputImage;
	XnFPSData m_ReadCalls;
	XnFPSData m_OutputDepth;
	XnFPSData m_OutputImage;

	XnUInt64 m_nLastPrint;
	XnDumpFile* m_FramesDump;
};

#endif //__XN_SENSOR_FPS_H__
