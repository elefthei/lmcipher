#define _byte char
#define r0 3.887
#define _byte_size 8*sizeof(unsigned char)-1 //size of unsigned char in bits

static inline int circ(int a){
  return a%2;
}

static inline int cdigits(const double & num){
  int k=0;
  double cache=num;
  double expo=1;
  while(cache/expo>1){
    k++;
    expo=expo*10;
  }
  return k;
}

//accessing Y1,Y2 by using a circular array saves memory
//global variables
double Y1[2];
double Y2[2];
