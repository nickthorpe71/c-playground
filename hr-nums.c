#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	float a, b;
	int c, d;

	scanf("%d %d", &c, &d);
	scanf("%f %f", &a, &b);

	printf("%d %d\n", c+d, c-d);
	printf("%.1f %.1f\n", a+b, a-b);

    	return 0;
}
