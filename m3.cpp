#include <iostream>
#include <memory>
using namespace std;

struct Node{
	int data;
	weak_ptr<Node> next;// dlfjgrp!!
	~Node(){ cout << "��� �ı�" << endl; }
};

void main(){
	//weak_ptr : wp -> ���������� ������������� �ʿ���� ����� �ƴ϶�
	//shared_ptr : sp
	shared_ptr<Node> p1(new Node);
	shared_ptr<Node> p2(new Node);
	p1->next = p2;
	p2->next = p1;
}