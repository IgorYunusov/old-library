#include <windows.h>
#include <mmsystem.h>
#include <tchar.h>
#include <commctrl.h>
#pragma comment(lib, "winmm")
#pragma comment(lib, "comctl32")
#define  MCI_NOT_OPEN        ((UINT)-1)
#define  ID_CHECKBUTTON_MUTE  150
#define  ID_BUTTON_PREV       160
#define  ID_BUTTON_STOP       161
#define  ID_BUTTON_PLAY       162
#define  ID_BUTTON_NEXT       163
#define  ID_LISTBOX_PLAYLIST  170
#define  ID_BUTTON_LIST_ADD   180
#define  ID_BUTTON_LIST_DEL   181
#define  ID_COMBOBOX_REPEAT   200
#define  ID_COMBOBOX_SHUFFLE  201

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
HINSTANCE g_hInst;
HWND      g_hWnd;
LPCTSTR   lpszClass=TEXT("MP3플레이어");
UINT      g_wDeviceID=MCI_NOT_OPEN;
HWND      hTrackPlay=NULL;
HWND      hTrackWaveVol=NULL;
HWND      hComboRepeat=NULL;
HWND      hComboShuffle=NULL;
HWND      hCheckButtonMute=NULL;
HWND      hListPlay=NULL;
int       nPlayStatus=0;
DWORD     dwThreadID=0;
HANDLE    hThread=NULL;
DWORD     dwPlayPos=0;
UINT      nPlayMsg=0;
int       nMainLoop=0;
HANDLE    hMP3DelayEvent=NULL;
typedef struct
{
 char szFilePath[MAX_PATH];
 char szFileName[MAX_PATH];
}PLAYITEMDATA;
typedef struct
{
 HMIXER  hMixer;
 DWORD   dwChannels;
 DWORD   dwMixerCtrlID;
 DWORD   dwMixerMuteCtrlID;
}MIXERDATA;
PLAYITEMDATA nowPlaySongData;
MIXERDATA  stMP3Mixer={NULL, 0, 0, 0};
TCHAR      *strRepeatItems[]={TEXT("반복없음"),TEXT("지금곡반복"),TEXT("전체반복")};
TCHAR      *strShuffleItems[]={TEXT("순서대로"),TEXT("무작위")};
int         nPlayListNum=0;
HFONT       hFontTime, hOldFontTime;
TCHAR       szPlayTime[128]="00:00:00";
int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance
   ,LPSTR lpszCmdParam,int nCmdShow)
{
 MSG       Message;
 WNDCLASS  WndClass;
 g_hInst=hInstance;
 WndClass.cbClsExtra=0;
 WndClass.cbWndExtra=0;
 WndClass.hbrBackground=(HBRUSH)(COLOR_WINDOW+1);
 WndClass.hCursor=LoadCursor(NULL,IDC_ARROW);
 WndClass.hIcon=LoadIcon(NULL,IDI_APPLICATION);
 WndClass.hInstance=hInstance;
 WndClass.lpfnWndProc=WndProc;
 WndClass.lpszClassName=lpszClass;
 WndClass.lpszMenuName=NULL;
 WndClass.style=CS_HREDRAW | CS_VREDRAW;
 RegisterClass(&WndClass);
 g_hWnd=CreateWindow(lpszClass,lpszClass,WS_POPUPWINDOW | WS_CAPTION | WS_MINIMIZEBOX ,
                  CW_USEDEFAULT,CW_USEDEFAULT,326,630,
                  NULL,(HMENU)NULL,hInstance,NULL);
 ShowWindow(g_hWnd, nCmdShow);
 while (GetMessage(&Message,NULL,0,0))
 {
  TranslateMessage(&Message);
  DispatchMessage(&Message);
 }
 return (int)Message.wParam;
}
HMIXER OpenVolumeCtrl(HWND hWnd, MIXERDATA *pstMP3Mixer)
{
 MMRESULT           result;
 HMIXER             hMixer;
 MIXERLINE          ml  = {0};
 MIXERLINECONTROLS  mlc = {0};  
 MIXERCONTROL       mc  = {0};
 
 result = mixerOpen(&hMixer, MIXER_OBJECTF_MIXER, (DWORD)hWnd,
                 0, MIXER_OBJECTF_MIXER | CALLBACK_WINDOW);
 if (MMSYSERR_NOERROR != result)
    {
  MessageBox(hWnd, "mixerOpen Error!", "Mixer Error", MB_OK);
  return FALSE;
 }
 
 ZeroMemory(&ml,sizeof(MIXERLINE));
 ml.cbStruct = sizeof(MIXERLINE);

 // http://msdn.microsoft.com/en-us/library/ms712129(VS.85).aspx
 // 마스터 볼륨
 //ml.dwComponentType = MIXERLINE_COMPONENTTYPE_DST_SPEAKERS;
 // Wave 볼륨
    ml.dwComponentType = MIXERLINE_COMPONENTTYPE_SRC_WAVEOUT;
   
 result = mixerGetLineInfo((HMIXEROBJ) hMixer,
                        &ml, MIXER_OBJECTF_HMIXER | MIXER_GETLINEINFOF_COMPONENTTYPE);
 
 if (MMSYSERR_NOERROR != result)
    {
   MessageBox(hWnd, "mixerGetLineInfo Error!", "Mixer Error", MB_OK);
         return FALSE;
 }
 pstMP3Mixer->dwChannels = MIXERCONTROL_CONTROLF_UNIFORM;
 // 볼륨 컨트롤 ID얻기
 mlc.cbStruct = sizeof(MIXERLINECONTROLS);  
 mlc.dwLineID = ml.dwLineID;  
 mlc.dwControlType = MIXERCONTROL_CONTROLTYPE_VOLUME;  
 mlc.cControls = 1;  
 mlc.pamxctrl = &mc;  
 mlc.cbmxctrl = sizeof(MIXERCONTROL);  
 result = mixerGetLineControls((HMIXEROBJ) hMixer,
&mlc, MIXER_OBJECTF_HMIXER | MIXER_GETLINECONTROLSF_ONEBYTYPE);
 if (MMSYSERR_NOERROR != result)
    {
  MessageBox(hWnd, "mixerGetLineControls Error! - Wave Control", "Mixer Error", MB_OK);
  return FALSE;
 }
 pstMP3Mixer->dwMixerCtrlID=mc.dwControlID;
 pstMP3Mixer->hMixer=hMixer;

 // Mute 컨트롤 ID얻기
 mlc.dwControlType = MIXERCONTROL_CONTROLTYPE_MUTE;  
 result = mixerGetLineControls((HMIXEROBJ) hMixer,
  &mlc, MIXER_OBJECTF_HMIXER | MIXER_GETLINECONTROLSF_ONEBYTYPE);
 
 if (MMSYSERR_NOERROR != result)
    {
  MessageBox(hWnd, "mixerGetLineControls Error! - Mute Control", "Mixer Error", MB_OK);
  return FALSE;
 }
 
 pstMP3Mixer->dwMixerMuteCtrlID=mc.dwControlID;   
 return hMixer;
}

