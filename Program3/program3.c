#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/********************************************************************/
/*                  DO NOT ALTER THE DRIVER CODE                    */
/********************************************************************/
int myStrStr(char haystack[], char needle[], char buffer[]);
void findJediName(char* first, char* last, char buffer[]);
int findAllJediNames(char * filename, char buffer[50][10]);
void extraCredit();
char first_name[]="Vidhi";
char last_name[]="Kamdar";

int main(){
    printf("\t-----------------------------------\n");
	printf("\t-   Part1 : String Manipulation   -\n");
    printf("\t-----------------------------------\n");

	char haystack[][20] = {"apple","orange","blueberry","strawberry","banana","grapefruit"};
	char needle[][20] = {"app","ge","ueber","strawberry","na","terrible"};
    char buffer[255];

    printf("\n\t=========Testing myStrStr with '%s' and substring '%s'===========\n\n", haystack[0], needle[0]);
    int result = myStrStr(haystack[0],needle[0],buffer);
    assert(result == 1 && strcmp(needle[0], buffer) == 0);
    printf("\n\t\t....Test Passed\n");

    printf("\n\t=========Testing myStrStr with '%s' and substring '%s'===========\n\n", haystack[1], needle[1]);
    result = myStrStr(haystack[1],needle[1],buffer);
    printf("needle: %s, buffer: %s\n", needle[1], buffer );
    assert(result == 1 && strcmp(needle[1], buffer) == 0);
    printf("\n\t\t....Test Passed\n");

    printf("\n\t=========Testing myStrStr with 'blueberry' and substring 'ueber'===========\n\n");
    result = myStrStr(haystack[2],needle[2],buffer);
    assert(result == 1 && strcmp(needle[2], buffer) == 0);
    printf("\n\t\t....Test Passed\n");

    printf("\n\t=========Testing myStrStr with 'strawberry' and substring 'strawberry'===========\n\n");
    result = myStrStr(haystack[3],needle[3],buffer);
    assert(result == 1 && strcmp(needle[3], buffer) == 0);
    printf("\n\t\t....Test Passed\n");

    printf("\n\t=========Testing myStrStr with 'banana' and substring 'na'===========\n\n");
    result = myStrStr(haystack[4],needle[4],buffer);
    assert(result == 1 && strcmp(needle[4], buffer) == 0);
    printf("\n\t\t....Test Passed\n");

    printf("\n\t=========Testing myStrStr with 'grapefruit' and substring 'terrible'===========\n\n");
    result = myStrStr(haystack[5],needle[5],buffer);
    assert(result == 0);
    printf("\n\t\t....Test Passed\n");

//////////////////////////////////////////////////////////////////////////////
    printf("\t-----------------------------------\n");
    printf("\t-   Part2 : Jedi Names            -\n");
    printf("\t-----------------------------------\n");

	printf("\t----Part 2: What's Our Jedi Name----\n");
    printf("\t--Part A: Your Jedi Name--\n");
	findJediName(first_name, last_name, buffer);
	printf("\tMy JediName = %s\n\n", buffer);

	//Part B: Classmates jediname list
    printf("\n\t=========Testing Jedi names===========\n\n");
    char double_buffer[50][10];
    int num = findAllJediNames("names.txt", double_buffer);
    char test_buffer[][10] = {"Awash","Bhaap","Chani","Chipr","Chodh","Dalma",
                            "Despr","Dhapr","Dhayo","Gajch","Garpr","Ghodi",
                            "Gupab","Jadsh","Jaitu","Jakdh","Kamvi","Konsu",
                            "Konja","Kotga","Kouvi","Kurgi","Ladne","Memka",
                            "Mitve","Modam","Naine","Patdi","Patdi","Patki",
                            "Pawpr","Rajpa","Sansa","Shahi","Shani","Shavy",
                            "Shesh","Shiku","Sinan","Sivdh","Thaki","Thapr",
                            "Tuspo","Velab","Venna","Vinse"};
    int i = 0;
    for(; i < num; i++){
        //fprintf(stderr, "%s\t%s\n", double_buffer[i], test_buffer[i]);
        assert(strcmp(double_buffer[num-1], test_buffer[num-1]) == 0);
    }
    printf("\n\t\t....Test Passed\n");
    printf("\n\t=========All Tests Passed. Don't forget to submit!===========\n\n");

	extraCredit();
	return 0;
}
