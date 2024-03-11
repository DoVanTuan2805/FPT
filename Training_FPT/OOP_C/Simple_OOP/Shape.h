#ifndef SHAPE_H
#define SHAPE_H
#include <stdint.h>
typedef struct
{
    uint16_t x;
    uint16_t y;
} Shape;
void Shape_ctor(Shape *const me, uint16_t x, uint16_t y);
void Shape_moveTo(Shape *const me, uint16_t dx, uint16_t dy);
void Shape_display(Shape *const me);
#endif