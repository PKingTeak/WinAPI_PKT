#include "EngineCore.h"
#include <Windows.h>
#include "Level.h"
#include "EnginePlatform/EngineInput.h"


EngineCore* GEngine = nullptr;

EngineCore::EngineCore()
	: MainWindow() // 이거의 의도 이해 안됨 질문)
{
}

EngineCore::~EngineCore()
{
}

void EngineCore::EngineTick()
{
	float DeltaTime = GEngine->MainTimer.TimeCheck(); //이걸로 엔진Tick과Tick사이의 시간을 잰다 .
	if (nullptr == GEngine->CurLevel)
	{
		MsgBoxAssert("엔진을 시작할 레벨이 지정되지 않았습니다 치명적인 오류입니다");
	}
	//현재 보여지고 있는 레벨에 관련된 

	// 레벨이 먼저 틱을 돌리고
	GEngine->CurLevel->Tick(0.0f);
	GEngine->CurLevel->ActorTick(0.0f);
}

void EngineCore::EngineEnd()
{
	// std::map<std::string, ULevel*>::iterator StartI

	for (std::pair<const std::string, ULevel*>& _Pair : GEngine->AllLevel)
	{
		if (nullptr == _Pair.second)
		{
			continue;
		}

		delete _Pair.second;
		_Pair.second = nullptr;
	}

	GEngine->AllLevel.clear();
}

void EngineCore::EngineStart(HINSTANCE _hInstance, EngineCore* _UserCore)
{
	EngineCore* Ptr = _UserCore;
	GEngine = Ptr;
	Ptr->CoreInit(_hInstance);
	Ptr->BeginPlay();
	EngineWindow::WindowMessageLoop(EngineTick, EngineEnd);
}

void EngineCore::CoreInit(HINSTANCE _HINSTANCE) //윈도우 클래스 등록 
{
	if (true == EngineInit) //이미 있다면 그냥 반환 엔진 코어는 하나만 존재해야 되니까

	{
		return;
	}

	EngineWindow::Init(_HINSTANCE);
	MainWindow.Open();

	EngineInit = true;
}

void EngineCore::BeginPlay()
{

}

void EngineCore::Tick(float _DeltaTime)
{

}

void EngineCore::End()
{

}

void EngineCore::ChangeLevel(std::string_view _Name)
{
	std::string UpperName = EngineString::ToUpper(_Name);

	if (false == AllLevel.contains(UpperName))
	{
		MsgBoxAssert(std::string(_Name) + "라는 존재하지 않는 레벨로 체인지 하려고 했습니다");
	}

	// 눈에 보여야할 레벨이죠?
	CurLevel = AllLevel[UpperName];
}

void EngineCore::LevelInit(ULevel* _Level)
{
	_Level->BeginPlay();
}