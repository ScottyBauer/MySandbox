#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



/* Do memory mapped files get updated to the filesystem without a sync() ? */

/* I guess I could just read the man page, lol 

   MAP_SHARED Share this mapping.  Updates to the mapping are visible to
   other processes that map this file, and are carried
   through to the underlying file.  The file may not actually
   be updated until msync(2) or munmap() is called.
*/

static const char* text = "MAP_SHARED Share this mapping.  Updates to the mapping are visible to other processes that map this file, and are carried through to the underlying file. The file may not actuallbe updated until msync(2) or munmap() is called.";

int main(void)
{

	char *file = 0;
	int fd = open("test1.txt", O_RDWR);
	if(fd < 0){
		printf("Open failure with %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	
	file = mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_SHARED,fd, 0);
	strncpy(file,text,4096);
	printf("strncpy complete, look at the file, sleeping for 15 seconds\n");
	sleep(15);
	printf("Now syncing with msync()\n");
	msync(file,4096,MS_SYNC);
	printf("Sync'd sleeping for 30 sec\n");
	sleep(15);
	munmap(file,4096);
	
	return EXIT_SUCCESS;

	
	

}
