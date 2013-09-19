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

using namespace std;

//-------------------------------------------------------------------
static string IFile = "D:\\result\\input.txt";
static string OFile = "D:\\result\\result.txt";
ifstream input();
ofstream output();
//-------------------------------------------------------------------

//Heap template------------------------------------------------------
#define HEAPVAL int
class HeapComparison
{
	bool reverse;
public:
	HeapComparison(const bool& revparam=false) {reverse=revparam;}

	bool operator() (const HEAPVAL& lhs, const HEAPVAL&rhs) const
	{
		if (reverse) return (lhs>rhs);
		else return (lhs<rhs);
	}
};

class Heap {
private:
	HeapComparison comp;
	priority_queue<int,std::vector<HEAPVAL>, HeapComparison> pQueue;
public:
	// Default min heap
	Heap(const bool& min=true) : comp(min){ 
		pQueue = priority_queue<HEAPVAL,std::vector<HEAPVAL>, HeapComparison>(comp);
	}

	bool empty() { return pQueue.empty(); }
	int size() { return pQueue.size(); }
	HEAPVAL top() { return pQueue.top(); }
	void push (const HEAPVAL& val) { pQueue.push(val); }
	void pop() { pQueue.pop(); }

	void buildHeap(HEAPVAL *vals, int size) {
		for (int i = 0; i < size; ++i) push(vals[i]);
	}
};
//End Heap template------------------------------------------------------


void mainHeap() {
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

		////Main Process Here----------------------------------------------
		Heap minHeap(true);
		minHeap.buildHeap(array, count);
		while (!minHeap.empty()) {
			cout << minHeap.top() << ",";
			minHeap.pop();
		}

		cout << endl;
		Heap maxHeap(false);
		maxHeap.buildHeap(array, count);
		while (!maxHeap.empty()) {
			cout << maxHeap.top() << ",";
			maxHeap.pop();
		}


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

