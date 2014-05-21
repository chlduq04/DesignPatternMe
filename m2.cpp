#if 0
// �Լ� ������ �����ε�
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
	// �ӽð�ü ���� �ȵ� - ����ȭ(RVO)
	return Complex(c1.real + c2.real, c1.image + c2.image);
}

void main(){
	Complex c1(1, 1), c2(2, 2);
	Complex c3 = c1 + c2; // c1.operator+(c2)
}


#endif
# if 0
// ����Ʈ ������
#include <iostream>
using namespace std;

class Car{

public:
	Car(){ cout << "Car()" << endl; }
	~Car(){ cout << "~Car()" << endl; }
	void go(){ cout << "Go! Go! Go!" << endl; }
};

//����Ʈ ������ ����!!!!!
// �����͸� ��ü�� ���� ���, ����ڰ� ����, ����, ����, �Ҹ��� ��� ������ ������ �� �ִ�.
// ���� �����͸� Ȱ���� �� : �Ҹ��ڸ� ����� ��ü�� �Ҹ�
class Sptr{
	Car* ptr;
public:
	Sptr(Car* p) : ptr(p) {}
	~Sptr(){ if (ptr) delete ptr; ptr = 0; }

	//����Ʈ �������� ������ �Ʒ��� �����ڸ� �ݵ�� �����ؾ��Ѵ�.
	Car* operator->(){ return ptr; }
	Car& operator*(){ return *ptr; } // Car�� �ƴ϶� Car&�� �ؾ� �ӽð�ü�� ������ �ʴ´�.
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

	//����Ʈ �������� ������ �Ʒ��� �����ڸ� �ݵ�� �����ؾ��Ѵ�.
	Car* operator->(){ return ptr; }
	Car& operator*(){ return *ptr; } // Car�� �ƴ϶� Car&�� �ؾ� �ӽð�ü�� ������ �ʴ´�.

};

void main(){
	int n;
	int *p = &n;
	int *q = p;

	Sptr p1 = new Car;
	Sptr p2 = p1;
	// ������ �ִ�. �ذ���� �������縦 �ϰų� �������� �絵�Ѵ�(������ ������� = auto_ptr), ������� unique_ptr, 
	// ������� ���(����� �ΰ� �� ����� count�� ++��Ų��. �׸��� count�� 0 �̸� �����Ѵ�.)
	// ��������� ���� ������ ������ ������ �ȵǴϱ� �Ѱ��� �����ΰ� �ּҷ� �����Ѵ�.
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

	//����Ʈ �������� ������ �Ʒ��� �����ڸ� �ݵ�� �����ؾ��Ѵ�.
	T* operator->(){ return ptr; }
	T& operator*(){ return *ptr; } // Car�� �ƴ϶� Car&�� �ؾ� �ӽð�ü�� ������ �ʴ´�.

	// ������� ������ ���������
	Sptr(const Sptr& o) : ptr(o.ptr), ref(o.ref){
		++(*ref);
	}
};

void main(){
	Sptr<Car> p = new Car;
	Sptr<Car> q = p; // �⺻ ��������ڰ� ����ȴ�.
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

	//����Ʈ �������� ������ �Ʒ��� �����ڸ� �ݵ�� �����ؾ��Ѵ�.
	T* operator->(){ return ptr; }
	T& operator*(){ return *ptr; } // Car�� �ƴ϶� Car&�� �ؾ� �ӽð�ü�� ������ �ʴ´�.

	// ������� ������ ���������
	Sptr(const Sptr& o) : ptr(o.ptr), ref(o.ref){
		++(*ref);
	}
};

void main(){

	Sptr<int> p = new int;
	*p = 10;
	cout << *p << endl;
	// �ߵȴ�. ������ �������ִ�.

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
	//��ü ���� �� ���� ��� ����
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
	Car* p = new Car; // ��ü ����
	p->incStrong();
	Car* q = p; // ��ü ����
	p->incStrong();
	//--------------------
	p->decStrong(); // ���� ��� ����
	p->decStrong(); // ���� �豸 ���� �� ����
	*/


	//�ȵ���̵��� ����Ʈ ������
	//Proxy pattern �̶�� �Ѵ�. 
	Sptr<Car> p = new Car;
	Sptr<Car> q = p;

	cout << sizeof(Sptr<Car>) << endl;

	// Sptr<int> p1 = new int; �̰� �ȵȴ�.
	// �ȵ���̵��� sp : ���� : �޸� ����ȭ
	//					 ���� : refbase�� �ڽĸ� ó������

	// ǥ�� sp : ���� : ��� Ÿ��ó������ 
	//			 ���� : �޸� ���� �߻�

	return 0;
}

