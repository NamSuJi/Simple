#include<afxwin.h>

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
	CPaintDC dc(this);
	CBrush b;
	b.CreateSolidBrush(RGB(0, 0, 255));//색상 적용 가능
	dc.SelectObject(&b);
	dc.Rectangle(100, 100, 200, 200);
}