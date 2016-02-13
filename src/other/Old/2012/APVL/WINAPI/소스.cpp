#define USING_AT_TR
//==========================================
// 현재 이 부분을 삭제하기 위한 알고리즘을 개발중
//==========================================
#define ONPAINT
#define ONDESTROY
#define ONCOMMAND
//==========================================
#include "at_tr.h"

HINSTANCE g_hInst;
LPCTSTR IpszClass = TEXT("CET Project");
_AAI __event_master_main ct;	// 이벤트 메인

int WIN_MAIN(STD_PARAM)
{
	AUTO_REGISTER(
		CS_HREDRAW | CS_VREDRAW,
		COLOR_BTNFACE+1
		)
	
	hWnd = CreateWindowEx(0,IpszClass,IpszClass,WS_OVERLAPPEDWINDOW, 
			CW_USEDEFAULT,CW_USEDEFAULT,800,800,
			NULL,(HMENU)NULL,hInstance,NULL);
	ShowWindow(hWnd,nCmdShow);
	
	MESSAGE_LOOP()
}

AAI_BEGIN
	ONCALL __t_proc_tc::OnCommand(WPARAM wParam)
	{
	}
	ONCALL __t_proc_tc::OnPaint()
	{
		++ct.emd;
			ct.emd.DrawRect(&MakeRect(10,10,100,100));
			ct.emd.SetText(10, 10, TEXT("asdf"));
		--ct.emd;
	}
	ONCALL __t_proc_tc::OnDestroy()
	{
		ct.MsgBox("asdfasdf", "asfasd");
		ct.DestroyAll();
	}
AAI_END