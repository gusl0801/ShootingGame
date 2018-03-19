#pragma once

/*
�ۼ��� : ������
�ۼ��� : 2018-03-09
����   : CGameAppŬ������ ������ �ʱ�ȭ �� ����, �۾� ó��
�Լ����� ������ �°� ȣ���� �� �ֵ��� �����ϴ� Ŭ�����Դϴ�.
*/

// h���Ͽ��� �ش� ��ũ�θ� ȣ���Ͽ� ����Ʈ �����ڸ� �����ϰ� 
// �̱��� Ŭ������ ������ ������ �ϵ��� �մϴ�.
#define SINGLETON_DECL(T) protected: T(); friend class Singleton<T>; private:

// cpp���Ͽ��� �ش� ��ũ�θ� ȣ���Ͽ� �̱��� �ν��Ͻ��� �ʱ�ȭ �ϵ��� �մϴ�.
#define SINGLETON_IMPL(T) T* Singleton<T>::instance = nullptr;

template <class T>
class Singleton
{
public:
	static void Create() { instance = new T; }
	static T* Get() { return instance; }
	static void Destroy() { delete instance; instance = nullptr; }

protected:
	static T* instance;
};

