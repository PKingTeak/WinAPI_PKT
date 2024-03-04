#include "ArkanoidCore.h"
#include "User.h"
#include "Stage1Level.h"
#include "TitleLevel.h"
#include <EngineBase/EngineFile.h>
#include <EngineCore/EngineResourcesManager.h>
#include<EnginePlatform/EngineSound.h>

#include<EngineBase/EngineDirectory.h>


FVector ArkanoidCore::ScreenSize = { 552,602 }; //Static을 이용하여 만들어서 구현하는 곳에 초기화 

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
	MainWindow.SetClearColor(Color8Bit::BlackA);
	UEngineDirectory Dir;
	UEngineDirectory SDir;
	Dir.MoveToSearchChild("ImageResource");
	//SDir.MoveToSearchChild("SoundResource");
	SDir.MoveParent();
	SDir.Move("SoundResource");


	std::list<UEngineFile> FList = Dir.AllFile({ ".png",".bmp" }, true);
	for (UEngineFile& File : FList)

	{
		UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
	}
	std::list<UEngineFile> NewList = SDir.AllFile({ ".wav", ".mp3" }, true);
	// 엔진만의 규칙을 정할거냐.
	for (UEngineFile& File : NewList)
	{
		UEngineSound::Load(File.GetFullPath());

		int a = 0;

	}


	UEngineResourcesManager::GetInst().CuttingImage("NewBlock.png", 4, 2);
	UEngineResourcesManager::GetInst().CuttingImage("OtherBlock.png", 6, 2);

	CreateLevel<TitleLevel>("TitleLevel");
	CreateLevel<Stage1Level>("Stage1Level");

	ChangeLevel("Stage1Level");



	//이꺼때문에 안짤린거였다.

	// 이때되면 이미 윈도우 창은 만들어져있는 상태일거라고 
	//창이 실행되면서 초기설정 
	// 예를 들면 창크기 변경같은거 

	//여기를 수정하면 된다. 
	//여기에서 Update를 하여 뱀게임을 예로 들면 여기에 헤드 부분
	//

	// 엔진만의 규칙을 정할거냐.


}

void ArkanoidCore::Tick(float _DelatTime)

{
	UEngineCore::Tick(_DelatTime);
	if (UEngineInput::IsDown('P'))
	{
		DebugMod();
	}
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

void ArkanoidCore::DebugMod()
{
	GEngine->EngineDebugSwitch();
}
void ArkanoidCore::CreateBlock()
{


}

void ArkanoidCore::End()
{
	//소멸자 호출이나 릴리즈 같은거 게임종료

}