#include <iostream>
using namespace std;
#define interface class

interface IPhone{
public: 
	// {}�̷��� �ϸ� �����ΰ� �־ ������ �ȵȴ�. =0 ���� ���־�� �Ѵ�.
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

	// ���� ������ �Լ��� ���Ѵ�.
	// �������̽��� �����Ѵٸ� ���δٸ� �� ������ �ӵ��� ���� �� �ִ�.
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