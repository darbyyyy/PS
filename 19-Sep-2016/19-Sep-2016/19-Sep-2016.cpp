//https://algospot.com/judge/problem/read/PROMISES

#include <stdio.h>
#include <stdlib.h>

#define _MAX_VERTICES 201
#define _INF 100000000

int _T, _V = 0, _M, _N, a, b, c, answer;
int ary[_MAX_VERTICES][_MAX_VERTICES];

void update(int a, int b, int c);

int main() {
	
	scanf("%d", &_T);

	while (_T--) {
		scanf("%d%d%d", &_V, &_M, &_N);

		answer = 0;
		for (int i = 0; i < _V; i++)	//init array
			for (int j = 0; j < _V; j++) 
				ary[i][j] = _INF;
		for (int i = 0; i < _V; i++)	//infinite loop?
			ary[i][i] = 0;

		while (_M--) {	//can be optimized by using vector
			scanf("%d%d%d", &a, &b, &c);
			update(a, b, c);
		}


		for (int i = 0; i < _N; i++) {
			scanf("%d%d%d", &a, &b, &c);
			if (ary[a][b] > c) {
				update(a, b, c);
				answer++;
			}
		}

	
		printf("%d\n", _N-answer);
	}
	system("pause");
	return 0;
}

void update(int a, int b, int c) {
	ary[a][b] = c;
	ary[b][a] = c;

	for (int i = 0; i < _V; i++) {
		if ((ary[b][i] + c) < ary[a][i])	//check the cost between a and i and update
			update(a, i, ary[b][i] + c);
		if ((ary[a][i] + c) < ary[b][i])	//check the cost between b and i and update
			update(b, i, ary[a][i] + c);
	}
}