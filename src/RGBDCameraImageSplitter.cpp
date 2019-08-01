// -*- C++ -*-
/*!
 * @file  RGBDCameraImageSplitter.cpp
 * @brief RGBDCameraImage converted to Img::TimedCameraImage and RGBDCamera::TimedDepthImage
 * @date $Date$
 *
 * $Id$
 */

#include "RGBDCameraImageSplitter.h"

// Module specification
// <rtc-template block="module_spec">
static const char* rgbdcameraimagesplitter_spec[] =
  {
    "implementation_id", "RGBDCameraImageSplitter",
    "type_name",         "RGBDCameraImageSplitter",
    "description",       "RGBDCameraImage converted to ImgTimedCameraImage and RGBDCameraTimedDepthImage",
    "version",           "1.0.0",
    "vendor",            "Sugar Sweet Robotics",
    "category",          "Sensor",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",

	"conf.default.debug", "1",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
RGBDCameraImageSplitter::RGBDCameraImageSplitter(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_rgbdIn("rgbd", m_rgbd),
    m_rgbOut("rgb", m_rgb),
    m_depthOut("depth", m_depth)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
RGBDCameraImageSplitter::~RGBDCameraImageSplitter()
{
}



RTC::ReturnCode_t RGBDCameraImageSplitter::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("rgbd", m_rgbdIn);
 m_rgbdIn.addConnectorDataListener(ON_BUFFER_WRITE,	  new RGBDDataListener(this));

  // Set OutPort buffer
  addOutPort("rgb", m_rgbOut);
  addOutPort("depth", m_depthOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t RGBDCameraImageSplitter::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RGBDCameraImageSplitter::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RGBDCameraImageSplitter::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RGBDCameraImageSplitter::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RGBDCameraImageSplitter::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RGBDCameraImageSplitter::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RGBDCameraImageSplitter::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RGBDCameraImageSplitter::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RGBDCameraImageSplitter::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RGBDCameraImageSplitter::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RGBDCameraImageSplitter::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void RGBDCameraImageSplitterInit(RTC::Manager* manager)
  {
    coil::Properties profile(rgbdcameraimagesplitter_spec);
    manager->registerFactory(profile,
                             RTC::Create<RGBDCameraImageSplitter>,
                             RTC::Delete<RGBDCameraImageSplitter>);
  }
  
};


