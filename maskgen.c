#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int type = 0xB;
	long m,n;
	n = 32;
	m = 12;
	
	printf("%lx\n", (~(~0 << m) << n));
	printf("%lx\n", (~(~0 << m) << n) & ((type<<n)|(type<<n+4)|(type<<n+8)));

}
