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

//-------------------------------------------------------------------
static string IFile = "D:\\result\\input.txt";
static string OFile = "D:\\result\\result.txt";
ifstream input();
ofstream output();
//-------------------------------------------------------------------

#define SORTVAL int
static bool cmp (SORTVAL i,SORTVAL j) { return (i<j); }
static bool cmp_desc (SORTVAL i,SORTVAL j) { return (i>j); }

#define SEARCHVAL int
int cmp_search(SEARCHVAL val, SEARCHVAL target) {
	if (val == target) return 0;

	if (val > target) return 1;
	else return -1;
}

int cmp_search_desc(SEARCHVAL val, SEARCHVAL target) {
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

void mainSearch() {
	ifstream in = input();
	ofstream out = output();

	int T = 0;
	int cases = 0;

	//string line;
	//should call getline after in >> XXX to move to the next line
	//getline(in,line);
	in >> T;
	while (T-- > 0) {
		// cases is the index of current case
		cases++;
		
		////clean data of prev cases---------------------------------------
		//init();

		////Get Input here-------------------------------------------------
		int count;
		in >> count;

		int *array = new int[count];
		for (int i = 0; i < count; ++i) {
			in >> array[i];
		}

		sort(array, array + count);
		cout << bsearchInArray(array, array[3], 0, count - 1) << endl;
		cout << bsearchInArray(array, array[3], 0, count - 5) << endl;
		cout << bsearchInArray(array, array[3], 0, 3) << endl;
		cout << bsearchInArray(array, array[0], 0, 3) << endl;

		int start = 0, end = count - 1;
		cout << start << "," << end << endl;
		boundInArray(array, array[0], start, end);
		cout << start << "," << end << endl;

		start = 0, end = count - 1;
		boundInArray(array, array[end], start, end);
		cout << start << "," << end << endl;

		start = 0, end = count - 1;
		boundInArray(array, array[1], start, end);
		cout << start << "," << end << endl;

		start = 0, end = 0;
		boundInArray(array, array[1], start, end);
		cout << start << "," << end << endl;

		start = 0, end = count - 1;
		boundInArray(array, array[end] + 1, start, end);
		cout << start << "," << end << endl;

		start = 0, end = count - 2;
		boundInArray(array, array[end] + 1, start, end);
		cout << start << "," << end << endl;

		start = 1, end = count - 2;
		boundInArray(array, array[end] + 1, start, end);
		cout << start << "," << end << endl;

		start = 0, end = count - 1;
		boundInArray(array, array[start] - 1, start, end);
		cout << start << "," << end << endl;


		////Main Process Here----------------------------------------------


		////Out new line, finish this case---------------------------------
		//out << "Case #" << cases << ": " << XXX << endl; 
		cout << endl;
	}

	in.close();
	out.close();
}

static ifstream input() {
	ifstream in;
	in.open(IFile);

	return in;
}

static ofstream output() {
	ofstream out;
	out.open(OFile); 
	return out;
}

