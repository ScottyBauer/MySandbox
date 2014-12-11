#include "sat_ops.h"


/* unload as much into compile time as possible */
static mysint s_min = ((myuint)0x1 << ((sizeof(mysint)*8)-1));
/* static mysint s_max = ((mysint)~s_min);*/
static mysint s_max = (mysint)~((myuint)0x1 << ((sizeof(mysint)*8)-1));


static inline mysint abs(mysint x){
  mysint mask = (x >> ((sizeof(mysint)*8)-1));
  return (x ^ mask) - mask;
}

myuint sat_unsigned_add(myuint x, myuint y){
  myuint ret = (x + y);
  if(ret >= x && ret >= y) return ret;
  return (myuint)~0;
}

myuint sat_unsigned_sub (myuint x, myuint y){
  if(y > x) return 0;
  return  x - y ;
}


/*
Testing with -1,168,558,655, -605,346,418
res is 2,521,062,223 and u_max is 2147483647
*/

mysint sat_signed_add(mysint x, mysint y){
  mysint res = (myuint)x + (myuint)y;
  /* TODO do i have to check res > y and res > x? */
  if(x < 0 && y < 0 && res >=0){
    /* underflowed to positive */
    return s_min;
  }
  /* overflowed to neg */
  if(x > 0 && y > 0 && res <= 0){
    return s_max;
  }
  return x + y;
}

mysint sat_signed_sub(mysint x, mysint y){
  mysint temp = s_min;
  mysint temp1 = s_max;
  if(x < 0){
    temp -= x;
    if(abs(temp) < y){
      return s_min;
    }
    return x - y;
  }
  if(y < 0){
    /* todo, abs(int_min) will fail  -- FIXED */
    temp1 += y;
    if(x > temp){ 
      return s_max;
    }
  }
  return x - y;
}

