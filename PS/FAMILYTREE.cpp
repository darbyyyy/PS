//https://algospot.com/judge/problem/read/FAMILYTREE#

#include <stdio.h>
#include <vector>
#include <stdlib.h>
using namespace std;

int parents[100000];
int traverse(vector<vector<int>> & child, vector<int> &depth, vector<int> &in2tr, int _depth, int idx, int cnt);

int main() {
	int _T, _N, _Q, a, b, temp;
	parents[0] = -1;	//root
	scanf("%d", &_T);
	while (_T--) {
		vector<vector<int>> child;
		vector<int> depth;
		vector<int> in2tr;
		scanf("%d%d", &_N, &_Q);

		child.clear();
		depth.clear();
		in2tr.clear();
		child.resize(_N + 1);
		depth.resize(_N + 1);
		in2tr.resize(_N + 1);

		for (int i = 1; i < _N; i++) {
			scanf("%d", &parents[i]);
			child[parents[i]].push_back(i);
		}
		traverse(child, depth, in2tr, 0, 0, 0);
		
		for (int i = 0; i < _Q; i++) {
			scanf("%d%d", &a, &b);

			if (in2tr[a] > in2tr[b]) {	//if a > b,
				temp = a;	//swap a and b
				a = b;
				b = temp;
			}
			//Whatever a n b are, a < b.
			if (a == b)	printf("0\n");
			else {
				temp = b;
				while (in2tr[a] < in2tr[parents[temp]])
					temp = parents[temp];
				printf("%d\n", -2* depth[parents[temp]] + depth[a]+depth[b]);
			}
		}
	}
	return 0;
}
/*
depth[i] - store i-th node's depth information on the tree
in2tr[i] - store the number of i-th node based on traversal search
child[i] - store i-th node's child's idxs
*/
int traverse(vector<vector<int>> &child, vector<int> &depth, vector<int> &in2tr, int _depth, int idx, int cnt) {
	depth[idx] = _depth;
	in2tr[idx] = cnt++;
	int size = (int)child[idx].size();
	for (int i = 0; i < size; i++) cnt = traverse(child, depth, in2tr, _depth + 1, child[idx][i], cnt);
	return cnt;
}