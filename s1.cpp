//디자인 패턴
//강형민 checkdisk@ioacademy.co.kr
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
	int x, y;//스택 영역
	//void set(Point * const this, int a, int b)
	//이렇게 작동한다. 이런 this를 thiscall( 멤버 함수가 호출될 때 객체의 주소를 넘기면서 호출하는 방식 )이라고 한다.

	void set(int a, int b){//텍스트 영역, 스택 프레임, 어셈블러, ebp
		x = a;//this->x = a;
		y = b;//this->y = b;
	}
};

int main(){
	Point p;
	cout << sizeof(p) << endl;

	p.set(1, 1);
	//Point::set(&p,1,1); 객체의 주소는 범용 레지스터(ECX)에 저장된다.
	cout << p.x <<", "<< p.y << endl;
	return 0;
}
#endif


#include <iostream>
using namespace std;

class Test{

	//static은 컴파일에 이미 결정된다.
	int member_val;
	static int class_val;//전역이긴 한데 linking time에 연결할 수 없다.
	//C++ : 정적 멤버 변수, java : 클래스 변수

public:
	//void Test::member_function(Test * const this);
	void member_function(){
		member_val = 0; 
		//this->member_val = 0; 이것과 같은 말이다. 왜냐하면 this가 자연히 들어오기 때문이다
		class_val = 0;
		//class_val = 0; 왜냐면 static이라 어디서든 접근 가능하기 때문이다.

		member_function();
		//member_function(this);
		class_function();
		//
	}
	//C++ : 정적 멤버 변수, Java : 클래스 매서드

	//void Test::class_function()
	static void class_function(){//일반함수이기 때문에 this가 안들어온다.
		//member_val = 0;
		//member_function();
		//이것들이 오류가 나는 이유는 class_function에 this가 안들어오기 때문에 this를 연결할 수 없다.

		class_val = 0;
		class_function();

		cout << "class_function()" << endl;
	}
};
int Test::class_val = 0; // 링커에게 이 심볼의 위치를 알려줘야한다.

//정적 멤버 함수는 정적 멤버만 접근 가능하다.
//일반 멤버 함수는 모든 멤버에 접근 가능하다.

void main(){
	//Test a; -> 런타임 문법이다.
	Test::class_function();
	//Java : Test.class_function();
	//Test::member_function();
	//이건 this가 넘어가야는데 안넘어간다.
	Test::class_function();

	Test t;
	t.member_function();
	t.class_function();

}


