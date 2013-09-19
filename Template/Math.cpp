#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <queue>         
#include <list>
#include <set>
#include <map>
#include <math.h>
#include <algorithm>
#include <functional> 
#include <stdio.h>
#include <float.h>

using namespace std;

//ax^2 + bx + c = 0
void solvePoly(double a, double b, double c, double &maxResult, double &minResult) {
	double b2_4ac = b * b - 4 * a * c;
	if (abs(b2_4ac) < 0.1e-10) b2_4ac = 0.0;

	double sqrt_b2_4ac = sqrt(b2_4ac);
	maxResult = (sqrt_b2_4ac - b) / (2 * a);
	minResult = (-sqrt_b2_4ac - b) / (2 * a);
}

//GCD
int GCD(int x, int y)
{
     int t;
     while(y > 0) {
          t = x % y;
          x = y;
          y = t;
     }

     return x;
}