void CloseVolumeCtrl(MIXERDATA *pstMP3Mixer)
{
    if (pstMP3Mixer->hMixer) mixerClose(pstMP3Mixer->hMixer);
}

void SetVolume(MIXERDATA *pstMP3Mixer, DWORD dwVolume)
{
 MMRESULT                      result;
 MIXERCONTROLDETAILS           mcd  = {0};  
 MIXERCONTROLDETAILS_UNSIGNED  mcdu = {0};
 
 if (dwVolume > 65535) dwVolume=65535;
 mcdu.dwValue = dwVolume; // 볼륨 크기는 0에서 65535 사이 값  
 mcd.cbStruct = sizeof(MIXERCONTROLDETAILS);  
 mcd.hwndOwner = 0;
 mcd.dwControlID = pstMP3Mixer->dwMixerCtrlID;  
 mcd.paDetails = &mcdu;
 mcd.cbDetails = sizeof(MIXERCONTROLDETAILS_UNSIGNED);  
 mcd.cChannels = pstMP3Mixer->dwChannels;
 
 result = mixerSetControlDetails((HMIXEROBJ) pstMP3Mixer->hMixer,
&mcd, MIXER_SETCONTROLDETAILSF_VALUE);
 if (MMSYSERR_NOERROR != result)
    {
  MessageBox(g_hWnd, "mixerSetControlDetails Error!", "Mixer Error", MB_OK);
  return ;
 }
}

DWORD GetVolume(MIXERDATA *pstMP3Mixer)
{
 MMRESULT                      result;
 MIXERCONTROLDETAILS           mcd  = {0};  
 MIXERCONTROLDETAILS_UNSIGNED  mcdu = {0};
 
 mcdu.dwValue = 0; // 볼륨 크기는 0에서 65535 사이 값  
 mcd.cbStruct = sizeof(MIXERCONTROLDETAILS);  
 mcd.hwndOwner = 0;
 mcd.dwControlID = pstMP3Mixer->dwMixerCtrlID;  
 mcd.paDetails = &mcdu;
 mcd.cbDetails = sizeof(MIXERCONTROLDETAILS_UNSIGNED);  
 mcd.cChannels = pstMP3Mixer->dwChannels;
 
 result = mixerGetControlDetails((HMIXEROBJ) pstMP3Mixer->hMixer,
                     &mcd, MIXER_GETCONTROLDETAILSF_VALUE);
 if (MMSYSERR_NOERROR != result)
    {
  MessageBox(g_hWnd, "mixerGetControlDetails Error!", "Mixer Error", MB_OK);
  return FALSE;
 }
 return mcdu.dwValue;
}

BOOL GetMute(MIXERDATA *pstMP3Mixer)
{
 MMRESULT                     m_nStatus;
    MIXERCONTROLDETAILS          mcd;
    MIXERCONTROLDETAILS_BOOLEAN  mcd_b = {0};
 
    mcd.cbStruct = sizeof(MIXERCONTROLDETAILS);
    mcd.dwControlID = pstMP3Mixer->dwMixerMuteCtrlID;
    mcd.cChannels = pstMP3Mixer->dwChannels;
    mcd.cMultipleItems = 0;
    mcd.cbDetails = sizeof(MIXERCONTROLDETAILS_BOOLEAN);
    mcd.paDetails = &mcd_b;
    m_nStatus = mixerGetControlDetails((HMIXEROBJ)pstMP3Mixer->hMixer, &mcd, 0L);
    return mcd_b.fValue;
}

