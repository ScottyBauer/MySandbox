#include <stdio.h>
#include <stdlib.h>


static void modify_ptrs(void* orig, void **_orig){
	orig+=4;
	*_orig+=4;
}


int main(void){
	int test1 = 99;
	int test2 = 100;
	int *ptr = &test2;
	int *ptr2 = &test1;
	
	printf("ptr %p, and ptr2 %p\n", ptr, ptr2);
	modify_ptrs((void*)ptr2, (void**)&ptr);
	printf("ptr %p, and ptr2 %p\n", ptr, ptr2);
	



}
