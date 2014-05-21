//������ ����
//������ checkdisk@ioacademy.co.kr
/*
#include <stdio.h>
#include <iostream>
using namespace std;
int main(){

	return 0;
}
*/

#if 0

#include <stdio.h>
#include <iostream>
using namespace std;
class Point{
public :
	int x, y;//���� ����
	//void set(Point * const this, int a, int b)
	//�̷��� �۵��Ѵ�. �̷� this�� thiscall( ��� �Լ��� ȣ��� �� ��ü�� �ּҸ� �ѱ�鼭 ȣ���ϴ� ��� )�̶�� �Ѵ�.

	void set(int a, int b){//�ؽ�Ʈ ����, ���� ������, �����, ebp
		x = a;//this->x = a;
		y = b;//this->y = b;
	}
};

int main(){
	Point p;
	cout << sizeof(p) << endl;

	p.set(1, 1);
	//Point::set(&p,1,1); ��ü�� �ּҴ� ���� ��������(ECX)�� ����ȴ�.
	cout << p.x <<", "<< p.y << endl;
	return 0;
}
#endif


#include <iostream>
using namespace std;

class Test{

	//static�� �����Ͽ� �̹� �����ȴ�.
	int member_val;
	static int class_val;//�����̱� �ѵ� linking time�� ������ �� ����.
	//C++ : ���� ��� ����, java : Ŭ���� ����

public:
	//void Test::member_function(Test * const this);
	void member_function(){
		member_val = 0; 
		//this->member_val = 0; �̰Ͱ� ���� ���̴�. �ֳ��ϸ� this�� �ڿ��� ������ �����̴�
		class_val = 0;
		//class_val = 0; �ֳĸ� static�̶� ��𼭵� ���� �����ϱ� �����̴�.

		member_function();
		//member_function(this);
		class_function();
		//
	}
	//C++ : ���� ��� ����, Java : Ŭ���� �ż���

	//void Test::class_function()
	static void class_function(){//�Ϲ��Լ��̱� ������ this�� �ȵ��´�.
		//member_val = 0;
		//member_function();
		//�̰͵��� ������ ���� ������ class_function�� this�� �ȵ����� ������ this�� ������ �� ����.

		class_val = 0;
		class_function();

		cout << "class_function()" << endl;
	}
};
int Test::class_val = 0; // ��Ŀ���� �� �ɺ��� ��ġ�� �˷�����Ѵ�.

//���� ��� �Լ��� ���� ����� ���� �����ϴ�.
//�Ϲ� ��� �Լ��� ��� ����� ���� �����ϴ�.

void main(){
	//Test a; -> ��Ÿ�� �����̴�.
	Test::class_function();
	//Java : Test.class_function();
	//Test::member_function();
	//�̰� this�� �Ѿ�ߴµ� �ȳѾ��.
	Test::class_function();

	Test t;
	t.member_function();
	t.class_function();

}


