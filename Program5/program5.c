#include "vector.h"
#include "vector.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>/* timeval, gettimeofday() */

/********************************************************************/
/*    DO NOT ALTER ANY OF THE THE DRIVER CODE 	                    */
/********************************************************************/

void printVector(Vector *v){
	Data *d;
	printf("[");
	int i = 0;
	if( (*v).current_size != 0){
		for(i= 0 ; i< ((*v).current_size -1) ; i++){
			d = vectorRead(v,i);
			printf("%d,",d->value);
		}
		d = vectorRead(v,i);
		printf("%d]\n",d->value);		//current size first
	}else{
		printf("]\n");
	}
}

void printArray(Data * d, int size){
	printf("[");
	int i = 0;
	for(i= 0 ; i< size ; i++){
		printf("%d,",d[i].value);
	}
	printf("]\n");
}

int main(){
	int i = 0;
	srand(time(NULL));
	printf("\t-----------------------------------\n");
	printf("\t-          Part1 : Vectors        -\n");
	printf("\t-----------------------------------\n");

	printf("\n\t=========Test #1: Creating your Vector===========\n\n");

	Vector *vect = initVector();
	assert(vect->current_size == 0);
	assert(vect->max_size == 0);
	assert(vect->data == NULL);
	printf("\n\t=========Test #1 Passed...            ===========\n\n");

	printf("\n\t=========Test #2: Inserting 20 random values into your Vector===========\n\n");
	//Insert Vector
	Data data_array[20];
	for(i = 0 ; i < 20 ; i++){
		data_array[i].value = (rand() % 20) + 1;
		vectorInsert(vect, i, data_array[i]);
	}

	assert(vect->max_size == 31);
	assert(vect->current_size == 20);
	printf("\n\t=========Test #2 Passed...            ===========\n\n");

	printf("\n\t=========Test #3: Inserting values into out of bounds index===========\n\n");
	vectorInsert(vect, 49, (Data){49});
	assert(vect->max_size == 99);
	assert(vect->current_size == 50);

	printf("\n\t=========Test #3 Passed...            ===========\n\n");

	printf("\n\t=========Test #4: Inserting values into out of bounds index===========\n\n");
	//tests outof bounds insert with expansion
	vectorInsert(vect, 40, (Data){40});
	assert(vect->max_size == 99);
	assert(vect->current_size == 50);

	printf("\n\t=========Test #4 Passed...            ===========\n\n");

	printf("\n\t=========Test #5: Reading from your vector===========\n\n");

	for(i = 0 ; i < 20 ; i++){
		Data * d = vectorRead(vect, i);
		fprintf(stderr, "%d %d\n",data_array[i].value, d->value );
		assert(data_array[i].value == d->value);
	}
	Data * d = vectorRead(vect, 49);
	assert(49 == d->value);

	printf("\n\t=========Test #5 Passed...            ===========\n\n");

	printf("\n\t=========Test #6: Reading from unititialized vector index (should return -1)===========\n\n");

	d = vectorRead(vect, 45);
	fprintf(stderr, "%d\n", d->value);
	assert(d->value == -1);

	printf("\n\t=========Test #6 Passed...            ===========\n\n");

	printf("\n\t=========Test #7: Attempting to read from out of bounds===========\n\n");

	d = vectorRead(vect, 100);
	assert(d == NULL);

	printf("\n\t=========Test #7 Passed...            ===========\n\n");

	printf("\n\t=========Test #8: Remove elements from the vector ===========\n\n");

	//RemoveVector
	vectorRemove(vect, 49);
	vectorRemove(vect, 40);

	printf("\n\t=========Test #8 Passed...            ===========\n\n");

	printf("\n\t=========Test #9: Remove elements from the vector randomly ===========\n\n");

	while(vect->current_size){
		vectorRemove(vect, (rand()%5));
	}
	vectorRemove(vect, 50);
	printf("\n\t=========Test #9 Passed...            ===========\n\n");

	printf("\n\t=========Test #10: Delete the vector from memory ===========\n\n");

	deleteVector(vect);
	vect = NULL;

	printf("\n\t=========Test #10 Passed...            ===========\n\n");

	printf("\n\t=========Test #11: Speed Tests ===========\n\n");

	printf("Comparing Geomertic and Incremental Approach\n\t1.Geometric Apparoach : max_size = max_size * 2\n");
	int test[10000];
	Vector * test1 = initVector();

	struct timeval start, stop;
	gettimeofday(&start, NULL);

	for(i = 0; i< 10000; i ++){
		if((rand() % 2) == 1){
			vectorInsert(test1, i, (Data) {i});
		}
	}
	gettimeofday(&stop, NULL);
	time_t start_time = (start.tv_sec* 1000000) + start.tv_usec;
	printf("\tstart time = %ld\n", start_time);
	time_t stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
	printf("\tstop time = %ld\n", stop_time);
	time_t final_time = stop_time - start_time;
	printf("\tfinal time = %ld\n", final_time);
	printf("\tmax_size = %d, current size = %d\n",(*test1).max_size , (*test1).current_size);

	float ratio = (float) (*test1).max_size / (float) (*test1).current_size;
	printf("\tRatio=%f\n",ratio);
	float profileTime = ratio * final_time;
	printf("\tprofileTime = %lf\n", profileTime);
	deleteVector(test1);
	test1 = NULL;
	/////////////////////////////Incremental Apparoach
	printf("\n\tIncreamental Apparoach: max_size = max_size + 1\n");
	Vector * test2 = initVector();

	struct timeval start2, stop2;
	gettimeofday(&start2, NULL);

	for(i = 0; i< 10000; i ++){
		if((rand() % 2) == 1){
			vectorInsertIncremental(test2, i, (Data) {i});
		}
	}
	gettimeofday(&stop2, NULL);
	time_t start_time2 = (start2.tv_sec* 1000000) + start2.tv_usec;
	printf("\tstart time = %ld\n", start_time2);
	time_t stop_time2 = (stop2.tv_sec* 1000000) + stop2.tv_usec;
	printf("\tstop time = %ld\n", stop_time2);
	time_t final_time2 = stop_time2 - start_time2;
	printf("\tfinal time = %ld\n", final_time2);
	printf("\tmax_size = %d, current size = %d\n",(*test2).max_size , (*test2).current_size);

	float ratio2 = (float) (*test2).max_size / (float) (*test2).current_size;
	printf("\tRatio=%f\n",ratio2);
	float profileTime2 = ratio2 * final_time2;
	printf("\tprofileTime = %lf\n", profileTime2);
	deleteVector(test2);
	test2 = NULL;
	//////////////////////Part C

	printf("\n\t3. My Apparoach \n");
	Vector * test3 = initVector();

	struct timeval start3, stop3;
	gettimeofday(&start3, NULL);

	for(i = 0; i< 10000; i ++){
		if((rand() % 2) == 1){
			vectorInsertMine(test3, i, (Data) {i});
		}
	}
	gettimeofday(&stop3, NULL);
	time_t start_time3 = (start3.tv_sec* 1000000) + start3.tv_usec;
	printf("\tstart time = %ld\n", start_time3);
	time_t stop_time3 = (stop3.tv_sec* 1000000) + stop3.tv_usec;
	printf("\tstop time = %ld\n", stop_time3);
	time_t final_time3 = stop_time3 - start_time3;
	printf("\tfinal time = %ld\n", final_time3);
	printf("\tmax_size = %d, current size = %d\n",(*test3).max_size , (*test3).current_size);

	float ratio3 = (float)(*test3).max_size / (float)(*test3).current_size;
	printf("\tRatio=%f\n",ratio3);
	float profileTime3 = ratio3 * final_time3;
	printf("\tprofileTime = %lf\n", profileTime3);
	deleteVector(test3);
	test3 = NULL;
	printf("\n\t========= Don't forget to submit! ===========\n\n");

	return 0;
}
