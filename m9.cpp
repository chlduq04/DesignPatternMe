#if 0

//�Ӽ��� ������ ��ü�� �����ϴ� ������ ���� ��� : �ö��̿���Ʈ ���
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

class Image{
	string url;
public:
	Image(string u) : url(u){
		cout << "downloading image( " << url << " )"<< endl;
		Sleep(1000);
	}

	void draw(){
		cout << "image( " << url << " )"<< endl; 
	}
};

void main(){
	Image* image1 = new Image("http://www.naver.com");
	image1->draw();
	Image* image2 = new Image("http://www.naver.com");
	image2->draw();
}

// ������ : ������ �̹����� �ٿ�ε��Ͽ� ���� �ٸ� ��ü�� �����ϹǷ� �޸��� ���� �߻�.

#endif


// �Ӽ��� ������ ��ü�� �����ϴ� ������ ���� ��� : �ö��̿���Ʈ ���
#include <iostream>
#include <string>
#include <Windows.h>
#include <map>
using namespace std;

// ����ڰ� ��ü�� ������ ���Ƿ� �� �� ������ private �����ڸ� �����մϴ�.
class Image{
	string url;
	Image(string u) : url(u){
		cout << "downloading image( " << url << " )" << endl;
		Sleep(1000);
	}
	static map<string, Image*> imageMap;
public:
	static Image* imageWithUrl(string u){
		if (imageMap[u] == 0){
			imageMap[u] = new Image(u);
		}
		return imageMap[u];
	}
	void draw(){
		cout << "image( " << url << " )" << endl;
	}
};

map<string, Image*> Image::imageMap;

void main(){
	Image* image1 = Image::imageWithUrl("http://www.naver.com/a.png");
	image1->draw();
	Image* image2 = Image::imageWithUrl("http://www.naver.com/a.png");
	image2->draw();
}

// ������ : ������ �̹����� �ٿ�ε��Ͽ� ���� �ٸ� ��ü�� �����ϹǷ� �޸��� ���� �߻�.

// ������ ����
// å��õ : ��� �۽�Ʈ ������ ���� -> �ڹ�
// å��õ : GOF ������ ���� -> C++
// å��õ : Ŭ���� ������ ���ؿ� ����
// å��õ : Elemental Design Patterns
// å��õ : ���� �ڵ�� ���� �ǿ����� ����������
// å��õ : ���������� (�Ǿ�������̼��ڸ���)
// �����丵 ��ƾ �Ŀ﷯

//��Ű����
// CBD 