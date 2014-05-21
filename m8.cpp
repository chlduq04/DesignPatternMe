//프레임워크 기반의 디자인 패턴(템플릿 메서드 패턴)
//라이브러리와 프레임워크의 공통점 : 사용자가 사용할 수 있는 도구를 제공
//라이브러리와 프레임워크의 차이점 : 라이브러리의 경우 사용자가 실행의 흐름을 결정, 프레임워크의 경우 라이브러리가 실행의 흐름을 결정

#include <iostream>
using namespace std;

class CWinApp;
CWinApp* g_app = 0;
class CWinApp{
public : 
	CWinApp(){ g_app = this; }
	virtual bool InitInstance(){ return false; }
	virtual int ExitInstance(){ return 0; }
	virtual int Run(){ return 0; }
};
CWinApp* AfxGetApp(){ return g_app; }

int main(){
	CWinApp *pApp = AfxGetApp();
	if (pApp->InitInstance()){
		pApp->Run();
	}
	pApp->ExitInstance();
}

// 위는 라이브러리 안쪽에 주현된 코드입니다.
//---------------------------------
// 1. CWinApp의 자식 클래스 구현
class CMyApp : public CWinApp{
public : 
	bool InitInstance(){ // on Create in Android
		cout << "프로그램이 초기화" << endl;
		return false;
 	}
	int ExitInstance(){
		cout << "프로그램의 종료 및 자원 해지" << endl;
		return 0;
	}
};

// 2. 파생 클래스를 전역 변수로 선언합니다.
CMyApp theApp;