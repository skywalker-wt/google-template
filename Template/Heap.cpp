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
