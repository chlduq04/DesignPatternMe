#if 0
#include <stdio.h>
#include <iostream>
#include <Windows.h>
using namespace std;

//c�� �Լ������ͷ� ���������� c++�� callback�� �Լ������� �Ӿƴ϶� �����Լ��� ���� �� �ִ�.
unsigned long __stdcall threadMain(void* arg){ //__stdcall
	while (1){
		printf("Do worker thread\n");
		Sleep(1000);
	}
	return 0;
}

int main(){
	//�۹̼�, ���û�����(=0 �ü���� �˾Ƽ�), �Լ�������, �����尡 ȣ��Ǿ����� �Ķ����, �÷���, ���̵�
	CreateThread(0, 0, threadMain, "A", 0, 0);
	getchar();
	return 0;
}
#endif

#include <stdio.h>
#include <iostream>
#include <Windows.h>
using namespace std;

class Thread{
protected:
	virtual void threadMain(){}
	static unsigned long __stdcall __threadMain(void* arg){ 
		Thread* self = (Thread*)arg;
		self->threadMain(); 
		return 0;
	};
public:
	void run(){
		//�̰� ���, this��� �Ķ���Ͱ� �Ѿ��. �̶� this�� ������ Thread class�ϱ� (Thread*)�� ��ȯ�� �����ϰ� �̿��� threadMain()�� �θ� �� �ְԵȴ�.
		CreateThread(0, 0, __threadMain, this, 0, 0);
	};
};

class FileDownThread : public Thread{
public:
	//threadMain�� �������̵� �ϸ� �˴ϴ�.
	void threadMain(){
		for (int i = 0; i < 10; i++){
			system("cls");
			cout << i * 10 << "% downloading..." << endl;
			Sleep(700);
		}
		cout << "Download Complete!" << endl;
	};
};

int main(){
	FileDownThread t;
	t.run();
	getchar();
	return 0;
}