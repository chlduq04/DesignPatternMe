#if 0
#include <stdio.h>
#include <iostream>
#include <Windows.h>
using namespace std;

//c는 함수포인터로 구현하지만 c++는 callback을 함수포인터 뿐아니라 가상함수로 만들 수 있다.
unsigned long __stdcall threadMain(void* arg){ //__stdcall
	while (1){
		printf("Do worker thread\n");
		Sleep(1000);
	}
	return 0;
}

int main(){
	//퍼미션, 스택사이즈(=0 운영체제가 알아서), 함수포인터, 쓰레드가 호출되었을때 파라미터, 플래그, 아이디
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
		//이건 기믹, this라는 파라미터가 넘어간다. 이때 this는 무조건 Thread class니까 (Thread*)로 변환이 가능하고 이에서 threadMain()을 부를 수 있게된다.
		CreateThread(0, 0, __threadMain, this, 0, 0);
	};
};

class FileDownThread : public Thread{
public:
	//threadMain을 오버라이딩 하면 됩니다.
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