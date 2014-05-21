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
		cout << getTitle() <<" 메뉴가 선택됨" << endl;
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
	//팝업 메뉴는 자신이 클릭될 경우, 자신이 가지고 있는 메뉴 아이템을 출력해야 합니다.
	void command(){
		while (1){
			system("cls");
			int size = items.size();
			for (int i = 0; i < size; i++){
				cout << i + 1 << ". " << items[i]->getTitle() << endl;
			}
			cout << size + 1 << ". 상위 메뉴로" << endl;

			int cmd;
			cout << "# 메뉴를 선택하세요" << endl;
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
	PopupMenu* menu = new PopupMenu("파일");
	menu->addMenu(new MenuItem("열기"));
	menu->addMenu(new MenuItem("저장"));
	menu->addMenu(new MenuItem("인쇄"));
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
		cout << getTitle() << " 메뉴가 선택됨" << endl;
		getch();
	}

};

class PopupMenu : public BaseMenu{
	vector<BaseMenu* > items;
public:
	PopupMenu(string t) :BaseMenu(t){}
	void addMenu(BaseMenu* p){ items.push_back(p); }
	//팝업 메뉴는 자신이 클릭될 경우, 자신이 가지고 있는 메뉴 아이템을 출력해야 합니다.
	void command(){
		while (1){
			system("cls");
			int size = items.size();
			for (int i = 0; i < size; i++){
				cout << i + 1 << ". " << items[i]->getTitle() << endl;
			}
			cout << size + 1 << ". 상위 메뉴로" << endl;

			int cmd;
			cout << "# 메뉴를 선택하세요" << endl;
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

//컴포지트 패턴
int main(){

	PopupMenu* menubar = new PopupMenu("메뉴바");

	PopupMenu* file = new PopupMenu("파일");
	file->addMenu(new MenuItem("열기"));
	file->addMenu(new MenuItem("저장"));
	file->addMenu(new MenuItem("인쇄"));
	menubar->addMenu(file);
	
	PopupMenu* edit = new PopupMenu("편집");
	edit->addMenu(new MenuItem("복사하기"));
	edit->addMenu(new MenuItem("잘라내기"));
	edit->addMenu(new MenuItem("붙여넣기"));
	menubar->addMenu(edit);

	menubar->command();
	return 0;
}