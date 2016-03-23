#include <iostream>
using namespace std;

enum SIGNIN{Null = 0, Sign, Sick, Thing, Skip};
typedef struct TIME
{
	int nYear;
	int nMonth;
	int nDay;
}DATA;

typedef struct PERSON
{
	char	szName[20];	// 姓名
	char	szSection[20];	// 部门
	char	szPost[20];	// 职务
	SIGNIN emEmploy;
}Employ;

CEmployee::CEmployee()
{
	return ;
}

CEmployee::~CEmployee()
{
	return ;
}

void CEmployee::Init()
{
	system("cls");
	cout << "请输入姓名：";
	cin >> m_stEmp.szName;
	cout << endl << "部门：";
	cin >> m_stEmp.szSection;
	cout << endl << "请输入职务：";
	cin >> m_stEmp.szPost;
	m_stEmp.emEmploy = Null;
	next = NULL;
}

void CEmployee::SignFun()
{
	system("cls");
	if(m_stEmp.emEmploy == Null)
	{
		m_stEmp.emEmploy = Sign;
		cout << m_stEmp.szName << "签到成功!" << endl;
	}
	else
	{
		cout << "你已经签过了!" << endl;
	}
	cout << endl << endl << "按任意键继续~" ;
	getch();
	return ;
}

void CEmployee::SickFun()
{
	system("cls");
	if(m_stEmp.emEmploy == Null)
	{
		m_stEmp.emEmploy = Sick;
		cout << m_stEmp.szName << "请病假被批准!" << endl;
	}
	else
	{
		cout << "你已经签过了!" << endl;
	}
	cout << endl << endl << "按任意键继续~" ;
	getch();
	return ;
}

void CEmployee::ThingFun()
{
	system("cls");
	if(m_stEmp.emEmploy == Null)
	{
		m_stEmp.emEmploy = Thing;
		cout << m_stEmp.szName << "请事假被批准!" << endl;
	}
	else
	{
		cout << "你已经签过了!" << endl;
	}
	cout << endl << endl << "按任意键继续~" ;
	getch();
	return ;
}

void CEmployee::SkipFun()
{
	system("cls");
	if(m_stEmp.emEmploy == Null)
	{
		m_stEmp.emEmploy = Skip;
		cout << m_stEmp.szName << "旷工被添加!" << endl;
	}
	else
	{
		cout << "你已经签过了!" << endl;
	}
	cout << endl << endl << "按任意键继续~" ;
	getch();
	return ;
}

void CEmployee::Show()
{
	switch(m_stEmp.emEmploy)
	{
	case Null:
		cout<< "未签" << endl << endl;
		break;

	case Sign:
		cout<< "签到" << endl << endl;
		break;

	case Sick:
		cout<< "病假" << endl << endl;
		break;

	case Thing:
		cout<< "事假" << endl << endl;
		break;

	case Skip:
		cout<< "旷工" << endl << endl;
		break;
	}

	return ;
}

void CEmployee::Display()
{
	cout << "姓名：" << m_stEmp.szName << '\t';
	cout << "部门：" << m_stEmp.szSection << '\t';
	cout << "职务：" << m_stEmp.szPost << '\t';
	cout << "签到情况：" ;
	Show();

	return ;
}

void CEmployee::ShowName()
{
	cout << "姓名：" << m_stEmp.szName << '\t';
	cout << "签到情况：";
	Show();

	return ;
}

char* CEmployee::GetName()
{
	return m_stEmp.szName;
}

void CEmployee::AmName(char* _szName)
{
	strcpy(m_stEmp.szName, _szName);
}


void CEmployee::AmszPost(char* _pszch)
{
	strcpy(m_stEmp.szPost, _pszch);

	return ;
}

void CEmployee::AmszSection(char* _pszch)
{
	strcpy(m_stEmp.szSection, _pszch);

	return ;
}

void CEmployee::AmSign(int _nNum)
{
	switch(_nNum)
	{
	case 0:
		m_stEmp.emEmploy = Null;
		break;
	case 1:
		m_stEmp.emEmploy = Sign;
		break;
	case 2:
		m_stEmp.emEmploy = Sick;
		break;
	case 3:
		m_stEmp.emEmploy = Thing;
		break;
	case 4:
		m_stEmp.emEmploy = Skip;
		break;
	default:
		cout << "系统问题" << endl;
		break;
	}
}


char* CEmployee::GetPost()
{
	return m_stEmp.szPost;
}

char* CEmployee::GetSection()
{
	return m_stEmp.szSection;
}

int CEmployee::GetSign()
{
	return m_stEmp.emEmploy;
}

