#pragma once
#include "CSignup.h"

// CLogin 대화 상자

class CLogin : public CDialog
{
	DECLARE_DYNAMIC(CLogin)

public:
	CLogin(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CLogin();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_LOGIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtLogin();
	CString m_id;
	CString m_pw;
	afx_msg void OnBnClickedButtSignup();
	CSignup CSignupDialog; //회원가입 모달창 객체
	CString id = _T("1234"); //초기 아이디
	CString pw = _T("1234"); //초기 비밀번호
	CString user_name;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
