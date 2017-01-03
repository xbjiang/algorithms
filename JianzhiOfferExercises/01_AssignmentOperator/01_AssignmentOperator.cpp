// 01_AssignmentOperator.cpp : 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include <string>

class CMyString
{
public:
	CMyString(char* pData = NULL);
	CMyString(const CMyString& str);
	CMyString& operator = (const CMyString& str);
	~CMyString(void);
	void Print();
private:
	char* m_pData;
};

CMyString::CMyString(char* pData)
{
	if (pData == NULL)
	{
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else
	{
		m_pData = new char[strlen(pData) + 1];
		strncpy(m_pData, pData, strlen(pData)+1);
	}
}

CMyString::CMyString(const CMyString& str)
{
	m_pData = new char[strlen(str.m_pData) + 1];
	strncpy(m_pData, str.m_pData, strlen(str.m_pData)+1);
}

CMyString& CMyString::operator = (const CMyString& str)
{
	if (this == &str)
		return *this;
	
	delete[] m_pData;
	m_pData = NULL;

	m_pData = new char[strlen(str.m_pData) + 1];
	strncpy(m_pData, str.m_pData, strlen(str.m_pData)+1);
	return *this;
}

CMyString::~CMyString()
{
	delete[] m_pData;
}

//-----------测试部分----------
void CMyString::Print()
{
	printf("%s", m_pData);
}

void test1()
{
	printf("Test1 begins:\n");
	
	char* text = "Hello world!";
	
	CMyString str1(text);
	CMyString str2;
	
	str2 = str1;
	
	printf("The expected result is :%s\n", text);
	printf("The actual result is :");
	str2.Print();
	printf("\n");
}

void test2()
{
	printf("Test2 begins:\n");
	
	char* text = "Hello world!";
	CMyString str1(text);
	str1 = str1;
	
	printf("The expected result is :%s\n", text);
	printf("The actual result is :");
	str1.Print();
	printf("\n");
}

void test3()
{
	printf("Test3 begins:\n");
	
	char* text = "Hello world!";
	CMyString str1(text);
	CMyString str2, str3;
	str2 = str3 = str1;
	
	printf("The expected result is :%s\n", text);
	printf("The actual result is :");
	str2.Print();
	printf("\n");
	
	printf("The expected result is :%s\n", text);
	printf("The actual result is :");
	str3.Print();
	printf("\n");

}


int _tmain(int argc, _TCHAR* argv[])
{
	test1();
	test2();
	test3();
	return 0;
}

