#pragma once

#include "CGameObject.h"

class CObjectManager
{
public:
	CObjectManager() {}
	~CObjectManager() { if (!m_objects.empty()) m_objects.clear(); }

	void AddObject(CGameObject* object) { if (object) m_objects.emplace_back(object); }
	
	void Update() { for (CGameObject* object : m_objects) object->Update(); }
	void Draw(HDC hdc) { for (CGameObject* object : m_objects) object->Draw(hdc);}
	void CheckDelete() 
	{
		m_objects.erase(remove_if(m_objects.begin(), m_objects.end(),
			[](CGameObject* object) {return object->IsDelete(); }), m_objects.end());
	}
	void CheckCollision() {}

private:
	vector<CGameObject*> m_objects;
};

