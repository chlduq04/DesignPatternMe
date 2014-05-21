#include <iostream>
#include <vector>
//��ü�� �����ϴ� ���� - ���丮 ����
using namespace std;
//��� Ÿ���� �� ó���ϵ��� �θ�Ŭ���� ����
class Shape{
public:
	//�ڽ��� �����Լ��� �� ��������
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
		cin >> cmd; // 1. �簢��, 2. ��, 3. �ﰢ��, ����, ���
		if (cmd < 0){
			continue;
		}
		if (cmd == 0){
			for (int i = 0;i<v.size();i++){
				v[i]->draw(); // ������(polymophism)
				continue;
			}
		}
		else if (cmd == 9){
			cout << "������� ���� : ";
			int num; cin >> num;
			v.push_back(v[num]->clone());
			continue;
		}

		v.push_back(sh.make(cmd));
	}

}