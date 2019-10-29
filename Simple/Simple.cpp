#include<afxwin.h>
#include<atlimage.h>
//이미지 처리를 위해 atlimage.h 헤더 추가
class CMainFrame : public CFrameWnd {
public:
	CMainFrame() {
		Create(NULL, L"Hi !");
	}
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
};

class CMyApp : public CWinApp {
	BOOL InitInstance() {
		CMainFrame* Frm = new CMainFrame();
		m_pMainWnd = Frm;
		Frm->ShowWindow(1);
		return TRUE;
	}
};

CMyApp theApp;//객체 만들어짐

//MAP은 전부 매크로이므로 ;을 붙이지 않는다BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()


void CMainFrame::OnPaint()
{
	CImage img;
	CPaintDC dc(this);
	img.Load(L"wel.jpg");
	img.Draw(dc, 100, 0);
}
