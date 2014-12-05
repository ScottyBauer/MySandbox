#include <stdio.h>
#include <stdlib.h>


static void modify_ptrs(void* orig, void **_orig){
	orig+=4;
	*_orig+=4;
}


int main(void){
	int test1 = 99;
	int test2 = 100;
	int *SHOULD_BE_MODIFIED = &test2;
	int *SHOULD_NOT_BE_MODIFIED = &test1;
	
	printf("SHOULD_NOT_BE_MODIFIED %p, and SHOULD_BE_MODIFIED %p\n", SHOULD_NOT_BE_MODIFIED, SHOULD_BE_MODIFIED);
	modify_ptrs((void*) SHOULD_NOT_BE_MODIFIED, (void**)&SHOULD_BE_MODIFIED);
	printf("SHOULD_NOT_BE_MODIFIED %p, and SHOULD_BE_MODIFIED %p\n", SHOULD_NOT_BE_MODIFIED, SHOULD_BE_MODIFIED);	


	



}
