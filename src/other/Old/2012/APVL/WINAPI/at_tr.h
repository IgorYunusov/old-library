/****************************************************************
 *																*
 *																*
 *			ROLLRAT AUTO PERSONA VERBOTER LIBROFEX				*
 *																*
 *																*
 *		COPYRIGHT (c) rollrat. 2013. ALL RIGHTS RESERVED.		*
 *																*
 *																*
 ****************************************************************/

#ifndef __memory_apvl
#define __memory_apvl

#include <Windows.h>

#define WIN_MAIN(ts_)			APIENTRY WinMain(ts_)
#define STD_PARAM				HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR IpszCmdParam, int nCmdShow
#define PROC_NONE				HWND, UINT, UINT_PTR, DWORD

#define AUTO_REGISTER(style, brush)			HWND hWnd;\
    MSG Message;\
    WNDCLASSEX WndClass = {sizeof(WNDCLASSEX), style, _AT_TR::__t_proc_tc::msProc, 0, 0, hInstance, \
                LoadIcon(NULL,IDC_ARROW),  LoadCursor(NULL,IDC_ARROW),\
                (HBRUSH)(brush),\
                NULL, IpszClass};\
    g_hInst = hInstance;\
 \
    RegisterClassEx(&WndClass);

#define MESSAGE_LOOP() while(GetMessage(&Message,NULL,0,0))\
    {\
        TranslateMessage(&Message);\
        DispatchMessage(&Message);\
    } return (int)Message.wParam;

#ifdef USING_AT_TR

