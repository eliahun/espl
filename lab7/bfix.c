
      #include <stdio.h>
      #include <string.h>
      #include <stdlib.h>
      #include <unistd.h>
      
   // void write_in_file(File file_to_write_in,char changes_buffer,   ){
   //   fwrite(&new_byte_as_char , 1, 1, first_file );
   // }
    
    void fix (char first_buffer ,char second_buffer ,int lSize_2){
      int j=0;
      int index=0; 
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
	    fwrite(&new_byte_as_char , 1, 1, first_file ); **
	  }
	  j++;
      }  
      
    }

    int main(int argc, char **argv) {

      FILE *first_file=fopen(argv[argc-2], "w+"); 
      FILE *second_file=fopen(argv[argc-1], "r"); 
      
      size_t result;
      
      char first_buffer[1024];
      char second_buffer[1024];
  
      int lSize_1; 
      int lSize_2;
      
      
      
      fseek (first_file , 0 , SEEK_END);
      lSize_1 = ftell (first_file);
      rewind (first_file);
    
      fseek (second_file , 0 , SEEK_END);
      lSize_2 = ftell (second_file);
      rewind (second_file);
		      
  
      result = fread (second_buffer,1,lSize_2,second_file); 
      result = fread (first_buffer,1,lSize_1,first_file);
    
    
      
	fclose(first_file);
	fclose(second_file);
      
      return 0;
      
    }
    
    