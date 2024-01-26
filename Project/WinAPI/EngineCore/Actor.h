#pragma once
#include <EngineBase\Transform.h>
#include "TickObject.h"
#include "NameObject.h"
#include "Level.h"
#include "ImageRenderer.h"

class ULevel;

// 설명 : A가 붙은 오브젝트는 화면에 위치가 존재해야한다.
// Level->SpawnActor를 통해서 만들면
// 레벨이 자연스럽게 자신의 관리하에 두고 언제나 Tick을 실행해준다.
class AActor : public UNameObject, public UTickObject
{
	friend ULevel;

public:
	// constrcuter destructer
	AActor();
	~AActor();

	// delete Function
	AActor(const AActor& _Other) = delete;
	AActor(AActor&& _Other) noexcept = delete;
	AActor& operator=(const AActor& _Other) = delete;
	AActor& operator=(AActor&& _Other) noexcept = delete;

	FVector GetActorLocation()
	{
		return Transform.GetPosition();
	}

	void SetActorLocation(FVector _Value)
	{
		Transform.SetPosition(_Value);
	}

	void AddActorLocation(FVector _Value)
	{
		Transform.AddPosition(_Value);
	}

	void SetActorScale(FVector _Value)
	{
		Transform.SetScale(_Value);
	}

	FTransform GetTransform()
	{
		return Transform;
	}

	ULevel* GetWorld()
	{
		return World;
	}

	UImageRenderer* CreateImageRenderer(int Order = 0); 

protected:

private:
	std::list<UImageRenderer*> Renderers; //모든 렌더러를 관리해주는 것  Actor에서 관리하는 이유는

	ULevel* World = nullptr;
	FTransform Transform = FTransform(); //위치 값 랜더러는 위치를 가지기 때문에 엑터 안에도 위치를 가진다 

	void SetWorld(ULevel* _Value)
	{
		World = _Value;
	}
};



