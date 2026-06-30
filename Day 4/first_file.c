#include <stdio.h>

int main() {
	int x = 5;
	int* p = &x;
	printf("The value of x is: %d\n", *p);
	int arr[3] = {1,2,3};
	printf("The size of int is: %lu\n", sizeof(int));
	printf("%p\n", arr);
	printf("%p\n", (arr+1));
	printf("%p\n", (arr+2));
	printf("%d\n", *(arr+1));
	return 0;
}