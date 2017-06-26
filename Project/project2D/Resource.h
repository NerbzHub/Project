#pragma once
#include <string.h>


template <typename T>
class Resource
{
public:
	Resource(char* szFilename)
	{
		int length = strlen(szFilename);
		m_szFilename = new char[length + 1];
		strcpy_s(m_szFilename, length, szFilename);


		m_pData = new T(szFilename);
	}

	~Resource()
	{
		delete m_Data;
		delete[] m_szFilename;
	}

	char* m_szFilename;
	T* m_pData;
};