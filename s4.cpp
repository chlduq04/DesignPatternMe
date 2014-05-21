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
	pAnimal->cry();// cry( pAnimal ); 이렇게 컴파일타임에 결정

	Cat* pCat = new Cat;
	pCat->cry();// cry( pCat );

	Animal* p = pCat;// upcasting
	p->cry(); // Animal::cry();

	// animal이 실행된다. 컴파일타임에 함수가 결정된다, static binding(정적 바인딩)
	// 그래서 동적 binding(런타임 바인딩)을 지원하게 하고싶어했다. 그래서 virtual 키워드를 넣는다.
	// 자바는 기본이 동적 binding이기 때문에 알아서 타입 케스팅을 해준다. 하지만 c++은 안해준다.
}