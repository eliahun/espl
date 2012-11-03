	  #include <stdio.h>
	  #include <string.h>
	  #include "fgetname.h"


	  int main(int argc, char **argv) {
	    
	      //creating the key words list
		char *key_words[31]; 
		key_words[0]="auto"; 
		key_words[1]="break"; 
		key_words[2]="case"; 
		key_words[3]="char";
		key_words[4]="const";
		key_words[5]="continue";
		key_words[6]="default";
		key_words[7]="do";
		key_words[8]="double";
		key_words[9]="else";
		key_words[10]="enum";
		key_words[11]="extern";
		key_words[12]="float";
		key_words[13]="for";
		key_words[14]="goto";
		key_words[15]="if";
		key_words[16]="int";
		key_words[17]="long";
		key_words[18]="register";
		key_words[19]="return";
		key_words[20]="short";
		key_words[21]="signed";
		key_words[22]="sizeof";
		key_words[23]="static";
		key_words[24]="switch";
		key_words[25]="typedef";
		key_words[26]="union";
		key_words[27]="unsigned";
		key_words[28]="void";
		key_words[29]="volatile";
		key_words[30]="while";
		
		int number_of_key_words[31]; 
		number_of_key_words[0]=0; 
		number_of_key_words[1]=0; 
		number_of_key_words[2]=0; 
		number_of_key_words[3]=0; 
		number_of_key_words[4]=0;
		number_of_key_words[5]=0; 
		number_of_key_words[6]=0; 
		number_of_key_words[7]=0; 
		number_of_key_words[8]=0; 
		number_of_key_words[9]=0; 
		number_of_key_words[10]=0; 
		number_of_key_words[11]=0; 
		number_of_key_words[12]=0; 
		number_of_key_words[13]=0; 
		number_of_key_words[14]=0; 
		number_of_key_words[15]=0; 
		number_of_key_words[16]=0; 
		number_of_key_words[17]=0; 
		number_of_key_words[18]=0; 
		number_of_key_words[19]=0; 
		number_of_key_words[20]=0; 
		number_of_key_words[21]=0; 
		number_of_key_words[22]=0; 
		number_of_key_words[23]=0; 
		number_of_key_words[24]=0; 
		number_of_key_words[25]=0; 
		number_of_key_words[26]=0; 
		number_of_key_words[27]=0; 
		number_of_key_words[28]=0; 
		number_of_key_words[29]=0; 
		number_of_key_words[30]=0; 
		
		
		int numberKeyWords=31;
	    
		
		FILE *in;
		char buffer[128];
		
		int i;
		int j;
		int result;
		  for( i = 1; i < argc; i++ ){    //a loop for all files
		      in=fopen(argv[i], "r"); 
			while (fgetname(buffer, 128, in) != NULL){            //a loop for all words
			      for (j=0; j<numberKeyWords; j++){
				result=strcmp(buffer,key_words[j]);
				if (result==0){
				  number_of_key_words[j]++;
				}
			      }   
			}
			fclose(in);
		    }
		
		
		
		int k; 
		printf( "The key words list:\n");
		for( k = 0; k < numberKeyWords; k++ ){
		  if (number_of_key_words[k]==1){
		    printf( "%s\n", key_words[k] );
		  }
		}



		return 0; 
	  } 
