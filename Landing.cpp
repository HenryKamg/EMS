#include <iostream>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "Landing.h"
#include "Cosnt.h"
#include "Admer.h"

using namespace std;

CLanding::CLanding()
{
	strcpy(m_szName, "");
	strcpy(m_szPassWord, "");
	m_nPop = USERPOPEDOM;
	m_pUser = NULL ;

	return;
}

CLanding::CLanding(char* _pszName, char* _pszPassWord, unsigned _Pop)
{
	strcpy(m_szName, _pszName);
	strcpy(m_szPassWord, _pszPassWord);
	m_nPop = _Pop;
	m_pUser = NULL;

	return ;
}

bool CLanding::operator ==(const CLanding& _obj)
{
	if(strcmp(m_szName, _obj.m_szName) == 0 && strcmp(m_szPassWord, _obj.m_szPassWord) == 0)
	{
		if(strcmp(m_szName, "侯占山") == 0)
		{
			m_nPop = ADM;
		}
		else
		{
			m_nPop = USERR;
		}
		return true;
	}

	return false;
}

void CLanding::In()
{
	int k = 0;
	int temp = 0;
	cout << "\n\n\n\n\n";
	cout << "\t\t  员工管理系统登陆界面\n\n";
	cout << "\t\t\t用户名:\t";
	cin >> m_szName;
	cout << "\n\n\t\t\t密码:\t";
	do
	{
		m_szPassWord[k] = getch();
		if(m_szPassWord[k] == 13)
		{
			break;
		}
		else if(m_szPassWord[k] == 8)
		{
			if(k != 0)
			{
				system("cls");
				--k;
				m_szPassWord[k] = '\0';
				Out();
				temp = k;
				while(temp)
				{
					printf("*");
					-- temp;
				}
			}
			else
			{
				m_szPassWord[k] = '\0';
			}
		}
		else
		{
			printf("*");
			++ k;
		}
	}while(1);
	m_szPassWord[k] = '\0';
	printf("\n"); 
}


void CLanding::Out()
{
	cout << "\n\n\n\n\n";
	cout << "\t\t  员工管理系统登陆界面\n\n";
	cout << "\t\t\t用户名:\t";
	cout << m_szName;
	cout << "\n\n\n\t\t\t密码:\t";
}

bool CLanding::IsLanding()
{
	for(int i=0; i< NUM; i++)
	{
		if(*this == obj[i])
		{
			Rest();
			system("cls");
			cout << "\n\n登陆成功!";
			cout << "\n\n";
			cout << "\n按任意键继续~";
			getch();

			return true;
		}
	}

	if(i == 2)
	{
		system("cls");
		cout << "\n\n你输入的用户名或密码错误! 登陆失败";
		cout << endl;
	}

	return false;
}

void CLanding::Init()
{
	In();
	if(IsLanding())
	{
		if((m_nPop ^ USERR) == ADMPOPEDOM)
		{
			m_pUser = new CAdmer;
			m_pUser->Show();
			m_pUser->Init();
		}
		else if((m_nPop ^ USERR) == USERPOPEDOM)
		{
			m_pUser = new CUser;
			m_pUser->Show();
			m_pUser->Init();
		}
		else
		{
			cout << "程序崩溃!" << endl;
		}
	}
}

void CLanding::Rest()
{
	cout << endl << endl << endl;
	cout << "密码验证中，请稍等......." ;
	Sleep(3000);
}