namespace _AT_TR {
	
#define _AAI	_AT_TR::
#define AAI_BEGIN	namespace _AT_TR {
#define AAI_END		}
#define ONCALL	void inline CALLBACK
#define CALL	ONCALL _AAI

WPARAM wParam;
LPARAM lParam;
HWND hWnd;

class __t_proc_tc 
	{
public:
	static LRESULT CALLBACK msProc(HWND hWndo,UINT iMessage,WPARAM wParam1,LPARAM lParam1)
		{
		wParam = wParam1;
		lParam = lParam1;
		hWnd = hWndo;
		switch(iMessage) {
			case WM_NULL: OnNull(); break;
			case WM_CREATE: OnCreate(); break;
			case WM_DESTROY: OnDestroy(); break;
			case WM_MOVE: OnMove(); break;
			case WM_SIZE: OnSize(); break;
			case WM_ACTIVATE: OnActivate(); break;
			case WM_SETFOCUS: OnSetFocus(); break;
			case WM_KILLFOCUS: OnKillFocus(); break;
			case WM_ENABLE: OnEnable(); break;
			case WM_SETREDRAW: OnSetReDraw(); break;
			case WM_SETTEXT: OnSetText(); break;
			case WM_GETTEXT: OnGetText(); break;
			case WM_GETTEXTLENGTH: OnGetTextLength(); break;
			case WM_PAINT: OnPaint(); break;
			case WM_CLOSE: OnClose(); break;
			case WM_QUERYENDSESSION: OnQueryEndSession(); break;
			case WM_QUERYOPEN: OnQueryOpen(); break;
			case WM_ENDSESSION: OnEndSession(); break;
			case WM_QUIT: OnQuit(); break;
			case WM_ERASEBKGND: OnEraseBkGnd(); break;
			case WM_SYSCOLORCHANGE: OnSysColorChange(); break;
			case WM_SHOWWINDOW: OnShowWindow(); break;
#ifndef _WININICHANGE_USELESS
			case WM_WININICHANGE: OnWinIniChange(); break;
#else
			case WM_SETTINGCHANGE: OnSettingChange(); break;
#endif
			case WM_DEVMODECHANGE: OnDevModeChange(); break;
			case WM_ACTIVATEAPP: OnActivateApp(); break;
			case WM_FONTCHANGE: OnFontChange(); break;
			case WM_TIMECHANGE: OnTimeChange(); break;
			case WM_CANCELMODE: OnCancelMode(); break;
			case WM_SETCURSOR: OnSetCursor(); break;
			case WM_MOUSEACTIVATE: OnMouseActivate(); break;
			case WM_CHILDACTIVATE: OnChildActivate(); break;
			case WM_QUEUESYNC: OnQueueSync(); break;
			case WM_GETMINMAXINFO: OnGetMinMaxInfo(); break;
			case WM_PAINTICON: OnPaintIcon(); break;
			case WM_ICONERASEBKGND: OnIconEraseBkGnd(); break;
			case WM_NEXTDLGCTL: OnNextDlgCtl(); break;
			case WM_SPOOLERSTATUS: OnSpoolerStatus(); break;
			case WM_DRAWITEM: OnDrawItem(); break;
			case WM_MEASUREITEM: OnMeasureItem(); break;
			case WM_DELETEITEM: OnDeleteItem(); break;
			case WM_VKEYTOITEM: OnVKeyToItem(); break;
			case WM_CHARTOITEM: OnCharToItem(); break;
			case WM_SETFONT: OnSetFont(); break;
			case WM_GETFONT: OnGetFont(); break;
			case WM_SETHOTKEY: OnSetHotKey(); break;
			case WM_GETHOTKEY: OnGetHotKey(); break;
			case WM_QUERYDRAGICON: OnQueryDragIcon(); break;
			case WM_COMPAREITEM: OnCompareItem(); break;
			case WM_GETOBJECT: OnGetObject(); break;
			case WM_COMPACTING: OnCompacting(); break;
			case WM_COMMNOTIFY: OnCommNotify(); break;
			case WM_WINDOWPOSCHANGING: OnWindowPosChanging(); break;
			case WM_WINDOWPOSCHANGED: OnWindowPosChanged(); break;
			case WM_POWER: OnPower(); break;
			case WM_COPYDATA: OnCopyData(); break;
			case WM_CANCELJOURNAL: OnCancelJournal(); break;
			case WM_NOTIFY: OnNotify(); break;
			case WM_INPUTLANGCHANGEREQUEST: OnInputLangChangeRequest(); break;
			case WM_INPUTLANGCHANGE: OnInputLangChange(); break;
			case WM_TCARD: OnTCard(); break;
			case WM_HELP: OnHelp(); break;
			case WM_USERCHANGED: OnUserChanged(); break;
			case WM_NOTIFYFORMAT: OnNotifyFormat(); break;
			case WM_CONTEXTMENU: OnContextMenu(); break;
			case WM_STYLECHANGING: OnStyleChanging(); break;
			case WM_STYLECHANGED: OnStyleChanged(); break;
			case WM_DISPLAYCHANGE: OnDisplayChange(); break;
			case WM_GETICON: OnGetIcon(); break;
			case WM_SETICON: OnSetIcon(); break;
			case WM_NCCREATE: OnNccReate(); break;
			case WM_NCDESTROY: OnNcDestroy(); break;
			case WM_NCCALCSIZE: OnNcCalcSize(); break;
			case WM_NCHITTEST: OnNcHitTest(); break;
			case WM_NCACTIVATE: OnNcActivate(); break;
			case WM_GETDLGCODE: OnGetDlgCode(); break;
			case WM_SYNCPAINT: OnSyncPaint(); break;
			case WM_NCMOUSEMOVE: OnNcMouseMove(); break;
			case WM_NCLBUTTONDOWN: OnNcLButtonDown(); break;
			case WM_NCLBUTTONUP: OnNcLButtonUp(); break;
			case WM_NCLBUTTONDBLCLK: OnNcLButtonDblClk(); break;
			case WM_NCRBUTTONDOWN: OnNcRButtonDown(); break;
			case WM_NCRBUTTONUP: OnNcRButtonUp(); break;
			case WM_NCRBUTTONDBLCLK: OnNcRButtonDblClk(); break;
			case WM_NCMBUTTONDOWN: OnNcMButtonDown(); break;
			case WM_NCMBUTTONUP: OnNcMButtonUp(); break;
			case WM_NCMBUTTONDBLCLK: OnNcMButtonDblClk(); break;
			case WM_NCXBUTTONDOWN: OnNcxButtonDown(); break;
			case WM_NCXBUTTONUP: OnNcxButtonUp(); break;
			case WM_NCXBUTTONDBLCLK: OnNcxButtonDblClk(); break;
			case WM_INPUT_DEVICE_CHANGE: OnInputDeviceChange(); break;
			case WM_INPUT: OnInput(); break;
#ifndef _KEYDOWN_USELESS
			case WM_KEYDOWN: OnKeyDown(wParam); break;
#else
			case WM_KEYFIRST: OnKeyFirst(wParam); break;
#endif
			case WM_KEYUP: OnKeyUp(wParam); break;
			case WM_CHAR: OnChar((TCHAR)wParam); break;
			case WM_DEADCHAR: OnDeadChar(); break;
			case WM_SYSKEYDOWN: OnSysKeyDown(); break;
			case WM_SYSKEYUP: OnSysKeyUp(); break;
			case WM_SYSCHAR: OnSysChar(); break;
			case WM_SYSDEADCHAR: OnSysDeadChar(); break;
#ifndef _UNICHAR_USELESS
			case WM_UNICHAR: OnUniChar(); break;
#else
			case WM_KEYLAST: OnKeyLast(); break;
#endif
			case WM_IME_STARTCOMPOSITION: OnImeStartComposition(); break;
			case WM_IME_ENDCOMPOSITION: OnImeEndComposition(); break;
#ifndef _IME_COMPOSITION_USELESS
			case WM_IME_COMPOSITION: OnImeComposition(); break;
#else
			case WM_IME_KEYLAST: OnImeKeyLast(); break;
#endif
			case WM_INITDIALOG: OnInitDialog(); break;
			case WM_COMMAND: OnCommand(wParam); break;
			case WM_SYSCOMMAND: OnSysCommand(); break;
			case WM_TIMER: OnTimer(); break;
			case WM_HSCROLL: OnHScroll(); break;
			case WM_VSCROLL: OnVScroll(); break;
			case WM_INITMENU: OnInitMenu(); break;
			case WM_INITMENUPOPUP: OnInitMenuPopUp(); break;
			case WM_GESTURE: OnGesture(); break;
			case WM_GESTURENOTIFY: OnGestureNotify(); break;
			case WM_MENUSELECT: OnMenuSelect(); break;
			case WM_MENUCHAR: OnMenuChar(); break;
			case WM_ENTERIDLE: OnEnterIdle(); break;
			case WM_MENURBUTTONUP: OnMenuRButtonUp(); break;
			case WM_MENUDRAG: OnMenuDrag(); break;
			case WM_MENUGETOBJECT: OnMenuGetObject(); break;
			case WM_UNINITMENUPOPUP: OnUnInitMenuPopUp(); break;
			case WM_MENUCOMMAND: OnMenuCommand(); break;
			case WM_CHANGEUISTATE: OnChangeUIState(); break;
			case WM_UPDATEUISTATE: OnUpdateUIState(); break;
			case WM_QUERYUISTATE: OnQueryUIState(); break;
			case WM_CTLCOLORMSGBOX: OnCtlColorMsgbox(); break;
			case WM_CTLCOLOREDIT: OnCtlColorEdit(); break;
			case WM_CTLCOLORLISTBOX: OnCtlColorListbox(); break;
			case WM_CTLCOLORBTN: OnCtlColorBtn(); break;
			case WM_CTLCOLORDLG: OnCtlColorDlg(); break;
			case WM_CTLCOLORSCROLLBAR: OnCtlColorScrollbar(); break;
			case WM_CTLCOLORSTATIC: OnCtlColorStatic(); break;
#ifndef _MOUSEMOVE_USELESS
			case WM_MOUSEMOVE: OnMouseMove(LOWORD(lParam), HIWORD(lParam)); break;
#else
			case WM_MOUSEFIRST: OnMouseFirst(LOWORD(lParam), HIWORD(lParam)); break;
#endif
			case WM_LBUTTONDOWN: OnLButtonDown(LOWORD(lParam), HIWORD(lParam)); break;
			case WM_LBUTTONUP: OnLButtonUp(LOWORD(lParam), HIWORD(lParam)); break;
			case WM_LBUTTONDBLCLK: OnLButtonDBlClk(LOWORD(lParam), HIWORD(lParam)); break;
			case WM_RBUTTONDOWN: OnRButtonDown(LOWORD(lParam), HIWORD(lParam)); break;
			case WM_RBUTTONUP: OnRButtonUp(LOWORD(lParam), HIWORD(lParam)); break;
			case WM_RBUTTONDBLCLK: OnRButtonDBlClk(LOWORD(lParam), HIWORD(lParam)); break;
			case WM_MBUTTONDOWN: OnMButtonDown(LOWORD(lParam), HIWORD(lParam)); break;
			case WM_MBUTTONUP: OnMButtonUp(LOWORD(lParam), HIWORD(lParam)); break;
			case WM_MBUTTONDBLCLK: OnMButtonDBlClk(LOWORD(lParam), HIWORD(lParam)); break;
			case WM_MOUSEWHEEL: OnMouseWheel(LOWORD(lParam), HIWORD(lParam)); break;
			case WM_XBUTTONDOWN: OnXButtonDown(); break;
			case WM_XBUTTONUP: OnXButtonUp(); break;
			case WM_XBUTTONDBLCLK: OnXButtonDblClk(); break;
#ifndef _MOUSEHWHEEL_USELESS
			case WM_MOUSEHWHEEL: OnMouseHWheel(); break;
#else
			case WM_MOUSELAST: OnMouseLast(); break;
#endif
			case WM_PARENTNOTIFY: OnParentNotify(); break;
			case WM_ENTERMENULOOP: OnEnterMenuLoop(); break;
			case WM_EXITMENULOOP: OnExitMenuLoop(); break;
			case WM_NEXTMENU: OnNextMenu(); break;
			case WM_SIZING: OnSizing(); break;
			case WM_CAPTURECHANGED: OnCaptureChanged(); break;
			case WM_MOVING: OnMoving(); break;
			case WM_POWERBROADCAST: OnPowerBroadcast(); break;
			case WM_DEVICECHANGE: OnDeviceChange(); break;
			case WM_MDICREATE: OnMdiCreate(); break;
			case WM_MDIDESTROY: OnMdiDestroy(); break;
			case WM_MDIACTIVATE: OnMdiActivate(); break;
			case WM_MDIRESTORE: OnMdiRestore(); break;
			case WM_MDINEXT: OnMdiNext(); break;
			case WM_MDIMAXIMIZE: OnMdiMaximize(); break;
			case WM_MDITILE: OnMdiTile(); break;
			case WM_MDICASCADE: OnMdiCascade(); break;
			case WM_MDIICONARRANGE: OnMdiIconArrange(); break;
			case WM_MDIGETACTIVE: OnMdiGetActive(); break;
			case WM_MDISETMENU: OnMdiSetMenu(); break;
			case WM_ENTERSIZEMOVE: OnEnterSizeMove(); break;
			case WM_EXITSIZEMOVE: OnExitSizeMove(); break;
			case WM_DROPFILES: OnDropFiles(); break;
			case WM_MDIREFRESHMENU: OnMdiRefreshMenu(); break;
			case WM_POINTERDEVICECHANGE: OnPointerDeviceChange(); break;
			case WM_POINTERDEVICEINRANGE: OnPointerDeviceInRange(); break;
			case WM_POINTERDEVICEOUTOFRANGE: OnPointerDeviceOutOfRange(); break;
			case WM_TOUCH: OnTouch(); break;
			case WM_NCPOINTERUPDATE: OnNcPointerUpdate(); break;
			case WM_NCPOINTERDOWN: OnNcPointerDown(); break;
			case WM_NCPOINTERUP: OnNcPointerUp(); break;
			case WM_POINTERUPDATE: OnPointerUpdate(); break;
			case WM_POINTERDOWN: OnPointerDown(); break;
			case WM_POINTERUP: OnPointerUp(); break;
			case WM_POINTERENTER: OnPointerEnter(); break;
			case WM_POINTERLEAVE: OnPointerLeave(); break;
			case WM_POINTERACTIVATE: OnPointerActivate(); break;
			case WM_POINTERCAPTURECHANGED: OnPointerCaptureChanged(); break;
			case WM_TOUCHHITTESTING: OnTouchHitTesting(); break;
			case WM_POINTERWHEEL: OnPointerWheel(); break;
			case WM_POINTERHWHEEL: OnPointerHWheel(); break;
			case WM_IME_SETCONTEXT: OnImeSetContext(); break;
			case WM_IME_NOTIFY: OnImeNotify(); break;
			case WM_IME_CONTROL: OnImeControl(); break;
			case WM_IME_COMPOSITIONFULL: OnImeCompositionFull(); break;
			case WM_IME_SELECT: OnImeSelect(); break;
			case WM_IME_CHAR: OnImeChar(); break;
			case WM_IME_REQUEST: OnImeRequest(); break;
			case WM_IME_KEYDOWN: OnImeKeyDown(); break;
			case WM_IME_KEYUP: OnImeKeyUp(); break;
			case WM_MOUSEHOVER: OnMouseHover(); break;
			case WM_MOUSELEAVE: OnMouseLeave(); break;
			case WM_NCMOUSEHOVER: OnNcMouseHover(); break;
			case WM_NCMOUSELEAVE: OnNcMouseLeave(); break;
			case WM_WTSSESSION_CHANGE: OnWtsSessionChange(); break;
			case WM_TABLET_FIRST: OnTabletFirst(); break;
			case WM_TABLET_LAST: OnTabletLast(); break;
			case WM_CUT: OnCut(); break;
			case WM_COPY: OnCopy(); break;
			case WM_PASTE: OnPaste(); break;
			case WM_CLEAR: OnClear(); break;
			case WM_UNDO: OnUndo(); break;
			case WM_RENDERFORMAT: OnRenderFormat(); break;
			case WM_RENDERALLFORMATS: OnRenderAllFormats(); break;
			case WM_DESTROYCLIPBOARD: OnDestroyClipboard(); break;
			case WM_DRAWCLIPBOARD: OnDrawClipboard(); break;
			case WM_PAINTCLIPBOARD: OnPaintClipboard(); break;
			case WM_VSCROLLCLIPBOARD: OnVScrollClipboard(); break;
			case WM_SIZECLIPBOARD: OnSizeClipboard(); break;
			case WM_ASKCBFORMATNAME: OnAskCbFormatName(); break;
			case WM_CHANGECBCHAIN: OnChangeCbChain(); break;
			case WM_HSCROLLCLIPBOARD: OnHScrollClipboard(); break;
			case WM_QUERYNEWPALETTE: OnQueryNewPalette(); break;
			case WM_PALETTEISCHANGING: OnPaletteIsChanging(); break;
			case WM_PALETTECHANGED: OnPaletteChanged(); break;
			case WM_HOTKEY: OnHotKey(); break;
			case WM_PRINT: OnPrint(); break;
			case WM_PRINTCLIENT: OnPrintClient(); break;
			case WM_APPCOMMAND: OnAppCommand(); break;
			case WM_THEMECHANGED: OnThemeChanged(); break;
			case WM_CLIPBOARDUPDATE: OnClipboardUpdate(); break;
			case WM_DWMCOMPOSITIONCHANGED: OnDwmCompositionChanged(); break;
			case WM_DWMNCRENDERINGCHANGED: OnDwmNcRenderingChanged(); break;
			case WM_DWMCOLORIZATIONCOLORCHANGED: OnDwmColorizationColorChanged(); break;
			case WM_DWMWINDOWMAXIMIZEDCHANGE: OnDwmWindowMaximizedChange(); break;
			case WM_DWMSENDICONICTHUMBNAIL: OnDwmSendIconIcThumbnail(); break;
			case WM_DWMSENDICONICLIVEPREVIEWBITMAP: OnDwmSendIconIcLivePreviewBitmap(); break;
			case WM_GETTITLEBARINFOEX: OnGetTitlebarInfoEx(); break;
			case WM_HANDHELDFIRST: OnHandHeldFirst(); break;
			case WM_HANDHELDLAST: OnHandHeldLast(); break;
			case WM_AFXFIRST: OnAfxFirst(); break;
			case WM_AFXLAST: OnAfxLast(); break;
			case WM_PENWINFIRST: OnPenWinFirst(); break;
			case WM_PENWINLAST: OnPenWinLast(); break;
			case WM_APP: OnApp(); break;
			}
		return(DefWindowProc(hWndo,iMessage,wParam1,lParam1));
		}
	static ONCALL OnNull();
	static ONCALL OnCreate();
	static ONCALL OnDestroy();
	static ONCALL OnMove();
	static ONCALL OnSize();
	static ONCALL OnActivate();
	static ONCALL OnSetFocus();
	static ONCALL OnKillFocus();
	static ONCALL OnEnable();
	static ONCALL OnSetReDraw();
	static ONCALL OnSetText();
	static ONCALL OnGetText();
	static ONCALL OnGetTextLength();
	static ONCALL OnPaint();
	static ONCALL OnClose();
	static ONCALL OnQueryEndSession();
	static ONCALL OnQueryOpen();
	static ONCALL OnEndSession();
	static ONCALL OnQuit();
	static ONCALL OnEraseBkGnd();
	static ONCALL OnSysColorChange();
	static ONCALL OnShowWindow();
	static ONCALL OnWinIniChange();
	static ONCALL OnSettingChange();
	static ONCALL OnDevModeChange();
	static ONCALL OnActivateApp();
	static ONCALL OnFontChange();
	static ONCALL OnTimeChange();
	static ONCALL OnCancelMode();
	static ONCALL OnSetCursor();
	static ONCALL OnMouseActivate();
	static ONCALL OnChildActivate();
	static ONCALL OnQueueSync();
	static ONCALL OnGetMinMaxInfo();
	static ONCALL OnPaintIcon();
	static ONCALL OnIconEraseBkGnd();
	static ONCALL OnNextDlgCtl();
	static ONCALL OnSpoolerStatus();
	static ONCALL OnDrawItem();
	static ONCALL OnMeasureItem();
	static ONCALL OnDeleteItem();
	static ONCALL OnVKeyToItem();
	static ONCALL OnCharToItem();
	static ONCALL OnSetFont();
	static ONCALL OnGetFont();
	static ONCALL OnSetHotKey();
	static ONCALL OnGetHotKey();
	static ONCALL OnQueryDragIcon();
	static ONCALL OnCompareItem();
	static ONCALL OnGetObject();
	static ONCALL OnCompacting();
	static ONCALL OnCommNotify();
	static ONCALL OnWindowPosChanging();
	static ONCALL OnWindowPosChanged();
	static ONCALL OnPower();
	static ONCALL OnCopyData();
	static ONCALL OnCancelJournal();
	static ONCALL OnNotify();
	static ONCALL OnInputLangChangeRequest();
	static ONCALL OnInputLangChange();
	static ONCALL OnTCard();
	static ONCALL OnHelp();
	static ONCALL OnUserChanged();
	static ONCALL OnNotifyFormat();
	static ONCALL OnContextMenu();
	static ONCALL OnStyleChanging();
	static ONCALL OnStyleChanged();
	static ONCALL OnDisplayChange();
	static ONCALL OnGetIcon();
	static ONCALL OnSetIcon();
	static ONCALL OnNccReate();
	static ONCALL OnNcDestroy();
	static ONCALL OnNcCalcSize();
	static ONCALL OnNcHitTest();
	static ONCALL OnNcActivate();
	static ONCALL OnGetDlgCode();
	static ONCALL OnSyncPaint();
	static ONCALL OnNcMouseMove();
	static ONCALL OnNcLButtonDown();
	static ONCALL OnNcLButtonUp();
	static ONCALL OnNcLButtonDblClk();
	static ONCALL OnNcRButtonDown();
	static ONCALL OnNcRButtonUp();
	static ONCALL OnNcRButtonDblClk();
	static ONCALL OnNcMButtonDown();
	static ONCALL OnNcMButtonUp();
	static ONCALL OnNcMButtonDblClk();
	static ONCALL OnNcxButtonDown();
	static ONCALL OnNcxButtonUp();
	static ONCALL OnNcxButtonDblClk();
	static ONCALL OnInputDeviceChange();
	static ONCALL OnInput();
	static ONCALL OnKeyFirst(WPARAM);
	static ONCALL OnKeyDown(WPARAM);
	static ONCALL OnKeyUp(WPARAM);
	static ONCALL OnChar(TCHAR);
	static ONCALL OnDeadChar();
	static ONCALL OnSysKeyDown();
	static ONCALL OnSysKeyUp();
	static ONCALL OnSysChar();
	static ONCALL OnSysDeadChar();
	static ONCALL OnUniChar();
	static ONCALL OnKeyLast();
	static ONCALL OnImeStartComposition();
	static ONCALL OnImeEndComposition();
	static ONCALL OnImeComposition();
	static ONCALL OnImeKeyLast();
	static ONCALL OnInitDialog();
	static ONCALL OnCommand(WPARAM);
	static ONCALL OnSysCommand();
	static ONCALL OnTimer();
	static ONCALL OnHScroll();
	static ONCALL OnVScroll();
	static ONCALL OnInitMenu();
	static ONCALL OnInitMenuPopUp();
	static ONCALL OnGesture();
	static ONCALL OnGestureNotify();
	static ONCALL OnMenuSelect();
	static ONCALL OnMenuChar();
	static ONCALL OnEnterIdle();
	static ONCALL OnMenuRButtonUp();
	static ONCALL OnMenuDrag();
	static ONCALL OnMenuGetObject();
	static ONCALL OnUnInitMenuPopUp();
	static ONCALL OnMenuCommand();
	static ONCALL OnChangeUIState();
	static ONCALL OnUpdateUIState();
	static ONCALL OnQueryUIState();
	static ONCALL OnCtlColorMsgbox();
	static ONCALL OnCtlColorEdit();
	static ONCALL OnCtlColorListbox();
	static ONCALL OnCtlColorBtn();
	static ONCALL OnCtlColorDlg();
	static ONCALL OnCtlColorScrollbar();
	static ONCALL OnCtlColorStatic();
	static ONCALL OnMouseFirst(WORD x, WORD y);
	static ONCALL OnMouseMove(WORD x, WORD y);
	static ONCALL OnLButtonDown(WORD x, WORD y);
	static ONCALL OnLButtonUp(WORD x, WORD y);
	static ONCALL OnLButtonDBlClk(WORD x, WORD y);
	static ONCALL OnRButtonDown(WORD x, WORD y);
	static ONCALL OnRButtonUp(WORD x, WORD y);
	static ONCALL OnRButtonDBlClk(WORD x, WORD y);
	static ONCALL OnMButtonDown(WORD x, WORD y);
	static ONCALL OnMButtonUp(WORD x, WORD y);
	static ONCALL OnMButtonDBlClk(WORD x, WORD y);
	static ONCALL OnMouseWheel(WORD x, WORD y);
	static ONCALL OnXButtonDown();
	static ONCALL OnXButtonUp();
	static ONCALL OnXButtonDblClk();
	static ONCALL OnMouseHWheel();
	static ONCALL OnMouseLast();
	static ONCALL OnParentNotify();
	static ONCALL OnEnterMenuLoop();
	static ONCALL OnExitMenuLoop();
	static ONCALL OnNextMenu();
	static ONCALL OnSizing();
	static ONCALL OnCaptureChanged();
	static ONCALL OnMoving();
	static ONCALL OnPowerBroadcast();
	static ONCALL OnDeviceChange();
	static ONCALL OnMdiCreate();
	static ONCALL OnMdiDestroy();
	static ONCALL OnMdiActivate();
	static ONCALL OnMdiRestore();
	static ONCALL OnMdiNext();
	static ONCALL OnMdiMaximize();
	static ONCALL OnMdiTile();
	static ONCALL OnMdiCascade();
	static ONCALL OnMdiIconArrange();
	static ONCALL OnMdiGetActive();
	static ONCALL OnMdiSetMenu();
	static ONCALL OnEnterSizeMove();
	static ONCALL OnExitSizeMove();
	static ONCALL OnDropFiles();
	static ONCALL OnMdiRefreshMenu();
	static ONCALL OnPointerDeviceChange();
	static ONCALL OnPointerDeviceInRange();
	static ONCALL OnPointerDeviceOutOfRange();
	static ONCALL OnTouch();
	static ONCALL OnNcPointerUpdate();
	static ONCALL OnNcPointerDown();
	static ONCALL OnNcPointerUp();
	static ONCALL OnPointerUpdate();
	static ONCALL OnPointerDown();
	static ONCALL OnPointerUp();
	static ONCALL OnPointerEnter();
	static ONCALL OnPointerLeave();
	static ONCALL OnPointerActivate();
	static ONCALL OnPointerCaptureChanged();
	static ONCALL OnTouchHitTesting();
	static ONCALL OnPointerWheel();
	static ONCALL OnPointerHWheel();
	static ONCALL OnImeSetContext();
	static ONCALL OnImeNotify();
	static ONCALL OnImeControl();
	static ONCALL OnImeCompositionFull();
	static ONCALL OnImeSelect();
	static ONCALL OnImeChar();
	static ONCALL OnImeRequest();
	static ONCALL OnImeKeyDown();
	static ONCALL OnImeKeyUp();
	static ONCALL OnMouseHover();
	static ONCALL OnMouseLeave();
	static ONCALL OnNcMouseHover();
	static ONCALL OnNcMouseLeave();
	static ONCALL OnWtsSessionChange();
	static ONCALL OnTabletFirst();
	static ONCALL OnTabletLast();
	static ONCALL OnCut();
	static ONCALL OnCopy();
	static ONCALL OnPaste();
	static ONCALL OnClear();
	static ONCALL OnUndo();
	static ONCALL OnRenderFormat();
	static ONCALL OnRenderAllFormats();
	static ONCALL OnDestroyClipboard();
	static ONCALL OnDrawClipboard();
	static ONCALL OnPaintClipboard();
	static ONCALL OnVScrollClipboard();
	static ONCALL OnSizeClipboard();
	static ONCALL OnAskCbFormatName();
	static ONCALL OnChangeCbChain();
	static ONCALL OnHScrollClipboard();
	static ONCALL OnQueryNewPalette();
	static ONCALL OnPaletteIsChanging();
	static ONCALL OnPaletteChanged();
	static ONCALL OnHotKey();
	static ONCALL OnPrint();
	static ONCALL OnPrintClient();
	static ONCALL OnAppCommand();
	static ONCALL OnThemeChanged();
	static ONCALL OnClipboardUpdate();
	static ONCALL OnDwmCompositionChanged();
	static ONCALL OnDwmNcRenderingChanged();
	static ONCALL OnDwmColorizationColorChanged();
	static ONCALL OnDwmWindowMaximizedChange();
	static ONCALL OnDwmSendIconIcThumbnail();
	static ONCALL OnDwmSendIconIcLivePreviewBitmap();
	static ONCALL OnGetTitlebarInfoEx();
	static ONCALL OnHandHeldFirst();
	static ONCALL OnHandHeldLast();
	static ONCALL OnAfxFirst();
	static ONCALL OnAfxLast();
	static ONCALL OnPenWinFirst();
	static ONCALL OnPenWinLast();
	static ONCALL OnApp();

	};

#ifndef ONNULL
	ONCALL __t_proc_tc::OnNull(){}
#endif
#ifndef ONCREATE
	ONCALL __t_proc_tc::OnCreate(){}
#endif
#ifndef ONDESTROY
	ONCALL __t_proc_tc::OnDestroy(){}
#endif
#ifndef ONMOVE
	ONCALL __t_proc_tc::OnMove(){}
#endif
#ifndef ONSIZE
	ONCALL __t_proc_tc::OnSize(){}
#endif
#ifndef ONACTIVATE
	ONCALL __t_proc_tc::OnActivate(){}
#endif
#ifndef ONSETFOCUS
	ONCALL __t_proc_tc::OnSetFocus(){}
#endif
#ifndef ONKILLFOCUS
	ONCALL __t_proc_tc::OnKillFocus(){}
#endif
#ifndef ONENABLE
	ONCALL __t_proc_tc::OnEnable(){}
#endif
#ifndef ONSETREDRAW
	ONCALL __t_proc_tc::OnSetReDraw(){}
#endif
#ifndef ONSETTEXT
	ONCALL __t_proc_tc::OnSetText(){}
#endif
#ifndef ONGETTEXT
	ONCALL __t_proc_tc::OnGetText(){}
#endif
#ifndef ONGETTEXTLENGTH
	ONCALL __t_proc_tc::OnGetTextLength(){}
#endif
#ifndef ONPAINT
	ONCALL __t_proc_tc::OnPaint(){}
#endif
#ifndef ONCLOSE
	ONCALL __t_proc_tc::OnClose(){}
#endif
#ifndef ONQUERYENDSESSION
	ONCALL __t_proc_tc::OnQueryEndSession(){}
#endif
#ifndef ONQUERYOPEN
	ONCALL __t_proc_tc::OnQueryOpen(){}
#endif
#ifndef ONENDSESSION
	ONCALL __t_proc_tc::OnEndSession(){}
#endif
#ifndef ONQUIT
	ONCALL __t_proc_tc::OnQuit(){}
#endif
#ifndef ONERASEBKGND
	ONCALL __t_proc_tc::OnEraseBkGnd(){}
#endif
#ifndef ONSYSCOLORCHANGE
	ONCALL __t_proc_tc::OnSysColorChange(){}
#endif
#ifndef ONSHOWWINDOW
	ONCALL __t_proc_tc::OnShowWindow(){}
#endif
#ifndef ONWININICHANGE
	ONCALL __t_proc_tc::OnWinIniChange(){}
#endif
#ifndef ONSETTINGCHANGE
	ONCALL __t_proc_tc::OnSettingChange(){}
#endif
#ifndef ONDEVMODECHANGE
	ONCALL __t_proc_tc::OnDevModeChange(){}
#endif
#ifndef ONACTIVATEAPP
	ONCALL __t_proc_tc::OnActivateApp(){}
#endif
#ifndef ONFONTCHANGE
	ONCALL __t_proc_tc::OnFontChange(){}
#endif
#ifndef ONTIMECHANGE
	ONCALL __t_proc_tc::OnTimeChange(){}
#endif
#ifndef ONCANCELMODE
	ONCALL __t_proc_tc::OnCancelMode(){}
#endif
#ifndef ONSETCURSOR
	ONCALL __t_proc_tc::OnSetCursor(){}
#endif
#ifndef ONMOUSEACTIVATE
	ONCALL __t_proc_tc::OnMouseActivate(){}
#endif
#ifndef ONCHILDACTIVATE
	ONCALL __t_proc_tc::OnChildActivate(){}
#endif
#ifndef ONQUEUESYNC
	ONCALL __t_proc_tc::OnQueueSync(){}
#endif
#ifndef ONGETMINMAXINFO
	ONCALL __t_proc_tc::OnGetMinMaxInfo(){}
#endif
#ifndef ONPAINTICON
	ONCALL __t_proc_tc::OnPaintIcon(){}
#endif
#ifndef ONICONERASEBKGND
	ONCALL __t_proc_tc::OnIconEraseBkGnd(){}
#endif
#ifndef ONNEXTDLGCTL
	ONCALL __t_proc_tc::OnNextDlgCtl(){}
#endif
#ifndef ONSPOOLERSTATUS
	ONCALL __t_proc_tc::OnSpoolerStatus(){}
#endif
#ifndef ONDRAWITEM
	ONCALL __t_proc_tc::OnDrawItem(){}
#endif
#ifndef ONMEASUREITEM
	ONCALL __t_proc_tc::OnMeasureItem(){}
#endif
#ifndef ONDELETEITEM
	ONCALL __t_proc_tc::OnDeleteItem(){}
#endif
#ifndef ONVKEYTOITEM
	ONCALL __t_proc_tc::OnVKeyToItem(){}
#endif
#ifndef ONCHARTOITEM
	ONCALL __t_proc_tc::OnCharToItem(){}
#endif
#ifndef ONSETFONT
	ONCALL __t_proc_tc::OnSetFont(){}
#endif
#ifndef ONGETFONT
	ONCALL __t_proc_tc::OnGetFont(){}
#endif
#ifndef ONSETHOTKEY
	ONCALL __t_proc_tc::OnSetHotKey(){}
#endif
#ifndef ONGETHOTKEY
	ONCALL __t_proc_tc::OnGetHotKey(){}
#endif
#ifndef ONQUERYDRAGICON
	ONCALL __t_proc_tc::OnQueryDragIcon(){}
#endif
#ifndef ONCOMPAREITEM
	ONCALL __t_proc_tc::OnCompareItem(){}
#endif
#ifndef ONGETOBJECT
	ONCALL __t_proc_tc::OnGetObject(){}
#endif
#ifndef ONCOMPACTING
	ONCALL __t_proc_tc::OnCompacting(){}
#endif
#ifndef ONCOMMNOTIFY
	ONCALL __t_proc_tc::OnCommNotify(){}
#endif
#ifndef ONWINDOWPOSCHANGING
	ONCALL __t_proc_tc::OnWindowPosChanging(){}
#endif
#ifndef ONWINDOWPOSCHANGED
	ONCALL __t_proc_tc::OnWindowPosChanged(){}
#endif
#ifndef ONPOWER
	ONCALL __t_proc_tc::OnPower(){}
#endif
#ifndef ONCOPYDATA
	ONCALL __t_proc_tc::OnCopyData(){}
#endif
#ifndef ONCANCELJOURNAL
	ONCALL __t_proc_tc::OnCancelJournal(){}
#endif
#ifndef ONNOTIFY
	ONCALL __t_proc_tc::OnNotify(){}
#endif
#ifndef ONINPUTLANGCHANGEREQUEST
	ONCALL __t_proc_tc::OnInputLangChangeRequest(){}
#endif
#ifndef ONINPUTLANGCHANGE
	ONCALL __t_proc_tc::OnInputLangChange(){}
#endif
#ifndef ONTCARD
	ONCALL __t_proc_tc::OnTCard(){}
#endif
#ifndef ONHELP
	ONCALL __t_proc_tc::OnHelp(){}
#endif
#ifndef ONUSERCHANGED
	ONCALL __t_proc_tc::OnUserChanged(){}
#endif
#ifndef ONNOTIFYFORMAT
	ONCALL __t_proc_tc::OnNotifyFormat(){}
#endif
#ifndef ONCONTEXTMENU
	ONCALL __t_proc_tc::OnContextMenu(){}
#endif
#ifndef ONSTYLECHANGING
	ONCALL __t_proc_tc::OnStyleChanging(){}
#endif
#ifndef ONSTYLECHANGED
	ONCALL __t_proc_tc::OnStyleChanged(){}
#endif
#ifndef ONDISPLAYCHANGE
	ONCALL __t_proc_tc::OnDisplayChange(){}
#endif
#ifndef ONGETICON
	ONCALL __t_proc_tc::OnGetIcon(){}
#endif
#ifndef ONSETICON
	ONCALL __t_proc_tc::OnSetIcon(){}
#endif
#ifndef ONNCCREATE
	ONCALL __t_proc_tc::OnNccReate(){}
#endif
#ifndef ONNCDESTROY
	ONCALL __t_proc_tc::OnNcDestroy(){}
#endif
#ifndef ONNCCALCSIZE
	ONCALL __t_proc_tc::OnNcCalcSize(){}
#endif
#ifndef ONNCHITTEST
	ONCALL __t_proc_tc::OnNcHitTest(){}
#endif
#ifndef ONNCACTIVATE
	ONCALL __t_proc_tc::OnNcActivate(){}
#endif
#ifndef ONGETDLGCODE
	ONCALL __t_proc_tc::OnGetDlgCode(){}
#endif
#ifndef ONSYNCPAINT
	ONCALL __t_proc_tc::OnSyncPaint(){}
#endif
#ifndef ONNCMOUSEMOVE
	ONCALL __t_proc_tc::OnNcMouseMove(){}
#endif
#ifndef ONNCLBUTTONDOWN
	ONCALL __t_proc_tc::OnNcLButtonDown(){}
#endif
#ifndef ONNCLBUTTONUP
	ONCALL __t_proc_tc::OnNcLButtonUp(){}
#endif
#ifndef ONNCLBUTTONDBLCLK
	ONCALL __t_proc_tc::OnNcLButtonDblClk(){}
#endif
#ifndef ONNCRBUTTONDOWN
	ONCALL __t_proc_tc::OnNcRButtonDown(){}
#endif
#ifndef ONNCRBUTTONUP
	ONCALL __t_proc_tc::OnNcRButtonUp(){}
#endif
#ifndef ONNCRBUTTONDBLCLK
	ONCALL __t_proc_tc::OnNcRButtonDblClk(){}
#endif
#ifndef ONNCMBUTTONDOWN
	ONCALL __t_proc_tc::OnNcMButtonDown(){}
#endif
#ifndef ONNCMBUTTONUP
	ONCALL __t_proc_tc::OnNcMButtonUp(){}
#endif
#ifndef ONNCMBUTTONDBLCLK
	ONCALL __t_proc_tc::OnNcMButtonDblClk(){}
#endif
#ifndef ONNCXBUTTONDOWN
	ONCALL __t_proc_tc::OnNcxButtonDown(){}
#endif
#ifndef ONNCXBUTTONUP
	ONCALL __t_proc_tc::OnNcxButtonUp(){}
#endif
#ifndef ONNCXBUTTONDBLCLK
	ONCALL __t_proc_tc::OnNcxButtonDblClk(){}
#endif
#ifndef ONINPUTDEVICECHANGE
	ONCALL __t_proc_tc::OnInputDeviceChange(){}
#endif
#ifndef ONINPUT
	ONCALL __t_proc_tc::OnInput(){}
#endif
#ifndef ONKEYFIRST
	ONCALL __t_proc_tc::OnKeyFirst(WPARAM){}
#endif
#ifndef ONKEYDOWN
	ONCALL __t_proc_tc::OnKeyDown(WPARAM){}
#endif
#ifndef ONKEYUP
	ONCALL __t_proc_tc::OnKeyUp(WPARAM){}
#endif
#ifndef ONCHAR
	ONCALL __t_proc_tc::OnChar(TCHAR){}
#endif
#ifndef ONDEADCHAR
	ONCALL __t_proc_tc::OnDeadChar(){}
#endif
#ifndef ONSYSKEYDOWN
	ONCALL __t_proc_tc::OnSysKeyDown(){}
#endif
#ifndef ONSYSKEYUP
	ONCALL __t_proc_tc::OnSysKeyUp(){}
#endif
#ifndef ONSYSCHAR
	ONCALL __t_proc_tc::OnSysChar(){}
#endif
#ifndef ONSYSDEADCHAR
	ONCALL __t_proc_tc::OnSysDeadChar(){}
#endif
#ifndef ONUNICHAR
	ONCALL __t_proc_tc::OnUniChar(){}
#endif
#ifndef ONKEYLAST
	ONCALL __t_proc_tc::OnKeyLast(){}
#endif
#ifndef ONIMESTARTCOMPOSITION
	ONCALL __t_proc_tc::OnImeStartComposition(){}
#endif
#ifndef ONIMEENDCOMPOSITION
	ONCALL __t_proc_tc::OnImeEndComposition(){}
#endif
#ifndef ONIMECOMPOSITION
	ONCALL __t_proc_tc::OnImeComposition(){}
#endif
#ifndef ONIMEKEYLAST
	ONCALL __t_proc_tc::OnImeKeyLast(){}
#endif
#ifndef ONINITDIALOG
	ONCALL __t_proc_tc::OnInitDialog(){}
#endif
#ifndef ONCOMMAND
	ONCALL __t_proc_tc::OnCommand(WPARAM){}
#endif
#ifndef ONSYSCOMMAND
	ONCALL __t_proc_tc::OnSysCommand(){}
#endif
#ifndef ONTIMER
	ONCALL __t_proc_tc::OnTimer(){}
#endif
#ifndef ONHSCROLL
	ONCALL __t_proc_tc::OnHScroll(){}
#endif
#ifndef ONVSCROLL
	ONCALL __t_proc_tc::OnVScroll(){}
#endif
#ifndef ONINITMENU
	ONCALL __t_proc_tc::OnInitMenu(){}
#endif
#ifndef ONINITMENUPOPUP
	ONCALL __t_proc_tc::OnInitMenuPopUp(){}
#endif
#ifndef ONGESTURE
	ONCALL __t_proc_tc::OnGesture(){}
#endif
#ifndef ONGESTURENOTIFY
	ONCALL __t_proc_tc::OnGestureNotify(){}
#endif
#ifndef ONMENUSELECT
	ONCALL __t_proc_tc::OnMenuSelect(){}
#endif
#ifndef ONMENUCHAR
	ONCALL __t_proc_tc::OnMenuChar(){}
#endif
#ifndef ONENTERIDLE
	ONCALL __t_proc_tc::OnEnterIdle(){}
#endif
#ifndef ONMENURBUTTONUP
	ONCALL __t_proc_tc::OnMenuRButtonUp(){}
#endif
#ifndef ONMENUDRAG
	ONCALL __t_proc_tc::OnMenuDrag(){}
#endif
#ifndef ONMENUGETOBJECT
	ONCALL __t_proc_tc::OnMenuGetObject(){}
#endif
#ifndef ONUNINITMENUPOPUP
	ONCALL __t_proc_tc::OnUnInitMenuPopUp(){}
#endif
#ifndef ONMENUCOMMAND
	ONCALL __t_proc_tc::OnMenuCommand(){}
#endif
#ifndef ONCHANGEUISTATE
	ONCALL __t_proc_tc::OnChangeUIState(){}
#endif
#ifndef ONUPDATEUISTATE
	ONCALL __t_proc_tc::OnUpdateUIState(){}
#endif
#ifndef ONQUERYUISTATE
	ONCALL __t_proc_tc::OnQueryUIState(){}
#endif
#ifndef ONCTLCOLORMSGBOX
	ONCALL __t_proc_tc::OnCtlColorMsgbox(){}
#endif
#ifndef ONCTLCOLOREDIT
	ONCALL __t_proc_tc::OnCtlColorEdit(){}
#endif
#ifndef ONCTLCOLORLISTBOX
	ONCALL __t_proc_tc::OnCtlColorListbox(){}
#endif
#ifndef ONCTLCOLORBTN
	ONCALL __t_proc_tc::OnCtlColorBtn(){}
#endif
#ifndef ONCTLCOLORDLG
	ONCALL __t_proc_tc::OnCtlColorDlg(){}
#endif
#ifndef ONCTLCOLORSCROLLBAR
	ONCALL __t_proc_tc::OnCtlColorScrollbar(){}
#endif
#ifndef ONCTLCOLORSTATIC
	ONCALL __t_proc_tc::OnCtlColorStatic(){}
#endif
#ifndef ONMOUSEFIRST
	ONCALL __t_proc_tc::OnMouseFirst(WORD x, WORD y){}
#endif
#ifndef ONMOUSEMOVE
	ONCALL __t_proc_tc::OnMouseMove(WORD x, WORD y){}
#endif
#ifndef ONLBUTTONDOWN
	ONCALL __t_proc_tc::OnLButtonDown(WORD x, WORD y){}
#endif
#ifndef ONLBUTTONUP
	ONCALL __t_proc_tc::OnLButtonUp(WORD x, WORD y){}
#endif
#ifndef ONLBUTTONDBLCLK
	ONCALL __t_proc_tc::OnLButtonDBlClk(WORD x, WORD y){}
#endif
#ifndef ONRBUTTONDOWN
	ONCALL __t_proc_tc::OnRButtonDown(WORD x, WORD y){}
#endif
#ifndef ONRBUTTONUP
	ONCALL __t_proc_tc::OnRButtonUp(WORD x, WORD y){}
#endif
#ifndef ONRBUTTONDBLCLK
	ONCALL __t_proc_tc::OnRButtonDBlClk(WORD x, WORD y){}
#endif
#ifndef ONMBUTTONDOWN
	ONCALL __t_proc_tc::OnMButtonDown(WORD x, WORD y){}
#endif
#ifndef ONMBUTTONUP
	ONCALL __t_proc_tc::OnMButtonUp(WORD x, WORD y){}
#endif
#ifndef ONMBUTTONDBLCLK
	ONCALL __t_proc_tc::OnMButtonDBlClk(WORD x, WORD y){}
#endif
#ifndef ONMOUSEWHEEL
	ONCALL __t_proc_tc::OnMouseWheel(WORD x, WORD y){}
#endif
#ifndef ONXBUTTONDOWN
	ONCALL __t_proc_tc::OnXButtonDown(){}
#endif
#ifndef ONXBUTTONUP
	ONCALL __t_proc_tc::OnXButtonUp(){}
#endif
#ifndef ONXBUTTONDBLCLK
	ONCALL __t_proc_tc::OnXButtonDblClk(){}
#endif
#ifndef ONMOUSEHWHEEL
	ONCALL __t_proc_tc::OnMouseHWheel(){}
#endif
#ifndef ONMOUSELAST
	ONCALL __t_proc_tc::OnMouseLast(){}
#endif
#ifndef ONPARENTNOTIFY
	ONCALL __t_proc_tc::OnParentNotify(){}
#endif
#ifndef ONENTERMENULOOP
	ONCALL __t_proc_tc::OnEnterMenuLoop(){}
#endif
#ifndef ONEXITMENULOOP
	ONCALL __t_proc_tc::OnExitMenuLoop(){}
#endif
#ifndef ONNEXTMENU
	ONCALL __t_proc_tc::OnNextMenu(){}
#endif
#ifndef ONSIZING
	ONCALL __t_proc_tc::OnSizing(){}
#endif
#ifndef ONCAPTURECHANGED
	ONCALL __t_proc_tc::OnCaptureChanged(){}
#endif
#ifndef ONMOVING
	ONCALL __t_proc_tc::OnMoving(){}
#endif
#ifndef ONPOWERBROADCAST
	ONCALL __t_proc_tc::OnPowerBroadcast(){}
#endif
#ifndef ONDEVICECHANGE
	ONCALL __t_proc_tc::OnDeviceChange(){}
#endif
#ifndef ONMDICREATE
	ONCALL __t_proc_tc::OnMdiCreate(){}
#endif
#ifndef ONMDIDESTROY
	ONCALL __t_proc_tc::OnMdiDestroy(){}
#endif
#ifndef ONMDIACTIVATE
	ONCALL __t_proc_tc::OnMdiActivate(){}
#endif
#ifndef ONMDIRESTORE
	ONCALL __t_proc_tc::OnMdiRestore(){}
#endif
#ifndef ONMDINEXT
	ONCALL __t_proc_tc::OnMdiNext(){}
#endif
#ifndef ONMDIMAXIMIZE
	ONCALL __t_proc_tc::OnMdiMaximize(){}
#endif
#ifndef ONMDITILE
	ONCALL __t_proc_tc::OnMdiTile(){}
#endif
#ifndef ONMDICASCADE
	ONCALL __t_proc_tc::OnMdiCascade(){}
#endif
#ifndef ONMDIICONARRANGE
	ONCALL __t_proc_tc::OnMdiIconArrange(){}
#endif
#ifndef ONMDIGETACTIVE
	ONCALL __t_proc_tc::OnMdiGetActive(){}
#endif
#ifndef ONMDISETMENU
	ONCALL __t_proc_tc::OnMdiSetMenu(){}
#endif
#ifndef ONENTERSIZEMOVE
	ONCALL __t_proc_tc::OnEnterSizeMove(){}
#endif
#ifndef ONEXITSIZEMOVE
	ONCALL __t_proc_tc::OnExitSizeMove(){}
#endif
#ifndef ONDROPFILES
	ONCALL __t_proc_tc::OnDropFiles(){}
#endif
#ifndef ONMDIREFRESHMENU
	ONCALL __t_proc_tc::OnMdiRefreshMenu(){}
#endif
#ifndef ONPOINTERDEVICECHANGE
	ONCALL __t_proc_tc::OnPointerDeviceChange(){}
#endif
#ifndef ONPOINTERDEVICEINRANGE
	ONCALL __t_proc_tc::OnPointerDeviceInRange(){}
#endif
#ifndef ONPOINTERDEVICEOUTOFRANGE
	ONCALL __t_proc_tc::OnPointerDeviceOutOfRange(){}
#endif
#ifndef ONTOUCH
	ONCALL __t_proc_tc::OnTouch(){}
#endif
#ifndef ONNCPOINTERUPDATE
	ONCALL __t_proc_tc::OnNcPointerUpdate(){}
#endif
#ifndef ONNCPOINTERDOWN
	ONCALL __t_proc_tc::OnNcPointerDown(){}
#endif
#ifndef ONNCPOINTERUP
	ONCALL __t_proc_tc::OnNcPointerUp(){}
#endif
#ifndef ONPOINTERUPDATE
	ONCALL __t_proc_tc::OnPointerUpdate(){}
#endif
#ifndef ONPOINTERDOWN
	ONCALL __t_proc_tc::OnPointerDown(){}
#endif
#ifndef ONPOINTERUP
	ONCALL __t_proc_tc::OnPointerUp(){}
#endif
#ifndef ONPOINTERENTER
	ONCALL __t_proc_tc::OnPointerEnter(){}
#endif
#ifndef ONPOINTERLEAVE
	ONCALL __t_proc_tc::OnPointerLeave(){}
#endif
#ifndef ONPOINTERACTIVATE
	ONCALL __t_proc_tc::OnPointerActivate(){}
#endif
#ifndef ONPOINTERCAPTURECHANGED
	ONCALL __t_proc_tc::OnPointerCaptureChanged(){}
#endif
#ifndef ONTOUCHHITTESTING
	ONCALL __t_proc_tc::OnTouchHitTesting(){}
#endif
#ifndef ONPOINTERWHEEL
	ONCALL __t_proc_tc::OnPointerWheel(){}
#endif
#ifndef ONPOINTERHWHEEL
	ONCALL __t_proc_tc::OnPointerHWheel(){}
#endif
#ifndef ONIMESETCONTEXT
	ONCALL __t_proc_tc::OnImeSetContext(){}
#endif
#ifndef ONIMENOTIFY
	ONCALL __t_proc_tc::OnImeNotify(){}
#endif
#ifndef ONIMECONTROL
	ONCALL __t_proc_tc::OnImeControl(){}
#endif
#ifndef ONIMECOMPOSITIONFULL
	ONCALL __t_proc_tc::OnImeCompositionFull(){}
#endif
#ifndef ONIMESELECT
	ONCALL __t_proc_tc::OnImeSelect(){}
#endif
#ifndef ONIMECHAR
	ONCALL __t_proc_tc::OnImeChar(){}
#endif
#ifndef ONIMEREQUEST
	ONCALL __t_proc_tc::OnImeRequest(){}
#endif
#ifndef ONIMEKEYDOWN
	ONCALL __t_proc_tc::OnImeKeyDown(){}
#endif
#ifndef ONIMEKEYUP
	ONCALL __t_proc_tc::OnImeKeyUp(){}
#endif
#ifndef ONMOUSEHOVER
	ONCALL __t_proc_tc::OnMouseHover(){}
#endif
#ifndef ONMOUSELEAVE
	ONCALL __t_proc_tc::OnMouseLeave(){}
#endif
#ifndef ONNCMOUSEHOVER
	ONCALL __t_proc_tc::OnNcMouseHover(){}
#endif
#ifndef ONNCMOUSELEAVE
	ONCALL __t_proc_tc::OnNcMouseLeave(){}
#endif
#ifndef ONWTSSESSIONCHANGE
	ONCALL __t_proc_tc::OnWtsSessionChange(){}
#endif
#ifndef ONTABLETFIRST
	ONCALL __t_proc_tc::OnTabletFirst(){}
#endif
#ifndef ONTABLETLAST
	ONCALL __t_proc_tc::OnTabletLast(){}
#endif
#ifndef ONCUT
	ONCALL __t_proc_tc::OnCut(){}
#endif
#ifndef ONCOPY
	ONCALL __t_proc_tc::OnCopy(){}
#endif
#ifndef ONPASTE
	ONCALL __t_proc_tc::OnPaste(){}
#endif
#ifndef ONCLEAR
	ONCALL __t_proc_tc::OnClear(){}
#endif
#ifndef ONUNDO
	ONCALL __t_proc_tc::OnUndo(){}
#endif
#ifndef ONRENDERFORMAT
	ONCALL __t_proc_tc::OnRenderFormat(){}
#endif
#ifndef ONRENDERALLFORMATS
	ONCALL __t_proc_tc::OnRenderAllFormats(){}
#endif
#ifndef ONDESTROYCLIPBOARD
	ONCALL __t_proc_tc::OnDestroyClipboard(){}
#endif
#ifndef ONDRAWCLIPBOARD
	ONCALL __t_proc_tc::OnDrawClipboard(){}
#endif
#ifndef ONPAINTCLIPBOARD
	ONCALL __t_proc_tc::OnPaintClipboard(){}
#endif
#ifndef ONVSCROLLCLIPBOARD
	ONCALL __t_proc_tc::OnVScrollClipboard(){}
#endif
#ifndef ONSIZECLIPBOARD
	ONCALL __t_proc_tc::OnSizeClipboard(){}
#endif
#ifndef ONASKCBFORMATNAME
	ONCALL __t_proc_tc::OnAskCbFormatName(){}
#endif
#ifndef ONCHANGECBCHAIN
	ONCALL __t_proc_tc::OnChangeCbChain(){}
#endif
#ifndef ONHSCROLLCLIPBOARD
	ONCALL __t_proc_tc::OnHScrollClipboard(){}
#endif
#ifndef ONQUERYNEWPALETTE
	ONCALL __t_proc_tc::OnQueryNewPalette(){}
#endif
#ifndef ONPALETTEISCHANGING
	ONCALL __t_proc_tc::OnPaletteIsChanging(){}
#endif
#ifndef ONPALETTECHANGED
	ONCALL __t_proc_tc::OnPaletteChanged(){}
#endif
#ifndef ONHOTKEY
	ONCALL __t_proc_tc::OnHotKey(){}
#endif
#ifndef ONPRINT
	ONCALL __t_proc_tc::OnPrint(){}
#endif
#ifndef ONPRINTCLIENT
	ONCALL __t_proc_tc::OnPrintClient(){}
#endif
#ifndef ONAPPCOMMAND
	ONCALL __t_proc_tc::OnAppCommand(){}
#endif
#ifndef ONTHEMECHANGED
	ONCALL __t_proc_tc::OnThemeChanged(){}
#endif
#ifndef ONCLIPBOARDUPDATE
	ONCALL __t_proc_tc::OnClipboardUpdate(){}
#endif
#ifndef ONDWMCOMPOSITIONCHANGED
	ONCALL __t_proc_tc::OnDwmCompositionChanged(){}
#endif
#ifndef ONDWMNCRENDERINGCHANGED
	ONCALL __t_proc_tc::OnDwmNcRenderingChanged(){}
#endif
#ifndef ONDWMCOLORIZATIONCOLORCHANGED
	ONCALL __t_proc_tc::OnDwmColorizationColorChanged(){}
#endif
#ifndef ONDWMWINDOWMAXIMIZEDCHANGE
	ONCALL __t_proc_tc::OnDwmWindowMaximizedChange(){}
#endif
#ifndef ONDWMSENDICONICTHUMBNAIL
	ONCALL __t_proc_tc::OnDwmSendIconIcThumbnail(){}
#endif
#ifndef ONDWMSENDICONICLIVEPREVIEWBITMAP
	ONCALL __t_proc_tc::OnDwmSendIconIcLivePreviewBitmap(){}
#endif
#ifndef ONGETTITLEBARINFOEX
	ONCALL __t_proc_tc::OnGetTitlebarInfoEx(){}
#endif
#ifndef ONHANDHELDFIRST
	ONCALL __t_proc_tc::OnHandHeldFirst(){}
#endif
#ifndef ONHANDHELDLAST
	ONCALL __t_proc_tc::OnHandHeldLast(){}
#endif
#ifndef ONAFXFIRST
	ONCALL __t_proc_tc::OnAfxFirst(){}
#endif
#ifndef ONAFXLAST
	ONCALL __t_proc_tc::OnAfxLast(){}
#endif
#ifndef ONPENWINFIRST
	ONCALL __t_proc_tc::OnPenWinFirst(){}
#endif
#ifndef ONPENWINLAST
	ONCALL __t_proc_tc::OnPenWinLast(){}
#endif
#ifndef ONAPP
	ONCALL __t_proc_tc::OnApp(){}
#endif

class __event_master_dc
	{ // event master dc
	HDC hdc;
	PAINTSTRUCT ps;
public:
	__event_master_dc() : hdc(0){}
	void operator~(){hdc = GetDC(hWnd);}
	void operator&(){ReleaseDC(hWnd, hdc);}
	void operator++(){hdc = BeginPaint(hWnd, &ps);}
	void operator--(){EndPaint(hWnd, &ps);}
	HDC operator*(){return hdc;}
	void SetText(int x, int y, LPCSTR text, UINT option = 0)
	{if(option) SetTextAlign(hdc, option);TextOut(hdc, x, y, text, lstrlen(text));}
#pragma push_macro("DrawText")
#undef DrawText
	void DrawText(LPRECT lpRect, LPCTSTR text, UINT Format = 0)
	{
#ifdef UNICODE
	DrawTextW(hdc, text, -1, lpRect, Format);
#else
	DrawTextA(hdc, text, -1, lpRect, Format);
#endif // !UNICODE
	}
	void DrawPixel(int x, int y, DWORD color){SetPixel(hdc, x, y, color);}
	void DrawLine(int x1, int y1, int x2, int y2){MoveToEx(hdc, x1, y1, NULL);LineTo(hdc, x2, y2);}
	void DrawRect(LPRECT lpRect){Rectangle(hdc, lpRect->left, lpRect->top, lpRect->right, lpRect->bottom);}
	void DrawCircle(LPRECT lpRect){Ellipse(hdc, lpRect->left, lpRect->top, lpRect->right, lpRect->bottom);}
	};

class __event_master_timer
	{ // event master dc
public:
	static void New(int inteval, int id, bool proc = false){SetTimer(hWnd, id, inteval, proc ? NULL : timer_proc);}
	static VOID CALLBACK timer_proc(PROC_NONE);
	};

class __event_master_transfer
	{ // transfer
public:
	void transfer()
		{
		
		}
	};

typedef enum _msg_box_button
{
	arl = MB_ABORTRETRYIGNORE,
	okc = MB_OKCANCEL,
	rc = MB_RETRYCANCEL,
	yn = MB_YESNO,
	ync = MB_YESNOCANCEL,
	none = MB_OK,
} msg_button;

typedef enum _msg_box_icon
{
	question = MB_ICONQUESTION,
	user = MB_USERICON,
	err = MB_ICONERROR,
	info = MB_ICONINFORMATION,
	stop = MB_ICONSTOP,
} msg_icon;

typedef enum _msg_out
{
	abort = IDABORT,
	ign = IDIGNORE,
	ok = IDOK,
	r = IDRETRY,
	n = IDNO,
	y = IDYES,
	c = IDCANCEL,
} msg_out;	// dialog box return

class __event_master_main
	{ // event master main
	int timerx;
public:
	__event_master_main() : timerx(0) {}
	__event_master_dc emd;
	__event_master_timer timer;
	void Invalidate(RECT *rt = 0) {InvalidateRect(hWnd, rt ? rt : NULL, FALSE);}
	int MsgBox(LPCTSTR body, LPCTSTR title, _msg_box_button mod = none, _msg_box_icon icon = err){return MessageBox(hWnd, body, title, mod | icon);}
	int CreateTimer(int inteval,  bool proc = false){timer.New(inteval, timerx++, proc); return timerx;}
	/* automatic */ void TerminateTimer(UINT timer_id){KillTimer(hWnd, timer_id);}
	SYSTEMTIME LocalTime(){SYSTEMTIME st;GetLocalTime(&st);return st;}
	void MessageSend(UINT msg, WPARAM w, LPARAM l){SendMessage(hWnd, msg, w, l);}
	void DestroyAll(){if(timerx)for(int i = 0; i < timerx; i++)TerminateTimer(i);PostQuitMessage(0);}
	RECT ClientRect(){RECT x; GetClientRect(hWnd, &x); return x;}
	};

class __del_dll
	{ // del dll
public:
	};

#ifdef STDLOGIC
#pragma pop_macro("DrawText")
#endif

}
#endif

RECT MakeRect(int left, int top, int right, int bottom)
{
	RECT xt = {left, top, right, bottom};
	return xt;
}

#endif