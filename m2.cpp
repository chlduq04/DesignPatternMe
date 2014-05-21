#if 0
// 함수 연산자 오버로딩
#include <iostream>
using namespace std;

struct Complex{
private:
public:
	int real, image;
	Complex(int r, int i) : real(r), image(i) {}
	void print(){ printf("%d+%di\n",real,image); };

	Complex operator+(const Complex& other){
		return Complex(real + other.real, image + other.image);
	}
};

Complex add(const Complex& c1, const Complex& c2){
	// 임시객체 생성 안됨 - 최적화(RVO)
	return Complex(c1.real + c2.real, c1.image + c2.image);
}

void main(){
	Complex c1(1, 1), c2(2, 2);
	Complex c3 = c1 + c2; // c1.operator+(c2)
}


#endif
# if 0
// 스마트 포인터
#include <iostream>
using namespace std;

class Car{

public:
	Car(){ cout << "Car()" << endl; }
	~Car(){ cout << "~Car()" << endl; }
	void go(){ cout << "Go! Go! Go!" << endl; }
};

//스마트 포인터 도입!!!!!
// 포인터를 객체로 만들 경우, 사용자가 생성, 복사, 대입, 소멸의 모든 과정을 제어할 수 있다.
// 스맡 포인터를 활용한 예 : 소멸자를 사용한 객체의 소멸
class Sptr{
	Car* ptr;
public:
	Sptr(Car* p) : ptr(p) {}
	~Sptr(){ if (ptr) delete ptr; ptr = 0; }

	//스마트 포인터의 조건의 아래의 연산자를 반드시 제공해야한다.
	Car* operator->(){ return ptr; }
	Car& operator*(){ return *ptr; } // Car가 아니라 Car&로 해야 임시객체가 생기지 않는다.
};

void main(){
	{
		//		Car* p = new Car;
		//		delete p;

		Sptr p = new Car;
		p->go(); // p.operator->()go()  ---> (p.operator->())->go()
		(*p).go(); // (p.operator*())->go()
	}
	getchar();
}
#endif


#if 0
#include <iostream>
using namespace std;

class Car{

public:
	Car(){ cout << "Car()" << endl; }
	~Car(){ cout << "~Car()" << endl; }
	void go(){ cout << "Go! Go! Go!" << endl; }
};

class Sptr{
	Car* ptr;
public:
	Sptr(Car* p) : ptr(p) {}
	~Sptr(){ if (ptr) delete ptr; ptr = 0; }

	//스마트 포인터의 조건의 아래의 연산자를 반드시 제공해야한다.
	Car* operator->(){ return ptr; }
	Car& operator*(){ return *ptr; } // Car가 아니라 Car&로 해야 임시객체가 생기지 않는다.

};

void main(){
	int n;
	int *p = &n;
	int *q = p;

	Sptr p1 = new Car;
	Sptr p2 = p1;
	// 문제가 있다. 해결법은 깊은복사를 하거나 소유권을 양도한다(소유권 이전방식 = auto_ptr), 복사방지 unique_ptr, 
	// 참조계수 방식(계수를 두고 그 계수의 count를 ++시킨다. 그리고 count가 0 이면 제거한다.)
	// 참조계수도 각자 가지고 있으면 연동이 안되니까 한곳에 만들어두고 주소로 관리한다.
	getchar();
}

#endif


#if 0 
#include <iostream>
using namespace std;

class Car{

public:
	Car(){ cout << "Car()" << endl; }
	~Car(){ cout << "~Car()" << endl; }
	void go(){ cout << "Go! Go! Go!" << endl; }
};

template <typename T> class Sptr{
	T* ptr;
	int* ref;
public:
	Sptr(T* p = 0) : ptr(p) {
		ref = new int(1);
	}
	~Sptr(){ 
		if (--(*ref) == 0){
			delete ptr;
			delete ref;
		}
	}

	//스마트 포인터의 조건의 아래의 연산자를 반드시 제공해야한다.
	T* operator->(){ return ptr; }
	T& operator*(){ return *ptr; } // Car가 아니라 Car&로 해야 임시객체가 생기지 않는다.

	// 참조계수 형태의 복사생성자
	Sptr(const Sptr& o) : ptr(o.ptr), ref(o.ref){
		++(*ref);
	}
};

void main(){
	Sptr<Car> p = new Car;
	Sptr<Car> q = p; // 기본 복사생성자가 실행된다.
	getchar();
}

#endif

#if 0

#include <iostream>
#include <memory>
using namespace std;

void main(){
	shared_ptr<int> p(new int(10));
	*p = 10;
	cout << *p << endl;

	shared_ptr<int> q(p);
}

#endif

#if 0
#include <iostream>
using namespace std;

class Car{

public:
	Car(){ cout << "Car()" << endl; }
	~Car(){ cout << "~Car()" << endl; }
	void go(){ cout << "Go! Go! Go!" << endl; }
};

template <typename T> class Sptr{
	T* ptr;
	int* ref;
public:
	Sptr(T* p = 0) : ptr(p) {
		ref = new int(1);
	}
	~Sptr(){
		if (--(*ref) == 0){
			delete ptr;
			delete ref;
		}
	}

	//스마트 포인터의 조건의 아래의 연산자를 반드시 제공해야한다.
	T* operator->(){ return ptr; }
	T& operator*(){ return *ptr; } // Car가 아니라 Car&로 해야 임시객체가 생기지 않는다.

	// 참조계수 형태의 복사생성자
	Sptr(const Sptr& o) : ptr(o.ptr), ref(o.ref){
		++(*ref);
	}
};

void main(){

	Sptr<int> p = new int;
	*p = 10;
	cout << *p << endl;
	// 잘된다. 하지만 문제가있다.

	cout << sizeof(int*) << endl;
	cout << sizeof(Sptr<int>) << endl;
	getchar();
}

#endif


#include <iostream>
using namespace std;

class RefBase{
	int mCount;
public :
	RefBase() :mCount(0){}
	virtual ~RefBase(){}
	void incStrong(){ ++mCount; }
	void decStrong(){
		if ((--mCount) == 0){ delete this; }
	}
};

class Car : public RefBase{
public:
	Car(){ cout << "Car()" << endl; }
	~Car(){ cout << "~Car()" << endl; }
	void go(){ cout << "Go! Go! Go!" << endl; }
};

template<typename T> class Sptr{
	T* ptr;
public:
	//객체 생성 후 참조 계수 증가
	Sptr(T* p) :ptr(p){
		if (ptr){
			ptr->incStrong();
		}
	}

	Sptr(const Sptr& o) : ptr(o.ptr){
		if (ptr){
			ptr->incStrong();
		}
	}

	~Sptr(){
		if (ptr){ ptr->decStrong(); }
	}

	T* operator->(){ return ptr; }
	T& operator*(){ return *ptr; }
};

int main(){
	/*
	Car* p = new Car; // 객체 생성
	p->incStrong();
	Car* q = p; // 객체 복사
	p->incStrong();
	//--------------------
	p->decStrong(); // 참조 계수 감소
	p->decStrong(); // 참조 계구 감소 후 삭제
	*/


	//안드로이드의 스마트 포인터
	//Proxy pattern 이라고 한다. 
	Sptr<Car> p = new Car;
	Sptr<Car> q = p;

	cout << sizeof(Sptr<Car>) << endl;

	// Sptr<int> p1 = new int; 이건 안된다.
	// 안드로이드의 sp : 장점 : 메모리 최적화
	//					 단점 : refbase의 자식만 처리가능

	// 표준 sp : 장점 : 모든 타입처리가능 
	//			 단점 : 메모리 낭비가 발생

	return 0;
}

