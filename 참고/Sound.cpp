#include "stdafx.h"
#include "Sound.h"

#define SOUNDMGR SoundManager::GetInstance()

//Create & Destory
SoundManager::SoundManager()
{
	System_Create(&g_pSystem);
	g_pSystem->init(64, FMOD_INIT_NORMAL, 0);
}

SoundManager::~SoundManager()
{
	g_pSystem->release();
	g_pSystem->close();
}

//Load
void SoundManager::LoadSound()
{
	////char
	//AddStrem("../Resource/Sound/BGM/GamePlaying.mp3", "게임중");
	//AddStrem("../Resource/Sound/BGM/Select.mp3", "메뉴화면");
	//
	//AddSound("../Resource/Sound/BGM/loding33.wav", "로딩띠리링");
	//AddSound("../Resource/Sound/EFFECT/Jump.wav", "점프");
	//AddSound("../Resource/Sound/EFFECT/Stomp.wav", "아이템사용");
	//AddSound("../Resource/Sound/EFFECT/getCoin.wav", "몬스터획득");
	//AddSound("../Resource/Sound/EFFECT/btn.wav", "마우스드래그");
	//AddSound("../Resource/Sound/EFFECT/BtnCLick.wav", "마우스클릭");
	//AddSound("../Resource/Sound/EFFECT/ShowDialog.wav", "다이어로그");
	//AddSound("../Resource/Sound/EFFECT/GameOver.wav", "게임오버");
	//AddSound("../Resource/Sound/EFFECT/start.wav", "스타트");
}

//Add
void SoundManager::AddSound(char* filePath, std::string name)
{
	auto pFindSound = this->FindSound(name);

	if (pFindSound != NULL)
		return;

	else
	{
		FMOD::Sound* sound;
		g_pSystem->createStream(filePath, FMOD_HARDWARE || FMOD_LOOP_NORMAL, 0, &sound);
		if (sound) m_pSound.insert(std::make_pair(name, sound));
		//else GlobalVar::GetInstance()->ErrorMessage(filePath, "경로가 잘못되었습니다");
		
	}

}

void SoundManager::AddStrem(char* filePath, std::string name)
{
	auto pFindSound = this->FindSound(name);

	if (pFindSound != NULL)
		return;

	else
	{
		FMOD::Sound* sound;
		g_pSystem->createSound(filePath, FMOD_HARDWARE || FMOD_LOOP_NORMAL, 0, &sound);
		if (sound) m_pSound.insert(std::make_pair(name, sound));
		//else GlobalVar::GetInstance()->ErrorMessage(filePath, "경로가 잘못되었습니다");
	}
}

//Find
FMOD::Sound* SoundManager::FindSound(std::string name)
{
	std::map<std::string, FMOD::Sound*>::iterator iter = m_pSound.find(name);

	if (iter == m_pSound.end())
	{
		//MessageBox(NULL,name.c_str(),"사운드가 없당",NULL);
		return NULL;
	}
	else
		return iter->second;
}


//Update
void SoundManager::OnUpdate()
{
	g_pSystem->update();
}


//Play

void SoundManager::PlayBGM(std::string name)
{
	g_pChannel[SOUND_BGM]->stop();
	g_pSystem->playSound(FMOD_CHANNEL_FREE, FindSound(name), false, &g_pChannel[SOUND_BGM]);
}

void SoundManager::PlayEFFECT(std::string name)
{
	g_pSystem->playSound(FMOD_CHANNEL_FREE, FindSound(name), false, &g_pChannel[SOUND_EFFECT]);
}

void SoundManager::Play(std::string name)
{
	g_pSystem->playSound(FMOD_CHANNEL_FREE, FindSound(name), false, &g_pChannel[SOUND_EFFECT]);
}

//Stop
void SoundManager::Stop()
{
	g_pChannel[SOUND_EFFECT]->stop();
	g_pChannel[SOUND_BGM]->stop();
}


//Volum
void SoundManager::VolumSet(float vol)
{
	g_pChannel[SOUND_EFFECT]->setVolume(vol);
	g_pChannel[SOUND_BGM]->setVolume(vol);
	//g_pSystem->playSound(FMOD_CHANNEL_FREE, g_pSound[esound], false, &g_pChannel[SOUND_EFFECT]);
}

