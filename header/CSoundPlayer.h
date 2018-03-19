#pragma once

/*
�ۼ��� : 2018-03-18
���� : ���� ���� ���õ� ����� ó���ϴ� Ŭ�����Դϴ�.
������ �ۼ��ص� �ڵ带 �״�� �����Ա⿡ ���� ������ �ʿ��մϴ�.
*/

#pragma comment (lib, "lib/fmodex_vc.lib")

#include "inc/fmod.h"
#include "inc/fmod.hpp"
#include "inc/fmod_errors.h"

typedef enum
{
	SOUND_BGM = 0
	, SOUND_EFFECT
	, SOUND_COUNT
}SoundType;

enum class Sound_Name : int
{
	BGM_TITLE = 0,
};

class CSoundManager
{
public:		//������, �Ҹ���
	CSoundManager();
	~CSoundManager();

public:		//���� �߰�
	
	void AddStream(const char*  szPath, Sound_Name varName);	//��������� �߰��մϴ�.
	void AddSound(const char*  szPath, Sound_Name varName);	//ȿ������ �߰��մϴ�.

public:		//���� ���
	void OnUpdate();					//���� ����� ������ �ʵ��� �մϴ�.

	void PlayBgm(Sound_Name varName);		//��������� ����մϴ�.
	void PlayEffect(Sound_Name varName);	//ȿ������ ����մϴ�.

	void Stop();		//���� ����� �����մϴ�.
	void SetVolume(float volume);	//������ ũ�⸦ �����մϴ�.
public:		//��Ÿ
	FMOD_SOUND * FindSound(Sound_Name key);	//�ش� Ű ���� �̹� ��� �Ǿ� �ִ����� ã���ϴ�.
private:
	float m_fVolume;	//���� ����� ���� ũ�⸦ �����մϴ�.

	FMOD_SYSTEM *  m_pSystem;
	FMOD_CHANNEL * m_pChannel[SoundType::SOUND_COUNT];

	std::map <Sound_Name, FMOD_SOUND* > m_mapSound;
};

