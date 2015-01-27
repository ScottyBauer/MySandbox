#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
 

extern void nibble_sort_scotty(unsigned long *buf);

int read_nibble(unsigned long w, int i) {
  assert(i >= 0 && i < 16);
  unsigned long res = w >> (i * 4);
  return res & 0xf;
}
 
void write_nibble(unsigned long *w, int i, int v) {
  assert(i >= 0 && i < 16);
  unsigned long mask = 0xf;
  mask <<= (i * 4);
  *w &= ~mask;
  unsigned long prom = v;
  prom <<= (i * 4);
  *w |= prom;
}
 
unsigned long nibble_sort_word(unsigned long arg) {
  for (int i = 0; i < 16; ++i) {
    int min = i;
    for (int j = i+1; j < 16; ++j) {
      if (read_nibble(arg, j) < read_nibble(arg, min))
        min = j;
    }
    if (min != i) {
      int tmp = read_nibble(arg, i);
      write_nibble(&arg, i, read_nibble(arg, min));
      write_nibble(&arg, min, tmp);
    }
  }
  return arg;
}
 
void nibble_sort_ref(unsigned long *buf) {
  for (int i=0; i<1024; i++)
    buf[i] = nibble_sort_word(buf[i]);
}

 
static long timediff(struct timespec start, struct timespec end) {
  struct timespec temp;
  if ((end.tv_nsec-start.tv_nsec)<0) {
    temp.tv_sec = end.tv_sec-start.tv_sec - 1;
    temp.tv_nsec = 1000000000L + end.tv_nsec-start.tv_nsec;
  } else {
    temp.tv_sec = end.tv_sec-start.tv_sec;
    temp.tv_nsec = end.tv_nsec-start.tv_nsec;
  }
  return temp.tv_sec * 1000000000L + temp.tv_nsec;
}
 
static const int REPS = 25;
static const int BUFSIZE = 1024;
 
typedef void (*nibble_func_t)(unsigned long *buf);
typedef struct { nibble_func_t func; const char *name; } nibble_sort_t;
static nibble_sort_t funcs[] = {
  { nibble_sort_scotty, "scotty" },
};
 
int main (void) {
  assert(sizeof(unsigned long)==8);
  srand(time(NULL) + getpid());
 
  int res;
  unsigned long *data;
  res = posix_memalign((void **)&data, 4096, BUFSIZE*8);
  assert(res == 0);
  assert(data);
  assert(((intptr_t)data & 0xfff) == 0);
 
  unsigned long *buf;
  res = posix_memalign((void **)&buf, 4096, BUFSIZE*8);
  assert(res == 0);
  assert(buf);
  assert(((intptr_t)buf & 0xfff) == 0);
 
  unsigned long *buf2;
  res = posix_memalign((void **)&buf2, 4096, BUFSIZE*8);
  assert(res == 0);
  assert(buf2);
  assert(((intptr_t)buf2 & 0xfff) == 0);
 
  for (int i=0; i<BUFSIZE*8; i++)
    ((unsigned char *)data)[i] = rand() & 0xff;
 
  {
    memcpy(buf2, data, BUFSIZE*8);
    nibble_sort_ref(buf2);
    for (int func=0; func<sizeof(funcs)/sizeof(nibble_sort_t); ++func) {
      memcpy(buf, data, BUFSIZE*8);
      funcs[func].func(buf);
      for (int i=0; i<BUFSIZE; i++) {
        if (buf[i] != buf2[i]) {
          printf("oops expected %016lx at %d to sort to %016lx but got %016lx at iteration %d \n",
                 data[i], i, buf2[i], buf[i], i);
          assert(0);
        }
      }
    }
  }
 
  for (int func=0; func<sizeof(funcs)/sizeof(nibble_sort_t); ++func) {
    long times[REPS];
    
    for (int i=0; i<REPS; ++i) {
      memcpy(buf, data, BUFSIZE*8);
      struct timespec start, end;
      clock_gettime(CLOCK_REALTIME, &start);
      funcs[func].func(buf);
      clock_gettime(CLOCK_REALTIME, &end);
      times[i] = timediff(start, end);
    }
    printf("%s: ", funcs[func].name);
    for (int i=0; i<REPS; i++) {
      printf("%ld ", times[i]);
    }
    printf("\n");
  }
  return 0;
}
