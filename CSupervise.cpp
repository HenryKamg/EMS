#include <iostream>
#include <string>
#include <string.h>
#include <conio.h>
#include <fstream>
#include "CSupervise.h"
#include "Employee.h"
#include "Admer.h"
using namespace std;

CSupervise::CSupervise()
{
	m_pFirst = NULL;
	m_pHead = NULL;
	m_pLast = NULL;
	Load();

	return ;
}

CSupervise::~CSupervise()
{

}

void CSupervise::Free()
{
	CEmployee *m_pTemp = NULL;
	
	while(m_pHead != NULL)
	{
		m_pTemp = m_pHead;
		m_pHead = m_pHead->next;
		delete m_pTemp;
	}

	return ;
}
/*
void CSupervise::Load()
{
	FILE *pFile = fopen("Ա����Ϣ.txt", "r");
	if(!pFile)
	{
		cout << "���ļ�������" << endl;
		getch();
		return ;
	}
	while(!feof(pFile))
	{
		
		
		if(m_pHead == NULL)
		{
			m_pFirst = m_pLast = new CEmployee;
			fread(m_pFirst, sizeof(CEmployee), 1, pFile);
			m_pHead = m_pFirst;
		}
		else
		{
			m_pLast->next = m_pFirst;
			m_pLast = m_pFirst;
			m_pFirst = new CEmployee;
			fread(m_pFirst, sizeof(CEmployee), 1, pFile);
		}
	}
	m_pLast->next = NULL;

	fclose(pFile);
	return;
}
*/

/*
void CSupervise::Load()
{
	ifstream in("Ա����Ϣ.txt");

	if(in.fail())
	{
		return;
	}

	while(!in.eof())
	{
		if(m_pHead == NULL)
		{
			m_pFirst = m_pLast = new CEmployee;
			in >> *m_pFirst;
			m_pHead = m_pFirst;
		}
		else
		{
			m_pLast->next = m_pFirst;
			m_pLast = m_pFirst;
			m_pFirst = new CEmployee;
			in >> *m_pFirst;
		}
	}
	m_pLast->next = NULL;
	
	in.close();
	return ;
}
*/

void CSupervise::Load()
{
	ifstream in("Ա��.txt");
	if(in.fail())
	{
		cout << "��ȡ�ļ�ʧ��" << endl;
		system("pause");
		return ;
	}

	int nNum = 1;
	while(nNum > 0)
	{
		if(m_pHead == NULL)
		{
			m_pFirst = m_pLast = new CEmployee;
			in.read((char*)m_pFirst, sizeof(CEmployee));
			m_pHead = m_pFirst;
		}
		else
		{
			m_pLast->next = m_pFirst;
			m_pLast = m_pFirst;
			m_pFirst = new CEmployee;
			in.read((char*) m_pFirst, sizeof(CEmployee));
		}
		nNum = in.gcount();
	}

	m_pLast->next = NULL;

	in.close();

	return ;
}


void CSupervise::AddNew()
{
	CEmployee *pTemp = new CEmployee;
	pTemp->Init();

	if(m_pHead == NULL)
	{
		m_pHead = pTemp;
	}
	else
	{
		pTemp->next = m_pHead;
		m_pHead = pTemp;
	}

	return ;
}

void CSupervise::OutPut()
{
	CEmployee* pTemp = m_pHead;
	int nNum = 0;

	system("cls");
	while(pTemp != NULL)
	{
		pTemp->Display();
		++ nNum;
		pTemp = pTemp->next;
		if(nNum >= 4 && nNum % 4 == 0 && pTemp != NULL)
		{
			cout << "���������ʾ��һҳ" << endl;
			getch();
			system("cls");
		}
	}

	system("PAUSE");
	return ;
}

/*
void CSupervise::Save()
{
	FILE *pFile = fopen("Ա����Ϣ.txt", "w");
	if(!pFile)
	{
		cout << "���ļ�����д��ʧ��!" << endl;
		return ;
	}

	CEmployee *pTemp = m_pHead;
	
	while(pTemp != NULL)
	{
		fwrite(pTemp, sizeof(CEmployee), 1, pFile);
		pTemp = pTemp->next;
	}

	fclose(pFile);
	system("cls");
	cout << "�����ļ��ɹ�!" << endl;
	cout << endl << endl ;
	system("PAUSE");
	return ;
}
*/

/*
void CSupervise::Save()
{
	ofstream out("Ա����Ϣ.txt");
	if(out.fail())
	{
		return ;
	}

	CEmployee* pTemp = m_pHead;
	while(pTemp != NULL)
	{
		out << *pTemp;
		pTemp = pTemp->next;
	}
	out.close();
	system("cls");
	cout << "�����ļ��ɹ�!" << endl;
	cout << endl << endl ;
	system("PAUSE");
	return ;
}*/

void CSupervise::Save()
{
	ofstream out("Ա��.txt");
	if(out.fail())
	{
		cout << "�����ļ�ʧ��!" << endl;
		getch();
		return ;
	}

	CEmployee* pTmp = m_pHead;

	while(pTmp != NULL)
	{
		out.write((char*)pTmp, sizeof(CEmployee));
		pTmp = pTmp->next;
	}
	out.close();
	system("cls");
	cout << "�����ļ��ɹ�!" << endl;
	cout << endl << endl ;
	system("PAUSE");
	return ;
}

