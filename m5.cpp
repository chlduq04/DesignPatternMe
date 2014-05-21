#if 0
#include <iostream>
using namespace std;

class Button{
private:
	struct OnClickListener;
	OnClickListener * listener;
public:
	//��ư �̺�Ʈ�� ó���ϴ� ��� ��ü�� �Ʒ��� �������̽��� �ݵ�� �����ؾ� �մϴ�.
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

// �̺�Ʈ ó���� ���������� ��� ��ü���� �̺�Ʈ�� �߻��ߴ��� �� �� ����.
// �׷��� �ȵ���̵�� id�� ����Ѵ�.

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

	int id;// ���� ��ư�� �ĺ��ϱ� ���Ͽ� ���̵� �����մϴ�.

public:
	Button(int id) : id(id){}
	int getId(){ return id; }
	//��ư �̺�Ʈ�� ó���ϴ� ��� ��ü�� �Ʒ��� �������̽��� �ݵ�� �����ؾ� �մϴ�.
	struct OnClickListener{
		virtual ~OnClickListener(){}
		virtual void onClick(Button& btn) = 0;
		//�̷� �������̽���� ��Ʈ���� ���ɻ� �̽��� �ִ� 
		//�׷��� �Լ������ͷ� �Ѵ�.
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

// �̺�Ʈ ó���� ���������� ��� ��ü���� �̺�Ʈ�� �߻��ߴ��� �� �� ����.
// �׷��� �ȵ���̵�� id�� ����Ѵ�.

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

//�Լ� ������ ����� �̺�Ʈ �ڵ鸵 ���
//MFC, Qt, ios�� �� ��� �ڵ鸵

#include <iostream>
using namespace std;

class Dialog{
public :
	void close(){ cout << "Dialog::close()" << endl; }

};

class Button{
	Dialog* pDlg;
	void(Dialog::*handler)();//selector, �̰��� Dialog���� ����� �� �ִ�. �׷��� �����Լ� �����Ͱ� �ʿ��ϴ�.
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

