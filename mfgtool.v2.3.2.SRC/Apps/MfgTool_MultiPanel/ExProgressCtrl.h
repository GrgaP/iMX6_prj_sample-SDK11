/*
 * Copyright (C) 2012-2013, Freescale Semiconductor, Inc. All Rights Reserved.
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 *
 */

////////////////////////////////////////////////////////////////////////////////
// CExProgressCtrl class
class CExProgressCtrl : public CProgressCtrl
{
// Constructor / Destructor
public:
	CExProgressCtrl();
	virtual ~CExProgressCtrl();
	
// Operations
public:
    void SetBarColor(COLORREF crBarColor)
    {
        ::SendMessage(m_hWnd, PBM_SETBARCOLOR, 0, (LPARAM)crBarColor);
    }
    
    void SetBarBkColor(COLORREF crBarBkColor)
    {
        ::SendMessage(m_hWnd, PBM_SETBKCOLOR, 0, (LPARAM)crBarBkColor);
    }
    
    COLORREF GetBarColor() const
    {
       return( (COLORREF)::SendMessage(m_hWnd, PBM_GETBARCOLOR, 0, 0) );
    }
    
    COLORREF GetBarBkColor() const
    {
		return( (COLORREF)::SendMessage(m_hWnd, PBM_GETBKCOLOR, 0, 0) );
    }
    
protected:
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
    afx_msg void OnPaint();
    afx_msg LRESULT OnSetBarColor(WPARAM, LPARAM);
	afx_msg LRESULT OnSetBarBkColor(WPARAM, LPARAM);
	afx_msg LRESULT OnGetBarColor(WPARAM, LPARAM);
	afx_msg LRESULT OnGetBarBkColor(WPARAM, LPARAM);
	afx_msg LRESULT OnSetRange32(WPARAM nLow, LPARAM nHigh);
	afx_msg LRESULT OnSetPos(WPARAM nNewPos, LPARAM);
	
	DECLARE_MESSAGE_MAP()
	
	COLORREF  m_crBarColor;
	COLORREF  m_crBarBkColor;
	int       m_nPos;
	int       m_nLow;
    int       m_nHigh;
};
