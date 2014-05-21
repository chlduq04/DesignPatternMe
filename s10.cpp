#include <iostream>
#include <vector>
//객체를 생성하는 패턴 - 팩토리 패턴
using namespace std;
//모든 타입을 다 처리하도록 부모클래스 설걔
class Shape{
public:
	//자식의 공통함수는 다 구현하자
	virtual void draw() = 0;
	virtual Shape* clone() = 0;
};
class Rect : public Shape{
public:
	void draw(){ cout << "drawing rect" << endl; }
	Shape* clone(){ return new Rect(*this); }
};
class Circle : public Shape{
	void draw(){ cout << "drawing Circle" << endl; }
	Shape* clone(){ return new Circle(*this); }
};
class Triangle : public Shape{
	void draw(){ cout << "drawing Triangle" << endl; }
	Shape* clone(){ return new Triangle(*this); }
};

class ShapeFactory{
public:
	Shape* make(int cmd){
		switch (cmd){
		case 1: return new Rect; 
		case 2: return new Circle; 
		case 3: return new Triangle; 
		default: break;
		}
	}
};

void main(){
	vector<Shape*> v;
	ShapeFactory sh;
	while (1){
		int cmd;
		cin >> cmd; // 1. 사각형, 2. 원, 3. 삼각형, 복사, 출력
		if (cmd < 0){
			continue;
		}
		if (cmd == 0){
			for (int i = 0;i<v.size();i++){
				v[i]->draw(); // 다형성(polymophism)
				continue;
			}
		}
		else if (cmd == 9){
			cout << "몇번도형 복사 : ";
			int num; cin >> num;
			v.push_back(v[num]->clone());
			continue;
		}

		v.push_back(sh.make(cmd));
	}

}