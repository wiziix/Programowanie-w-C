#include <stdio.h>

void valueDouble(float* f) {
	*f *= 2;
}

int main() {

	float f = 1.35;

	valueDouble(&f);

	printf("%f", f);

}
