
#if defined(__CYGWIN32__)
#define UNITY_INTERFACE_API __stdcall
#define UNITY_INTERFACE_EXPORT __declspec(dllexport)
#elif defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(_WIN64) || defined(WINAPI_FAMILY)
#define UNITY_INTERFACE_API __stdcall
#define UNITY_INTERFACE_EXPORT __declspec(dllexport)
#elif defined(__MACH__) || defined(__ANDROID__) || defined(__linux__) || defined(__QNX__)
#define UNITY_INTERFACE_API
#define UNITY_INTERFACE_EXPORT
#else
#define UNITY_INTERFACE_API
#define UNITY_INTERFACE_EXPORT
#endif


extern "C"  {
    

	UNITY_INTERFACE_EXPORT void* VMGUnity_CreateGloveInstance();
	UNITY_INTERFACE_EXPORT void VMGUnity_DestroyGloveInstance(void*instance);
	UNITY_INTERFACE_EXPORT bool VMGUnity_Open(void*instance, int port, int fps = 0);
	UNITY_INTERFACE_EXPORT bool VMGUnity_Disconnect(void*instance);
	UNITY_INTERFACE_EXPORT int VMGUnity_GetID(void*instance);
	UNITY_INTERFACE_EXPORT bool VMGUnity_IsConnected(void*instance);
	UNITY_INTERFACE_EXPORT bool VMGUnity_GetFingers(void*instance,double* fingers);

}
