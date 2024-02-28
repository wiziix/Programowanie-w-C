#include <stdio.h>

int main() {
	int variable = 5;
	int * pointer = &variable;
	* pointer = 2;

	printf("%d\n%d", variable, *pointer);

}
