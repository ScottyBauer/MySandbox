#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


/* compiled with -m32 */


int main(void)
{

	unsigned int location;
	void *vlocation = &location;
	char *clocation = (char *) &location;
	
	assert(sizeof(void *) == 4);
	assert(sizeof(char*) == 4);
	
	assert(vlocation == clocation);
	printf("vlocation %p and cloation %p\n", vlocation+1, clocation+4);
	assert((vlocation+1) == (clocation+4));
	assert((vlocation+4) == (clocation+16));
	return EXIT_SUCCESS;
}
