#if 0
#include <iostream>
using namespace std;

//�Լ� ������ ��ü�� ����ռ� ������ ��ü ��θ� ó���ϱ� ���Ͽ� �θ�Ŭ������ �����մϴ�
//���� �ٸ� Ÿ���� �ϳ��� Ÿ������ ó���Ϸ��� �ݵ�� �θ� Ŭ������ �������Ѵ�.
struct ICommand{
	virtual ~ICommand(){}
	virtual void execute() = 0;
};
//�Ϲ��Ѽ� �����͸� �����ϴ� Ŭ����
class FunctionCommand : public ICommand{
	typedef void(*CALLBACK)();
	CALLBACK handler;
public:
	FunctionCommand(CALLBACK h) : handler(h){}
	void execute(){ handler(); };
};

//����ռ� �����͸� �����ϴ� Ŭ����
template<typename T> class MemberCommand : public ICommand{
	typedef void(T::*CALLBACK)();
	T* pObject;
	CALLBACK handler;

public:
	MemberCommand(CALLBACK h, T*p) : pObject(p), handler(h){}
	void execute(){
		(pObject->*handler)();
	}
};

//�Ϲ��Լ�
void function(){ cout << "::function()" << endl; };
class Dialog{
public:
	void function(){ cout << "Dialog::function()" << endl; }
};

template<typename T> MemberCommand<T>* cmd(void(T::*handler)(), T* p){
	return new MemberCommand<T>(handler, p);
}

FunctionCommand* cmd(void(*handler)()){
	return new FunctionCommand(handler);
}

void main(){
	//1
	//	FunctionCommand fc(&function);
	//	fc.execute();


	//2
	//	FunctionCommand* p1 = cmd(&function);
	//p1->execute();

	//3
	ICommand* p1 = cmd(&function);
	p1->execute();

	//MemberCommand<Dialog> mc(&Dialog::function, &dlg);
	//mc.execute();
	Dialog dlg;
	//MemberCommand<Dialog>* p2 = cmd(&Dialog::function, &dlg);
	ICommand* p2 = cmd(&Dialog::function, &dlg);
	p2->execute();
	//�̷��� �������̽� ����̶�� ICommand�� ���ιۿ� ������ �ʴ´�. �׷��� ������ �ȴ�.
}
//�̷� �����Լ� �����ʹ� 2008�⵵�� ǥ���Ƿ� ä�õǾ���.
#endif 



#include <iostream>
#include <functional>
using namespace std;

void foo(){ cout << "Foo()" << endl; };
void goo(int a){ cout << "Goo()" << endl; };

class Dialog{
public:
	void close(){ cout << "Dialg::close()" << endl; }
};

void main(){
	function<void()> fp = &foo;
	fp();
	fp = bind(&goo, 3);
	fp();
	//function<void(int)> fp1 = &goo;
	//fp1();
	Dialog dlg;
	fp = bind(&Dialog::close, &dlg);
	fp();
}