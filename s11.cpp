#if 0
#define ADD(x,y) ((x)+(y))
#define 
#include <iostream>
using namespace std;

void add(int a, int b, int *result){
	*result = a + b;
}
void main(){
	int ret;
	add(1,1,&ret);
	
	__asm{
		mov ret, eax
	}

	cout << ret << endl;
}
#endif
#if 0
#include <iostream>
using namespace std;

int add(int a, int b){ return a + b; }
inline int inline_add(int a, int b){ return a + b; }

void main(){
	int n = add(1, 1);
	int m = inline_add(1,1);
}
#endif
