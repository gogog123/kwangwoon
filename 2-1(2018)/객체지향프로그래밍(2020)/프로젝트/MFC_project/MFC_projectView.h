
// MFC_projectView.h: CMFCprojectView 클래스의 인터페이스
//

#pragma once


class CMFCprojectView : public CView
{
protected: // serialization에서만 만들어집니다.
	CMFCprojectView() noexcept;
	DECLARE_DYNCREATE(CMFCprojectView)

// 특성입니다.
public:
	CMFCprojectDoc* GetDocument() const;
	MyBoard board;

// 작업입니다.
public:
	CPoint start_point;
	CPoint end_point;
	int count = 1;
	ofstream fout;
// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void keydownfunc(int direct);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMFCprojectView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString m_strWindowSize;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CString m_strOutText;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	bool m_bDrag;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC_projectView.cpp의 디버그 버전
inline CMFCprojectDoc* CMFCprojectView::GetDocument() const
   { return reinterpret_cast<CMFCprojectDoc*>(m_pDocument); }
#endif
