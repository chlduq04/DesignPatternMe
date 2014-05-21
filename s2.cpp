//Java�� Thread�� ���� �����ӿ�ũ�� ���������� c�� c++�� ���� �������� �ʴ´�.
#include <iostream>
using namespace std;

// �Լ��� Ÿ���� ����Ÿ�� + �Ű�����
// �Լ��� ���� : ����Ÿ�� �Լ���(�Ű�����);
void function(){
	cout << "::function()" << endl;
}

class Clazz{
public:
	void member_function(){
		cout << "Clazz::member_function()" << endl;
	}
	static void class_function(){
		cout << "Clazz::class_function()" << endl;
	}
};

void main(){
	int n;
	//������ ������ ������ : Ÿ�� * ������;
	int *p = &n;//�����϶� �󸶳� ������ ���� �̷��� ����� 4 byte�� �д´�.

	//�Լ��� �ּҸ� ��� ���
	printf("0x%p\n", &function);//�ּҰ��� ��µȴ�.

	//�����Ϸ��� �ڿ��� �ؼ�
	//�׷��� void* func()�� �Լ��� �ؼ��Ѵ�.
	//�̰��� �Լ� �����Ͷ�� ���� �̾߱��ؾ� �Ѵ�.
	void(*func)() = &function;
	func();

	//�Լ� ȣ��Ծ��� �ִ� calling convention
	void(*fp1)() = &function;
	void(*fp2)() = &Clazz::class_function;
	void(Clazz::*fp3)() = &Clazz::member_function;
	//void(__thisclass *fp3)() = &Clazz::member_function; �̷� �ǹ������� ���� ����� �Ұ���
	fp1();
	fp2();

	Clazz clazz;
	//fp3(); fp3(&clazz)�̷��� �Ǵ°� �����Ϸ��� ���ִ°��� ���� ������ ����.
	(clazz.*fp3)();
	//.*�̰� �ϳ��� �����ھ� �Ϲ������� this�� �־��� ���� �����ϱ� �̷��� ȣ���ؾ��Ѵ�.

	Clazz *cp = new Clazz;
	(cp->*fp3)();
	//->*�̰ŵ� �ϳ��� �����ڴ�.

}