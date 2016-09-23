//https://algospot.com/judge/problem/read/KBODRAFT#

#include <stdio.h>
#include <stdlib.h>

#define _MAX_PLAYER 100000

int ary[_MAX_PLAYER][2];
int exist[10];

int main() {
	int _T, _K, _N, ability_sum, max, cnt;
	scanf("%d", &_T);
	while (_T--) {
		for (int i = 1; i < 10; i++) exist[i] = 0;
		ability_sum = 0;
		cnt = 0;
		max = 0;

		scanf("%d%d", &_N, &_K);
		for (int i = 0;i < _N; i++) scanf("%d%d", &ary[i][0], &ary[i][1]);
		//0 to _K-1
		for (int i = 0; i < _K; i++) {	exist[ary[i][0]]++;	ability_sum += ary[i][1];}	
		for (int i = 1; i < 10; i++)	cnt += (exist[i]>0);
		if ((cnt == 9) && (max < ability_sum)) 	max = ability_sum;
		//_K to _N-1
		for (int i = _K; i < _N; i++) {
			exist[ary[i - _K][0]]--;
			cnt = cnt - !exist[ary[i-_K][0]] + !exist[ary[i][0]];
			exist[ary[i][0]]++;
			ability_sum = ability_sum - ary[i - _K][1] + ary[i][1];
			if ((cnt == 9 )&&(max < ability_sum)) max = ability_sum;
		}
		printf("%d\n", max);
	}
	system("pause");
	return 0;
}