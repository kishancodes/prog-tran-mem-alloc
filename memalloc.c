#include <stdio.h>
#include <stdlib.h>
/***** MACRO DEFINITION ***/
#define ARR_SIZE 1000
/***** FUNCTION DECLARATION ***/
#define ARR_SIZE 1000
/***** FUNCTION DECLARATION ***/
void f1(void);
void f2(void);
void f3(void);

int main(){ 
	printf("\nPrinting function 1: \n");
	f1(); 
	printf("\nPrinting function 3: \n");
	f3(); 
	return 0; 
}
/* Function definition f1() */
void f1(void){
	char arr[ARR_SIZE];
	static int n = 1; /* No. of activation records */
	static long int addr; /* Starting address of the array */
	static long int prev_addr;
	static long int AR_size;
	addr = (long int) arr;
	AR_size = (prev_addr - addr);
	printf("Call #%d " , n);
	printf("at %x\n" , (unsigned int) addr);
	printf("AR Size #%d is %ld\n" , n, AR_size);
	prev_addr = addr;
	n++; 
	if(n <= 10){ 
		f1(); 
	}
}
/* Function definition f2() */
void f2(void){
	char arr[ARR_SIZE];
	static int n = 1; /* No. of activation records */
	static long int addr; /* Starting address of the array */
	static long int prev_addr;
	static long int AR_size;
	addr = (long int) arr;
	AR_size = (prev_addr - addr);
	printf("Call #%d " , n);
	printf("at %x\n" , (unsigned int) addr);
	printf("AR Size #%d is %ld\n" , n, AR_size);
	printf("Stack Size #%d is %ld\n" , n, (n * AR_size));
	prev_addr = addr;
	n++; 
	/* Recursive call withouthout any condition for Sementation fault */
	f2();
}
/* Function definition f3() */
void f3(void){
	char *arr;
	arr = (char *) malloc (sizeof(char) * ARR_SIZE);
	if(arr == NULL){
		/* Memory not allocated successfully */
		printf("Memory not allocated successfully");
		exit(0); 
	}
	static int n = 1; /* No. of activation records */
	static long int addr;
	static long int AR_size;
	addr = (long int) arr;
	AR_size = (sizeof(char) * ARR_SIZE);
	printf("Call #%d " , n);
	printf("at %x\n" , (unsigned int) addr);
	printf("AR Size #%d is %ld\n" , n, AR_size);
	n++;
	free(arr); /* free the array from the heap */
	if(n <= 10){ 
		f3();
	}
}
