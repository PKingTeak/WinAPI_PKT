#pragma once
#include<EngineBase/EngineMath.h>
#include"Stage1BackGround.h"
#include<EngineCore/Actor.h>
#include<EngineCore/EngineCore.h>
// ���� :
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
	//	//�浹�� �ϳ��� �����ϰ� �ϰ�ͱ� ������ ���� Ŭ�����̴�.
	//	//�̱���
	//}

	//void IsCol(UWindowImage* _ColObject, float _DeltaTime);
	

protected:

private:
	UWindowImage* CloObject = nullptr;
	Color8Bit ColColor = Color8Bit();
};

