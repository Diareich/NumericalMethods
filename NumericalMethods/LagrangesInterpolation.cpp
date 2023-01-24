#include "LagrangesInterpolation.h"

double lagrangesInterpolate(vector<point> points, double xi)
{
    int n = (int)points.size();
    double result = 0;
    for (int i = 0; i < n; i++)
    {
        double term = points[i].y;
        for (int j = 0; j < n; j++)
            if (j != i)
                term = term * (xi - points[j].x) / double(points[i].x - points[j].x);
        result += term;
    }
    return result;
}
