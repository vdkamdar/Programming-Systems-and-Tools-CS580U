#include<stdio.h>
#include <math.h>
#include <assert.h>

//Function to calcualte next multiple of two given values
int findNextMultiple(int num1, int num2)
{
	int next_multiple = num1 + num2 - num1 % num2;
	return(next_multiple);
}

//Function to convert Fahrenheit to Celsuius
float convertFtoC(float fahren)
{
	float celsius;
	celsius=(fahren-32)/1.8;
	return(celsius);

}

//Function to calculate fibonacci series for first 20 numbers
int fibonacci()
{
	int f0=0,f1=1,fibo_sum,n=1,i;
	
	for(i=0;i<n&&n<21;i++)
	{
		if(i<=1)
		{
			printf("%d\t",i);
			n++;
		}
		else
		{
			fibo_sum=f0+f1;
			printf("%d\t",fibo_sum);
			f0=f1;
			f1=fibo_sum;
			n++;
		}
	}
return(fibo_sum);
}

//Function to cast a long to an int
int castToInt(long num)
{
	return((int)num);
}

//Function to cast a long to an double
double castToDouble(long num)
{
	double a;
	a=(double)num;
	return(a);
}

//Function to cast a long to an char
char castToChar(long num)
{
	char a;
	a=(char)num;
	return(a);
}

//The main driver
int main(){

	//TODO Write code to print "Hello World"
	printf("\n Hello World!");
	//TODO For given value of x calculate value of expression
	printf("\n\t=============================\n");
	printf("\t=           PART A          =\n");
	printf("\t=============================\n\n");

	printf("\n\t=========Starting Expression Conversion Tests===========\n");
	//Write code to evaluate the following expression: 3x^3 - 5x^2 + 6 for x = 2.5.
	float x=2.5;
	float result = 0; //TODO write your expression here

	result=((3*(pow(x,3)))-(5*(pow(x,2)))+6);

	assert(result == 21.625);

	//Write code to evaluate the following expression: (3 × 10^8 + 2 × 10^-7) / (7 × 10^-6 + 2 × 10^8)
	//and round the result to the nearest integer
	
	result = 0;//TODO write your expression here
	
	result=(3*(pow(10,8))+2*(pow(10,-7)))/(7*(pow(10,-6))+2*(pow(10,8)));
	result=result+0.5;
	result=floor(result);
	assert(result == 2.0);

	printf("\n\t\t....Converting Expressions Tests Passed\n");

	printf("\n\t=========Starting Next Multiple Tests===========\n");
	//For given numbers find next multiple

	int number1 = 365, number2 = 7;
	assert(371 == findNextMultiple(number1,number2));

	number1 = 12258; number2 = 28;
	assert(12264 == findNextMultiple(number1,number2));

	number1 = 996; number2 = 4;
	assert(1000 == findNextMultiple(number1,number2));

	printf("\n\t\t....Next Multiple Tests Passed\n");

	printf("\n\t=========Starting Fahrenheit to Celsius Tests===========\n");

	//Convert Fahrenheit value to Celsius value

	float fahren = 95;
	float celsius = convertFtoC(fahren);
	assert(35.0 == celsius);

	fahren = 32;
	celsius = convertFtoC(fahren);
	assert(0.0 == celsius);

	fahren = -40;
	celsius = convertFtoC(fahren);
	assert(-40.0 == celsius);
	printf("\n\t\t....Fahrenheit to Celsius Tests Passed\n");

	printf("\n\t=============================\n");
	printf("\t=           PART B          =\n");
	printf("\t=============================\n\n");


	printf("\n\t=========Starting Casting Tests===========\n");
	//Testing our Casting and how its loses values for wrong casting
	long int large_num = 9223372036854775617;
	int large_num_as_int = castToInt(large_num);
	assert(-191 == large_num_as_int);
	double large_num_as_double = castToDouble(large_num);
	assert(9223372036854775808.0 == large_num_as_double);
	char large_num_as_char = castToChar(large_num);
	assert('A' == large_num_as_char);

	printf("\n\t\t....Casting Tests Passed\n");

	printf("\n\t=============================\n");
	printf("\t=           PART C          =\n");
	printf("\t=============================\n\n");

	printf("\n\t=========Starting Fibonacci Tests===========\n\n");
	//finding fibonacci series for first 20 numbers
	assert(4181 == fibonacci());

	printf("\n\t\t....Fibonacci Tests Passed\n\n");

	printf("\t=========ALL TESTS PASSED===========\n");

	return 0;
}
