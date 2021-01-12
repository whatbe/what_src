#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/type.h>

#define LIM 1e10


int main()
{
	uint8_t *p = malloc(LIM);
	if (!p) exit(1);
	memset(p, 1, 2);

	uint64_t o;

	for (uint64_t n = 4; n < LIM; n+=2) p[n] = 1;
	for (uint64_t n = 3; n*n < LIM; n+=2)
	{
		if (!p[n])
		{
			o = n << 1;
			for (uint64_t m = n*n; m < LIM; m+=o) p[m] = 1;
		}
	}

	/*
	for (uint64_t i = 0; i < LIM; i++)
		if (!p[i])
			printf("%lu\n", i);
			*/
}
