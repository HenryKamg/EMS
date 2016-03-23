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
	FILE *pFile = fopen("员工信息.txt", "r");
	if(!pFile)
	{
		cout << "无文件被加载" << endl;
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
	ifstream in("员工信息.txt");

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
	ifstream in("员工.txt");
	if(in.fail())
	{
		cout << "读取文件失败" << endl;
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
			cout << "按任意键显示下一页" << endl;
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
	FILE *pFile = fopen("员工信息.txt", "w");
	if(!pFile)
	{
		cout << "打开文件错误，写入失败!" << endl;
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
	cout << "保存文件成功!" << endl;
	cout << endl << endl ;
	system("PAUSE");
	return ;
}
*/

/*
void CSupervise::Save()
{
	ofstream out("员工信息.txt");
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
	cout << "保存文件成功!" << endl;
	cout << endl << endl ;
	system("PAUSE");
	return ;
}*/

void CSupervise::Save()
{
	ofstream out("员工.txt");
	if(out.fail())
	{
		cout << "保存文件失败!" << endl;
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
	cout << "保存文件成功!" << endl;
	cout << endl << endl ;
	system("PAUSE");
	return ;
}

CEmployee* CSupervise::Find(char* _pszName)
{
	char szName[20];
	cout << "输入要查询员工的姓名：";
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
	cout << "请输入员工的姓名：";
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
	cout << "公司没有" << szName << "这个人!" << endl;
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
		cout << "请输入操作码：" << endl;
		cin >> szch;
		switch(szch[0])
		{
		case 'a':
			cout << "请输入你要修改的性别：" << endl;
			cin >> szTemp;
			pTmp->AmSex(szTemp);
			break;
			
		case 'b':
			cout << "请输入你要修改的民族：" << endl;
			cin >> szTemp;
			pTmp->AmszNation(szTemp);
			break;
			
		case 'c':
			cout << "请输入你要修改的学历：" << endl;
			cin >> szTemp;
			pTmp->AmszSchoolRecord(szTemp);
			break;
			
		case 'd':
			cout << "请输入你要修改的出生日期(格式：年 月 日)：" << endl;
			cin >> nYear >> nMonth >> nDay ;
			pTmp->AmBorn(nYear, nMonth, nDay);
			break;
			
		case 'e':
			cout << "请输入你要修改的到职日期(格式：年 月 日)：" << endl;
			cin >> nYear >> nMonth >> nDay ;
			pTmp->AmBorn(nYear, nMonth, nDay);
			break;
			
		case 'f':
			cout << "请输入你要修改的籍贯：" << endl;
			cin >> szTemp;
			pTmp->AmszNativePlace(szTemp);
			break;
			
		case 'g':
			cout << "请输入你要修改的部门：" << endl;
			cin >> szTemp;
			pTmp->AmszSection(szTemp);
			break;
			
		case 'i':
			cout << "请输入你要修改的职务：" << endl;
			cin >> szTemp;
			pTmp->AmszPost(szTemp);
			break;
			
		case 'j':
			cout << "请输入你要修改的地址：" << endl;
			cin >> szTemp;
			pTmp->AmszAddress(szTemp);
			break;

		default:
			cout << "你输入的操作码错误, 请重新输入!" << endl;
			break;
		}
	}
	else
	{
		cout << "没有找到这个员工!" << endl;
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
		cout << "公司没有" << szName << "这个人!" << endl;
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
	cout << "请输入被辞退员工的姓名：";
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
			cout << "员工" << szName << "辞退成功!" << endl;

			delete m_pFirst;
			m_pFirst = NULL;
		}
	}
	else
	{
		system("cls");
		cout << "公司内还没有员工，请添加员工!" << endl;
	}

	system("PAUSE");
}