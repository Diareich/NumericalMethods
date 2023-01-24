#include "InterpolationMultipleNodes.h"

double interpolationMultipleNodes(vector<point> points, double xi)
{
    int n = (int)points.size();
    double f = 0;
    for (int i = 0; i < n; i++)
    {
        double y = points[i].y;
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                y = y * (xi - points[j].x) / 
                    double(points[i].x - points[j].x);
            }
        }
        f += y;
    }
    return f;
}
