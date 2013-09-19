#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <queue>         
#include <functional> 
#include <list>
#include <set>
#include <map>
#include <stdio.h>
#include <float.h>
#include <algorithm>

using namespace std;

#define SORTVAL int

//qsort-------------------------------------------------
int compare(const void * a, const void * b)
{
  return (*(SORTVAL*)a - *(SORTVAL*)b );
}

int compare_desc(const void * a, const void * b)
{
  return (*(SORTVAL*)b - *(SORTVAL*)a);
}

//SORTVAL *array;
//qsort(array, size, sizeof(SORTVAL), compare);
//qsort(array, size, sizeof(SORTVAL), compare_desc);
//end qsort-------------------------------------------------

//sort---------------------------------------------------
static bool cmp (SORTVAL i,SORTVAL j) { return (i<j); }
static bool cmp_desc (SORTVAL i,SORTVAL j) { return (i>j); }

//int array[] = {32,71,12,45,26,80,53,33};
//vector<int> myvector (myints, myints+8);              // 32 71 12 45 26 80 53 33
//sort(array, array + count, cmp);
//sort(myvector.begin(), myvector.begin()+4);           //(12 32 45 71)26 80 53 33
//sort(myvector.begin()+4, myvector.end(), cmp); // 12 32 45 71(26 33 53 80)
//sort(myvector.begin()+4, myvector.end(), cmp_desc); // 12 32 45 71(26 33 53 80)