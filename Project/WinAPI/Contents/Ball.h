#pragma once
#include<EngineCore/Actor.h>
#include"User.h"
#include"ColliderManager.h"
#include"Block.h"
#include<EngineBase/EngineMath.h>
class Ball : public AActor
{
	friend Block;
private: 
	static Ball* MainBall;;
public:
	// constrcuter destructer
	Ball();
	~Ball();

	// delete Function
	Ball(const Ball& _Other) = delete;
	Ball(Ball&& _Other) noexcept = delete;
	Ball& operator=(const Ball& _Other) = delete;
	Ball& operator=(Ball&& _Other) noexcept = delete;


	//���� ����� ������ ������ 
	/*
	1. ������ ����  -> �÷��̾� ��ġ�� ���� 
		���� �÷��̾� ��ġ�� �����ͼ� ����ٴϰ� �� isballLive�� ���� �ʿ� �����ϴ��� äũ�ϴ°��̴�. 
	2. ������ ���� Ȥ�� �����̽��ٸ� ������ �ٷ� ������ ����
		�ʻ󿡼� ���� ������ �Ѱ��� ���� �ؾߵ� == boolŸ������ ���� �����ߴ��� Ȯ���غ���
	3. ���� �������� ������� �ٽ� ����� ������ = �÷��̾� ��ġ
	4. ���� �ε������� ��ó
	5. ��ϵ�� �ε������� ��ó ���

	*/
	void SetPos(FVector _CurPos);
	void StartPos(FVector _StartPos);

	void WallCheck();
	void UserCheck();
	void BlockCheck();

	void Reflect(FVector _CurBallPos);
	void GetUserScale();

	UCollision* GetCollision();
//static UCollision* GetBallCollision();

	Block* NewBlock = nullptr;
	
	bool BlockSideCheckLR(Block* _ColBlock );
	bool BlockSideCheckUD(Block* _ColBlock  );
	//void YLReflect();
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	
	
private:
	void MoveSurface(FVector _CurBallPos , float _Standard);
	void BlockRatio(Block* _NewBlock);
	void Reset();
	void Move(float _DeltaTime);
	void GameStartCheck();
	void PlayerPos();
	UImageRenderer* BallRender = nullptr;
	FVector CurBallPos = {};
	FVector BDir = {0.5f,-0.5f};
	FVector BallSize = { 10,8 };
	UCollision* BallCollison = nullptr;
	bool IsballLive = false;
	float Speed = 300.0f;
	bool isRight = false;
	bool isDown = false;
	bool MidHeight = false;
	bool MidTopHeight = false;
	bool isCol = false;
};