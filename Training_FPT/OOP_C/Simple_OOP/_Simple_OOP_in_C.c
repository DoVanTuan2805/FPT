#include <stdio.h>
#include <stdint.h>
#include "Shape.c"
#include "Rectangle.c"

void main()
{
    printf("hello\n");
    Shape s1, s2;
    Rectangle r1, r2;
    // Shape_ctor(&s1, 1, 2);
    Rectangle_ctor(&r1, 1, 2, 10, 20);
    // Shape_ctor(&s2, 3, 4);

    Shape_moveTo(&r1.shape, 100, 100);
    Shape_display((Shape *)&r1);
    Shape_display(&r1.shape);
    return;
}
