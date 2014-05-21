#include <iostream>// GoF's Singleton
using namespace std;
// ���� �ϳ��� �ν��Ͻ����� �����ϴ� ���� ���

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
	//�ڽĸ� ���ٰ���
	static T* sInstance;
	static Mutex mutex;
public:
	static T& getInstance(){
		ScopedLock<Mutex> sl(mutex);//lock
		if (sInstance == 0){
			sInstance = new T; // ���� ���� �߻�(deadlock)
		}
		return *sInstance;
	}
};
template<typename T>T* Singleton<T>::sInstance = 0;
template<typename T>Mutex Singleton<T>::mutex;

// ���ø� ����� ����ϸ� ���ø��� ���ڷ� ������� �ɺ��� ���ڷ� ���� �� �����Ƿ�
// �� �̷��� ����ڰ� ����ϰ� �� �ɹ���ó���� �� �ִ�.(CRTP)
class Cursor : public Singleton<Cursor>{

};

void main(){
	Cursor& c1 = Cursor::getInstance(); // �⺻ ������
	Cursor& c2 = Cursor::getInstance();
	cout << "c1 : " << &c1 << ", c2 : " << &c2 << endl;
}
