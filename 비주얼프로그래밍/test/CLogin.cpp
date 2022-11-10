// CLogin.cpp: 구현 파일
//

#include "pch.h"
#include "test.h"
#include "CLogin.h"
#include "afxdialogex.h"
#include "CSignup.h"


using namespace std;


// CLogin 대화 상자

IMPLEMENT_DYNAMIC(CLogin, CDialog)

CLogin::CLogin(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_LOGIN, pParent)
	, m_id(_T(""))
	, m_pw(_T(""))
{

}

CLogin::~CLogin()
{
}

void CLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ID, m_id);
	DDX_Text(pDX, IDC_EDIT_PW, m_pw);
}


BEGIN_MESSAGE_MAP(CLogin, CDialog)
	ON_BN_CLICKED(IDC_BUTT_LOGIN, &CLogin::OnBnClickedButtLogin)
	ON_BN_CLICKED(IDC_BUTT_SIGNUP, &CLogin::OnBnClickedButtSignup)
END_MESSAGE_MAP()


// CLogin 메시지 처리기


void CLogin::OnBnClickedButtLogin()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	id = CSignupDialog.m_id; //사용자가 회원가입시 입력한 아이디 비밀번호
	pw = CSignupDialog.m_pw;
	UpdateData(FALSE);
	
	UpdateData(TRUE);
	CString user_id = m_id; //사용자가 로그인창에서 입력한 아이디, 비밀번호
	CString user_pw = m_pw;
	user_name = CSignupDialog.m_name;
	UpdateData(FALSE);

	
	if (id == user_id && pw == user_pw && user_id != "" && user_pw != "") {
		MessageBox(_T("로그인 성공"));
		OnOK();	
	}
	else {
		MessageBox(_T("로그인 실패"));
	}
	
}


void CLogin::OnBnClickedButtSignup()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (CSignupDialog.DoModal() == IDCANCEL) {
		
		MessageBox(_T("회원가입이 취소되었습니다."));
	}
	else {
		MessageBox(_T("회원가입을 축하드립니다!"));
	}
	
	

}


BOOL CLogin::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_RETURN) // ENTER키 눌릴 시
			return TRUE;
		else if (pMsg->wParam == VK_ESCAPE) // ESC키 눌릴 시
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}
