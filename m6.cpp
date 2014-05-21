#if 0
#include <iostream>
using namespace std;

//함수 포인터 객체와 멤버합수 포인터 객체 모두를 처리하기 위하여 부모클래스를 설계합니다
//서로 다른 타입을 하나의 타입으로 처리하려면 반드시 부모 클래스를 만들어야한다.
struct ICommand{
	virtual ~ICommand(){}
	virtual void execute() = 0;
};
//일반한수 포인터를 저장하는 클래스
class FunctionCommand : public ICommand{
	typedef void(*CALLBACK)();
	CALLBACK handler;
public:
	FunctionCommand(CALLBACK h) : handler(h){}
	void execute(){ handler(); };
};

//멤버합수 포인터를 저장하는 클래스
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

//일반함수
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
	//이렇게 인터페이스 기반이라면 ICommand의 내부밖에 보이지 않는다. 그래서 은닉이 된다.
}
//이런 범용함수 포인터는 2008년도에 표준의로 채택되었다.
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