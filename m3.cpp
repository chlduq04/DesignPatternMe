#include <iostream>
#include <memory>
using namespace std;

struct Node{
	int data;
	weak_ptr<Node> next;// dlfjgrp!!
	~Node(){ cout << "노드 파괴" << endl; }
};

void main(){
	//weak_ptr : wp -> 참조변수를 사용하지않지만 필요없는 기능이 아니라
	//shared_ptr : sp
	shared_ptr<Node> p1(new Node);
	shared_ptr<Node> p2(new Node);
	p1->next = p2;
	p2->next = p1;
}