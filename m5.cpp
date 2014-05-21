#if 0
#include <iostream>
using namespace std;

class Button{
private:
	struct OnClickListener;
	OnClickListener * listener;
public:
	//버튼 이벤트를 처리하는 모든 객체는 아래의 인터페이스를 반드시 구현해야 합니다.
	struct OnClickListener{
		virtual ~OnClickListener(){}
		virtual void onClick() = 0;
	};
	void setOnClickListener(OnClickListener *p){
		listener = p;
	}
	void click(){ listener->onClick(); }
};

class MainActivity : public Button::OnClickListener{
public:
	void onClick(){
		cout << "clicked button" << endl;
	}
};

// 이벤트 처리는 가능하지만 어떠한 객체에서 이벤트가 발생했는지 알 수 없다.
// 그래서 안드로이드는 id를 사용한다.

void main(){
	MainActivity a;
	Button btnOK, btnCancle;
	btnOK.setOnClickListener(&a);
	btnCancle.setOnClickListener(&a);

	getchar();
	btnOK.click();
	btnCancle.click();
}

/*
void main(){
MainActivity activity;
Button btn;
btn.setOnClickListener(&activity);
getchar();
btn.click();
}
*/


#if 0
#endif
#include <iostream>
using namespace std;
enum{ BTN_OK, BTN_CANCEL }; // R.java

class Button{
private:
	struct OnClickListener;
	OnClickListener * listener;

	int id;// 현재 버튼을 식별하기 위하여 아이디를 설정합니다.

public:
	Button(int id) : id(id){}
	int getId(){ return id; }
	//버튼 이벤트를 처리하는 모든 객체는 아래의 인터페이스를 반드시 구현해야 합니다.
	struct OnClickListener{
		virtual ~OnClickListener(){}
		virtual void onClick(Button& btn) = 0;
		//이런 인터페이스기반 컨트롤은 성능상 이슈가 있다 
		//그래서 함수포인터로 한다.
	};
	void setOnClickListener(OnClickListener *p){
		listener = p;
	}
	void click(){ listener->onClick(*this); }
};

class MainActivity : public Button::OnClickListener{
public:
	void onClick(Button &btn){
		switch (btn.getId()){
		case BTN_OK:
			cout << "clicked Ok" << endl;
			break;
		case BTN_CANCEL : 
			cout << "clicked Cancel" << endl;
			break;
		}
	}
};

// 이벤트 처리는 가능하지만 어떠한 객체에서 이벤트가 발생했는지 알 수 없다.
// 그래서 안드로이드는 id를 사용한다.

void main(){
	MainActivity a;
	Button btnOK(BTN_OK), btnCancle(BTN_CANCEL);
	btnOK.setOnClickListener(&a);
	btnCancle.setOnClickListener(&a);

	getchar();
	btnOK.click();
	btnCancle.click();
}
#endif

//함수 포인터 기반의 이벤트 핸들링 기법
//MFC, Qt, ios가 이 방식 핸들링

#include <iostream>
using namespace std;

class Dialog{
public :
	void close(){ cout << "Dialog::close()" << endl; }

};

class Button{
	Dialog* pDlg;
	void(Dialog::*handler)();//selector, 이것은 Dialog형만 사용할 수 있다. 그래서 범용함수 포인터가 필요하다.
public : 
	void setHandler(Dialog* p, void(Dialog::*h)()){
		pDlg = p;
		handler = h;
	}
	void click(){
		(pDlg->*handler)();
	}

};

void main(){
	Dialog dlg;
	Button btnClose;
	btnClose.setHandler(&dlg,&Dialog::close);

	getchar();
	btnClose.click();
}

