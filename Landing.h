#include "User.h"
#ifndef _LANDING_H
#define _LANDING_H

class CLanding
{
public:
	CLanding();
	CLanding(char *_pszName, char *_pszPassWord, unsigned _Pop);
	void Init();
	void In();
	void Out();
	bool operator ==(const CLanding& _obj);
	bool IsLanding();
	void Rest();
private:
	char m_szName[20];
	char m_szPassWord[20];
	unsigned m_nPop;
	CUser *m_pUser;
};

#endif