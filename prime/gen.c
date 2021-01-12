#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/type.h>

#define LIM 1e10

typedef uint64_t u64;


int main()
{
	char *p = malloc(LIM);
	if (!p) exit(1);
	memset(p, 1, 2);

	u64 o;

	for (u64 n = 4; n < LIM; n+=2) p[n] = 1;
	for (u64 n = 3; n*n < LIM; n+=2)
	{
		if (!p[n])
		{
			o = n << 1;
			for (u64 m = n*n; m < LIM; m+=o) p[m] = 1;
		}
	}

	/*
	for (u64 i = 0; i < LIM; i++)
		if (!p[i])
			printf("%lu\n", i);
			*/
}
