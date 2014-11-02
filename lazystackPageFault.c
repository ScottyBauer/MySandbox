#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(void){
	int where_is_esp = 9;
	printf("Stack is at %p\n",&where_is_esp);
	char *test = alloca(4096 * 100000); //4 mB?
	printf("Stack is now at %p\n", test);
	if(test){
		test[0] = 'a';
		test[4095*100000] = 'a'; //fuck you gcc stop optimizing my shit.
	}
	printf("%c\n", *test);


}
