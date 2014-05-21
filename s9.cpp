#if 0
#include <iostream>// GoF's Singleton
#include <string>
#include <vector>
#include <conio.h>

using namespace std;
class MenuItem{

private:
	string title;
public:
	MenuItem(string t) : title(t){}
	string getTitle(){
		return title;
	}
	void command(){
		cout << getTitle() <<" �޴��� ���õ�" << endl;
		getch();
	}

};

class PopupMenu{
	string title;
	vector<MenuItem* > items;
public:
	PopupMenu(string t):title(t){}
	string getTitle(){ return title; }
	void addMenu(MenuItem* p){ items.push_back(p); }
	//�˾� �޴��� �ڽ��� Ŭ���� ���, �ڽ��� ������ �ִ� �޴� �������� ����ؾ� �մϴ�.
	void command(){
		while (1){
			system("cls");
			int size = items.size();
			for (int i = 0; i < size; i++){
				cout << i + 1 << ". " << items[i]->getTitle() << endl;
			}
			cout << size + 1 << ". ���� �޴���" << endl;

			int cmd;
			cout << "# �޴��� �����ϼ���" << endl;
			cin >> cmd;

			if (cmd == size + 1){
				break;
			}
			if (cmd < 1 || cmd > size+1){
				continue;
			}
			items[cmd - 1]->command();
		}
	}
};
int main(){
	PopupMenu* menu = new PopupMenu("����");
	menu->addMenu(new MenuItem("����"));
	menu->addMenu(new MenuItem("����"));
	menu->addMenu(new MenuItem("�μ�"));
	return 0;
}
#endif
#pragma warning(disable:4996)
#include <iostream>// GoF's Singleton
#include <string>
#include <vector>
#include <conio.h>
using namespace std;
class BaseMenu{
	string title;
public:
	virtual void command() = 0;
	BaseMenu(string t) : title(t){}
	string getTitle(){ return title; };
};

class MenuItem : public BaseMenu{

public:
	MenuItem(string t) : BaseMenu(t){}
	void command(){
		cout << getTitle() << " �޴��� ���õ�" << endl;
		getch();
	}

};

class PopupMenu : public BaseMenu{
	vector<BaseMenu* > items;
public:
	PopupMenu(string t) :BaseMenu(t){}
	void addMenu(BaseMenu* p){ items.push_back(p); }
	//�˾� �޴��� �ڽ��� Ŭ���� ���, �ڽ��� ������ �ִ� �޴� �������� ����ؾ� �մϴ�.
	void command(){
		while (1){
			system("cls");
			int size = items.size();
			for (int i = 0; i < size; i++){
				cout << i + 1 << ". " << items[i]->getTitle() << endl;
			}
			cout << size + 1 << ". ���� �޴���" << endl;

			int cmd;
			cout << "# �޴��� �����ϼ���" << endl;
			cin >> cmd;

			if (cmd == size + 1){
				break;
			}
			if (cmd < 1 || cmd > size + 1){
				continue;
			}
			items[cmd - 1]->command();
		}
	}
};

//������Ʈ ����
int main(){

	PopupMenu* menubar = new PopupMenu("�޴���");

	PopupMenu* file = new PopupMenu("����");
	file->addMenu(new MenuItem("����"));
	file->addMenu(new MenuItem("����"));
	file->addMenu(new MenuItem("�μ�"));
	menubar->addMenu(file);
	
	PopupMenu* edit = new PopupMenu("����");
	edit->addMenu(new MenuItem("�����ϱ�"));
	edit->addMenu(new MenuItem("�߶󳻱�"));
	edit->addMenu(new MenuItem("�ٿ��ֱ�"));
	menubar->addMenu(edit);

	menubar->command();
	return 0;
}