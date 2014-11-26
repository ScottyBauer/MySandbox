#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void* my_memmove(void* _src, void* _dest, size_t amount)
{

	unsigned char * src = _src;
	unsigned char * dest = _dest;

	/* few cases, the man page for memmove says that 'as if a
	   temporrary buffer'  were used
	*/

	if(src == dest)
		return dest;
	
	
	/* copy backwards */
	if(dest > src) {
		src += (amount-1);
		dst += (amount-1);
		while(amount--){
			*dest = *src;
			dest--;
			src--;
		}
	}
	else{
		while(amount--){
			*dest = *src;
			src++;
			dest++;
		}
	}
	return _dest;
}

/* attempt at an optimized memcpy, possibly force using xmm regs */


static void* my_memmove_fast(void* _src, void* _dest, size_t amount)
{
	unsigned long long *src = _src;
	unsigned long long *dest = _dest;
	
	/* standard says (I think) guaranteed to be AT LEAST 64 bit */
	size_t longsize = sizeof(unsigned long long);
	
	if(src == dest)
		return dest;
	
	if( dest > src) {
		while(amount >= longsize) {
			*dest = *src;
			dest--;
			src--;
			amount -= longsize;
		}
	}
	else{
		while(amount >= longsize) {
			*dest = *src;
			dest++;
			src++;
			amount -= longsize;
		}
	}	
	

	/* clean up if cpy amount was not % 64 bit */
	/* inline me! */
	if(amount > 0){
		my_memmove(src,dest,amount);
	}
	return _dest;
}



int main(int argc, char **argv)
{
	
	size_t strlength = strlen(argv[1]);
	
	char * temp = malloc(strlength+1);
	if(!temp) {
		exit(EXIT_FAILURE);
	}
	
	temp[strlength] = '\0';

	temp = my_memmove_fast(argv[1],temp,strlength);
	printf("%s %s\n", argv[1],temp);

	return EXIT_SUCCESS;

}
