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
#include <unordered_map>
#include <unordered_set>

using namespace std;

//-------------------------------------------------------------------
static string IFile = "D:\\result\\input.txt";
static string OFile = "D:\\result\\result.txt";
ifstream input();
ofstream output();
//-------------------------------------------------------------------


void main() {
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
		//int count;
		//in >> count;
		//while (count-- > 0) {
		//	in >> 
		//}

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

