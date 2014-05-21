#if 0
#include <iostream>
using namespace std;
//오직 하나의 인스턴스만을 생성하는 설계 기법
class Cursor{
private : 
	// 1. private 생성자를 정의합니다.
	Cursor(){}

	// 3. 복사 생성자도 private 영역에 선언해야 한다.
	Cursor(const Cursor& c){}
public:
	// 2. 오직 하나의 객체만을 반환하는 정적 인터페이스를 추가합니다.
	static Cursor & getInstance(){ // self
		static Cursor instance; // 정적 니역 변수로 선언(.data)
		return instance;
	}
};


void main(){
	Cursor& c1 = Cursor::getInstance(); // 기본 생성자
	Cursor& c2 = Cursor::getInstance();
	cout <<"c1 : "<< &c1 <<", c2 : "<< &c2 << endl;
	Cursor c3 = c1;//값 복제가 일어나면서 다른 인스턴스가 생성되었다.
}
#endif


#if 0
#include <iostream>
using namespace std;
//오직 하나의 인스턴스만을 생성하는 설계 기법
class Cursor{
private:
	// 1. private 생성자를 정의합니다.
	Cursor(){}
	// 3. 복사 생성자도 private 영역에 선언해야 한다.
	//    대입 연산자도 private 영역에 선언해야 한다.

	Cursor(const Cursor&) = delete;
	// 링커는 런타임하다가 구현부를 찾아 연결을 시켜주는데 {}가 없기때문에 런타임에서 오류가 난다.
	Cursor& operator=(const Cursor&) = delete;

public:
	// 2. 오직 하나의 객체만을 반환하는 정적 인터페이스를 추가합니다.
	static Cursor & getInstance(){ // self
		static Cursor instance; // 정적 니역 변수로 선언(.data)
		return instance;
	}
	void foo(){
		Cursor& c1 = getInstance();
		Cursor c2 = c1;
		Cursor c3;
		c3 = c1;
	}
};


void main(){
	Cursor& c1 = Cursor::getInstance(); // 기본 생성자
	Cursor& c2 = Cursor::getInstance();
	cout << "c1 : " << &c1 << ", c2 : " << &c2 << endl;
}

#endif

#if 0
#include <iostream>// GoF's Singleton
using namespace std;
// 오직 하나의 인스턴스만을 생성하는 설계 기법
class Cursor{
private:
	// 1. private 생성자를 정의합니다.
	Cursor(){}
	// 3. 복사 생성자도 private 영역에 선언해야 한다.
	//    대입 연산자도 private 영역에 선언해야 한다.

	Cursor(const Cursor&) = delete;
	// 링커는 런타임하다가 구현부를 찾아 연결을 시켜주는데 {}가 없기때문에 런타임에서 오류가 난다.
	Cursor& operator=(const Cursor&) = delete;

	static Cursor* sInstance;
public:
	// 2. 오직 하나의 객체만을 반환하는 정적 인터페이스를 추가합니다.
	static Cursor & getInstance(){ // self
		if (sInstance == 0){
			sInstance = new Cursor;
		}
		return *sInstance;
	}
};
Cursor* Cursor::sInstance = 0;
//이거좀 귀찮은데 자동생성하게 하자.

void main(){
	Cursor& c1 = Cursor::getInstance(); // 기본 생성자
	Cursor& c2 = Cursor::getInstance();
	cout << "c1 : " << &c1 << ", c2 : " << &c2 << endl;
}

#endif

#define MAKE_NO_COPY(CLASSNAME)				\
	private:								\
	CLASSNAME(const CLASSNAME&);			\
	CLASSNAME& operator=(const CLASSNAME&);

#define DECLARE_SINGLETON(CLASSNAME)		\
	MAKE_NO_COPY(CLASSNAME)					\
	private:								\
		CLASSNAME(){}						\
		static CLASSNAME* sInstance;		\
	public:									\
		static CLASSNAME& getInstance();		\

#define	IMPLEMENT_SINGLETON(CLASSNAME)		\
	CLASSNAME* CLASSNAME::sInstance = 0;	\
	CLASSNAME& CLASSNAME::getInstance(){	\
		if (sInstance == 0){				\
			sInstance = new CLASSNAME;		\
		}									\
		return *sInstance;					\
	}										\


#include <iostream>// GoF's Singleton
using namespace std;
// 오직 하나의 인스턴스만을 생성하는 설계 기법
class Cursor{
	DECLARE_SINGLETON(Cursor);
};
IMPLEMENT_SINGLETON(Cursor);
//이거좀 귀찮은데 자동생성하게 하자.

void main(){
	Cursor& c1 = Cursor::getInstance(); // 기본 생성자
	Cursor& c2 = Cursor::getInstance();
	cout << "c1 : " << &c1 << ", c2 : " << &c2 << endl;
}