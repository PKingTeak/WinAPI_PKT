#include "ArkanoidCore.h"
#include "User.h"
#include "Stage1Level.h"
#include "TitleLevel.h"
#include <EngineBase/EngineDirectory.h>
#include <EngineBase/EngineFile.h>
#include <EngineCore/EngineResourcesManager.h>

FVector ArkanoidCore::ScreenSize = { 800,600 };
//꿀팁 선언만 하고 구현을 안해주면 링커가 못찾는다. 
//1120 2001오류들 있으면 Static오류다 
//헤더 추가만 하면 끝~

ArkanoidCore::ArkanoidCore()
	:UEngineCore()
{
}

ArkanoidCore::~ArkanoidCore()
{
}

// 게임시작
void ArkanoidCore::BeginPlay()
{
	UEngineCore::BeginPlay();

	MainWindow.SetWindowScale({ ScreenSize.X,ScreenSize.Y }); //윈도우 설정해주고

	UEngineDirectory Dir;
	Dir.MoveParent();
	Dir.Move("ImageResource");


	std::list<UEngineFile> FList = Dir.AllFile({ ".png",".bmp" }, true);
	for (UEngineFile& File : FList)

	{
		UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
	}
	
	CreateLevel<TitleLevel>("TitleLevel");
	CreateLevel<Stage1Level>("Stage1Level");
	
	ChangeLevel("TitleLevel");
	
	
	UEngineResourcesManager::GetInst().CuttingImage("Player_Idle.png", 32,8);
	//이꺼때문에 안짤린거였다.
	
	// 이때되면 이미 윈도우 창은 만들어져있는 상태일거라고 
	//창이 실행되면서 초기설정 
	// 예를 들면 창크기 변경같은거 

	//여기를 수정하면 된다. 
	//여기에서 Update를 하여 뱀게임을 예로 들면 여기에 헤드 부분
	//

}

void ArkanoidCore::Tick(float _DelatTime)

{
	UEngineCore::Tick(_DelatTime);
	// 입력 받는거 혹은 상황을 넣어주는게 좋을듯 하고
	//특정 버튼을 누르고 changeLevel하는것인가?
	//if (/*플레이어가 충돌했다 뭐 게임을 클리어 했다*/)
	//{
	//ChangeLevel("Stage1");
	//
	//}
	//실행도중
	//플레이어 동작같은거 
	//로직 (객체들 함수 가져다 쓰는 공간)
}

void ArkanoidCore::End()
{
	//소멸자 호출이나 릴리즈 같은거 게임종료
	
}