
     #include <stdio.h>
     #include <string.h>
     #include <stdlib.h>
     #include <unistd.h>
     //#include "diff.h"


  /* OPTIONS
	-h  print a summary of options and exit
	-n  NUMBER  print first NUMBER differences and exit
	-q  do not print out the differences, exits with code 0
	if the files are identical, 1 otherwise */

 // struct globalArgs_t {cd
 //     int *number;               /* -n option */
 //     int *quit;               /* -q option */
      
	      
// } globalArgs;
 // static const char *optString = "h:n:q";
 

  int main(int argc, char **argv) {
    
    int opt = 0;
    static const char *optString = "h:n:q";
    
     int options=0;                /* -h option */
     int reverse=0;               /* -n option */
     int priint_change=0;
    
    
    FILE *first_file=fopen(argv[argc-2], "w+"); 
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
    
    opt = getopt( argc, argv, optString );
	  
	
          while( opt != -1 ) {
	  switch( opt ) {
	      case 'h':
		options=1;
		  break;
		  
	      case 'r':
		reverse=1;
		break;
		  
	      case 'm':
		  priint_change=1;
		break;  
		  
	      default:
		  /* You won't actually get here. */
		  break;
	  }
	  opt = getopt( argc, argv, optString );
      }
      
      
      
   /*   int i;
     for (i=0; i<lSize_2; i++){ 
         printf( " command %i\n", second_buffer[i] );
     } */
   
   
   
   
   int j=0;
   int index=0; 
    int counter=0;
    char line[100];
    char new_byte[100];
    char old_byte[100];
    
    int line_as_int=0;  
    int old_byte_as_int=0;
    int new_byte_as_int=0;
    int change;
    char c=0;
    char new_byte_as_char=0;
   
    
      
  while (j<lSize_2){
	change=0;
	index=0;
	if ('#'== second_buffer[j]){
	  j++;
	  while (second_buffer[j]!=':'){
	    line[index] = second_buffer[j];
	    j++;
	    index++;
	  }
	  line[index] =0;
	  line_as_int=atoi(line); 
	  printf( "#:%i \n", line_as_int );
	}
	
	if ('-'== second_buffer[j]){
	  j++;
	  while (second_buffer[j]!=' '){
	    old_byte[index] = second_buffer[j];
	    j++;
	    index++;
	  }
	  old_byte[index] =0;
	  old_byte_as_int=atoi(old_byte); 
	  printf( "old_byte_as_int: %c \n", old_byte_as_int );
	}
	
	if ('+'== second_buffer[j]){
	  change=1;
	  j++;
	  while (second_buffer[j]!=' '){
	    new_byte[index] = second_buffer[j];
	    j++;
	    index++;
	  }
	  new_byte[index] =0;
	  new_byte_as_int=atoi(new_byte); 
	  new_byte_as_char = (char)new_byte_as_int;
	  printf( "new_byte_as_int: %c \n", c );
	  
	}
	if (change){
	   printf( "if change \n");
	  fseek (first_file , line_as_int , SEEK_SET);
	  fwrite(&new_byte_as_char , 1, 1, first_file );
	}
	
	
	
	 
	
	j++;
	
    }  
    
    
      
      
 
	
	
	 
      
      
    /*if (first_buffer[j]!= second_buffer[j]){
	    printf( "#%i: ", j );
	    printf( "+%i -%i\n", first_buffer[j], second_buffer[j] );
	    counter++;
	  
  
    }*/
      
      
     /* if (options==1){
	printf( "OPTIONS: \n-h  print a summary of options and exit\n-n NUMBER  print first NUMBER differences and exit\n-q do not print out the differences, exits with code 0\nif the files are identical, 1 otherwise\n"); 
      }
      
      
      if (number==1){
	printf( "number of differences %i \n",counter ); 
	printf( "NUMBER %i \n",num ); 
      }
      
      
      if (quit==1){
	return 0;
      } */
      
    
      
      
      
      fclose(first_file);
      fclose(second_file);
    
    return 0;
    
  }
   
   