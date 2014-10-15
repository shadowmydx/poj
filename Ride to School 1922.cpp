#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
int main()
{
	int n, v, t;
	double time, min;
	while(1)
	{
		scanf("%d", &n);
		if (n == 0) break;
		min = 4.5 * 3600;
		while(n--)
		{
			scanf("%d%d", &v, &t);
			if (t < 0) continue;
			time = 4.5 / v * 3600 + t;
			if (time <= min)
			{
				min = time;
			}
		}
		t = ceil(min);
		printf("%d\n", t);
	}
	return 0;
}
