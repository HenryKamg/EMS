#include <iostream>
using namespace std;

class CUser
{
public:
	virtual ~CUser();
	void Init();
	virtual void Show();
	virtual void Operate();
	void Clean();
	void GetInPut();
protected:
	char m_szch[20];
	CSupervise *m_pSuper;
};

CUser::~CUser()
{
	delete m_pSuper;
}

void CUser::Operate()
{
	CEmployee *pTmp = NULL;
	switch(m_szch[0])
	{
	case 'a':
		m_pSuper->AddNew();
		break;

	case 'b':
		pTmp = m_pSuper->Find();
		if(pTmp)
		{
			pTmp->SignFun();
		}
		break;

	case 'c':
		pTmp = m_pSuper->Find();
		if(pTmp)
		{
			pTmp->SickFun();
		}
		break;

	case 'd':
		pTmp = m_pSuper->Find();
		if(pTmp)
		{
			pTmp->ThingFun();
		}
		break;

	case 'e':
		m_pSuper->OutPut();
		break;

	case 'f':
		m_pSuper->ShowSign();
		break;

	case 'g':
		m_pSuper->FindName();
		break;

	default:
		Clean();
		cout << "������Ĳ������������������!" << endl;
		cout << endl << endl << endl;
		cout << "�����������~" << endl;
		getch();
		break;
	}
}


void CUser::Show()
{
	Clean();
	cout << "\n\n";
	cout << "a�����Ա��\n";
	cout << "b��Ա��ǩ��\n";
	cout << "c��Ա������\n";
	cout << "d��Ա���¼�\n";
	cout << "e���鿴Ա���������\n";
	cout << "f���鿴Ա��ǩ�����\n";
	cout << "g����ѯԱ��ǩ�����\n";
	cout << "\n\n";

}

void CUser::Clean()
{
	system("cls");
}

void CUser::GetInPut()
{
	cout << "��ѡ�񣬰�'0'�˳�)" << endl;
	cin >> m_szch;
}

