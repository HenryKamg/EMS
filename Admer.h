#include "User.h"
#ifndef ADMER_H
#define AMDER_H

class CAdmer : public CUser
{
public:
	~CAdmer();
	virtual void Show();
	virtual void Operate();
	static void Display();
};

#endif