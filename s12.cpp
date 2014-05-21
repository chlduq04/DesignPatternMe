#if 0
#include <iostream>
#include <algorithm>
using namespace std;
//inline 재귀, 함수포인터는 구분할 수가 없어서 inline이 적요안된다.
void sort(int* arr, int len, bool(*cmp)(int,int)){
	for (int i = 0;i<len-1;i++){
		for (int j = i + 1;j<len;j++){
			if (cmp(arr[i],arr[j])){
				swap(arr[i], arr[j]);
			}
		}
	}
}
bool asc_int(int a, int b){ return a > b; }
bool dsc_int(int a, int b){ return a < b; }
void display(int* arr, int len){
	for (int i = 0;i<len;i++){
		printf("%3d ",arr[i]);
	}
	getchar();
}

void main(){
	int arr[10] = {1,3,5,7,9,2,4,6,8,10};
	display(arr, 10);
	sort(arr, 10, asc_int);
	display(arr, 10);
	sort(arr, 10, dsc_int);
	display(arr, 10);
}
#endif


#if 0
#include <iostream>
using namespace std;

class Adder{
public: 
	int operator()(int a, int b){ return a + b; }
};

class Suber{
public:
	int operator()(int a, int b){ return a - b; }
};

void main(){
	Adder add;
	cout << add(1,1) << endl;

	Suber sub;
	cout << sub(1,1) << endl;
}

#endif

#include <iostream>
#include <algorithm>
using namespace std;


struct Lesser{
public:
	inline bool operator()(int a, int b){ return a > b; }
};

struct Greater{
public:
	inline bool operator()(int a, int b){ return a < b; }
};

template <typename T>
//inline 재귀, 함수포인터는 구분할 수가 없어서 inline이 적요안된다.
void sort(int* arr, int len, T cmp){
	for (int i = 0; i<len - 1; i++){
		for (int j = i + 1; j<len; j++){
			if (cmp(arr[i], arr[j])){
				swap(arr[i], arr[j]);
			}
		}
	}
}
/*
void sort(int* arr, int len, Greater cmp){
	for (int i = 0; i<len - 1; i++){
		for (int j = i + 1; j<len; j++){
			if (cmp(arr[i], arr[j])){
				swap(arr[i], arr[j]);
			}
		}
	}
}
*/
void display(int* arr, int len){
	for (int i = 0; i<len; i++){
		printf("%3d ", arr[i]);
	}
	getchar();
}

void main(){
	Lesser l;
	Greater g;
	int arr[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
	display(arr, 10);
	sort(arr, 10, l);
	display(arr, 10);
	sort(arr, 10, g);
	display(arr, 10);
}