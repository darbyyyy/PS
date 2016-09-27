#include <stdio.h>
#include <vector>
using namespace std;

#define _MAX_NUM 1000001

int main() {
	int _T, _N, input, idx, result, cnt;
	scanf("%d", &_T);
	vector<int> ary;
	while (_T--) {
		scanf("%d", &_N);
		ary.clear();
		ary.resize(_MAX_NUM);
		result = 0;
		for (int i = 0; i < _N; i++) {
			scanf("%d", &input);
			cnt = 0;
			idx = input;
			//sum
			while (idx > 0) {
				cnt += ary[idx];
				idx &= (idx - 1);
			}
			cnt += ary[0];
			
			result = result + ary[1000000] - cnt;
			//add
			ary[1000000]++;
			if (!input)
				ary[0]++;
			else {
				while (input < 1000000) {
					ary[input]++;
					input += (input & -input);
				}
			}
		}
		printf("%d\n", result);
	}
	return 0;
}