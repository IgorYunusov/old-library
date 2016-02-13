#include <Windows.h>
#include <stdio.h>

#pragma comment(lib, "winmm.lib" )
#include <mmdeviceapi.h>
#include <endpointvolume.h>

bool ChangeVolume(double nVolume,bool bScalar)
{
 
    HRESULT hr=NULL;
    bool decibels = false;
    bool scalar = false;
    double newVolume=nVolume;
 
    CoInitialize(NULL);

		IMMDeviceEnumerator *deviceEnumerator = NULL;
		hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER, 
		                      __uuidof(IMMDeviceEnumerator), (LPVOID *)&deviceEnumerator);
		IMMDevice *defaultDevice = NULL;
 
		hr = deviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &defaultDevice);
		deviceEnumerator->Release();
		deviceEnumerator = NULL;
 
		IAudioEndpointVolume *endpointVolume = NULL;
		hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume), 
		     CLSCTX_INPROC_SERVER, NULL, (LPVOID *)&endpointVolume);
		defaultDevice->Release();
		defaultDevice = NULL;
 
		// -------------------------
		float currentVolume = 0;
		endpointVolume->GetMasterVolumeLevel(&currentVolume);
		//printf("Current volume in dB is: %f\n", currentVolume);

		hr = endpointVolume->GetMasterVolumeLevelScalar(&currentVolume);
		//CString strCur=L"";
		//strCur.Format(L"%f",currentVolume);
		//AfxMessageBox(strCur);

		// printf("Current volume as a scalar is: %f\n", currentVolume);
		if (bScalar==false)
		{
		    hr = endpointVolume->SetMasterVolumeLevel((float)newVolume, NULL);
		}
		else if (bScalar==true)
		{
		    hr = endpointVolume->SetMasterVolumeLevelScalar((float)newVolume, NULL);
		}
		endpointVolume->Release();
 
    CoUninitialize();
 
    return FALSE;
}


int main()
{
	ChangeVolume(0.5, true);
	return 0;
}

