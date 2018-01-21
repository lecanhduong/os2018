#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 10

typedef struct { 
	char type;
	int amount;
	char unit;
}item;

item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;

void produce(item *i){
	while ((first + 1) % BUFFER_SIZE == last){
	}
	memcpy(&buffer[first], i, sizeof(item));
	first = (first + 1) % BUFFER_SIZE;
}


item *consume() {
	item *i = malloc(sizeof(item));
	while (first == last) {
	}
	memcpy(i, &buffer[last], sizeof(item));
	last = (last + 1) % BUFFER_SIZE;
	return i;
}
void *produceThread(){	
	item n1,n2,n3;
	n1.type = 0;
        n1.amount = 5;
        n1.unit = 0;
 
 	n2.type = 1;
        n2.amount = 10;
        n2.unit = 1;
 
 	n3.type = 0;
 	n3.amount = 10;
 	n3.unit = 0;

	produce(&n1);
	printf("\nProducing item: first=%d,last=%d\n",first,last);
 	produce(&n2);
	printf("\nProducing item: first=%d,last=%d\n",first,last);
 	produce(&n3);
	printf("\nProducing item: first=%d,last=%d\n",first,last);
}

void *consumeThread(){
	consume();
	printf("\nConsumed item: first = %d, last = %d\n",first, last);
	consume();
	printf("\nConsumed item: first = %d, last = %d\n",first, last);
}

int main()
 {
 	pthread_t tid1, tid2;
 	pthread_create(
 		&tid1,
 		NULL,
 		produceThread,
 		NULL
 		);
 	pthread_create(
 		&tid2,
 		NULL,
 		consumeThread,
 		NULL
 		);
 	pthread_join(tid2,NULL);
 	return 0;
 
 }
