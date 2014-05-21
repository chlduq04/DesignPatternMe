#include <iostream>
using namespace std;

template <typename T>
//inline ���, �Լ������ʹ� ������ ���� ��� inline�� ����ȵȴ�.
void sort(int* arr, int len, T cmp){
	for (int i = 0; i<len - 1; i++){
		for (int j = i + 1; j<len; j++){
			if (cmp(arr[i], arr[j])){
				swap(arr[i], arr[j]);
			}
		}
	}
}
//inline ���, �Լ������ʹ� ������ ���� ��� inline�� ����ȵȴ�.
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

	// �Լ� ������
	// ���� : ��å�� �����ص� sort�� �ڵ��Ѱ�
	// ���� : ��å�� �ζ��� ġȯ�� �� ���� : ��������
	sort(arr, 10, asc_cmp);
	display(arr,10);
	sort(arr, 10, dsc_cmp);
	display(arr, 10);
}


// �Լ� �����ʹ� �ñ״�ó�� ������ ��� ���� Ÿ��������
// �Լ� ��ü�� �ñ״�ó�� ������ ��� �ٸ� Ÿ�Դϴ�.


