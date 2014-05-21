#include <iostream>
using namespace std;

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
//inline 재귀, 함수포인터는 구분할 수가 없어서 inline이 적요안된다.
void sort(int* arr, int len, bool(*cmp)(int,int)){
	for (int i = 0; i<len - 1; i++){
		for (int j = i + 1; j<len; j++){
			if (cmp(arr[i], arr[j])){
				swap(arr[i], arr[j]);
			}
		}
	}
}

bool asc_cmp(int a, int b){
	return a < b;
}
bool dsc_cmp(int a, int b){
	return a > b;
}

void display(int *arr,int len){
	for (int i = 0;i<len;i++){
		printf("%2d ",arr[i]);
	}
	getchar();
}

void main(){
	int arr[10] = {2,4,6,8,10,1,3,5,7,9};
	display(arr,10);

	// 함수 포인터
	// 장점 : 정책을 변경해도 sort는 코드한개
	// 단점 : 정책을 인라인 치환할 수 없다 : 성능저하
	sort(arr, 10, asc_cmp);
	display(arr,10);
	sort(arr, 10, dsc_cmp);
	display(arr, 10);
}


// 함수 포인터는 시그니처가 같으면 모두 같은 타입이지만
// 함수 객체는 시그니처가 같더라도 모두 다른 타입니다.


