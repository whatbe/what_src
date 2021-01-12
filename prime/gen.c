#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/type.h>

#define LIM 1e10
#define NOTP  1


int main()
{
	uint8_t *p = malloc(LIM);
	if (!p) exit(1);
	memset(p, NOTP, 2);

	uint64_t m, n, o;

	for (n = 4; n < LIM; n+=2) p[n] = NOTP;
	for (n = 3; n*n < LIM; n+=2)
	{
		if (!p[n])
		{
			o = n << 1;
			for (m = n*n; m < LIM; m+=o) p[m] = NOTP;
		}
	}

	/*
	for (uint64_t i = 0; i < LIM; i++)
		if (!p[i])
			printf("%lu\n", i);
			*/
}
