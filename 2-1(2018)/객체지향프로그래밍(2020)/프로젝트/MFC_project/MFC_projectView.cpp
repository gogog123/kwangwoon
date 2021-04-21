
// MFC_projectView.cpp: CMFCprojectView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFC_project.h"
#endif

#include "MFC_projectDoc.h"
#include "MFC_projectView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "MyBoard.h"
#include <conio.h> //Console inputand output


// CMFCprojectView

IMPLEMENT_DYNCREATE(CMFCprojectView, CView)

BEGIN_MESSAGE_MAP(CMFCprojectView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFCprojectView 생성/소멸

CMFCprojectView::CMFCprojectView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMFCprojectView::~CMFCprojectView()
{
}

BOOL CMFCprojectView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMFCprojectView 그리기

void CMFCprojectView::OnDraw(CDC* pDC)
{
	CMFCprojectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.

	//pDC->Rectangle(300, 300, 364, 364);
	/*
	pDC->TextOutW(10, 10, m_strWindowSize);

	CRect rect;
	GetClientRect(&rect);
	pDC->DrawText(m_strOutText, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
				CRect block_size;
			GetClientRect(&block_size);
	*/
	MyBlock* temp = pDoc->board.GetHead();
	MyBlock* temp_down = pDoc->board.GetHead();

	CString num;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			CRect rect(50 + (i * 100), 50 + (j * 100), 150 + (i * 100), 150 + (j * 100));
			//pDC->Rectangle(rect);
			if (temp->GetNumber() == 2)
				pDC->FillSolidRect(rect, RGB(255, 255, 0)); //yellow

			else if (temp->GetNumber() == 4)
				pDC->FillSolidRect(rect, RGB(255, 127, 0)); //orange

			else if (temp->GetNumber() == 8)
				pDC->FillSolidRect(rect, RGB(0, 255, 0)); //green

			else if (temp->GetNumber() == 16)
				pDC->FillSolidRect(rect, RGB(0, 0, 255)); //blue

			else if (temp->GetNumber() == 32)
				pDC->FillSolidRect(rect, RGB(166, 166, 166)); //gray

			else if (temp->GetNumber() == 64)
				pDC->FillSolidRect(rect, RGB(255, 0, 255)); //pink

			else if (temp->GetNumber() == 128)
				pDC->FillSolidRect(rect, RGB(0, 255, 255)); //cyan

			else if (temp->GetNumber() == 256)
				pDC->FillSolidRect(rect, RGB(128, 0, 128)); //purple

			else if (temp->GetNumber() == 512)
				pDC->FillSolidRect(rect, RGB(112, 48, 160)); //violet

			else if (temp->GetNumber() == 1024)
				pDC->FillSolidRect(rect, RGB(207, 110, 54)); //brown

			else if (temp->GetNumber() == 2048)
				pDC->FillSolidRect(rect, RGB(255, 0, 0)); //red

			else if (temp->GetNumber() == NULL)
				pDC->Rectangle(rect);

			if (temp->GetNumber() != NULL)
			{
				num.Format(_T("%d"), temp->GetNumber());
				pDC->TextOutW(95 + (100 * i), 95 + (100 * j), num);
			}
			
			temp = temp->GetRight();
		}
		if (temp_down->GetDown() == NULL)
			break;
		temp = temp_down->GetDown();
		temp_down = temp_down->GetDown();
	}
	//draw board
}

// CMFCprojectView 인쇄

BOOL CMFCprojectView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMFCprojectView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMFCprojectView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMFCprojectView 진단

#ifdef _DEBUG
void CMFCprojectView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCprojectView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCprojectDoc* CMFCprojectView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCprojectDoc)));
	return (CMFCprojectDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCprojectView 메시지 처리기


void CMFCprojectView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	//m_strWindowSize.Format(_T("Window Width=%d, Height=%d"), cx, cy);
	MoveWindow(0, 0, 600, 600); //

	CMFCprojectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if (pDoc->board.Win()==1)
	{
		if (MessageBox(L"Continue??", L"WIN!!", MB_ICONWARNING | MB_YESNO) == IDYES)
		{
			pDoc->board.Reset(); //game restart
			pDoc->board.Random_two();
		}
		else
		{
			this->DestroyWindow(); //game end
			PostQuitMessage(0);
		}

	}

	if (pDoc->board.Lose() == true && pDoc->board.Win() == 2)
	{
		if (MessageBox(L"Do you want new game?", L"LOSE!!", MB_ICONSTOP | MB_YESNO) == IDYES)
		{
			pDoc->board.Reset(); //game restart
			pDoc->board.Random_two();
		}
		else
		{
			this->DestroyWindow(); //game end
			PostQuitMessage(0);
		}
	}


	Invalidate();
}

void CMFCprojectView::keydownfunc(int direct)
{
	CMFCprojectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if (direct == 1)
		pDoc->board.Right();

	else if (direct == 2)
		pDoc->board.Left();

	else if (direct == 3)
		pDoc->board.Up();

	else if (direct == 4)
		pDoc->board.Down();
}


void CMFCprojectView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) //keyboard input
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	switch (nChar)
	{
	case VK_RIGHT:
	{
		keydownfunc(4);
		break;
	}
	case VK_LEFT:
	{
		keydownfunc(3);
		break;
	}
	case VK_UP:
	{
		keydownfunc(2);
		break;
	}
	case VK_DOWN:
	{
		keydownfunc(1);
		break;
	}
	default:
		break;

	}

	Invalidate(true);

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMFCprojectView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_bDrag == TRUE)
	{
		m_strOutText = _T("Mouse is being dragged.");
	}
	else
	{
		m_strOutText = _T("Mouse is just moving.");
	}

	CView::OnMouseMove(nFlags, point);
}

void CMFCprojectView::OnLButtonDown(UINT nFlags, CPoint point) // Action on mouse click
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CMFCprojectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	start_point = point;
	SetCapture();
	RedrawWindow();
	CView::OnLButtonDown(nFlags, point);
}

void CMFCprojectView::OnLButtonUp(UINT nFlags, CPoint point) // Action when the mouse is released
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CMFCprojectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	//Action on mouse click

	end_point = point; // Where the mouse click was released

	if (start_point.x > end_point.x)
	{
		pDoc->board.Turn_Right();
	}

	else if (start_point.x < end_point.x)
	{
		pDoc->board.Turn_Right();
		pDoc->board.Turn_Right();
		pDoc->board.Turn_Right();
	}
	//Move right three times = Move left
	
	RedrawWindow();
	ReleaseCapture();
	CView::OnLButtonUp(nFlags, point);
}
