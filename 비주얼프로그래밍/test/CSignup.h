#pragma once


// CSignup 대화 상자

class CSignup : public CDialog
{
	DECLARE_DYNAMIC(CSignup)

public:
	CSignup(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CSignup();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SIGNUP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSignupSingup();
	afx_msg void OnBnClickedButtIdcheck();
	CString m_pw;
	CString m_checkpw;
	CString m_name;
	CString m_id;
	CString input_pw;
	CString input_checkpw;
};
