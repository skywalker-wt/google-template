#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <queue>         
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <functional> 
#include <stdio.h>
#include <float.h>

using namespace std;

#define SEARCHVAL int
static int cmp_search(SEARCHVAL val, SEARCHVAL target) {
	if (val == target) return 0;

	if (val > target) return 1;
	else return -1;
}

static int cmp_search_desc(SEARCHVAL val, SEARCHVAL target) {
	if (val == target) return 0;

	if (val > target) return -1;
	else return 1;
}

// end points to the last element instead of the element after last
int bsearchInArray(SEARCHVAL *array, SEARCHVAL target, int start, int end) {
	if (start > end) return -1;

	int middle = (start + end) / 2;
	int cmp_result = cmp_search(array[middle], target);

	if (cmp_result == 0) return middle;

	if (cmp_result > 0) return bsearchInArray(array, target, start, middle - 1);
	else return bsearchInArray(array, target, middle + 1, end);
}

// end points to the last element instead of the element after last
int bsearchInVector(vector<SEARCHVAL> array, SEARCHVAL target, int start, int end) {
	if (start > end) return -1;

	int middle = (start + end) / 2;
	int cmp_result = cmp_search(array[middle], target);

	if (cmp_result == 0) return middle;

	if (cmp_result > 0) return bsearchInVector(array, target, start, middle - 1);
	else return bsearchInVector(array, target, middle + 1, end);
}

// end points to the last element instead of the element after last
void boundInArray(SEARCHVAL *array, SEARCHVAL target, int &start, int &end) {
	int (*pcmp)(SEARCHVAL, SEARCHVAL) = cmp_search;

	if (start > end) return;

	if ((*pcmp)(array[start], target) > 0) {
		end = start;
		start--;
		return;
	}

	if ((*pcmp)(array[end], target) < 0) {
		start = end;
		end++;
		return;
	}

	int middle = (start + end) / 2;
	int cmp_result = (*pcmp)(array[middle], target);

	if (cmp_result == 0) {
		start = end = middle;
		return;
	}

	if (cmp_result > 0) {
		if (middle == start) {
			end = start;
			start--;
			return;
		}
		end = middle - 1;
	}
	else {
		if (middle == end) {
			start = end;
			end++;
			return;
		}

		start = middle + 1;
	}

	boundInArray(array, target, start, end);
}