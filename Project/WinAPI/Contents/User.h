#pragma once
#include <EngineCore/Actor.h>
#include"Stage1BackGround.h"


// 설명 :
class User : public AActor
{
public:
	// constrcuter destructer
	User();
	~User();

	// delete Function
	User(const User& _Other) = delete;
	User(User&& _Other) noexcept = delete;
	User& operator=(const User& _Other) = delete;
	User& operator=(User&& _Other) noexcept = delete;

	static FVector CurPos;
	
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	

private:
	void AutoShot(float _DeltaTime);
	UImageRenderer* PlayerRenderer;
	bool Isballlive = false;
	float time = 0.0f;
	


	//사실 총쏘는 기능은 필요 없다. 
	// float QSkillColl = 0.0f; 
};

