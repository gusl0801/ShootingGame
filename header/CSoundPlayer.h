#pragma once

/*
작성일 : 2018-03-18
설명 : 음악 파일 관련된 기능을 처리하는 클래스입니다.
기존에 작성해둔 코드를 그대로 가져왔기에 추후 수정이 필요합니다.
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
public:		//생성자, 소멸자
	CSoundManager();
	~CSoundManager();

public:		//사운드 추가
	
	void AddStream(const char*  szPath, Sound_Name varName);	//배경음악을 추가합니다.
	void AddSound(const char*  szPath, Sound_Name varName);	//효과음을 추가합니다.

public:		//사운드 재생
	void OnUpdate();					//사운드 재생이 끊기지 않도록 합니다.

	void PlayBgm(Sound_Name varName);		//배경음악을 재생합니다.
	void PlayEffect(Sound_Name varName);	//효과음을 재생합니다.

	void Stop();		//사운드 재생을 중지합니다.
	void SetVolume(float volume);	//사운드의 크기를 조절합니다.
public:		//기타
	FMOD_SOUND * FindSound(Sound_Name key);	//해당 키 값이 이미 등록 되어 있는지를 찾습니다.
private:
	float m_fVolume;	//사운드 재생할 때의 크기를 지정합니다.

	FMOD_SYSTEM *  m_pSystem;
	FMOD_CHANNEL * m_pChannel[SoundType::SOUND_COUNT];

	std::map <Sound_Name, FMOD_SOUND* > m_mapSound;
};

