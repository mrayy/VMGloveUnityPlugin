
#include "Plugin.h"
#include <VMGLite.h>
#include <Windows.h>

UNITY_INTERFACE_EXPORT void* VMGUnity_CreateGloveInstance()
{

	VMGLite *dataglove = new VMGLite();
	return dataglove;
}

UNITY_INTERFACE_EXPORT void VMGUnity_DestroyGloveInstance(void*instance)
{

	VMGLite*dataglove = (VMGLite*)instance;
	if (!dataglove)
		return ;
	delete dataglove;
}
UNITY_INTERFACE_EXPORT bool VMGUnity_Open(void*instance, int port, int fps)
{
	VMGLite*dataglove = (VMGLite*)instance;
	if (!dataglove)
		return false;
	dataglove->SetConnectionParameters(port);
	dataglove->SetFPS(fps);
	dataglove->Connect(STREAM_FINGERS_QUATERNION);
	//wait for connection established
	long start = ::GetTickCount();
	while ((dataglove->Connected == NOT_CONNECTED))
	{
		if ((::GetTickCount() - start) > 10000) {
			//timeout, error with the connection
			dataglove->Disconnect();
			return false;
		}
	}

	return true;
}
UNITY_INTERFACE_EXPORT bool VMGUnity_Disconnect(void*instance)
{
	VMGLite*dataglove = (VMGLite*)instance;
	if (!dataglove)
		return false;

	//disconnect socket
	dataglove->Disconnect();
	Sleep(1000);
	//turn off module
	dataglove->TurnOFF(CONN_USB);
	return true;
}
UNITY_INTERFACE_EXPORT int VMGUnity_GetID(void*instance)
{
	VMGLite*dataglove = (VMGLite*)instance;
	if (!dataglove)
		return 0;
	char label[VHAND_STRLEN];
	int ID = 0;
	dataglove->GetID(label, &ID);
	return ID;

}
UNITY_INTERFACE_EXPORT bool VMGUnity_IsConnected(void*instance)
{

	VMGLite*dataglove = (VMGLite*)instance;
	if (!dataglove)
		return false;
	return dataglove->Connected;
}
UNITY_INTERFACE_EXPORT bool VMGUnity_GetFingers(void*instance, double* fingers)
{
	VMGLite*dataglove = (VMGLite*)instance;
	if (!dataglove)
		return false;

	int connstatus = dataglove->GetConnectionStatus();
	if (connstatus == USB_CONNECTED) {
		dataglove->GetFingers(fingers);
	}
	return true;

}