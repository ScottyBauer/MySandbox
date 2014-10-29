#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


static unsigned extractBit(unsigned short input, unsigned index)
{
	assert(index < sizeof(input) * 8 );
	return (0x1 & (input >> index));

}

static unsigned countOnes(unsigned short input)
{
	size_t width = sizeof(input) * 8;
	unsigned count = 0;
	unsigned i;
	
	

	for(i = 0; i< width; i++){
		count += extractBit(input, i);
	}
     
	return count;

}

int main(void)
{
	unsigned short x;
	/* x = 0xC8;  11001000 3*/ 

	x = 0xC0; /* 11000000 6*/

	/* cttz should be 3 */

	size_t width = sizeof(unsigned short) * 8;
	unsigned half = width/2;
	unsigned ones = 0;
	unsigned i,j;
	unsigned result;

	
	for( i = 0, j = 0; j < width; i++){
		j = 1<<i;
		x = (x | (x<<j));
	}

	printf("%x\n",x);

	ones = countOnes(x);
	printf("ones is %d\n", ones);
	result = width - ones;
	printf("result = %u\n", result);
	assert(result == 6);
}
