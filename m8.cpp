//�����ӿ�ũ ����� ������ ����(���ø� �޼��� ����)
//���̺귯���� �����ӿ�ũ�� ������ : ����ڰ� ����� �� �ִ� ������ ����
//���̺귯���� �����ӿ�ũ�� ������ : ���̺귯���� ��� ����ڰ� ������ �帧�� ����, �����ӿ�ũ�� ��� ���̺귯���� ������ �帧�� ����

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

// ���� ���̺귯�� ���ʿ� ������ �ڵ��Դϴ�.
//---------------------------------
// 1. CWinApp�� �ڽ� Ŭ���� ����
class CMyApp : public CWinApp{
public : 
	bool InitInstance(){ // on Create in Android
		cout << "���α׷��� �ʱ�ȭ" << endl;
		return false;
 	}
	int ExitInstance(){
		cout << "���α׷��� ���� �� �ڿ� ����" << endl;
		return 0;
	}
};

// 2. �Ļ� Ŭ������ ���� ������ �����մϴ�.
CMyApp theApp;