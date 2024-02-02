#pragma once
#include <EngineBase\EngineDebug.h>

// 설명 :
class UTickObject
{

public:
	// constrcuter destructer
	UTickObject();
	virtual ~UTickObject();

	// delete Function
	UTickObject(const UTickObject& _Other) = delete;
	UTickObject(UTickObject&& _Other) noexcept = delete;
	UTickObject& operator=(const UTickObject& _Other) = delete;
	UTickObject& operator=(UTickObject&& _Other) noexcept = delete;

	void ActiveOn()
	{
		IsActiveValue = true;
	}

	void ActiveOff()
	{
		IsActiveValue = false;
	}

	void SetActive(bool _Active)
	{
		IsActiveValue = _Active;
	}

	bool IsActive()
	{
		// 내가 켜져있고         죽지도 않았다면
		return IsActiveValue && IsDestroyValue == false;
	}


	virtual void Destroy(float _DestroyTime = 0.0f)
	{
		IsDestroyUpdate = true; // 언제 죽는지 시간을 계산 하는것
		DestroyTime = _DestroyTime;
		if (0.0f>= _DestroyTime)
		{
			this->IsDestroyValue = true;
		}
	}

	int GetOrder()
	{
		return Order;
	}

	virtual void SetOrder(int _Order)
	{
		Order = _Order;
	}

	virtual void DestroyUpdate(float _DeltaTime)
	{
		if (false == IsDestroyUpdate) //이걸로 true가 아니면 리턴
		{
			return;
		}

		DestroyTime -= _DeltaTime; //시간을 빼다가
		if (0.0f >= DestroyTime) //0초가 되면
		{
			Destroy(0.0f); //삭제 
		}
	}

	bool IsDestroy()
	{
		return IsDestroyValue;
	}

	virtual void BeginPlay();
	virtual void Tick(float _DeltaTime);

protected:

private:
	int Order = 0;
	bool IsDestroyUpdate = false;
	float DestroyTime = 0.0f;
	bool IsActiveValue = true;
	bool IsDestroyValue = false;

};

