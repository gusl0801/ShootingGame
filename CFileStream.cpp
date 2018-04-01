#include "stdafx.h"
#include "CFileStream.h"


CFileStream::CFileStream()
{
}


CFileStream::~CFileStream()
{
	if (m_IO) m_IO.close();
}

void CFileStream::Load(LPSTR szAddress, IO_TYPE type)
{
	m_IO.open(szAddress);
}

void CFileStream::Read()
{
	while (m_IO >> m_data)
		cout << m_data;
	cout << endl;
}

void CFileStream::Write()
{
	
}

void CFileStream::Close()
{
	m_IO.close();
}
