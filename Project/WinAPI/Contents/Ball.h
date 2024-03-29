#pragma once
#include<EngineCore/Actor.h>
#include"User.h"
#include"ColliderManager.h"
#include"Block.h"
#include<EngineBase/EngineMath.h>



class Ball : public AActor
{
private:
	static Ball* MainBall;
public:
	friend Block;
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
		변경 플레이어 위치를 가져와서 따라다니게 함 isballLive는 공이 맵에 존재하는지 채크하는것이다. 
	2. 몇초후 시작 혹은 스페이스바를 누르면 바로 앞으로 진행
		맵상에서 공은 무조건 한개만 존재 해야됨 == bool타입으로 공이 생존했는지 확인해보자
	3. 공이 떨어져서 사라지면 다시 생기는 시작점 = 플레이어 위치
	4. 벽과 부딪쳤을때 대처
	5. 블록들과 부딪쳤을때 대처 방법

	*/
	void SetPos(FVector _CurPos);
	void WallCheck();
	void BlockCheck();
	void Reflect(FVector _CurBallPos);
	void GetUserScale();

	void SetSpeed(float _Speed);
	static Ball* GetMainBall();
	UCollision* GetCollision();
//static UCollision* GetBallCollision();

	Block* NewBlock = nullptr;
	void SetBallCol(bool _isCol)
	{
		isCol = _isCol;
	}
	
	bool BlockSideCheckLR(Block* _ColBlock );
	bool BlockSideCheckUD(Block* _ColBlock  );
	void Reset();
	//void YLReflect();
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	
	
private:
	void BallAdjustwithPlayer(float _Pos);
	void BallAdjustwithWall(float _Pos , bool isX);
	void BlockRatio(Block* _NewBlock);
	
	void Move(float _DeltaTime);
	void GameStartCheck();
	void PlayerPos();
	void PreMove();
	UImageRenderer* BallRender = nullptr;
	FVector CurBallPos = {};
	FVector PreBallpos = {};
	FVector BDir = {0.5f,-0.5f};
	FVector BallSize = { 10,10 };
	UCollision* BallCollison = nullptr;
	bool IsballLive = false;
	float Speed = 300.0f;
	bool isRight = false;
	bool isDown = false;
	bool MidHeight = false;
	bool MidTopHeight = false;
	bool isBottom = false;
	bool isCol = false;

};