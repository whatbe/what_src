#include "sort.h"

int sort(int *t, size_t s)
{
	int *p1, *p2;
	size_t cur1, cur2, i, j, ii, jj;

	p1 = malloc(s * sizeof(int));
	p2 = malloc(s * sizeof(int));
	if (!(p1 && p2)) return -1;

	cur1 = cur2 = 0;
	while (1)
	{
		if (cur1 == s) cur1 = cur2 = 0;

		for (i = 0; cur1 < s-1 && t[cur1] <= t[cur1+1]; p1[i++] = t[cur1++]);
		p1[i++] = t[cur1++];

		if (cur1 == s)
		{
			if (i == s) return 0;
			continue;
		}

		for (j = 0; cur1 < s-1 && t[cur1] <= t[cur1+1]; p2[j++] = t[cur1++]);
		p2[j++] = t[cur1++];

		for (ii = jj = 0; ii < i && jj < j; ((p1[ii] <= p2[jj]) ? (t[cur2++] = p1[ii++]) : (t[cur2++] = p2[jj++])));
		while (ii < i) t[cur2++] = p1[ii++];
		while (jj < j) t[cur2++] = p2[jj++];
	}
}