BOOL SetMute(MIXERDATA *pstMP3Mixer, BOOL bVal)
{
 MMRESULT                     m_nStatus;
    MIXERCONTROLDETAILS          mcd;
    MIXERCONTROLDETAILS_BOOLEAN  mcd_b;
 
    mcd_b.fValue = bVal;
    mcd.cbStruct = sizeof(MIXERCONTROLDETAILS);
    mcd.dwControlID = pstMP3Mixer->dwMixerMuteCtrlID;
    mcd.cChannels = pstMP3Mixer->dwChannels;
    mcd.cMultipleItems = 0;
    mcd.cbDetails = sizeof(MIXERCONTROLDETAILS_BOOLEAN);
    mcd.paDetails = &mcd_b;
    m_nStatus = mixerSetControlDetails((HMIXEROBJ)pstMP3Mixer->hMixer, &mcd, 0L);
    return (m_nStatus == MMSYSERR_NOERROR);
}
 
//************************************************************************************************
// MCI 처리 함수들
//************************************************************************************************
DWORD OpenMP3(UINT *pwDeviceID, LPSTR lpszMP3filename)
{
 DWORD           Result;
 MCI_OPEN_PARMS  mciOpenParms;
    MCI_SET_PARMS   mciSetParms;
 // 장치를 Open하고 ID를 발급받는다.
 mciOpenParms.lpstrDeviceType = "MPEGVideo";
 mciOpenParms.lpstrElementName = lpszMP3filename;
 Result=mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT,
                   (DWORD)(LPVOID) &mciOpenParms);
 if (Result)
 {
  return Result;
 }
 *pwDeviceID=mciOpenParms.wDeviceID;
 
 mciSetParms.dwTimeFormat = MCI_FORMAT_MILLISECONDS;  // Time을 miliseconds단위로
 mciSendCommand(mciOpenParms.wDeviceID, MCI_SET, MCI_SET_TIME_FORMAT, (DWORD)&mciSetParms);
 return 0;
}

void Close(UINT *pwDeviceID)
{ 
    if((*pwDeviceID)!=MCI_NOT_OPEN)
 {
   MCI_GENERIC_PARMS mciGenericParms;
   mciSendCommand(*pwDeviceID,MCI_STOP,MCI_WAIT,(DWORD)&mciGenericParms);
         mciSendCommand(*pwDeviceID,MCI_CLOSE, 0, (DWORD)NULL);
     *pwDeviceID=MCI_NOT_OPEN;
 }
}

DWORD Play(HWND hWndNotify, UINT wDeviceID)
{
 DWORD           Result;
 MCI_PLAY_PARMS  mciPlayParms;
    mciPlayParms.dwCallback=(DWORD)hWndNotify;
 
 Result = mciSendCommand(wDeviceID, MCI_PLAY, MCI_NOTIFY,
                      (DWORD)(LPVOID)&mciPlayParms);
 if (Result)
 {
  mciSendCommand(wDeviceID, MCI_CLOSE, 0, (DWORD)NULL);
  return Result;
 }
 return 0;
}

void Stop(UINT wDeviceID)
{
 if(wDeviceID!=MCI_NOT_OPEN)
 {
  MCI_GENERIC_PARMS mciGenericParms;
  mciSendCommand(wDeviceID,MCI_STOP,MCI_WAIT,(DWORD)&mciGenericParms);
 }
}

void Pause(UINT wDeviceID)
{
 if(wDeviceID!=MCI_NOT_OPEN)
 {
  MCI_GENERIC_PARMS mciGenericParms;
  mciSendCommand(wDeviceID,MCI_PAUSE,MCI_WAIT,(DWORD)&mciGenericParms);
 }
}

void Resume(UINT wDeviceID)
{
 if(wDeviceID!=MCI_NOT_OPEN)
 {
  MCI_GENERIC_PARMS mciGenericParms;
  mciSendCommand(wDeviceID,MCI_RESUME,MCI_WAIT,(DWORD)&mciGenericParms);
 }
}

DWORD GetLength(UINT wDeviceID)
{
 if(wDeviceID!=MCI_NOT_OPEN)
 {
  MCI_STATUS_PARMS mciStatusParms;
  mciStatusParms.dwItem=MCI_STATUS_LENGTH;
  mciSendCommand(wDeviceID,MCI_STATUS,MCI_STATUS_ITEM,(DWORD)&mciStatusParms);
  return mciStatusParms.dwReturn;
 }
 
 return 0;
}

