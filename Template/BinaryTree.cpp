#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>

using namespace std;

struct TreeNode
{
	TreeNode *left, *right;
	// values;

	TreeNode() : left(NULL), right(NULL) {
	}
};

// This is pre-order
template<typename T>
void treeDfs(TreeNode *head, T &result) {
	if (head == NULL) return;

	//Do things here.

	treeDfs(head->left, result);
	treeDfs(head->right, result);
}


template<typename T>
void treeBfs(TreeNode *head, T &result) {
	if (head == NULL) return;

	list<TreeNode*> current;
	list<TreeNode*> next;

	next.push_back(head);

	while (!next.empty()) {
		current = next;

		//Could do staff here with the same level nodes in next.
		
		next.clear();
		while (!current.empty()) {
			TreeNode *front = current.front();
			current.pop_front();

			//Do things here with the first node(front) in queue.

			if (front->left != NULL) next.push_back(front->left);
			if (front->right != NULL) next.push_back(front->right);
		}
	}
}