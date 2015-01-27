#include <stdio.h>
#include <stdlib.h>
#include <emmintrin.h>
#include <inttypes.h>
#include <smmintrin.h>




int main(void)
{
	__m128i save_mask = _mm_set_epi8(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
	__m128i test = (__m128i)0x1122334455667788;
	__m128i save = _mm_shuffle_epi8(test, save);
	printf("%llx\n", (unsigned long long)(save>>64));
	printf("%llx\n", (unsigned long long)save);
	printf("%llx\n", (unsigned long long)(test>>64));
	printf("%llx\n", (unsigned long long)(test));

	printf("%llx\n", (unsigned long long)(save_mask>>64));
	printf("%llx\n", (unsigned long long)save_mask);

}
