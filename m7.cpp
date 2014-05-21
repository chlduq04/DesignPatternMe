#if 0 

#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

class LineEdit{
	string text;
	bool(*validate)(int ch);

public:
	void setValidator(bool(*v)(int)){ validate = v; }
	string getText(){
		text.clear();
		while (true){
			int ch = _getch();
			if (ch == 13){ break; }
			if (validate(ch)){
				text.push_back(ch);
				cout << ch;
			}
		}
		cout << endl;
		return text;
	}
};
bool isNumber(int ch){ return isdigit(ch) ? true : false; }

void main(){
}
#endif

#if 0

#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

class LineEdit{
	string text;
	virtual bool validate(char ch){ return true; }

public:
	string getText(){
		text.clear();
		while (true){
			int ch = _getch();
			if (ch == 13){ break; }
			if (validate(ch)){
				text.push_back(ch);
				cout << ch;
			}
		}
		cout << endl;
		return text;
	}
};

//라이브러리 : 
//프레임워크 : 일정한 실행의 흐름을 같이 제공하여 요구하는 스팩대로 만들어야한다.(템플릿 메소드 패턴)

class NumberLineEdit : public LineEdit{
public : 
	virtual bool validate(char ch){ return isdigit(ch) ? true : false; }
};

void main(){
	NumberLineEdit edit;
	while (true){
		string s = edit.getText();
		cout << s << endl;
	}
}

#endif


#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

struct IValidator{
	virtual ~IValidator(){}
	virtual bool validate(char ch) = 0;
};


struct LineEdit{
	string text;
	IValidator* pValidator;
public:
	LineEdit() : pValidator(0){}
	void setValidator(IValidator* p ){ pValidator = p; }

	string getText(){
		text.clear();
		while (true){
			int ch = _getch();
			if (ch == 13){ break; }
			if (pValidator == 0 || pValidator->validate(ch)){
				text.push_back(ch);
				cout << ch;
			}
		}
		cout << endl;
		return text;
	}

};

class NumberValidator : public IValidator{
public : 
	bool validate(char ch){ return isdigit(ch) ? true : false; }
};
//라이브러리 : 
//프레임워크 : 일정한 실행의 흐름을 같이 제공하여 요구하는 스팩대로 만들어야한다.(템플릿 메소드 패턴)


void main(){
	LineEdit edit;
	NumberValidator v;
	edit.setValidator(&v);
	while (true){
		string s = edit.getText();
		cout << s << endl;
	}
}
