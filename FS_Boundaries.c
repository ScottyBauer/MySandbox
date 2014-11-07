#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



static int search(char *input){
	int bool = 0;
	return memcmp(input,"MORAL SUCKS",11);
}


/* On the shellhost I use there are muiltiple users seperated by boundaires. this program is testing whetehr I can see deleted files from other users */

int main(void)
{

	int fd = open("LARGEFILE", O_RDWR|O_CREAT);
	char *file = 0;
	char *found = 0;
	char *original = 0;
	unsigned long long offp = 0;
	unsigned long long max_size = 109969500 * 1024;
	unsigned long long memchr_size = 0;
	unsigned long long GB = (1024*1024*1924);
	const char *string = "MORAL SUCKS2";
	int look_string_size = 12; 
       
	if(fd < 0){
		printf("Open Failure with %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	

	if(fallocate(fd, 0, 0, max_size) != 0){
		printf("fallocate failed, with %s\n",strerror(errno));
		exit(EXIT_FAILURE);
	}
	
	/* TODO SHOULD I DO MAP_POPULATE? is it any faster? */
	original = file = mmap(NULL, GB, PROT_READ, MAP_PRIVATE, fd, 0);

	if(!file){
		printf("Failed to mmap 1gb of the file, %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	
	offp = memchrsize = GB;
	do{
		
		found = memchr(file, 'M', memchrsize);
		//didnt find, unmap and remap and loop.
		if(!found){
			
			//munmap and remap, doing checks.
			if(munmap(original, GB) < 0){
				printf("Couldn't unmap file at %p, offset %llu, with error %s\n", file, offp, strerror(errno));
				exit(EXIT_FAILURE);
			}

			
			original = file = mmap(NULL, GB, PROT_READ, MAP_PRIVATE, fd, offp);
			if(!file){
				printf("Failed to mmap 1gb of the file, %s\n", strerror(errno));
				exit(EXIT_FAILURE);
			}
			memchrsize = GB; //may have done the else below a few times. 
			
			offp += GB;
		}
		else{
			//Do math to determine if we're about to blow out some bounnds. if we're not see if 11 away is a 2 or 1.
			//use a portion of booyer-moore algo

			/* weird edge case, what if the string lies between two GB boundaires, we need a really special gross edge case for that */
			
			if((found+(look_string_size-1) < (original + GB)){
					//not about to blow out of bounds, we know found[0] = M.
					if(found[11] == '2' || found[11] == '1'){
						if(search(found) == 0){
							printf("Found our string at fileoffset %llu\n", offp);
							exit(EXIT_SUCCESS);
						}
					}
					else{
						//too lazy to implement the true booyer-moore algo, just start at found+1.
						file = found++;
						memchrsize = found - original;
					}
				}
				else{
					/* TODO, time to abstract the unmapping and remapping ... */
					/* TODO, this else case is when we don't have enough bytes and we need to unmap and re-map, but also, we have that fishy case I listed above */
					
				}
			
		}

	}while(offp <= max_size);
	
	
	return EXIT_SUCCESS;
}
