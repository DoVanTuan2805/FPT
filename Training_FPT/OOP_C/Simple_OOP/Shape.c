#include "Shape.h"
void Shape_ctor(Shape *const me, uint16_t x, uint16_t y)
{

    me->x = x;
    me->y = y;
}
void Shape_moveTo(Shape *const me, uint16_t dx, uint16_t dy)
{
    me->x = dx;
    me->y = dy;
}

void Shape_display(Shape *const me)
{
    printf("Shape :: x : %d - y : %d\n", me->x, me->y);
}
