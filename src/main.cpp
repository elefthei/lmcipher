#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include "defs.h"
#include "prbg.h"

#define MAX_PASSWD 128
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
using namespace std;

int main(int argc, char* argv[]){

  //Checking input

  if(!(argc==3 && atoi(argv[1]))){
    //perror("Incorrect arguments");
    printf("\nCorrect usage:\n%s <KEY> [input file]\n\n<KEY>\n  Can be any integer with more than 4 digits which is not symetrical\n (not like this: 321321).\n\n[file]\n  Name of the input file.\n ",argv[0]); 
    return -1;
  }

  //initializations and checks
  const int key1size=strlen(argv[1])/2;
  char ckey1[key1size];
  char ckey2[key1size+1];
  
  if(strlen(argv[1])%2==0){
    for(int i=0;i<key1size;++i){
      ckey1[i]=argv[1][i];
      ckey2[i]=argv[1][key1size+i];
	}
  }
  else{
    for(int i=0;i<key1size;++i){
      ckey1[i]=argv[1][i];
      ckey2[i]=argv[1][key1size+i];
	}
    ckey2[key1size]=argv[1][2*key1size];
  }
  double key1=(double)atoi(ckey1), key2=(double)atoi(ckey2);
   if(key1==key2){perror("Key cannot be symmetrical! Use your imagination!\n"); return -1;}
   //end of initializations of key1, key2
   
   
   double eskey1=pow(key1,2)*pow(10,((-1)*cdigits(pow(key1,2)))+1), 
	  eskey2=pow(key2,2)*pow(10,((-1)*cdigits(pow(key2,2)))+1);

   Y1[0]=eskey1-floor(eskey1);
   Y2[0]=eskey2-floor(eskey2);
   //end initializations and checks
   //eskey = key^2*10^(-keydigits+1)
   FILE *fin,*fout;
   
   _byte c=0;
   char *pch=strstr(argv[2],".hid");
   char *outpfile;
   if(pch==NULL){

     int maxsize = MIN(strlen(argv[2])+4,MAX_PASSWD);
     outpfile= (char*) calloc(maxsize,sizeof(char));
     strncpy(outpfile,argv[2], maxsize);
     strcat(outpfile,".hid");
   }
   else {
     int maxsize = MIN(strlen(argv[2])-4,MAX_PASSWD);
     outpfile= (char*) calloc(maxsize,sizeof(char));
     for(int i = 0; i<maxsize; ++i)
       outpfile[i]=argv[2][i];
   }

    if((fin=fopen(argv[2],"rb"))!=NULL){
      if((fout=fopen(outpfile,"wb"))!=NULL){
	free(outpfile);
	while(!feof(fin)){
	  c=getc(fin);
	  c^=prbg(&eskey1,&eskey2);
	  putc(c,fout);
	}
	fclose(fout);
      }
      else{
	printf("No output file\n");
      }
      fclose(fin);
    }
    else{
      printf("No input file\n");
    }

return 0;
}
