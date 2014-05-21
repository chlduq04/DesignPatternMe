#if 0
//��ü�� ���¸� �����ϴ� ���� ��� - ����(state)����
#include <iostream>
using namespace std;
//������ �ɸ��� �����غ��ô�.
//�ڵ��� ������ �߻��ϰԵȴ�.
enum { item1, item2 };
class Charactor{
	int hp;
public:
	void run(int item){
		if (item == item1){
			cout << "run" << endl;
		}
		else if (item == item2){
			cout << "run fast" << endl;
		}
	}
	void attack(){
		cout << "attack" << endl;
	}
};

void main(){
	Charactor c;
	c.run();
	c.attack();
}

#endif


#if 0 
#include <iostream>
using namespace std;
//������ �ɸ��� �����غ��ô�.
enum { item1, item2 };
class Character{
	int hp;
public:
	void run(){ runImpl(); }
	void attack(){ attackImpl();  }

	virtual void runImpl(){}
	virtual void attackImpl(){}
};

class NormalCharacter : public Character{
public : 
	void runImpl(){ cout << "NormalCharacter::run" << endl; }
	void attackImpl(){ cout << "NormalCharacter::attack" << endl; }

};

class Item1Character : public Character{
public : 
	void runImpl(){ cout << "Item1Character::run" << endl; }
	void attackImpl(){ cout << "Item1Character::attack" << endl; }
};
// ����� �̿��� ������ ������ �ſ� ������ �����̹Ƿ� ���α׷��� �������� �������� �ڵ��� ��뷮�� �����մϴ�.
void main(){

	Character *c = new NormalCharacter;
	c->run();
	getchar();

	c = new Item1Character();
	c->run();
}

#endif

#include <iostream>
using namespace std;
//������ �ɸ��� �����غ��ô�.
enum { item1, item2 };

//���¿� ���� �������� �������̽�
struct IState{
	virtual ~IState(){};
	virtual void runImpl() = 0;
	virtual void attackImpl() = 0;
};

class Character{
	int hp;
	IState* state;
public:
	void setState(IState* p){ state = p; }
	void run(){ state->runImpl(); }
	void attack(){ state->attackImpl(); }
};



class NormalCharacter : public IState{
public:
	void runImpl(){ cout << "NormalCharacter::run" << endl; }
	void attackImpl(){ cout << "NormalCharacter::attack" << endl; }
};

class Item1Character : public IState{
public:
	void runImpl(){ cout << "Item1Character::run" << endl; }
	void attackImpl(){ cout << "Item1Character::attack" << endl; }
};
// ����� �̿��� ������ ������ �ſ� ������ �����̹Ƿ� ���α׷��� �������� �������� �ڵ��� ��뷮�� �����մϴ�.
void main(){

	Character c;

	NormalCharacter nc;
	Item1Character ic;

	c.setState(&nc);
	c.run();
	getchar();
	
	c.setState(&ic);
	c.run();
}
