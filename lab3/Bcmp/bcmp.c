  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  #include <unistd.h>


  /* OPTIONS
	-h  print a summary of options and exit
	-n  NUMBER  print first NUMBER differences and exit
	-q  do not print out the differences, exits with code 0
	if the files are identical, 1 otherwise */


 

  int old_main(int argc, char **argv) {
    
    int opt = 0;                                 //flag
    int num=0;					//flag
    static const char *optString = "h:n:q";     //flag
    
     int options=0;                /* -h option */   //flag
     int number=0;               /* -n option */      //flag
     int quit=0;					//flag
        
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
    
    opt = getopt( argc, argv, optString );
	  
	
      while( opt != -1 ) {
	  switch( opt ) {
	      case 'h':
		options=1;
		  break;
		  
	      case 'n':
		number=1;
		num=atoi(argv[argc-3]);
		break;
		  
	      case 'q':
		  quit=1;
		  break;
		  
		  
	      default:
		  /* You won't actually get here. */
		  break;
	  }
	  opt = getopt( argc, argv, optString );
      }
      
      
    int j;
    int counter=0;
      
    for (j=0; j<lSize_1 || j<lSize_2; j++){
	
      
	if (first_buffer[j]!= second_buffer[j]){
	    printf( "#%i: ", j );
	    printf( "-%i +%i\n", first_buffer[j], second_buffer[j] );
	    counter++;
	  }  
	 if (first_buffer[j]== second_buffer[j]){
	   printf( "#%i: \n", j );
	 }
  
      }
      
      
      if (options==1){
	printf( "OPTIONS: \n-h  print a summary of options and exit\n-n NUMBER  print first NUMBER differences and exit\n-q do not print out the differences, exits with code 0\nif the files are identical, 1 otherwise\n"); 
      }
      
      
      if (number==1){
	printf( "number of differences %i \n",counter ); 
	printf( "NUMBER %i \n",num ); 
      }
      
      
      if (quit==1){
	return 0;
      }
 
      
      fclose(first_file);
      fclose(second_file);
    
    return 0;
  }