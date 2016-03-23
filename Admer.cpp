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
	cout << "\t\t�����������������������\n";
	cout << "\t\t���\t\ta�����Ա��\t\t���\n";
	cout << "\t\t���\t\tb��Ա��ǩ��\t\t���\n";
	cout << "\t\t���\t\tc��Ա������\t\t���\n";
	cout << "\t\t���\t\td��Ա���¼�\t\t���\n";
	cout << "\t\t���\t\te��Ա������\t\t���\n";
	cout << "\t\t���\t\tf��Ա����ְ\t\t���\n";
	cout << "\t\t���\t\tg���鿴Ա���������\t���\n";
	cout << "\t\t���\t\th���鿴Ա��ǩ�����\t���\n";
	cout << "\t\t���\t\ti������������ѯǩ�����\t���\n";
	cout << "\t\t���\t\tj���޸�Ա����Ϣ\t\t���\n";
	cout << "\t\t���\t\tk��������Ϣ���ļ�\t���\n";
	cout << "\t\t�����������������������\n";

	return;
}

void CAdmer::Display()
{
	system("cls");
	cout << "\n";
	cout << "\t\t�����������������������\n";
	cout << "\t\t���\t\ta���޸��Ա�\t\t���\n";
	cout << "\t\t���\t\tb���޸�����\t\t���\n";
	cout << "\t\t���\t\tc���޸�ѧ��\t\t���\n";
	cout << "\t\t���\t\td���޸ĳ���ʱ��\t\t���\n";
	cout << "\t\t���\t\te���޸ĵ�ְ����\t\t���\n";
	cout << "\t\t���\t\tf���޸ļ���\t\t���\n";
	cout << "\t\t���\t\tg���޸Ĳ���\t\t���\n";
	cout << "\t\t���\t\th���޸�ְ��\t\t���\n";
	cout << "\t\t���\t\ti���޸�סַ\t\t���\n";
	cout << "\t\t�����������������������\n";

	return ;
}