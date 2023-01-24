#include "NewtonInterpolation.h"

float clculateU(float u, int n)
{
    float temp = u;
    for (int i = 1; i < n; i++)
        temp = temp * (u - i);
    return temp;
}

int factorial(int n)
{
    int f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}

double newtonInterpolation(vector<point> points, double xi)
{
    int n = points.size();
    vector<vector<double>> y(n);
    for (int i = 0; i < n; i++)
        y[i].push_back(points[i].y);
    for (int i = 1; i < n; i++)
        for (int j = 0; j < n - i; j++)
            y[j].push_back(y[j + 1][i - 1] - y[j][i - 1]);
    float sum = points[0].y;
    float u = (xi - points[0].x) / (points[1].x - points[0].x);
    for (int i = 1; i < n; i++)
        sum = sum + (clculateU(u, i) * y[0][i]) / factorial(i);
    return sum;
}
