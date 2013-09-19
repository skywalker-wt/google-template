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
int compare(const void * a, const void * b)
{
  return (*(SORTVAL*)a - *(SORTVAL*)b );
}

int compare_desc(const void * a, const void * b)
{
  return (*(SORTVAL*)b - *(SORTVAL*)a);
}

bool cmp (SORTVAL i,SORTVAL j) { return (i<j); }
bool cmp_desc (SORTVAL i,SORTVAL j) { return (i>j); }


void mainSort() {
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

		vector<int> vec(array, array + count);
		qsort(array, count, sizeof(SORTVAL), compare);
		for (int index = 0; index < count; ++index) {
			cout << array[index] << ",";
		}
		cout << endl;

		qsort(array, count, sizeof(SORTVAL), compare_desc);
		for (int index = 0; index < count; ++index) {
			cout << array[index] << ",";
		}
		cout << endl;

		sort(array, array + count, cmp);
		for (int index = 0; index < count; ++index) {
			cout << array[index] << ",";
		}
		cout << endl;

		sort(array, array + count, cmp_desc);
		for (int index = 0; index < count; ++index) {
			cout << array[index] << ",";
		}
		cout << endl;

		sort(vec.begin(), vec.begin()+count);
		for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
			cout << (*it) << ",";
		}
		cout << endl;

		sort(vec.begin(), vec.begin()+count, cmp_desc);
		for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
			cout << (*it) << ",";
		}
		cout << endl;
		////Main Process Here----------------------------------------------


		////Out new line, finish this case---------------------------------
		//out << "Case #" << cases << ": " << XXX << endl; 
		//out << endl;
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

