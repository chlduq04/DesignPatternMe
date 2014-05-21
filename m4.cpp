#if 0
//객체의 상태를 변경하는 설계 기법 - 상태(state)패턴
#include <iostream>
using namespace std;
//게임의 케릭을 생각해봅시다.
//코드의 수정이 발생하게된다.
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
//게임의 케릭을 생각해봅시다.
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
// 상속을 이용한 디자인 패턴은 매우 경직된 구조이므로 프로그램의 유연성이 떨어지며 코드의 사용량이 증가합니다.
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
//게임의 케릭을 생각해봅시다.
enum { item1, item2 };

//상태에 따른 동작정의 인터페이스
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
// 상속을 이용한 디자인 패턴은 매우 경직된 구조이므로 프로그램의 유연성이 떨어지며 코드의 사용량이 증가합니다.
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