DWORD GetPos(UINT wDeviceID)
{
 if(wDeviceID!=MCI_NOT_OPEN)
 {
  MCI_STATUS_PARMS mciStatusParms;
  mciStatusParms.dwItem=MCI_STATUS_POSITION;
  mciSendCommand(wDeviceID,MCI_STATUS,MCI_STATUS_ITEM|MCI_WAIT,(DWORD)&mciStatusParms);
  return mciStatusParms.dwReturn;
 }
 return 0;
}

void SetPos(UINT wDeviceID, DWORD dwPos)
{
 if(wDeviceID!=MCI_NOT_OPEN)
 {
  MCI_SEEK_PARMS mciSeekParms;
  mciSeekParms.dwTo=dwPos;
  mciSendCommand(wDeviceID,MCI_SEEK,MCI_TO,(DWORD)&mciSeekParms);
 } 
}

void MoveStartPos(UINT wDeviceID)
{
 if(wDeviceID!=MCI_NOT_OPEN)
 {
  MCI_SEEK_PARMS mciSeekParms;
  mciSendCommand(wDeviceID,MCI_SEEK,MCI_SEEK_TO_START,(DWORD)&mciSeekParms);
 }
}

void MoveEndPos(UINT wDeviceID)
{
 if(wDeviceID!=MCI_NOT_OPEN)
 {
  MCI_SEEK_PARMS mciSeekParms;
  mciSendCommand(wDeviceID,MCI_SEEK,MCI_SEEK_TO_END,(DWORD)&mciSeekParms);
 }
}
 
 
 
//************************************************************************************************
// 트랙바 처리 함수들
//************************************************************************************************
void SetTrackBarRangeMax(HWND hTrackbar, int nMax, BOOL bRedraw)
{
 SendMessage(hTrackbar, TBM_SETRANGEMAX, bRedraw, nMax);
}

void SetTrackBarRangeMin(HWND hTrackbar, int nMin, BOOL bRedraw)
{
 SendMessage(hTrackbar, TBM_SETRANGEMIN, bRedraw, nMin);
}

int GetTrackBarRangeMax(HWND hTrackbar)
{
 return SendMessage(hTrackbar, TBM_GETRANGEMAX, 0, 0);
}

int GetTrackBarRangeMin(HWND hTrackbar)
{
 return SendMessage(hTrackbar, TBM_GETRANGEMIN, 0, 0);
}

void SetTrackBarPos(HWND hTrackbar, int nPos, BOOL bRedraw)
{
 SendMessage(hTrackbar, TBM_SETPOS, bRedraw, nPos);
}

DWORD GetTrackBarPos(HWND hTrackbar)
{
 return SendMessage(hTrackbar, TBM_GETPOS, 0, 0);
}
 
 
//************************************************************************************************
// 스레드 함수
//************************************************************************************************
DWORD WINAPI MP3ThreadFunc(LPVOID temp)
{
 while(nMainLoop)
 {
  if (nPlayStatus)
  {
      SendMessage(g_hWnd, nPlayMsg, nPlayMsg, nPlayMsg);
  }
  WaitForMultipleObjects(1, &hMP3DelayEvent, TRUE, 100);
 }
 return 0;
}
 
 
//************************************************************************************************
// 스레드 및 연주 처리 함수
//************************************************************************************************
void StopFunc()
{
 nPlayStatus=0;
 
 Stop(g_wDeviceID);
 ResetEvent(hMP3DelayEvent);
 SetTrackBarPos(hTrackPlay, 0, TRUE);
}
void WaitThreadClose()
{
 nPlayStatus=0;
 nMainLoop=0;
 Stop(g_wDeviceID);
 if (hThread)
 {  
  PulseEvent(hMP3DelayEvent);
  WaitForSingleObject(hThread, INFINITE);
        CloseHandle(hThread);
  hThread=NULL;
 }
 SetTrackBarPos(hTrackPlay, 0, TRUE);
}
 

//************************************************************************************************
// 플레이 리스트 처리 함수
//************************************************************************************************
DWORD PlayList_AddData(HWND hWnd, HWND hList)
{
 OPENFILENAME   OFN;
 TCHAR          lpstrFile[MAX_PATH]="";
 PLAYITEMDATA  *pData=NULL;
    int            i, nSelIdxPlayList=0;
 memset(&OFN, 0, sizeof(OPENFILENAME));
 OFN.lStructSize = sizeof(OPENFILENAME);
 OFN.hwndOwner=hWnd;
 OFN.lpstrFilter=TEXT("MP3 파일(*.MP3)\0*.MP3\0");
 OFN.lpstrFile=lpstrFile;
 OFN.nMaxFile=MAX_PATH;
 if (GetOpenFileName(&OFN)!=0)
 {  
  pData=(PLAYITEMDATA *)malloc(sizeof(PLAYITEMDATA));
        strcpy(pData->szFilePath, OFN.lpstrFile);
  for(i=strlen(pData->szFilePath)-1; i > 0; i--)
  {
   if (pData->szFilePath[i]=='\\'){ i++; break; }
  }
  
  strcpy(pData->szFileName, &(pData->szFilePath[i]));
  
  nSelIdxPlayList=SendMessage(hList, LB_GETCOUNT,0,0);
  SendMessage(hList,LB_INSERTSTRING,nSelIdxPlayList,(LPARAM)pData->szFileName);
  SendMessage(hList, LB_SETITEMDATA,nSelIdxPlayList,(LPARAM)pData);
  return TRUE;
 }
 return FALSE;
}
DWORD PlayList_DelData(HWND hList)
{
 PLAYITEMDATA  *pData=NULL;
 int           *buffer=NULL;
 int            nSelCountPlayList, nSelIdxPlayList, i;
    
 nSelCountPlayList=SendMessage(hList,LB_GETSELCOUNT,0,0);    
    
 if (nSelCountPlayList!=0)
 {
  buffer=(int *)malloc(sizeof(int)*nSelCountPlayList);
   
  if (buffer)
  {
   SendMessage(hList, LB_GETSELITEMS,nSelCountPlayList,(LPARAM)buffer);
     
   for (i=nSelCountPlayList-1; i >= 0; i--)
   {
    nSelIdxPlayList=buffer[i];
    pData=(PLAYITEMDATA *)SendMessage(hList, LB_GETITEMDATA,nSelIdxPlayList,0);
    if (pData)
    {
     free(pData);
     SendMessage(hList, LB_DELETESTRING,nSelIdxPlayList,0);
    }else{
     MessageBox(g_hWnd,"No Del!","No Del!",MB_OK);
    }
   }
     
   free(buffer);
   return TRUE;
  }
 }
 return FALSE;
}

