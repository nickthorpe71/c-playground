#include <math.h>
#include <stdio.h>

int Liters(double time);

int main()
{
	printf("%i\n", Liters(3));
	return 0;
}

int Liters(double time)
{
        double result = time / 2;
        return (int) floor(result);
}
