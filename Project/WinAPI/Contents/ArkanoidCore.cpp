#include "ArkanoidCore.h"
#include "User.h"
#include "TitleLevel.h"
#include "Stage1.h"
ArkanoidCore::ArkanoidCore()
	:EngineCore()
{
}

ArkanoidCore::~ArkanoidCore()
{
}

// ���ӽ���
void ArkanoidCore::BeginPlay()
{
	CreateLevel<UTitleLevel>("TitleLevel");
	
	CreateLevel<Stage1>("Stage1");
	//���� ó���� level�� �� ���� �ʿ�� ����
	ChangeLevel("TitleLevel");
	//MainWindow.SetTitle();
	//MainWindow.SetScale();


	
	// �̶��Ǹ� �̹� ������ â�� ��������ִ� �����ϰŶ�� 
	//â�� ����Ǹ鼭 �ʱ⼳�� 
	// ���� ��� âũ�� ���氰���� 

	//���⸦ �����ϸ� �ȴ�. 
	//���⿡�� Update�� �Ͽ� ������� ���� ��� ���⿡ ��� �κ�
	//

}

void ArkanoidCore::Tick(float _DelatTime)
{ // �Է� �޴°� Ȥ�� ��Ȳ�� �־��ִ°� ������ �ϰ�
	//Ư�� ��ư�� ������ changeLevel�ϴ°��ΰ�?
	if (/*�÷��̾ �浹�ߴ� �� ������ Ŭ���� �ߴ�*/)
	{
	ChangeLevel("Stage1");

	}
	//���൵��
	//�÷��̾� ���۰����� 
	//���� (��ü�� �Լ� ������ ���� ����)
}

void ArkanoidCore::End()
{
	//�Ҹ��� ȣ���̳� ������ ������ ��������
	int a = 0;
}