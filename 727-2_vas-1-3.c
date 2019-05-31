#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int a, b;
	double c;
	scanf("%d %d", &a, &b);
	c = pow((double)a, (double)b);
	printf("%f", c);
	return 0;
}
