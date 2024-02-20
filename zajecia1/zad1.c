#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	char name[20];
	printf("Wprowadz swoje imie: ");
	scanf("%s", name);
	printf("Twoje imie to: %s", name);
	return 0;
}
