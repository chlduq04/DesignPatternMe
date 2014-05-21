#include <iostream>
using namespace std;
// 자바는 모든 class가 암묵적으로 Object를 상속받는다.
// 서로다른 객체를 하나의 객체로 핸들링 하기위해 Object를 만든 것이다.
// 상소의 본질은 코드의 재사용성과 유지보수가 아닌 서로다른 타입을 하나의 타입으로 처리하기 위하여 사용합니다.
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