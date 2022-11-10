// CSignup.cpp: 구현 파일
//

#include "pch.h"
#include "test.h"
#include "CSignup.h"
#include "afxdialogex.h"
#include "CLogin.h"



// CSignup 대화 상자

IMPLEMENT_DYNAMIC(CSignup, CDialog)

CSignup::CSignup(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_SIGNUP, pParent)
	, m_pw(_T(""))
	, m_checkpw(_T(""))
	, m_name(_T(""))
	, m_id(_T(""))
{

}

CSignup::~CSignup()
{
}

void CSignup::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SIGNUP_PW, m_pw);
	DDX_Text(pDX, IDC_SINGUP_CHECKPW, m_checkpw);
	DDX_Text(pDX, IDC_SIGNUP_NAME, m_name);
	DDX_Text(pDX, IDC_SINGUP_ID, m_id);
}


BEGIN_MESSAGE_MAP(CSignup, CDialog)
	ON_BN_CLICKED(IDC_BUTT_SINGUP, &CSignup::OnBnClickedSignupSingup)
	ON_BN_CLICKED(IDC_BUTT_IDCHECK, &CSignup::OnBnClickedButtIdcheck)
END_MESSAGE_MAP()


// CSignup 메시지 처리기


void CSignup::OnBnClickedSignupSingup() //회원가입 완료 버튼
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	input_pw = m_pw;
	input_checkpw = m_checkpw;
	UpdateData(FALSE);
	if (input_pw != m_checkpw) { //비밀번호가 서로 맞지 않는 경우
		MessageBox(_T("비밀번호를 다시 확인해주십시오."));
	}
	else if(input_pw == "" || input_checkpw == "") { //비밀번호를 입력하지 않은 경우
		MessageBox(_T("올바르지 않은 비밀번호입니다."));
	}
	else { //위의 두 경우가 아닌 올바르게 입력 된 경우
		OnOK();
	}
	

}


void CSignup::OnBnClickedButtIdcheck() //아이디 중복확인 버튼
{
	MessageBox(_T("사용가능한 ID 입니다."));
	GetDlgItem(IDC_BUTT_IDCHECK)->EnableWindow(FALSE); //ID 변경 불가능 처리
}
