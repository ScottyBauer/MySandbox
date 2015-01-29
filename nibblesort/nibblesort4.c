#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>


static unsigned long cache[256];
static unsigned long count_cache[16] = {0x1,0x10,0x100,0x1000,0x10000, /* 0 -> 4 */
					0x100000,0x1000000,0x10000000,0x100000000, /* 5 ->8 */
					0x1000000000,0x10000000000,0x100000000000, /* 9,11 */
					0x1000000000000, 0x10000000000000,
					0x100000000000000, 0x1000000000000000};
					;

static unsigned long init_create_mask(char amount, char type)
{
	unsigned long all = type;
	int i;
	for(i=0; i < amount-1; i++){
		all = ((all << 4) | type);
	}
	return all;

}

__attribute__((constructor))
static void cache_init(void)
{
	int i, j;
	unsigned char count = 0;
	for(i = 0; i < 256; i+=16){
		for(j = 0; j < 16; j++){
			cache[i + j] = init_create_mask(j,count);
		}
		count++;
	}
}


void nibble_sort_scotty(unsigned long *buf);

static inline unsigned long create_mask(char amount, char type, char location)
{

	int i;
	unsigned long all = type;

	switch(amount){
	case 0:
		return 0;
	default:
		return cache[ (type * 16) + amount] << location;
	}
}




static inline unsigned long write_new(unsigned long input)
{

	unsigned int where = 64;
	unsigned long write = 0;
	int i;

	for(i = 15; i > 0 ; i--){
		where = where - ((input >> (4 * i)) & 0xF)*4;
		write |= create_mask((input>>(4 * i) & 0xF), i, where);
	}
	return write;
}





void nibble_sort_scotty(unsigned long *temp)
{
	__builtin_prefetch(temp,1,3);


	unsigned long sorted;
	int i,j,x;
	int word_holder;
	unsigned long locations = 0;
	unsigned long locations2 = 0; /* trying to eliminate data dependency */
	unsigned char *buf = (unsigned char *)temp;
	for(j = 0; j < 1024; j++){
		for(i = 0; i < 8; i++){
			locations += count_cache[buf[i] & 0xF];
			locations2 += count_cache[(buf[i]>>4) & 0xF];
		}

		__builtin_prefetch((temp+1),1,3);
		*temp = write_new(locations+locations2);
		temp++;
		locations = locations2 = 0;
		buf = (unsigned char *)temp;

	}
}


/*
  int main(void)
  {
  //	unsigned long test = 0xc67b1f9a06cac113;
  unsigned long test = 0x728dc8ba40781809;//0xfbbbc9741902c44c;// at 0 to sort to fcccbbb997444210
  nibble_sort_scotty(&test);
  printf("%lx\n", test);

  }


*/
