#include <iostream>
using namespace std;

// c++ : base class
class Animal{
public:
	//void cry(Animal * const this)
	virtual void cry(){
		cout << "Animal::cry()" << endl;
	}
};

// c++ : drived class
class Cat : public Animal{
public:
	//void cry(Cat * const this)
	void cry(){
		cout << "Cat::cry()" << endl;
	}
};

void main(){

	Animal* pAnimal = new Animal;
	pAnimal->cry();// cry( pAnimal ); �̷��� ������Ÿ�ӿ� ����

	Cat* pCat = new Cat;
	pCat->cry();// cry( pCat );

	Animal* p = pCat;// upcasting
	p->cry(); // Animal::cry();

	// animal�� ����ȴ�. ������Ÿ�ӿ� �Լ��� �����ȴ�, static binding(���� ���ε�)
	// �׷��� ���� binding(��Ÿ�� ���ε�)�� �����ϰ� �ϰ�;��ߴ�. �׷��� virtual Ű���带 �ִ´�.
	// �ڹٴ� �⺻�� ���� binding�̱� ������ �˾Ƽ� Ÿ�� �ɽ����� ���ش�. ������ c++�� �����ش�.
}