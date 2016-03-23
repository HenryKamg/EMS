#include <iostream>
#include "Admer.h"
using namespace std;

CAdmer::~CAdmer()
{
	delete m_pSuper;
	m_pSuper = NULL;
}

void CAdmer::Operate()
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
		pTmp = m_pSuper->Find();
		if(pTmp)
		{
			pTmp->SkipFun();
		}
		break;
		
	case 'f':
		m_pSuper->Del();
		break;
		
	case 'g':
		m_pSuper->OutPut();
		break;
		
	case 'h':
		m_pSuper->ShowSign();
		break;
		
	case 'i':
		m_pSuper->FindName();
		break;
		
	case 'j':
		m_pSuper->Amend();
		break;
		
	case 'k':
		m_pSuper->Save();
		break;
	}
	
}

void CAdmer::Show()
{
	Clean();
	cout << "\t\t★★★★★★★★★★★★★★★★★★★★★★\n";
	cout << "\t\t★★\t\ta、添加员工\t\t★★\n";
	cout << "\t\t★★\t\tb、员工签到\t\t★★\n";
	cout << "\t\t★★\t\tc、员工病假\t\t★★\n";
	cout << "\t\t★★\t\td、员工事假\t\t★★\n";
	cout << "\t\t★★\t\te、员工旷工\t\t★★\n";
	cout << "\t\t★★\t\tf、员工辞职\t\t★★\n";
	cout << "\t\t★★\t\tg、查看员工基本情况\t★★\n";
	cout << "\t\t★★\t\th、查看员工签到情况\t★★\n";
	cout << "\t\t★★\t\ti、根据姓名查询签到情况\t★★\n";
	cout << "\t\t★★\t\tj、修改员工信息\t\t★★\n";
	cout << "\t\t★★\t\tk、保存信息到文件\t★★\n";
	cout << "\t\t★★★★★★★★★★★★★★★★★★★★★★\n";

	return;
}

void CAdmer::Display()
{
	system("cls");
	cout << "\n";
	cout << "\t\t★★★★★★★★★★★★★★★★★★★★★★\n";
	cout << "\t\t★★\t\ta、修改性别\t\t★★\n";
	cout << "\t\t★★\t\tb、修改民族\t\t★★\n";
	cout << "\t\t★★\t\tc、修改学历\t\t★★\n";
	cout << "\t\t★★\t\td、修改出生时间\t\t★★\n";
	cout << "\t\t★★\t\te、修改到职日期\t\t★★\n";
	cout << "\t\t★★\t\tf、修改籍贯\t\t★★\n";
	cout << "\t\t★★\t\tg、修改部门\t\t★★\n";
	cout << "\t\t★★\t\th、修改职务\t\t★★\n";
	cout << "\t\t★★\t\ti、修改住址\t\t★★\n";
	cout << "\t\t★★★★★★★★★★★★★★★★★★★★★★\n";

	return ;
}