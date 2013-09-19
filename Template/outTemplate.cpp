#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stdio.h>
#include <float.h>

using namespace std;

ofstream out;
int cases;

void outFloat() {
	out << fixed;
	out << "Case #" << cases << ": " << setprecision (7) << endl; 
}