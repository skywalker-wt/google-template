#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>

using namespace std;

//-------------------------------------------------------------------
static string IFile = "D:\\result\\input.txt";
static string OFile = "D:\\result\\result.txt";
ifstream input();
ofstream output();
//-------------------------------------------------------------------


#define VAL int
struct TreeNode
{
	TreeNode *left, *right;
	VAL value;

	TreeNode(VAL value) : value(value), left(NULL), right(NULL) {
	}
};

TreeNode* BuildTree(VAL *vals, int length) {
	if (length <= 0) return NULL;

	int rootIndex = length / 2;
	TreeNode *root = new TreeNode(vals[rootIndex]);

	root->left = BuildTree(vals, rootIndex);
	root->right = BuildTree(vals + rootIndex + 1, length - rootIndex - 1);

	return root;
}

void treeDfs(TreeNode *head) {
	if (head == NULL) return;

	treeDfs(head->left);
	cout << head->value << " ";
	treeDfs(head->right);
}

void treeBfs(TreeNode *head) {
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
			cout << front->value << ",";

			if (front->left != NULL) next.push_back(front->left);
			if (front->right != NULL) next.push_back(front->right);
		}
	}
}

void mainTree() {
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
		
		int count;
		in >> count;

		int *array = new int[count];
		for (int i = 0; i < count; ++i) {
			in >> array[i];
		}

		TreeNode *node = BuildTree(array, count);
		treeBfs(node);
	}

	//out << fixed;
	//out << "Case #" << cases << ": " << setprecision (7) << (result * 180 / PI)  << endl; 
	//out << "Case #" << cases << ": " << endl; 
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

