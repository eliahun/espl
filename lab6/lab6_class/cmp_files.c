  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  #include <unistd.h>



    void cmp_files(char* first_buffer, char* second_buffer,int lSize_1,int lSize_2 ) {
      
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
      
    } 
