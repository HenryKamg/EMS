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
		if(strcmp(m_szName, "��ռɽ") == 0)
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
	cout << "\t\t  Ա������ϵͳ��½����\n\n";
	cout << "\t\t\t�û���:\t";
	cin >> m_szName;
	cout << "\n\n\t\t\t����:\t";
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
	cout << "\t\t  Ա������ϵͳ��½����\n\n";
	cout << "\t\t\t�û���:\t";
	cout << m_szName;
	cout << "\n\n\n\t\t\t����:\t";
}

bool CLanding::IsLanding()
{
	for(int i=0; i< NUM; i++)
	{
		if(*this == obj[i])
		{
			Rest();
			system("cls");
			cout << "\n\n��½�ɹ�!";
			cout << "\n\n";
			cout << "\n�����������~";
			getch();

			return true;
		}
	}

	if(i == 2)
	{
		system("cls");
		cout << "\n\n��������û������������! ��½ʧ��";
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
			cout << "�������!" << endl;
		}
	}
}

void CLanding::Rest()
{
	cout << endl << endl << endl;
	cout << "������֤�У����Ե�......." ;
	Sleep(3000);
}