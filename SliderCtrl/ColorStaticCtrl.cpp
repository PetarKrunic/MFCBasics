// ColorStaticCtrl.cpp : implementation file
//

#include "pch.h"
#include "SliderCtrl.h"
#include "ColorStaticCtrl.h"


// ColorStaticCtrl

IMPLEMENT_DYNAMIC(ColorStaticCtrl, CStatic)

ColorStaticCtrl::ColorStaticCtrl()
{

}

ColorStaticCtrl::~ColorStaticCtrl()
{
}


BEGIN_MESSAGE_MAP(ColorStaticCtrl, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// ColorStaticCtrl message handlers




void ColorStaticCtrl::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	
	CRect rectWindow;
	GetClientRect(&rectWindow);


	auto color{ RGB(red, green, blue) };

	CBrush brush(color);

	dc.FillRect(&rectWindow, &brush);

	CString strPoint;
	strPoint.Format(_T("RGB: %d, %d, %d "), red, green, blue);
	dc.TextOutW(10, 10, strPoint);

	dc.SelectClipRgn(NULL);
}
