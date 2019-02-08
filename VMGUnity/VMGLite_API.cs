using System.Collections;
using System.Runtime.InteropServices;	// For DllImport.
using System;
using UnityEngine;

public class VMGLite_API  {

    internal const string DllName = "VMGUnity";

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    extern static protected System.IntPtr VMGUnity_CreateGloveInstance();

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    extern static protected void VMGUnity_DestroyGloveInstance(System.IntPtr intance);

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    extern static protected bool VMGUnity_Open(System.IntPtr intance, int port, int fps=0);

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    extern static protected bool VMGUnity_Disconnect(System.IntPtr instance);

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    extern static protected int VMGUnity_GetID(System.IntPtr instance);

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    extern static protected bool VMGUnity_IsConnected(System.IntPtr instance);

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    extern static protected bool VMGUnity_GetFingers(System.IntPtr instance, double[] fingers);

    System.IntPtr _instance= System.IntPtr.Zero;

    public VMGLite_API()
    {
        _instance = VMGUnity_CreateGloveInstance();
    }

    public void Destroy()
    {
        if (_instance != System.IntPtr.Zero)
            VMGUnity_DestroyGloveInstance(_instance);
        _instance = System.IntPtr.Zero;
    }


    public bool Open(int comPort,int FPS=0)
    {
        return VMGUnity_Open(_instance, comPort, FPS);
    }
    public bool Disconnect()
    {
        return VMGUnity_Disconnect(_instance);
    }
    public int GetID()
    {
        return VMGUnity_GetID(_instance);
    }
    public bool IsConnected()
    {
        return VMGUnity_IsConnected(_instance);
    }

    public bool GetFingers(double[] fingers)
    {
        return VMGUnity_GetFingers(_instance, fingers);
    }
}
