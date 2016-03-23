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
		cout << "你输入的操作码错误，请重新输入!" << endl;
		cout << endl << endl << endl;
		cout << "按任意键继续~" << endl;
		getch();
		break;
	}
}


void CUser::Show()
{
	Clean();
	cout << "\n\n";
	cout << "a、添加员工\n";
	cout << "b、员工签到\n";
	cout << "c、员工病假\n";
	cout << "d、员工事假\n";
	cout << "e、查看员工基本情况\n";
	cout << "f、查看员工签到情况\n";
	cout << "g、查询员工签到情况\n";
	cout << "\n\n";

}

void CUser::Clean()
{
	system("cls");
}

void CUser::GetInPut()
{
	cout << "请选择，按'0'退出)" << endl;
	cin >> m_szch;
}

