#include "stdafx.h"
#include "CJson.h"


CJson::CJson()
{
}

CJson::~CJson()
{
}

void CJson::Load(LPSTR szAddress, IO_TYPE type)
{
	fopen_s(&m_file,"szAddress", "rb"); // non-Windows use "r"
	rapidjson::FileReadStream fileStream(m_file, m_readBuffer, sizeof(m_readBuffer));
	m_document.ParseStream(fileStream);	// == m_document.Parse(fileStream);
	fclose(m_file);
}

void CJson::Read()
{	
	//assert(m_document.HasMember("hp"));
	//assert(m_document["hp"].IsInt());
	//m_nHp = m_document["hp"].GetInt();
	//
	//assert(m_document.HasMember("mp"));
	//assert(m_document["mp"].IsInt());
	//m_nMp = m_document["mp"].GetInt();
	//
	//assert(m_document.HasMember("x"));
	//assert(m_document["x"].IsInt());
	//m_nXpos = m_document["x"].GetInt();
	//
	//assert(m_document.HasMember("y"));
	//assert(m_document["y"].IsInt());
	//m_nYPos = m_document["y"].GetInt();
	//
	//assert(m_document.HasMember("attack"));
	//assert(m_document["attack"].IsInt());
	//m_nAttack = m_document["attack"].GetInt();
	//
	//assert(m_document.HasMember("defense"));
	//assert(m_document["defense"].IsInt());
	//m_nDefense = m_document["defense"].GetInt();
	//
	//m_nAttribute = (m_document["attribute"]["first"].GetInt());
}

void CJson::Write()
{
}

void CJson::Close()
{
}
