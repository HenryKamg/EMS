#include "CSupervise.h"

#ifndef USER_H
#define USER_H

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

#endif