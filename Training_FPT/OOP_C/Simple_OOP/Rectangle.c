#include "Rectangle.h"

void Rectangle_ctor(Rectangle *const me, uint16_t x, uint16_t y, uint16_t width, uint16_t height)
{
    Shape_ctor(&me->shape, x, y);
    me->x = x;
    me->y = y;
    me->width = width;
    me->height = height;
}
void Rec_display(Rectangle *const me)
{
    printf("x : %d - y : %d\n", me->x, me->y);
    printf("width : %d - heigth : %d\n", me->width, me->height);
}