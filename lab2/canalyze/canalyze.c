    
	#include <stdio.h>
	#include "fgetname.h"
	
	

	int main(int argc, char **argv) {
	  
	//creating the key words list
      char *key_words[4]; 
	key_words[0]="return"; 
	key_words[1]="while"; 
	key_words[2]="for"; 
	key_words[3]="long"; 
	int number_of_key_words=4;
      
	printf("keywords");
	
	//get 1 file  for testing

	FILE *in;
	/*in=fopen(argv[1], "r"); 
	char *word_from_file=0;
	
	char buffer[128];
	fgetname(buffer, 128, in);
	 printf( "line: %s\n", buffer );
	*/ 
	 //getting all files 
	 
	int i; 
	int j;
	char word_from_file[128];
	
	for( i = 1; i < argc-1; i++ ){
	  in = fopen(argv[i], "r");
	  fgetname(word_from_file, 128, in);  
	  printf("%s", word_from_file);
	  
	} 
	  /*for( j = 0; j < number_of_key_words; i++ ){ 
	    fgetname(word_from_file, size of(key_words[j]), in);
	    if (*word_from_file==*key_words[j])
	  } */   
	    
  //     }
      
      
      
      
    
      
      
      
      
      
      
      
      
 /*     char buffer[128];
	int count=0; 
	
	
	while (fgets(buffer, 128, in) != NULL){
	  count++;
	}

	fclose(in);
	in = fopen(argv[1], "r");
	
	srand( time(NULL) );
	int i;
	int ran= rand()% count+1;
	for( i = 0; i < ran; i++ ){
	  fgets(buffer, 128, in);  
	}
	  printf( "Random line #%d: %s\n", ran, buffer );
	
	fclose(in);
	return 0;
	
	
	namelist make_namelist() {
	    namelist nl = (namelist)malloc(sizeof(struct namelist));
	    nl->size = 0;
	    nl->capacity = INITIAL_CAPACITY;
	    nl->names = (struct namestat *)malloc(INITIAL_CAPACITY*sizeof(struct namestat));
	    return nl;
    }  */
	
       
	
	return 0; 
	
      }