		#include <stdio.h>
		#include <string.h>
		#include <math.h>
		#include "fgetname.h"
		

		int main(int argc, char **argv) {
		  
		  FILE *in=fopen(argv[1], "rb"); 
		  char * buffer;
		  
		  size_t result;
		  int lSize;
		  
		  fseek (in , 0 , SEEK_END);
		  lSize = ftell (in);
		  rewind (in);
		  
		  buffer = (char*) malloc (sizeof(char)*lSize);
		  result = fread (buffer,1,lSize,in);
		  
		  printf( "buffer %s\n", buffer );
		  printf( "lSize %d\n", lSize );
		  
		  
		  int i=0;
		  int j=0;
		  
		  int words_as_int [16];
		    for (i=0; i<16; i++){
		  words_as_int [i]=0;
		}
		
	
		
		  
		 for (i=0; i<lSize; i++){
		     
		      
		      
		      if (buffer[0]<60 && buffer[0]>47){
			    words_as_int[j]=buffer[0]-48;
			    j++;
			 
		      }
		      if (buffer[0]==97){
			words_as_int[j]=10;
			j++;
		      }
		      if (buffer[0]==98){
			words_as_int[j]=11;
			j++;
		      }
		      if (buffer[0]==99){
			words_as_int[j]=12;
			j++;
		      }
		      if (buffer[0]==100){
			words_as_int[j]=13;
			j++;
		      }
		      if (buffer[0]==101){
			words_as_int[j]=14;
		      j++;
		      }
		      if (buffer[0]==102){
			words_as_int[j]=15;
			j++;
		      }
		   
		      buffer++;
		}
		
		    for (i=0; i<16; i++){
		   printf( "loop %d\n", words_as_int[i] );
		}
		    
		  
	      
	      
	      
	      int f_num;
	      int s_num;
	      i=0;
	      j=0;
	      int first_dword[4];
	      int second_dword[4];
	      double  xor[4];
	      
	      for(j= 0;  j<4; ++j){
		  f_num=words_as_int[j];
		  s_num=words_as_int[j+8];
		  int ans;
		  double answer=0;
		 
		  for(i = 0;  i<4; ++i){
		
		    ans=f_num%2 -s_num%2 ;
		    printf( "f_num %d\n", f_num );
		    printf( "s_num %d\n", s_num );
		    printf( "ans %d\n", ans );
		   
		    if (ans==-1)
		      ans=1;
		    f_num=f_num/2;
		    s_num=s_num/2;
		    xor [i]=ans;
		    answer= answer+pow(2,  xor [i]);
		  } 
		  
		  
	      }
	      
	     
	      
	      
	      
	      
	      
	      
	     /*  for(j= 0;  j<4; ++j){
		  f_num=words_as_int[j];
		  s_num=words_as_int[j+8];
		  printf( "f_num %d\n", f_num );
		  printf( "s_num %d\n", s_num );
		  for(i = 0;  i<4; ++i){
		   // printf( "f_num %d\n", f_num );
		    first_dword[i]=f_num%2;
		    printf( "first_dword[i] %d\n", first_dword[i] );
		    f_num=f_num/2;
		   // printf( "f_num %d\n", f_num );
		    
		   //  printf( "s_num %d\n", s_num );
		    second_dword[i]=s_num%2;
		    printf( "second_dword[i] %d\n", second_dword[i] );
		    s_num=s_num/2;
		  //  printf( "s_num %d\n", s_num );
		    
		  } 
		  
	      } */
	      
		  
		  
		  
		/*  for (i=0; i<4; i++){
		    while(words_as_int!=NULL){
		     first_word_bin[j]=words_as_int[i]%2;
		     words_as_int[i]=words_as_int[i]/2;
		    }
		 printf( "words_as_int %d\n", first_word_bin[i] );    
		 
		  } */
		/*ans= words_as_int[i]%2 - words_as_int[i+8]%2;
		printf( "words_as_int %d\n", words_as_int[i] );
		printf( "words_as_int2 %d\n", words_as_int[i+4] );
		if (ans==0)
		  word[i]=0;
	      else word[i]=1;
		printf( "int %d\n", word[0] );
		  
	      } */
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
	      // while (buffer[0]=!NULL){
	      //  int j=0;
		
		//nulling the array 
	      
		
		
		
	     
	     
		  return 0;
		  
		}