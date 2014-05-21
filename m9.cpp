#if 0

//속성이 동일한 객체를 공유하는 디자인 패턴 기법 : 플라이웨이트 기법
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

// 문제점 : 동일한 이미지를 다운로드하여 서로 다른 객체로 생성하므로 메모리의 낭비가 발생.

#endif


// 속성이 동일한 객체를 공유하는 디자인 패턴 기법 : 플라이웨이트 기법
#include <iostream>
#include <string>
#include <Windows.h>
#include <map>
using namespace std;

// 사용자가 객체의 생성을 임의로 할 수 없도록 private 생성자를 도입합니다.
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

// 문제점 : 동일한 이미지를 다운로드하여 서로 다른 객체로 생성하므로 메모리의 낭비가 발생.

// 디자인 패턴
// 책추천 : 헤드 퍼스트 디자인 패턴 -> 자바
// 책추천 : GOF 디자인 패턴 -> C++
// 책추천 : 클래스 구조의 이해와 설계
// 책추천 : Elemental Design Patterns
// 책추천 : 실전 코드로 배우는 실용주의 디자인패턴
// 책추천 : 디자인패턴 (피어슨에듀케이션코리아)
// 리팩토링 마틴 파울러

//아키텍쳐
// CBD 