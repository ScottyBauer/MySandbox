#include <stdio.h>
#include <stdlib.h>

char toHex(int a){
	switch(a){
	case 0:
		return '0';
	case 1:
		return '1';
	case 2:
		return '2';
	case 3:
		return '3';
	case 4:
		return '4';
	case 5:
		return '5';
	case 6:
		return '6';
	case 7:
		return '7';
	case 8:
		return '8';
	case 9:
		return '9';
	case 0xa:
		return 'A';
	case 0xb:
		return 'B';
	case 0xc:
		return 'C';
	case 0xd:
		return 'D';
	case 0xe:
		return 'E';
	case 0xf:
		return 'F';


	}

}

int main(void){
	printf("switch\(var){\n");
	int i;
	for(i = 0; i < 256; i++){
		printf("\tcase %d:\n",i);
		printf("\t\t ox%c++;\n", toHex((i&0xf)));
		printf("\t\t ox%c++;\n", toHex(((i>>4)&0xf)));
		printf("\t\tbreak;\n");
	}
	printf("default:\n __builtin_abort();\n");
	printf("}\n");

}
