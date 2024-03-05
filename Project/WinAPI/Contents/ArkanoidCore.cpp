#include "ArkanoidCore.h"
#include "User.h"
#include "Stage1Level.h"
#include "TitleLevel.h"
#include <EngineBase/EngineFile.h>
#include <EngineCore/EngineResourcesManager.h>
#include<EnginePlatform/EngineSound.h>
#include"UIManager.h"
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

	MainWindow.SetWindowScale({ ScreenSize.X,ScreenSize.Y+50 }); //윈도우 설정해주고
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

	//이미지 로드
	UEngineResourcesManager::GetInst().CuttingImage("Player_Idle.png", 1, 6);
	UEngineResourcesManager::GetInst().CuttingImage("Player_Start.png", 1, 5);
	UEngineResourcesManager::GetInst().CuttingImage("Player_Dead.png", 4, 1);

	UEngineResourcesManager::GetInst().CuttingImage("NewBlock.png", 4, 2);
	UEngineResourcesManager::GetInst().CuttingImage("OtherBlock.png", 6, 2);

	//UI
	UEngineResourcesManager::GetInst().CuttingImage("UI_NumberWhite.png", 1, 10);

	CreateLevel<TitleLevel>("TitleLevel");
	CreateLevel<Stage1Level>("Stage1Level");

	ChangeLevel("Stage1Level");


}

void ArkanoidCore::Tick(float _DelatTime)

{
	UEngineCore::Tick(_DelatTime);
	if (UEngineInput::IsDown('P'))
	{
		DebugMod();
	}
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