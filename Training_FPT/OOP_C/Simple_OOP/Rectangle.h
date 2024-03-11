#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <stdio.h>
#include <stdint.h>
#include "Shape.h"
typedef struct
{
    Shape shape;
    uint16_t x;
    uint16_t y;
    uint16_t width;
    uint16_t height;
} Rectangle;
void Rectangle_ctor(Rectangle *const me, uint16_t x, uint16_t y, uint16_t width, uint16_t height);
void displayRec(Rectangle *const me);
#endif