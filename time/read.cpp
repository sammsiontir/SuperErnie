#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include <fstream>
#include <sstream>
int main(){
FILE *pFile;
FILE *oFile;
long lSize;
char* result;
size_t a;


oFile = fopen("output.txt", "wb");

char* f0 []= {"badnewarr_WORKS","badsub_WORKS","btest1","btest2","bubble_sort_test_WORKS"
           ,"bubble_sort_WORKS","char_at_test_WORKS","copy","copy_long","evens"
           ,"evens_long","factorial_WORKS","fib","fib_long","fib_rec","fib_WORKS"
           ,"insertion","merge_sort_test_WORKS","mult","objsort","parallel","parallel_long"
          ,"parsort","queue_mod_WORKS","saxpy","simple_WORKS","sort","strlen_test_WORKS"};


for(int i=0; i< 28;i++)
{
pFile = fopen(f0[i], "rb");
// obtain file size:
  fseek (pFile , 0 , SEEK_END);
  lSize = ftell (pFile);
  rewind (pFile);
  result = (char*) malloc (sizeof(char)*lSize);
   a = fread (result , 1, lSize , pFile);
       fwrite(result, 1 , sizeof(result), oFile);
	fputs(" ", oFile);
	fputs(f0[i], oFile);
	fputs("\n", oFile);
     fclose (pFile);
free (result);
}


/*fgets(result, 10, stdin);

fputs(result, oFile);

  fclose(pFile);
*/


  fclose (oFile);
  return 0;



}
