#include "Employee.h"

#ifndef CSUPERVISE_H
#define CSUPERVISE_H

class CSupervise
{
public:
	CSupervise();
	~CSupervise();
	void AddNew();
	void Del();
	void OutPut();
	void ShowSign();
	void FindName();
	void Amend();
	void Save();
	void Free();
	CEmployee* Find(char* _pszName);
	CEmployee* Find();
private:
	void Load();
	CEmployee *m_pHead;
	CEmployee *m_pFirst;
	CEmployee *m_pLast;
};

#endif