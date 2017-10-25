#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <assert.h>

/********************************************************************/
/*   DO NOT ALTER THE DRIVER CODE EXCEPT WHERE REQUIRED TO DO SO    */
/********************************************************************/

void binaryArray(int n, int array[], int size){

int i=0;
int c,k,l;

for(c=31;c>=0;c--)
{
	k=n>>c;
	array[i]=k;
	{
		if(1&k)
        	{
			int x=1;
			array[i]=x;
		}
		else
		{
			int x=0;
			array[i]=x;
       		 }
	i++;
	}
}
printf("\n");
}

void binaryPrinter(int array[], int size){
    int i;
    for(i = 0; i < size; i++){
        if((i%4) == 0) printf(" ");
        printf("%d", array[i]);
    }
    printf("\n\n");
}

void binaryTester(int array[], int test[], int size){
    int i;
    for(i = 0; i < size; i++){
        assert(array[i] == test[i]);
    }
    printf("\n");
}

int main(){
    int size = sizeof(int) * 8;
    int array[size], i;

    printf("\n\t=========Testing Conversion of 2===========\n\n");
    binaryArray(2, array, size);
    binaryPrinter(array, size);
    int test1[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0};
    binaryTester(array, test1, size);
    printf("\n\t\t....Converting 2 Passed\n");

    printf("\n\t=========Testing Conversion of 255===========\n\n");
    binaryArray(255, array, size);
    binaryPrinter(array, size);
    int test2[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1};
    binaryTester(array, test2, size);
    printf("\n\t\t....Converting 255 Passed\n");

    printf("\n\t=========Testing Conversion of -1===========\n\n");
    binaryArray(-1, array, size);
    binaryPrinter(array, size);
    int test3[32] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    binaryTester(array, test3, size);
    printf("\n\t\t....Converting -1 Passed\n");

    printf("\n\t=========Testing Conversion of INT_MAX===========\n\n");
    binaryArray(INT_MAX, array, size);
    binaryPrinter(array, size);
    int test4[32] = {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    binaryTester(array, test4, size);
    printf("\n\t\t....Converting INT_MAX Passed\n");

    printf("\n\t=========Testing Conversion of INT_MIN===========\n\n");
    binaryArray(INT_MIN, array, size);
    binaryPrinter(array, size);
    int test5[32] = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    binaryTester(array, test5, size);
    printf("\n\t\t....Converting INT_MIN Passed\n");

    printf("\n\t=========All Tests Passed. Don't forget to submit!===========\n\n");

    return 0;
}
