#if 0
#include <iostream>
using namespace std;
//���� �ϳ��� �ν��Ͻ����� �����ϴ� ���� ���
class Cursor{
private : 
	// 1. private �����ڸ� �����մϴ�.
	Cursor(){}

	// 3. ���� �����ڵ� private ������ �����ؾ� �Ѵ�.
	Cursor(const Cursor& c){}
public:
	// 2. ���� �ϳ��� ��ü���� ��ȯ�ϴ� ���� �������̽��� �߰��մϴ�.
	static Cursor & getInstance(){ // self
		static Cursor instance; // ���� �Ͽ� ������ ����(.data)
		return instance;
	}
};


void main(){
	Cursor& c1 = Cursor::getInstance(); // �⺻ ������
	Cursor& c2 = Cursor::getInstance();
	cout <<"c1 : "<< &c1 <<", c2 : "<< &c2 << endl;
	Cursor c3 = c1;//�� ������ �Ͼ�鼭 �ٸ� �ν��Ͻ��� �����Ǿ���.
}
#endif


#if 0
#include <iostream>
using namespace std;
//���� �ϳ��� �ν��Ͻ����� �����ϴ� ���� ���
class Cursor{
private:
	// 1. private �����ڸ� �����մϴ�.
	Cursor(){}
	// 3. ���� �����ڵ� private ������ �����ؾ� �Ѵ�.
	//    ���� �����ڵ� private ������ �����ؾ� �Ѵ�.

	Cursor(const Cursor&) = delete;
	// ��Ŀ�� ��Ÿ���ϴٰ� �����θ� ã�� ������ �����ִµ� {}�� ���⶧���� ��Ÿ�ӿ��� ������ ����.
	Cursor& operator=(const Cursor&) = delete;

public:
	// 2. ���� �ϳ��� ��ü���� ��ȯ�ϴ� ���� �������̽��� �߰��մϴ�.
	static Cursor & getInstance(){ // self
		static Cursor instance; // ���� �Ͽ� ������ ����(.data)
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
	Cursor& c1 = Cursor::getInstance(); // �⺻ ������
	Cursor& c2 = Cursor::getInstance();
	cout << "c1 : " << &c1 << ", c2 : " << &c2 << endl;
}

#endif

#if 0
#include <iostream>// GoF's Singleton
using namespace std;
// ���� �ϳ��� �ν��Ͻ����� �����ϴ� ���� ���
class Cursor{
private:
	// 1. private �����ڸ� �����մϴ�.
	Cursor(){}
	// 3. ���� �����ڵ� private ������ �����ؾ� �Ѵ�.
	//    ���� �����ڵ� private ������ �����ؾ� �Ѵ�.

	Cursor(const Cursor&) = delete;
	// ��Ŀ�� ��Ÿ���ϴٰ� �����θ� ã�� ������ �����ִµ� {}�� ���⶧���� ��Ÿ�ӿ��� ������ ����.
	Cursor& operator=(const Cursor&) = delete;

	static Cursor* sInstance;
public:
	// 2. ���� �ϳ��� ��ü���� ��ȯ�ϴ� ���� �������̽��� �߰��մϴ�.
	static Cursor & getInstance(){ // self
		if (sInstance == 0){
			sInstance = new Cursor;
		}
		return *sInstance;
	}
};
Cursor* Cursor::sInstance = 0;
//�̰��� �������� �ڵ������ϰ� ����.

void main(){
	Cursor& c1 = Cursor::getInstance(); // �⺻ ������
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
// ���� �ϳ��� �ν��Ͻ����� �����ϴ� ���� ���
class Cursor{
	DECLARE_SINGLETON(Cursor);
};
IMPLEMENT_SINGLETON(Cursor);
//�̰��� �������� �ڵ������ϰ� ����.

void main(){
	Cursor& c1 = Cursor::getInstance(); // �⺻ ������
	Cursor& c2 = Cursor::getInstance();
	cout << "c1 : " << &c1 << ", c2 : " << &c2 << endl;
}