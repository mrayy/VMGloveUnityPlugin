using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class VMGLite : MonoBehaviour {


    VMGLite_API _api;
    public int ComPort = 1;
    public double[] Fingers = new double[5];
    public Transform[] FingersTransform;
	// Use this for initialization
	void Start () {
        _api = new VMGLite_API();
        if (_api.Open(ComPort))
            Debug.Log("Glove Opened: " + _api.GetID());
        else
            Debug.LogWarning("Failed to open glove!" );
    }

    private void OnDestroy()
    {
        _api.Disconnect();
        _api.Destroy();
    }

    // Update is called once per frame
    void Update () {
        _api.GetFingers(Fingers);

        for(int i=0;i<5;++i)
        {
            FingersTransform[i].localRotation = Quaternion.Euler(0,0,-(float)Fingers[i]);
        }
	}
}
