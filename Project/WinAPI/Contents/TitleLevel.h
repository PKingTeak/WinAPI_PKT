#pragma once
#include <EngineCore\Level.h>

// 설명 :
class UTitleLevel : public ULevel
	//레벨을 관리해주는 클래스 core에 직접 영향을 주는
{
public:
	// constrcuter destructer
	UTitleLevel();
	~UTitleLevel();

	// delete Function
	UTitleLevel(const UTitleLevel& _Other) = delete;
	UTitleLevel(UTitleLevel&& _Other) noexcept = delete;
	UTitleLevel& operator=(const UTitleLevel& _Other) = delete;
	UTitleLevel& operator=(UTitleLevel&& _Other) noexcept = delete;

protected:

private:

};

