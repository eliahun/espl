    #include <stdio.h>
    
    //: rand, srand, fgets, , fclose, fprintf

    int main(int argc, char **argv) {
    FILE *in = fopen(argv[1], "r");
    char buffer[128];
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
    
    
  }
      
  
    