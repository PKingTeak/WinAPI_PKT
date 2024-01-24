#include "ArkanoidCore.h"
#include "User.h"
#include "TitleLevel.h"
#include "Stage1.h"
ArkanoidCore::ArkanoidCore()
	:EngineCore()
{
}

ArkanoidCore::~ArkanoidCore()
{
}

// 게임시작
void ArkanoidCore::BeginPlay()
{
	CreateLevel<UTitleLevel>("TitleLevel");
	
	CreateLevel<Stage1>("Stage1");
	//구지 처음에 level을 다 만들 필요는 없다
	ChangeLevel("TitleLevel");
	//MainWindow.SetTitle();
	//MainWindow.SetScale();


	
	// 이때되면 이미 윈도우 창은 만들어져있는 상태일거라고 
	//창이 실행되면서 초기설정 
	// 예를 들면 창크기 변경같은거 

	//여기를 수정하면 된다. 
	//여기에서 Update를 하여 뱀게임을 예로 들면 여기에 헤드 부분
	//

}

void ArkanoidCore::Tick(float _DelatTime)
{ // 입력 받는거 혹은 상황을 넣어주는게 좋을듯 하고
	//특정 버튼을 누르고 changeLevel하는것인가?
	if (/*플레이어가 충돌했다 뭐 게임을 클리어 했다*/)
	{
	ChangeLevel("Stage1");

	}
	//실행도중
	//플레이어 동작같은거 
	//로직 (객체들 함수 가져다 쓴느 공간)
}

void ArkanoidCore::End()
{
	//소멸자 호출이나 릴리즈 같은거 게임종료
	int a = 0;
}