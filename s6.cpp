#include <iostream>
using namespace std;
// �ڹٴ� ��� class�� �Ϲ������� Object�� ��ӹ޴´�.
// ���δٸ� ��ü�� �ϳ��� ��ü�� �ڵ鸵 �ϱ����� Object�� ���� ���̴�.
// ����� ������ �ڵ��� ���뼺�� ���������� �ƴ� ���δٸ� Ÿ���� �ϳ��� Ÿ������ ó���ϱ� ���Ͽ� ����մϴ�.
// Java : Object
// Android : RefBase

class Unit{

};

class Marine : public Unit{

};

class Ghost : public Unit{

};

void main(){
	Marine* m = new Marine;
	Ghost* g = new Ghost;
	Unit* group[2];
	group[0] = m;
	group[1] = g;
}