void PlayList_DelAllData(HWND hList)
{
 int            nSelCountPlayList, i;
 PLAYITEMDATA  *pData=NULL;
 nSelCountPlayList=SendMessage(hList, LB_GETCOUNT,0,0);
 for (i=nSelCountPlayList-1; i >= 0; i--)
 {
  pData=(PLAYITEMDATA *)SendMessage(hList,LB_GETITEMDATA,i,0);
  if (pData)
  {
   free(pData);
   SendMessage(hList,LB_DELETESTRING,i,0);
  }
 }
}
void PlayList_PlayData(HWND hWnd, PLAYITEMDATA *pData)
{
 DWORD          Result;
 TCHAR          str[256];
 if (pData)
 {
  if (g_wDeviceID!=MCI_NOT_OPEN)
  {
   StopFunc();
   Close(&g_wDeviceID);
  }
  Result=OpenMP3(&g_wDeviceID, pData->szFilePath);
  if (Result)
  {
   mciGetErrorString(Result, str, 256);
   MessageBox(hWnd, str,"에러 발생",MB_OK);
  }else{
   SetTrackBarRangeMin(hTrackPlay, 0, TRUE);
   SetTrackBarRangeMax(hTrackPlay, GetLength(g_wDeviceID), TRUE);
   SetTrackBarPos(hTrackPlay, 0, TRUE);
   
   Result=Play(hWnd, g_wDeviceID);
   if (Result)
   {
    mciGetErrorString(Result, str, 256);
    MessageBox(hWnd, str,"에러 발생",MB_OK);
   }else{
    nPlayStatus=1;
    dwPlayPos=0;
    ResetEvent(hMP3DelayEvent);        
   }
  }
 } 
}
void PlayList_PrevPlay(HWND hWnd, HWND hList)
{
 PLAYITEMDATA *pData=NULL;
 int           nSelIdxPlayList, nSelCountPlayList;
 nSelCountPlayList=SendMessage(hList, LB_GETCOUNT,0,0);
 if (nSelCountPlayList <= 0) return ;
 if (nSelCountPlayList <= nPlayListNum) nPlayListNum=nSelCountPlayList-1;

 nSelIdxPlayList=nPlayListNum;
 
 nSelIdxPlayList--;
 if (nSelIdxPlayList < 0) nSelIdxPlayList=nSelCountPlayList-1;
              
 nPlayListNum=nSelIdxPlayList;
 SetFocus(hList);
 
 SendMessage(hList, LB_SELITEMRANGE, 0, 0);
 
 pData=(PLAYITEMDATA *)SendMessage(hList, LB_GETITEMDATA, (WPARAM)nSelIdxPlayList,0);
 
 if (pData)
 {
  CopyMemory(&nowPlaySongData, pData, sizeof(PLAYITEMDATA));
  
  PlayList_PlayData(hWnd, &nowPlaySongData);
 }
}
void PlayList_NextPlay(HWND hWnd, HWND hList, BOOL bRepeat)
{
 PLAYITEMDATA *pData=NULL;
 int           nSelIdxPlayList, nSelCountPlayList;
 nSelCountPlayList=SendMessage(hList, LB_GETCOUNT,0,0);
 if (nSelCountPlayList <= 0) return ;
 if (nSelCountPlayList <= nPlayListNum) nPlayListNum=nSelCountPlayList-1;
 
 nSelIdxPlayList=nPlayListNum;
 
 nSelIdxPlayList++;
 if (nSelIdxPlayList >= nSelCountPlayList)
 {
  if (bRepeat!=TRUE)
  {
   if (g_wDeviceID!=MCI_NOT_OPEN)
   {
    StopFunc();
    Close(&g_wDeviceID);
   }
   return ;
  }
  nSelIdxPlayList=0;
 }
 nPlayListNum=nSelIdxPlayList;
 SetFocus(hList);
 SendMessage(hList, LB_SETCURSEL, (WPARAM)nSelIdxPlayList,0);
 pData=(PLAYITEMDATA *)SendMessage(hList, LB_GETITEMDATA, nSelIdxPlayList,0);
 
 if (pData)
 {
  CopyMemory(&nowPlaySongData, pData, sizeof(PLAYITEMDATA));
  
  PlayList_PlayData(hWnd, &nowPlaySongData);
 }
}
LRESULT CALLBACK WndProc(HWND hWnd,UINT iMessage,WPARAM wParam,LPARAM lParam)
{
 HDC           hdc;
 PAINTSTRUCT   ps;
 DWORD         Result;
 TCHAR         str[256];
 TCHAR        *Mes="(MP3플레이어)";
    DWORD         dwTmpPlayPos=0;
 DWORD         dwHour, dwMinute, dwSecond;
 int           i, nSelIdxRepeat, nSelIdxShuffle, nSelIdxPlayList, nSelCountPlayList;
 RECT          rtClear1={50,40,300,150};
 if (iMessage==nPlayMsg && wParam==(WPARAM)nPlayMsg && lParam==(LPARAM)nPlayMsg)
 {
  if (g_wDeviceID!=MCI_NOT_OPEN)
  {
   dwPlayPos=GetPos(g_wDeviceID);    
   SetTrackBarPos(hTrackPlay, dwPlayPos, TRUE);
   dwPlayPos/=1000;
            dwSecond=dwPlayPos%60;
   dwPlayPos/=60;
            dwMinute=dwPlayPos%60;
   dwPlayPos/=60;
            dwHour=dwPlayPos;
   wsprintf(szPlayTime, "%002d:%002d:%002d", dwHour, dwMinute, dwSecond);
   InvalidateRect(hWnd, &rtClear1, FALSE);
  } 
  return 0;
 }else switch(iMessage)
 {
 case WM_CREATE:
  ZeroMemory(&nowPlaySongData, sizeof(PLAYITEMDATA));
  hMP3DelayEvent=CreateEvent(NULL, FALSE, FALSE, "MP3DelayEvent");
  
  nPlayMsg=RegisterWindowMessage(TEXT("MOJIGURA@NAVER.COM_MCIMP3PLAY001"));
  hFontTime=CreateFont(50,0,0,0,FW_BOLD,0,0,0,HANGEUL_CHARSET,3,2,1,
                    VARIABLE_PITCH | FF_ROMAN,"굴림");
  InitCommonControls();
  
  hTrackPlay=CreateWindow(TRACKBAR_CLASS,NULL,WS_CHILD | WS_VISIBLE ,
   10,100,300,40,hWnd,NULL,g_hInst,NULL);
  
  hTrackWaveVol=CreateWindow(TRACKBAR_CLASS,NULL,WS_CHILD | WS_VISIBLE ,
   210,150,100,40,hWnd,NULL,g_hInst,NULL);
  hComboRepeat=CreateWindow("combobox",NULL,WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST,
   10,150,120,200,hWnd,(HMENU)ID_COMBOBOX_REPEAT,g_hInst,NULL);
  hComboShuffle=CreateWindow("combobox",NULL,WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST,
   10,180,120,200,hWnd,(HMENU)ID_COMBOBOX_SHUFFLE,g_hInst,NULL);
  hCheckButtonMute=CreateWindow(TEXT("button"),TEXT("Mute"),WS_CHILD | WS_VISIBLE |
   BS_AUTOCHECKBOX,135,150,65,25,hWnd,(HMENU)ID_CHECKBUTTON_MUTE,g_hInst,NULL);
  CreateWindow(TEXT("button"),TEXT("|◀"),WS_CHILD | WS_VISIBLE |
            BS_PUSHBUTTON,40,210,60,25,hWnd,(HMENU)ID_BUTTON_PREV,g_hInst,NULL);
  CreateWindow(TEXT("button"),TEXT("■"),WS_CHILD | WS_VISIBLE |
            BS_PUSHBUTTON,100,210,60,25,hWnd,(HMENU)ID_BUTTON_STOP,g_hInst,NULL);
  CreateWindow(TEXT("button"),TEXT("▶||"),WS_CHILD | WS_VISIBLE |
            BS_PUSHBUTTON,160,210,60,25,hWnd,(HMENU)ID_BUTTON_PLAY,g_hInst,NULL);
  CreateWindow(TEXT("button"),TEXT("▶|"),WS_CHILD | WS_VISIBLE |
            BS_PUSHBUTTON,220,210,60,25,hWnd,(HMENU)ID_BUTTON_NEXT,g_hInst,NULL);
  hListPlay=CreateWindow(TEXT("listbox"),NULL,WS_CHILD | WS_VISIBLE | WS_BORDER |
   LBS_NOTIFY | LBS_MULTIPLESEL,10,240,300,300,hWnd,(HMENU)ID_LISTBOX_PLAYLIST,g_hInst,NULL);
  CreateWindow(TEXT("button"),TEXT("ADD"),WS_CHILD | WS_VISIBLE |
            BS_PUSHBUTTON,20,535,60,25,hWnd,(HMENU)ID_BUTTON_LIST_ADD,g_hInst,NULL);
  CreateWindow(TEXT("button"),TEXT("DEL"),WS_CHILD | WS_VISIBLE |
            BS_PUSHBUTTON,80,535,60,25,hWnd,(HMENU)ID_BUTTON_LIST_DEL,g_hInst,NULL);
  for(i=0; i < 3; i++)
  {
   SendMessage(hComboRepeat,CB_ADDSTRING,0,(LPARAM)strRepeatItems[i]);
  }
  for(i=0; i < 1; i++)
  {
   SendMessage(hComboShuffle,CB_ADDSTRING,0,(LPARAM)strShuffleItems[i]);
  }
  SendMessage(hComboRepeat,CB_SETCURSEL,0,0);
  SendMessage(hComboShuffle,CB_SETCURSEL,0,0);
  SetTrackBarRangeMin(hTrackPlay, 0, TRUE);
  SetTrackBarRangeMax(hTrackPlay, 0, TRUE);
  SetTrackBarPos(hTrackPlay, 0, TRUE);
  OpenVolumeCtrl(hWnd, &stMP3Mixer); 
  if (GetMute(&stMP3Mixer)==TRUE) SendMessage(hCheckButtonMute,BM_SETCHECK,BST_CHECKED,0);
                      else  SendMessage(hCheckButtonMute,BM_SETCHECK,BST_UNCHECKED,0);
           
  SetTrackBarRangeMin(hTrackWaveVol, 0, TRUE);
  SetTrackBarRangeMax(hTrackWaveVol, 0xffff, TRUE);
  SetTrackBarPos(hTrackWaveVol, GetVolume(&stMP3Mixer), TRUE);
  nMainLoop=1;
       
  hThread = CreateThread(NULL, 0, MP3ThreadFunc, NULL, 0, &dwThreadID);
  
  return 0;

 case MM_MCINOTIFY:
  switch (wParam)
  {
  case MCI_NOTIFY_SUPERSEDED:
  case MCI_NOTIFY_ABORTED:
  case MCI_NOTIFY_FAILURE:
   break;
  case MCI_NOTIFY_SUCCESSFUL:
   nSelIdxRepeat=SendMessage(hComboRepeat, CB_GETCURSEL, 0, 0);
   nSelIdxShuffle=SendMessage(hComboShuffle, CB_GETCURSEL, 0, 0);
   switch(nSelIdxShuffle)
   {
   case 0: // 순서대로 연주
    switch(nSelIdxRepeat)
    {
    case 0: // 반복 없음
     PlayList_NextPlay(hWnd, hListPlay, FALSE);
     return 0;
    case 1: // 지금곡 반복
     MoveStartPos(g_wDeviceID);
           Play(hWnd, g_wDeviceID);
     return 0;
    case 2: // 전체 반복
     PlayList_NextPlay(hWnd, hListPlay, TRUE);
     return 0;
    }
    break;
   }
   
   StopFunc();
   Close(&g_wDeviceID);
   break;
  }
  return 0;
 
 case MM_MIXM_CONTROL_CHANGE:
  if ((WPARAM)stMP3Mixer.hMixer==wParam)    
  {
   if ((LPARAM)stMP3Mixer.dwMixerCtrlID==lParam)
   {
    SetTrackBarPos(hTrackWaveVol, GetVolume(&stMP3Mixer), TRUE);
    
   }else if ((LPARAM)stMP3Mixer.dwMixerMuteCtrlID==lParam)
   {
    if (GetMute(&stMP3Mixer)==TRUE) SendMessage(hCheckButtonMute,BM_SETCHECK,BST_CHECKED,0);
else SendMessage(hCheckButtonMute,BM_SETCHECK,BST_UNCHECKED,0);
   }
  }
  return 0;
 
 case WM_HSCROLL:
  if ((HWND)lParam == hTrackPlay)
  {
   Stop(g_wDeviceID);
   dwTmpPlayPos=SendMessage(hTrackPlay,TBM_GETPOS,0,0); 
   SetPos(g_wDeviceID, dwTmpPlayPos);
   Play(hWnd, g_wDeviceID);
  }else if ((HWND)lParam == hTrackWaveVol)
  {
            SetVolume(&stMP3Mixer, GetTrackBarPos(hTrackWaveVol));
  }
  return 0;
 
 case WM_COMMAND:
  switch (LOWORD(wParam))
  {
  case ID_COMBOBOX_REPEAT:
   {
    nSelIdxRepeat=SendMessage(hComboRepeat, CB_GETCURSEL, 0, 0);
    
    switch (HIWORD(wParam))
    {
    case CBN_SELCHANGE:   
     return 0;
    }
   }
   return 0;
  case ID_COMBOBOX_SHUFFLE:
   {
    nSelIdxShuffle=SendMessage(hComboShuffle, CB_GETCURSEL, 0, 0);
    
    switch (HIWORD(wParam))
    {
    case CBN_SELCHANGE:   
     return 0;
    }
   }
   return 0;
  case ID_CHECKBUTTON_MUTE:
   {
    if (SendMessage(hCheckButtonMute,BM_GETCHECK,0,0)==BST_UNCHECKED)
    {
     if (GetMute(&stMP3Mixer)==TRUE)  SetMute(&stMP3Mixer, FALSE);
    }else{
     if (GetMute(&stMP3Mixer)==FALSE) SetMute(&stMP3Mixer, TRUE);
    }
   }
   return 0;
  case ID_BUTTON_PREV:
   MessageBox(hWnd," 이전곡 Button Clicked","Button",MB_OK);
   return 0;
  case ID_BUTTON_STOP:
  {
    StopFunc();
                Close(&g_wDeviceID);
   }
   return 0;
  case ID_BUTTON_NEXT:
   MessageBox(hWnd," 다음곡 Button Clicked","Button",MB_OK);
   return 0;
  case ID_BUTTON_PLAY:
   {
    if (nPlayStatus==0)
    {   
     PLAYITEMDATA *pData=NULL;
     nSelCountPlayList=SendMessage(hListPlay, LB_GETCOUNT,0,0);
     if (nSelCountPlayList <= 0) return 0;
      
     nSelIdxPlayList=SendMessage(hListPlay, LB_GETCURSEL,0,0);
     SetFocus(hListPlay);
      
     SendMessage(hListPlay, LB_SETCURSEL,nSelIdxPlayList,0);
      
     nPlayListNum=nSelIdxPlayList;
     pData=(PLAYITEMDATA *)SendMessage(hListPlay, LB_GETITEMDATA, nSelIdxPlayList,0);
     
     if (pData)
     {
      CopyMemory(&nowPlaySongData, pData, sizeof(PLAYITEMDATA));
      
      PlayList_PlayData(hWnd, &nowPlaySongData);
     }
    }else if (nPlayStatus==1)
    {
     nPlayStatus=2;
                    Pause(g_wDeviceID);
    }else if (nPlayStatus==2)
    {
     nPlayStatus=1;
                    Resume(g_wDeviceID);
    }
   }
   return 0;
  case ID_BUTTON_LIST_ADD:
   {
    PlayList_AddData(hWnd, hListPlay);
   }
   return 0;
  case ID_BUTTON_LIST_DEL:
   {
    PlayList_DelData(hListPlay);
   }
   return 0;
  case ID_LISTBOX_PLAYLIST:
   switch (HIWORD(wParam))
   {
   case LBN_DBLCLK:
    {
     PLAYITEMDATA  *pData=NULL;
     nSelIdxPlayList=SendMessage(hListPlay, LB_GETCURSEL,0,0);
     pData=(PLAYITEMDATA *)SendMessage(hListPlay, LB_GETITEMDATA,nSelIdxPlayList,0);
     if (pData)
     {
      nPlayListNum=nSelIdxPlayList;
      CopyMemory(&nowPlaySongData, pData, sizeof(PLAYITEMDATA));
      if (g_wDeviceID!=MCI_NOT_OPEN)
      {
       StopFunc();
Close(&g_wDeviceID);
      }
      Result=OpenMP3(&g_wDeviceID, nowPlaySongData.szFilePath);
      if (Result)
      {
       mciGetErrorString(Result, str, 256);
       MessageBox(hWnd, str,"에러 발생",MB_OK);
      }else{
       SetTrackBarRangeMin(hTrackPlay, 0, TRUE);
       SetTrackBarRangeMax(hTrackPlay, GetLength(g_wDeviceID), TRUE);
       SetTrackBarPos(hTrackPlay, 0, TRUE);
       
       Result=Play(hWnd, g_wDeviceID);
       if (Result)
       {
        mciGetErrorString(Result, str, 256);
        MessageBox(hWnd, str,"에러 발생",MB_OK);
       }else{
        nPlayStatus=1;
        dwPlayPos=0;
        ResetEvent(hMP3DelayEvent);        
       }
      } 
     }
    }
    break;
   }
  }
  return 0;
 
 case WM_PAINT:
  hdc=BeginPaint(hWnd,&ps);
  TextOut(hdc,10,10,Mes,lstrlen(Mes));
  TextOut(hdc,200,10,Mes,lstrlen(Mes));
  hOldFontTime=(HFONT)SelectObject(hdc,hFontTime);
  TextOut(hdc,50,40,szPlayTime,lstrlen(szPlayTime));
  SelectObject(hdc,hOldFontTime);
  SetBkMode(hdc,TRANSPARENT);  
  EndPaint(hWnd,&ps);
  return 0;

 case WM_DESTROY:
  {    
   WaitThreadClose();
   Close(&g_wDeviceID);
   CloseHandle(hMP3DelayEvent);
   CloseVolumeCtrl(&stMP3Mixer);
   PlayList_DelAllData(hListPlay);
   if (hFontTime) DeleteObject(hFontTime);
   PostQuitMessage(0);
  }
  return 0;
 }
 return (DefWindowProc(hWnd,iMessage,wParam,lParam));
}
 