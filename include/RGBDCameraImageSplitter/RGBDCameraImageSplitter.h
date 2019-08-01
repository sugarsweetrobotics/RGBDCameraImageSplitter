// -*- C++ -*-
/*!
 * @file  RGBDCameraImageSplitter.h
 * @brief RGBDCameraImage converted to Img::TimedCameraImage and RGBDCamera::TimedDepthImage
 * @date  $Date$
 *
 * $Id$
 */

#ifndef RGBDCAMERAIMAGESPLITTER_H
#define RGBDCAMERAIMAGESPLITTER_H

#include <rtm/idl/BasicDataTypeSkel.h>
#include <rtm/idl/ExtendedDataTypesSkel.h>
#include <rtm/idl/InterfaceDataTypesSkel.h>

#include <rtm/idl/CameraCommonInterfaceSkel.h>

// Service implementation headers
// <rtc-template block="service_impl_h">

// </rtc-template>

// Service Consumer stub headers
// <rtc-template block="consumer_stub_h">
#include "DepthCameraStub.h"

// </rtc-template>

// Service Consumer stub headers
// <rtc-template block="port_stub_h">
using namespace RGBDCamera;
using namespace Img;
// </rtc-template>

#include <rtm/Manager.h>
#include <rtm/DataFlowComponentBase.h>
#include <rtm/CorbaPort.h>
#include <rtm/DataInPort.h>
#include <rtm/DataOutPort.h>

using namespace RTC;

/*!
 * @class RGBDCameraImageSplitter
 * @brief RGBDCameraImage converted to Img::TimedCameraImage and RGBDCamera::TimedDepthImage
 *
 */
class RGBDCameraImageSplitter
  : public RTC::DataFlowComponentBase
{
 public:
  /*!
   * @brief constructor
   * @param manager Maneger Object
   */
  RGBDCameraImageSplitter(RTC::Manager* manager);

  /*!
   * @brief destructor
   */
  ~RGBDCameraImageSplitter();

  // <rtc-template block="public_attribute">
  
  // </rtc-template>

  // <rtc-template block="public_operation">
  
  // </rtc-template>

  /***
   *
   * The initialize action (on CREATED->ALIVE transition)
   * formaer rtc_init_entry() 
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onInitialize();

  /***
   *
   * The finalize action (on ALIVE->END transition)
   * formaer rtc_exiting_entry()
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onFinalize();

  /***
   *
   * The startup action when ExecutionContext startup
   * former rtc_starting_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onStartup(RTC::UniqueId ec_id);

  /***
   *
   * The shutdown action when ExecutionContext stop
   * former rtc_stopping_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onShutdown(RTC::UniqueId ec_id);

  /***
   *
   * The activated action (Active state entry action)
   * former rtc_active_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onActivated(RTC::UniqueId ec_id);

  /***
   *
   * The deactivated action (Active state exit action)
   * former rtc_active_exit()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onDeactivated(RTC::UniqueId ec_id);

  /***
   *
   * The execution action that is invoked periodically
   * former rtc_active_do()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onExecute(RTC::UniqueId ec_id);

  /***
   *
   * The aborting action when main logic error occurred.
   * former rtc_aborting_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onAborting(RTC::UniqueId ec_id);

  /***
   *
   * The error action in ERROR state
   * former rtc_error_do()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onError(RTC::UniqueId ec_id);

  /***
   *
   * The reset action that is invoked resetting
   * This is same but different the former rtc_init_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onReset(RTC::UniqueId ec_id);
  
  /***
   *
   * The state update action that is invoked after onExecute() action
   * no corresponding operation exists in OpenRTm-aist-0.2.0
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onStateUpdate(RTC::UniqueId ec_id);

  /***
   *
   * The action that is invoked when execution context's rate is changed
   * no corresponding operation exists in OpenRTm-aist-0.2.0
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onRateChanged(RTC::UniqueId ec_id);


 protected:
  // <rtc-template block="protected_attribute">
  
  // </rtc-template>

  // <rtc-template block="protected_operation">
  
  // </rtc-template>

  // Configuration variable declaration
  // <rtc-template block="config_declare">

  // </rtc-template>

  // DataInPort declaration
  // <rtc-template block="inport_declare">
  RGBDCamera::TimedRGBDCameraImage m_rgbd;
  /*!
   */
  InPort<RGBDCamera::TimedRGBDCameraImage> m_rgbdIn;
  
  // </rtc-template>


  // DataOutPort declaration
  // <rtc-template block="outport_declare">
  Img::TimedCameraImage m_rgb;
  /*!
   */
  OutPort<Img::TimedCameraImage> m_rgbOut;
  RGBDCamera::TimedDepthImage m_depth;
  /*!
   */
  OutPort<RGBDCamera::TimedDepthImage> m_depthOut;
  
  // </rtc-template>

  // CORBA Port declaration
  // <rtc-template block="corbaport_declare">
  
  // </rtc-template>

  // Service declaration
  // <rtc-template block="service_declare">
  
  // </rtc-template>

  // Consumer declaration
  // <rtc-template block="consumer_declare">
  
  // </rtc-template>

 private:
  // <rtc-template block="private_attribute">
  
  // </rtc-template>

  // <rtc-template block="private_operation">
  
  // </rtc-template>

	 public:
		 void writeSplitData(const RGBDCamera::TimedRGBDCameraImage& data) {
			 m_rgb.data = data.data.cameraImage;
			 m_rgb.tm = data.tm;
			 m_rgbOut.write();

			 m_depth.data = data.data.depthImage;
			 m_depth.tm = data.tm;
			 m_depthOut.write();
		 }
};


class RGBDDataListener
	: public ConnectorDataListenerT<RGBDCamera::TimedRGBDCameraImage>
{
public:
	RGBDDataListener(RGBDCameraImageSplitter* rtc) : m_parent(rtc), vx(0), vy(0), vz(0) {}
	virtual ~RGBDDataListener()
	{
		//std::cout << "dtor of " << m_name << std::endl;
	}



	virtual ReturnCode operator()(ConnectorInfo& info,
		RGBDCamera::TimedRGBDCameraImage& data)
	{
		m_parent->writeSplitData(data);
		/*
		static int stdout_counter;
		double gain = m_parent->getGain();
		double dvx = data.data.vx - vx;
		if (dvx < 0 && dvx < -gain) { dvx = -gain; }
		else if (dvx > 0 && dvx > gain) { dvx = gain; }
		vx += dvx;


		double dvz = data.data.va - vz;
		if (dvz < 0 && dvz < -gain) { dvz = -gain; }
		else if (dvz > 0 && dvz > gain) { dvz = gain; }
		vz += dvz;

		stdout_counter++;
		if (stdout_counter % 10 == 0) {
			std::cout << "[RTC:VelocitySmoother] vx / target = " << vx << " / " << data.data.vx << " / " << dvx << std::endl;
			std::cout << "[RTC:VelocitySmoother] vz / target = " << vz << " / " << data.data.va << " / " << dvz << std::endl;
		}

		m_parent->writeVelocity(vx, vy, vz);
		*/
		return RTC::ConnectorDataListener::ReturnCode::NO_CHANGE;
	};


	RGBDCameraImageSplitter *m_parent;
	double vx, vy, vz;
};


extern "C"
{
  DLL_EXPORT void RGBDCameraImageSplitterInit(RTC::Manager* manager);
};

#endif // RGBDCAMERAIMAGESPLITTER_H
