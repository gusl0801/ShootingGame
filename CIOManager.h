#pragma once

enum class IO_TYPE
{
	Read = 0,
	Write = 1
};
	
class CIOManager
{
public:
	CIOManager();
	virtual ~CIOManager();

	virtual void Load(LPSTR szAddress, IO_TYPE type) = 0;

	virtual void Read() = 0;

	virtual void Write() = 0;

	virtual void Close() = 0;
};

