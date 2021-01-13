#ifndef __FUNFUNC_H__
#define __FUNFUNC_H__

#include <sys/types.h>
typedef uint64_t u64;

// find the greatest common divisor or the smallest common multiple of number a and b
u64 gcd(u64, u64);
u64 scm(u64, u64);

// find the place to be in a suscide circle of n members (cf.ref josephus problem)
u64 josephus(u64);

#endif
