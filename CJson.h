#pragma once

#include "CIOManager.h"

class CJson : public CIOManager
{
public:
	CJson();
	~CJson();

	virtual void Load(LPSTR szAddress, IO_TYPE type);

	virtual void Read();

	virtual void Write();

	virtual void Close();
};

