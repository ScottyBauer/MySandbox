#include <time.h>
#include <stdlib.h>
#include <stdio.h>


static int count;

static int oneinthree(void)
{
	count++;
	if((rand() % 2) == 0)
		return 0;
	else
		return 1 - oneinthree();
}

int main(void)
{
	srand(21);
	unsigned int loop = 0xffffffff;
	int max = 0;
	while(--loop){
		oneinthree();
		//		printf("Count is %d\n",count);
		if(count > max)
			max = count;
		count = 0;
	}
	      
	printf("max is %d\n", max);

}
