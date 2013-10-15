static inline _byte prbg(const double *eskey1,const double *eskey2){ //pseudo-random byte generator
  
  _byte y=0x00;  
  double r1=r0+pow(10,-2)*((*eskey1)/10 - floor((*eskey1)/10));
  double r2=r0+pow(10,-2)*((*eskey2)/10 - floor((*eskey2)/10));

  //end initializations (r1,r2, Y1(0),Y2(0))

  for(unsigned int i=0;i<_byte_size;++i){
    Y1[circ(i+1)]=r1*Y1[circ(i)]*(1-Y1[circ(i)]);
    Y2[circ(i+1)]=r2*Y2[circ(i)]*(1-Y2[circ(i)]);
    if(Y1[circ(i+1)]>Y2[circ(i+1)])
	y=(y<<1)|0x01;
      else
	y=(y<<1);
  }

  return y;
}
