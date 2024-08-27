#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main(void)
{
    uint32_t x = 50;
    uint32_t y = 50;
    uint32_t z = 10;
    uint32_t x1;

	x1 = x - z * sin(30 * (M_1_PI/180));
    printf("%d\n", z);
    printf("%f\n", sin(30 * (M_1_PI/180)));
    printf("%d\n", x1);
	return (0);
}