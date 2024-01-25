#pragma once
#include <Windows.h>
#include <string>
// 설명 :
class EngineWindow
{
public:
	// constrcuter destructer
	EngineWindow();
	~EngineWindow();

	// delete Function
	EngineWindow(const EngineWindow& _Other) = delete;
	EngineWindow(EngineWindow&& _Other) noexcept = delete;
	EngineWindow& operator=(const EngineWindow& _Other) = delete;
	EngineWindow& operator=(EngineWindow&& _Other) noexcept = delete;

	void Open(std::string_view _Title = "Title");

	static void Init(HINSTANCE _hInst);
	static unsigned __int64 WindowMessageLoop(void(*_Update)(), void(*_End)());

	HDC GetWindowDC()
	{
		return hDC;
	}

protected:

private:
	static bool WindowLive;
	static HINSTANCE hInstance;
	static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

	HWND hWnd = nullptr;
	HDC hDC = nullptr;
};



	/*
	
	
	static bool WindowLive;  //모든 창이 동시에 꺼지게 하기 위해서 static전역변수로 설정하여 관리한다.
	static HINSTANCE hInstance; // 윈도우에서 내프로그램의 번호를 지정
	//그럼 이거는 객체가 하나 할당되었을때 하나씩 인데 하나가 필요하니까 스테틱이다.
	static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); //이건 왜 전역으로 했을까?


	HWND hWnd = nullptr; //프로그램한개에 하나씩 존재해야되며 다 다들수 있기대문에 static으로 안한다
	//내프로그램의 번호라고 생각그리고 윈도우창에 관련된 것에 접근하기 위해서 
	HDC hDC = nullptr;
	//내 프로그램의 그림을 그리는 권한을 지정할것이다.
};
	*/

