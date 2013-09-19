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


#define GKEY string
struct GNode;
struct Edge {
	GNode *from;
	GNode *to;
	int distance;

	Edge(GNode *from, GNode *to, int distance) 
		: from(from), to(to), distance(distance) {}
};

struct GNode {
	list<Edge> edges;
	bool bvisited, dvisited;
	GKEY key;

	GNode(GKEY key) : key(key), bvisited(false), dvisited(false) {}

	void addEdge(GNode *adj, int distance = 1) { 
		edges.push_back(Edge(this, adj, distance)); 
	};

//};

	void graph_bfs() {
		queue<GNode *> bfsQueue;
		bfsQueue.push(this);
		bvisited = true;
		//init this here


		while (!bfsQueue.empty()) {
			GNode *from = bfsQueue.front();
			bfsQueue.pop();
			// Do staff here of from

			
			for (list<Edge>::iterator it = from->edges.begin(); it != from->edges.end(); ++it) {
				int distance = (*it).distance;
				GNode *to = (*it).to;

				//Do staff here of to


				if (!to->bvisited) bfsQueue.push(to);
				to->bvisited = true;
			}
		}
	}

	//return true means we could finish dfs
	bool graph_dfs() {
		dvisited = true;

		for (list<Edge>::iterator it = edges.begin(); it != edges.end(); ++it) {
			int distance = (*it).distance;
			GNode *to = (*it).to;

			if (!to->dvisited) {
				if (to->graph_dfs()) return true;
			}
		}
		
		dvisited = false;
		return false;
	}
};

void addEdge(GKEY a, GKEY b, map<GKEY, GNode*> &graph, int distance = 1) {
	if (graph.find(a) == graph.end())
		graph[a] = new GNode(a);
	if (graph.find(b) == graph.end())
		graph[b] = new GNode(b);

	GNode *aNode = graph[a];
	GNode *bNode = graph[b];

	aNode->addEdge(bNode, distance);
	if (aNode != bNode)
		bNode->addEdge(aNode, distance);
}


