#pragma once
#include<EngineCore/Actor.h>
#include"User.h"
class Ball : public AActor
{
public:
	// constrcuter destructer
	Ball();
	~Ball();

	// delete Function
	Ball(const Ball& _Other) = delete;
	Ball(Ball&& _Other) noexcept = delete;
	Ball& operator=(const Ball& _Other) = delete;
	Ball& operator=(Ball&& _Other) noexcept = delete;


	//공의 기능을 생각해 봤을때 
	/*
	1. 시작점 지정  -> 플레이어 위치에 지정 
		이거는 플레이어 내부에 있는 CurPos를 사용해야 하기 때문에 User에서 구현하는게 좋을듯
	2. 몇초후 시작 혹은 스페이스바를 누르면 바로 앞으로 진행
		맵상에서 공은 무조건 한개만 존재 해야됨 == bool타입으로 공이 생존했는지 확인해보자
	3. 공이 떨어져서 사라지면 다시 생기는 시작점 = 플레이어 위치
	4. 벽과 부딪쳤을때 대처
	5. 블록들과 부딪쳤을때 대처 방법

	*/
	void SetPos(FVector _CurPos);
	void Move(FVector _StartPos);
	inline void SetBallX(float _X)
	{
		BallX = _X;
	}
	inline void SetBallY(float _Y)
	{
		BallY = _Y;
	}
	float GetBallX()
	{
		return BallX;
	}
	float GetBallY()
	{
		return BallY;
	}
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	
	
private:
	void DirCheck();
	UImageRenderer* BallRender = nullptr;
	FVector CurBallPos = {};
	FVector BDir = {};
	float BallX;
	float BallY;
	float Speed = 300.0f;
};