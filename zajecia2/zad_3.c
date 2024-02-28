#include <stdio.h>
#include <math.h>

typedef struct {
    int x;
    int y;

} Point;

typedef struct {
    Point p1;
    Point p2;
    Point p3;
    Point p4;
} Rectangle;

void changeCoordinates(Point * p) {
    p->x = 5;
    p->y = 5;
}
float distanceCalculator(Point p1, Point p2) {
    return (float)sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y),2));
}

void rectangleCalculator(Rectangle r) {
    float a = distanceCalculator(r.p1, r.p2);
    float b = distanceCalculator(r.p3, r.p4);

    printf("Area: %f\nPerimeter: %f\n", a * b, 2 * a + 2 * b);
}

int main() {

    Point p1 = { 1,2 };

    changeCoordinates(&p1);

    printf("(%d,%d)", p1.x, p1.y);

    Rectangle r1 = { {2,5},{8,5},{2,3},{8,3} };

    printf("\n");

    rectangleCalculator(r1);

}
