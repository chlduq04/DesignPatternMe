//Java는 Thread를 언어에서 프레임워크로 제공하지만 c나 c++는 언어에서 제공하지 않는다.
#include <iostream>
using namespace std;

// 함수의 타입은 리턴타입 + 매개변수
// 함수의 선언 : 리턴타입 함수명(매개변수);
void function(){
	cout << "::function()" << endl;
}

class Clazz{
public:
	void member_function(){
		cout << "Clazz::member_function()" << endl;
	}
	static void class_function(){
		cout << "Clazz::class_function()" << endl;
	}
};

void main(){
	int n;
	//포인터 변수의 선언방법 : 타입 * 변수명;
	int *p = &n;//컴파일때 얼마나 읽을지 몰라서 이렇게 해줘야 4 byte를 읽는다.

	//함수의 주소를 얻는 방법
	printf("0x%p\n", &function);//주소값이 출력된다.

	//컴파일러는 뒤에서 해석
	//그래서 void* func()는 함수로 해석한다.
	//이것이 함수 포인터라는 것을 이야기해야 한다.
	void(*func)() = &function;
	func();

	//함수 호출규약이 있다 calling convention
	void(*fp1)() = &function;
	void(*fp2)() = &Clazz::class_function;
	void(Clazz::*fp3)() = &Clazz::member_function;
	//void(__thisclass *fp3)() = &Clazz::member_function; 이런 의미이지만 실제 사용은 불가능
	fp1();
	fp2();

	Clazz clazz;
	//fp3(); fp3(&clazz)이렇게 되는건 컴파일러가 해주는거지 직접 쓸수는 없다.
	(clazz.*fp3)();
	//.*이건 하나의 연산자야 암묵적으로 this를 넣어줄 수가 없으니까 이렇게 호출해야한다.

	Clazz *cp = new Clazz;
	(cp->*fp3)();
	//->*이거도 하나의 연산자다.

}