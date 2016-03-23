#ifndef EMPLOYEE_H
#define	EMPLOYEE_H
#include <fstream>
using namespace std;

enum SIGNIN{Null = 0, Sign, Sick, Thing, Skip};

typedef struct TIME
{
	int nYear;
	int nMonth;
	int nDay;
}DATA;


typedef struct PERSON
{
	char	szSex[5];	// 性别
	char	szNation[10];	// 民族
	char	szSchoolRecord[10];	// 学历
	DATA	stBorn;	// 出生时间
	DATA	stEOD;	// 到职日期
	char	szName[20];	// 姓名
	char	szNativePlace[20];	// 籍贯
	char	szSection[20];	// 部门
	char	szPost[20];	// 职务
	char	szAddress[25];	// 住址
	SIGNIN emEmploy;
}Employ;


class CEmployee
{
public:
	CEmployee();
	~CEmployee();
	void Init();
	void SignFun(); // 签到
	void SickFun(); // 病假
	void ThingFun(); // 事假
	void SkipFun(); // 矿工
	void Display();
	void ShowName();
	char* GetName();
	char* GetSex();
	char* GetNation();
	char* GetSchoolRecord();
	char* GetNativePlace();
	char* GetSection();
	char* GetPost();
	char* GetAddress();
	int GetYear() const;
	int GetMont() const;
	int GetDay() const;
	int GetY() const;
	int GetM() const;
	int GetD() const;
	int GetSign();
	CEmployee * next;
	void AmName(char*);
	void AmSex(char*);
	void AmszNation(char*);
	void AmszSchoolRecord(char*);
	void AmBorn(int, int, int);
	void AmEOD(int, int, int);
	void AmszNativePlace(char*);
	void AmszSection(char*);
	void AmszPost(char*);
	void AmszAddress(char*);
	void AmSign(int);
	friend istream& operator >>(istream& _in, CEmployee& _obj);	
	friend ostream& operator <<(ostream& _out,  CEmployee& _obj);
private:
	void Show();
	Employ m_stEmp;
};


#endif