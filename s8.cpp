#include <iostream>// GoF's Singleton
using namespace std;
// 오직 하나의 인스턴스만을 생성하는 설계 기법

class Mutex{
public:
	void lock(){ cout << "Mutex::lock" << endl; }
	void unlock(){ cout << "Mutex::unlock" << endl; }
};

template<typename T> class ScopedLock{
private:
	T& obj;
public:
	ScopedLock(T* o) : obj(*o){ obj.lock(); }
	ScopedLock(T& o) : obj(o){ obj.lock(); }
	~ScopedLock(){ obj.unlock(); }
};

template <typename T>class Singleton{
private:
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
protected:
	Singleton(){};
	//자식만 접근가능
	static T* sInstance;
	static Mutex mutex;
public:
	static T& getInstance(){
		ScopedLock<Mutex> sl(mutex);//lock
		if (sInstance == 0){
			sInstance = new T; // 교착 상태 발생(deadlock)
		}
		return *sInstance;
	}
};
template<typename T>T* Singleton<T>::sInstance = 0;
template<typename T>Mutex Singleton<T>::mutex;

// 템플릿 상속을 사용하면 템플릿의 인자로 사용자의 심볼을 인자로 받을 수 있으므로
// 먼 미래의 사용자가 사용하게 될 심벌을처리할 수 있다.(CRTP)
class Cursor : public Singleton<Cursor>{

};

void main(){
	Cursor& c1 = Cursor::getInstance(); // 기본 생성자
	Cursor& c2 = Cursor::getInstance();
	cout << "c1 : " << &c1 << ", c2 : " << &c2 << endl;
}
