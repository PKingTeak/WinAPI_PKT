#pragma once
#include<EngineCore/Level.h>


class TitleLevel :public ULevel
{
public:
	TitleLevel();
	~TitleLevel();

	// delete Function
	TitleLevel(const TitleLevel& _Other) = delete;
	TitleLevel(TitleLevel&& _Other) noexcept = delete;
	TitleLevel& operator=(const TitleLevel& _Other) = delete;
	TitleLevel& operator=(TitleLevel&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;



};