CEmployee* CSupervise::Find(char* _pszName)
{
	char szName[20];
	cout << "����Ҫ��ѯԱ����������";
	cin >> szName;

	CEmployee *pTemp = m_pHead;

	while(pTemp != NULL)
	{
		if(strcmp(szName, pTemp->GetName()) == 0)
		{
			strcpy(_pszName, szName);
			return pTemp;
		}
		pTemp = pTemp->next;
	}

	strcpy(_pszName, szName);
	return NULL;
}

CEmployee* CSupervise::Find()
{
	char szName[20];
	cout << "������Ա����������";
	cin >> szName;

	CEmployee *pTemp = m_pHead;

	while(pTemp != NULL)
	{
		if(strcmp(szName, pTemp->GetName()) == 0)
		{
			return pTemp;
		}
		pTemp = pTemp->next;
	}
	cout << "��˾û��" << szName << "�����!" << endl;
	return NULL;
}


void CSupervise::Amend()
{
	char szch[20] = "";
	char szTemp[20] = "";
	int nYear = 0;
	int nMonth = 0;
	int nDay = 0;

	CEmployee* pTmp = Find();
	CAdmer::Display();
	if(pTmp)
	{
		cout << "����������룺" << endl;
		cin >> szch;
		switch(szch[0])
		{
		case 'a':
			cout << "��������Ҫ�޸ĵ��Ա�" << endl;
			cin >> szTemp;
			pTmp->AmSex(szTemp);
			break;
			
		case 'b':
			cout << "��������Ҫ�޸ĵ����壺" << endl;
			cin >> szTemp;
			pTmp->AmszNation(szTemp);
			break;
			
		case 'c':
			cout << "��������Ҫ�޸ĵ�ѧ����" << endl;
			cin >> szTemp;
			pTmp->AmszSchoolRecord(szTemp);
			break;
			
		case 'd':
			cout << "��������Ҫ�޸ĵĳ�������(��ʽ���� �� ��)��" << endl;
			cin >> nYear >> nMonth >> nDay ;
			pTmp->AmBorn(nYear, nMonth, nDay);
			break;
			
		case 'e':
			cout << "��������Ҫ�޸ĵĵ�ְ����(��ʽ���� �� ��)��" << endl;
			cin >> nYear >> nMonth >> nDay ;
			pTmp->AmBorn(nYear, nMonth, nDay);
			break;
			
		case 'f':
			cout << "��������Ҫ�޸ĵļ��᣺" << endl;
			cin >> szTemp;
			pTmp->AmszNativePlace(szTemp);
			break;
			
		case 'g':
			cout << "��������Ҫ�޸ĵĲ��ţ�" << endl;
			cin >> szTemp;
			pTmp->AmszSection(szTemp);
			break;
			
		case 'i':
			cout << "��������Ҫ�޸ĵ�ְ��" << endl;
			cin >> szTemp;
			pTmp->AmszPost(szTemp);
			break;
			
		case 'j':
			cout << "��������Ҫ�޸ĵĵ�ַ��" << endl;
			cin >> szTemp;
			pTmp->AmszAddress(szTemp);
			break;

		default:
			cout << "������Ĳ��������, ����������!" << endl;
			break;
		}
	}
	else
	{
		cout << "û���ҵ����Ա��!" << endl;
	}
}

void CSupervise::FindName()
{
	char szName[20] = "";
	system("cls");
	CEmployee* pTmp = Find(szName);

	if(pTmp != NULL)
	{
		pTmp->Display();
	}
	else
	{
		cout << "��˾û��" << szName << "�����!" << endl;
	}

	system("PAUSE");
	return ;
}

void CSupervise::ShowSign()
{
	CEmployee* pTmp = m_pHead;

	system("cls");
	while(pTmp != NULL)
	{
		pTmp->ShowName();
		pTmp = pTmp->next;
	}

	system("PAUSE");
	return ;
}

void CSupervise::Del()
{
	char szName[20] = "";
	cout << "�����뱻����Ա����������";
	cin >> szName;
	m_pFirst = m_pHead;

	if(m_pFirst != NULL)
	{
		while(strcmp(m_pFirst->GetName(), szName) != 0 && m_pFirst->next != NULL)
		{
			m_pLast = m_pFirst;
			m_pFirst = m_pFirst->next;
		}
		if(strcmp(m_pFirst->GetName(), szName) == 0)
		{
			if(m_pFirst == m_pHead)
			{
				m_pHead = m_pFirst->next;
			}
			else
			{
				m_pLast->next = m_pFirst->next;
			}
			system("cls");
			cout << "Ա��" << szName << "���˳ɹ�!" << endl;

			delete m_pFirst;
			m_pFirst = NULL;
		}
	}
	else
	{
		system("cls");
		cout << "��˾�ڻ�û��Ա���������Ա��!" << endl;
	}

	system("PAUSE");
}