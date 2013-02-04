  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  #include <unistd.h>


  int old_main(int argc, char **argv) {
    
   
    FILE *first_file=fopen(argv[argc-2], "r"); 
    FILE *second_file=fopen(argv[argc-1], "r"); 
    size_t result;
    
    char* first_buffer=NULL;
    char* second_buffer=NULL;
    int lSize_1;
    int lSize_2;
    
    fseek (first_file , 0 , SEEK_END);
    lSize_1 = ftell (first_file);
    rewind (first_file);
		    
    first_buffer = (char*) malloc (sizeof(char)*lSize_1);
    result = fread (first_buffer,1,lSize_1,first_file);
      
    fseek (second_file , 0 , SEEK_END);
    lSize_2 = ftell (second_file);
    rewind (second_file);
		    
    second_buffer = (char*) malloc (sizeof(char)*lSize_2);
    result = fread (second_buffer,1,lSize_2,second_file); 
    
   
	
    cmp_files(first_buffer,second_buffer,lSize_1,lSize_2);
    printf("fine");
      
      
    
      
      
      fclose(first_file);
      fclose(second_file);
    
    return 0;
  }