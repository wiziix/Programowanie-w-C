#include <stdio.h>

typedef struct {
	char name[20];
	float grade;
} Student;


void bubbleSort(int size, Student * array) {
    int i;
    int j;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (array[j].grade < array[j + 1].grade) {
                Student temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
int main() {
	Student studentArray[5] = {
		{"Alice",4.5}, {"Bob", 3.0},
		{"Charlie", 3.5},	{"James", 5.0},
		{"Bob", 4.0}
	};

	int size = sizeof(studentArray) / sizeof(studentArray[0]);

	bubbleSort(size, studentArray);

	for (int i = 0; i < 5; i++) {
		printf("%s %f\n",studentArray[i].name, studentArray[i].grade);
	}
}
