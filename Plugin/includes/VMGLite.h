#pragma once

#define VHAND_STRLEN 256

//dataglove model
#define USB_MODEL 1
#define WIFI_MODEL 2

//dataglove connection types
#define CONNECTION_NOT_FOUND 0
#define USB_CONNECTION_FOUND 1
#define WIFI_CONNECTION_FOUND 2

//dataglove connection status
#define NOT_CONNECTED 0
#define CONNECTED 1

#define USB_NOT_CONNECTED 1
#define WIFI_NOT_CONNECTED 2
#define USB_CONNECTED 4
#define WIFI_CONNECTED 8

//dataglove connection type
#define CONN_USB 1
#define CONN_WIFI 2

//dataglove method results
#define GLOVE_PARAM_ERROR 0
#define GLOVE_OK 1
#define GLOVE_ERROR_NO_CONN 2
#define GLOVE_ERROR_NO_DATA 4
#define GLOVE_ERROR_STREAMING 8

//dataglove streaming mode
#define STREAM_FINGERS_QUATERNION 1
#define STREAM_QUATERNION 2
#define STREAM_FINGERS_RAW 3
#define STREAM_RAW 4
#define STREAM_FINGERS 5

#define NOT_FOUND 0
#define FOUND 1


#define PKG_ERROR 1
#define NO_ERRORS 0


#define FPS_STD 0
#define FPS_100 1
#define FPS_50	2
#define FPS_33	3
#define FPS_25	4
#define FPS_20	5
#define FPS_10  6


#ifdef VMGLite_SDK_EXPORTS
#define VMGLite_API __declspec(dllexport) 
#else
#define VMGLite_API __declspec(dllimport) 
#endif

 class VMGLite_API VMGLite
{
public:
	 VMGLite(void);
	  ~VMGLite(void);

	 int  SetConnectionParameters(int comport);
	 int  GetConnectionParameters(int *comport);
	 int  Connect(int StreamMode);
	 int  Disconnect();
	 int  GetConnectionStatus();

	 int  GetModel();
	 int  GetID(char *label, int *id);
	 int  GetMACAddress(unsigned char *mac);
	 int GetBTLabel(char *label);
	 int GetBTPasskey(char *passkey);
	 int  GetFWVersion(int *fw1, int *fw2, int *fw3);
	 int  GetConnectionMethod(int *connmethod);
	 int  GetStreamMode(int *strmode);
	 int  GetCOMSettings(int *COMPORT);

	 int  GetFingers(double *fingers);
	
	 int  GetAttitude(double *roll, double *pitch, double *yaw);
	 int  GetQuaternion(double *quat1, double *quat2, double *quat3, double *quat4);

	 int  GetGyros(double *gyro1, double *gyro2, double *gyro3);
	 int  GetAccels(double *accel1, double *accel2, double *accel3);
	 int  GetMagns(double *magn1, double *magn2, double *magn3);

	 int SetId(int id);
	 int SetLabel(char *label);
	 int SetBTLabel(char *label);
	 int SetBTPasskey(char *passkey);

	 unsigned int GetLastPackageTime();

	 int TurnOFF(int ConnMethod);

	 int SetFPS(int fps);
	 int GetFPS(int *fps);

public:
	//dataglove proprierties
	int Sampling		;	//!< Sampling ONOFF
	int Model			;	//!< dataglove model, USB or WiFi
	int Micro			;	//!< micro
	int ID			;	//!< dataglove ID
	char Name[VHAND_STRLEN]		;	//!< dataglove label
	char BTNAme[VHAND_STRLEN]	;
	char BTPasskey[VHAND_STRLEN];

	unsigned char MAC[6];
	
	unsigned char fwversion[3];

	int StreamMode		;	//!< streaming mode
	int ConnMode		;	//!< requested connection mode
	long lastPkgTime	;	//!< last package time in millisecond
	int Errors		;	//!< streaming error

	int COMPORT		;	//!< selected comport
	int COMFound		;	//!< found comport?
	int WiFiFound		;	//!< wifi found?

	int Connected		;	//!< dataglove connected in such a way....
	int COMConnected	;	//!< conneced over comport?

	double Fingers[5]	;	//!< fingers data 0.0 -> 100.0
	double Quat[4]		;	//!<raw quaternion values	
	double Roll		;	//!< roll (from quaternion)
	double Pitch		;	//!< pitch (from quaternion)
	double Yaw		;	//!< yaw (from quaternion)

	double gyro[3]		;	//!< raw gyros data
	double accel[3]	;	//!< raw accelerometer data
	double magn[3]		;	//!< raw magnetometer data

	int FrameRateBT	;

};

