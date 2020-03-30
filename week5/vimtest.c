#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	int num, i;

	srand(time(0));

	for(i=0;i<3;i++){
		num = rand() % 100 + 1;  
		printf("%d ",num);
	}
	printf("\n");

    return 0;
}
