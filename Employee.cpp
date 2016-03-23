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
	char	szName[20];	// ����
	char	szSection[20];	// ����
	char	szPost[20];	// ְ��
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
	cout << "������������";
	cin >> m_stEmp.szName;
	cout << endl << "���ţ�";
	cin >> m_stEmp.szSection;
	cout << endl << "������ְ��";
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
		cout << m_stEmp.szName << "ǩ���ɹ�!" << endl;
	}
	else
	{
		cout << "���Ѿ�ǩ����!" << endl;
	}
	cout << endl << endl << "�����������~" ;
	getch();
	return ;
}

void CEmployee::SickFun()
{
	system("cls");
	if(m_stEmp.emEmploy == Null)
	{
		m_stEmp.emEmploy = Sick;
		cout << m_stEmp.szName << "�벡�ٱ���׼!" << endl;
	}
	else
	{
		cout << "���Ѿ�ǩ����!" << endl;
	}
	cout << endl << endl << "�����������~" ;
	getch();
	return ;
}

void CEmployee::ThingFun()
{
	system("cls");
	if(m_stEmp.emEmploy == Null)
	{
		m_stEmp.emEmploy = Thing;
		cout << m_stEmp.szName << "���¼ٱ���׼!" << endl;
	}
	else
	{
		cout << "���Ѿ�ǩ����!" << endl;
	}
	cout << endl << endl << "�����������~" ;
	getch();
	return ;
}

void CEmployee::SkipFun()
{
	system("cls");
	if(m_stEmp.emEmploy == Null)
	{
		m_stEmp.emEmploy = Skip;
		cout << m_stEmp.szName << "���������!" << endl;
	}
	else
	{
		cout << "���Ѿ�ǩ����!" << endl;
	}
	cout << endl << endl << "�����������~" ;
	getch();
	return ;
}

void CEmployee::Show()
{
	switch(m_stEmp.emEmploy)
	{
	case Null:
		cout<< "δǩ" << endl << endl;
		break;

	case Sign:
		cout<< "ǩ��" << endl << endl;
		break;

	case Sick:
		cout<< "����" << endl << endl;
		break;

	case Thing:
		cout<< "�¼�" << endl << endl;
		break;

	case Skip:
		cout<< "����" << endl << endl;
		break;
	}

	return ;
}

void CEmployee::Display()
{
	cout << "������" << m_stEmp.szName << '\t';
	cout << "���ţ�" << m_stEmp.szSection << '\t';
	cout << "ְ��" << m_stEmp.szPost << '\t';
	cout << "ǩ�������" ;
	Show();

	return ;
}

void CEmployee::ShowName()
{
	cout << "������" << m_stEmp.szName << '\t';
	cout << "ǩ�������";
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
		cout << "ϵͳ����" << endl;
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

