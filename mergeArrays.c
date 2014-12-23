#include <stdio.h>
#include <stdlib.h>

/* assume arrays A and B are given to us somewhere.. */
 int* A;
 int* B;
 int B_size = 6;
 int A_size = 12;
int A_soft_size = 6;

int find_loc_in_A(int b_ele, int *soft_size)
{
	int i;
	for(i = 0; i < *soft_size ; i++){
		if(b_ele > A[i]){
			continue;
		}
		else{
			return i;
		}
	}
	return A_size -1;
}

void shuffle_A(int start_loc, int *soft_size, int *A)
{
	/* copy backwards… 
	 *    plot twist:
	 *    we know where the end of A is but we don’t know where the ‘soft’ end is
	 *    ie where the last element is before free space. Lets fix that
	 */
	int i;
	/* use memmove for optimization? */    
	/* memmove(src, dst, size)? */
	for (i = (*soft_size) -1 ; i >= start_loc ; i--) {
		A[i+1] = A[i];
	}
	(*soft_size)++;
}

void merge_A(int loc, int b_ele, int* A)
{
	A[loc] = b_ele;
}

int main(void)
{

	A = malloc(12);
	B = malloc(6);
	A[0] = 1;
	A[1] = 3;
	A[2] = 5;
	A[3] = 7;
	A[4] = 9;
	A[5] = 11;
	B[0] = 2;
	B[1] = 4;
	B[2] = 6;
	B[3] = 8;
	B[4] = 10;
	B[5] = 12;

	int i;
	int a_loc = 0;
	int temp_soft = A_soft_size;
	for( i = 0; i < B_size; i++){
		a_loc = find_loc_in_A(B[i], &temp_soft);
		shuffle_A(a_loc, &temp_soft, A);
		merge_A(a_loc, B[i], A );
	}
	
	for(i = 0; i < A_size; i++){
		printf("%d\n", A[i]);
	}
}    
