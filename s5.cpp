#include <iostream>
using namespace std;
#define interface class

interface IPhone{
public: 
	// {}이렇게 하면 구현부가 있어서 가상이 안된다. =0 으로 해주어야 한다.
	virtual void send(const char*) = 0;

};

class Sky : public IPhone{
public:
	void send(const char*n){
		printf("calling %s with Sky...\n", n);
	};
};

class AnyCall : public IPhone{
public :
	void send(const char* n){
		printf("calling %s with AnyCall...\n",n);
	}
};

class Cyon : public IPhone{
public:
	void send(const char* n){
		printf("calling %s with Cyon...\n",n);
	}
};

//OpenClose Principle(OCP)
class Person{
public:
	/*
	void usePhone(AnyCall* p, const char* n){
		p->send(n);
	}
	void usePhone(Cyon *p, const char* n){
		p->send(n);
	}
	void usePhone(Sky *p, const char* n){
		p->send(n);
	}
	*/

	// 위의 세개의 함수를 합한다.
	// 인터페이스를 설계한다면 서로다른 두 개발의 속도를 높일 수 있다.
	void usePhone(IPhone* p, const char* n){
		p->send(n);
	}

};

int main(){
	Person p;
	AnyCall a;
	Cyon c;

	p.usePhone(&a, "000-0000-0000");
	p.usePhone(&c, "000-0000-0000");
}