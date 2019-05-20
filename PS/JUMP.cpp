//https://algospot.com/judge/problem/read/JUMP#

#include <stdio.h>

int main() {
	unsigned long long int _T, _K, result;


	scanf("%lld", &_T);
	while (_T--) {
		scanf("%lld", &_K);
		
		result = ((_K * (_K + 1)) / 2)+1;
		result = (result*result)%20130728;

		printf("%lld\n", result);
	}
	return 0;
}