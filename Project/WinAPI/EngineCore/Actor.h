#pragma once
#include <EngineBase\Transform.h>
#include "TickObject.h"
#include "NameObject.h"
#include "Level.h"
#include "ImageRenderer.h"

class ULevel;

// ���� : A�� ���� ������Ʈ�� ȭ�鿡 ��ġ�� �����ؾ��Ѵ�.
// Level->SpawnActor�� ���ؼ� �����
// ������ �ڿ������� �ڽ��� �����Ͽ� �ΰ� ������ Tick�� �������ش�.
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
	std::list<UImageRenderer*> Renderers; //��� �������� �������ִ� ��  Actor���� �����ϴ� ������

	ULevel* World = nullptr;
	FTransform Transform = FTransform(); //��ġ �� �������� ��ġ�� ������ ������ ���� �ȿ��� ��ġ�� ������ 

	void SetWorld(ULevel* _Value)
	{
		World = _Value;
	}
};



