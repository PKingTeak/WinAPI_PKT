#pragma once
#include<EngineBase/EngineMath.h>
#include"Stage1BackGround.h"
#include<EngineCore/Actor.h>
#include<EngineCore/EngineCore.h>
// 설명 :
class CollisonManger
{
public:
	// constrcuter destructer
	CollisonManger();
	~CollisonManger();

	// delete Function
	CollisonManger(const CollisonManger& _Other) = delete;
	CollisonManger(CollisonManger&& _Other) noexcept = delete;
	CollisonManger& operator=(const CollisonManger& _Other) = delete;
	CollisonManger& operator=(CollisonManger&& _Other) noexcept = delete;
	static UWindowImage* ColMapImage;
	//static CollisonManger& GetInst()
	//{
	//	static CollisonManger Inst = CollisonManger();
	//	return Inst;
	//	//충돌도 하나만 존재하게 하고싶기 때문에 만든 클래스이다.
	//	//싱글톤
	//}

	//void IsCol(UWindowImage* _ColObject, float _DeltaTime);
	

protected:

private:
	UWindowImage* CloObject = nullptr;
	Color8Bit ColColor = Color8Bit();
};

