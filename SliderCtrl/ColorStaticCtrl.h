#pragma once


// ColorStaticCtrl

class ColorStaticCtrl : public CStatic
{
	DECLARE_DYNAMIC(ColorStaticCtrl)

public:
	ColorStaticCtrl();
	virtual ~ColorStaticCtrl();

	int red{ 255 }, green{ 0 }, blue{ 0 };

	void reDraw()
	{
		Invalidate();
		UpdateWindow();
	}


protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};


