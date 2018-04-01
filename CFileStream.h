#pragma once
#include "CIOManager.h"

class CFileStream :
	public CIOManager
{
public:
	CFileStream();
	~CFileStream();

	virtual void Load(LPSTR szAddress, IO_TYPE type);

	virtual void Read();

	virtual void Write();
		
	virtual void Close();

private:
	string m_data;
	fstream m_IO;
};

