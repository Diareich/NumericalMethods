#include "FiniteDifferenceInterpolation.h"

int fdiFactorial(int n)
{
	int fact = 1;
	while (n) 
	{
		fact = fact * n;
		n--;
	}
	return fact;
}

double finiteDifferenceInterpolation(vector<point> points, double xi)
{
	float f, f2 = 0, u, h;
	int i, n, k = 1;
	n = points.size() - 1;
	if (n >= 2)
	{
		int m = n;
		h = points[1].x - points[0].x;
		u = (xi - points[1].x) / h;
		vector<double> p(n + 1);
		vector<double> diff(n + 2);

		f = points[1].y;
		do
		{
			for (i = 1; i < n; i++)
			{
				p[i] = ((points[i + 1].y - points[i].y));
				points[i].y = p[i];
			}
			diff[k++] = p[1];
			n--;
		} while (n != 1);

		float df = u;
		float l = 1;
		for (int i = 1; i < m; i++)
		{
			if (i > 1)
				df = df / fdiFactorial(i);
			f2 = f2 + (df * diff[i]);
			for (int j = 0; j <= i; j++)
				l = l * (u - j);
			df = l;
		}
		f = f + f2;
		return f;
	}
}
