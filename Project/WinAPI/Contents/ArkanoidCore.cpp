#include "ArkanoidCore.h"
#include "User.h"
#include "TitleLevel.h"

ArkanoidCore::ArkanoidCore()
{
}

ArkanoidCore::~ArkanoidCore()
{
}

// 게임시작
void ArkanoidCore::Start()
{
	//MainWindow.SetTitle();
	//MainWindow.SetScale();

	User NewUser;
	
	// 이때되면 이미 윈도우 창은 만들어져있는 상태일거라고 
	//창이 실행되면서 초기설정 
	// 예를 들면 창크기 변경같은거 
	int a = 0;
}

void ArkanoidCore::Update()
{
	//실행도중
	//플레이어 동작같은거 
	//로직 (객체들 함수 가져다 쓴느 공간)
}

void ArkanoidCore::End()
{
	//소멸자 호출이나 릴리즈 같은거 게임종료
	int a = 0;
}