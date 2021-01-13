#include "funfunc.h"

u64 gcd(u64 a, u64 b)
{
	while (b)
	{
		a %= b;
		if (!a) return b;
		b %= a;
	}
	return a;
}

u64 scm(u64 a, u64 b)
{
	return a / gcd(a, b) * b;
}

u64 josephus(u64 n)
{
	u64 b = 0x8000000000000000;

	if (n < 2) return n;

	while (b > n) b >>= 1;
	return ((n ^ b) << 1) | 1;
}

u64 collatz(u64 n)
{
	if (!n) return 0;

	u64 count = 0;
	do
	{
		while (!(n&1))
		{
			n >>= 1;
			count++;
		}
		n = n * 3 + 1;
		count++;
	} while (n != 4)

	return count - 1;
}
