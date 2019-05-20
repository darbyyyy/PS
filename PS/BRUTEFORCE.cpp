#include <stdio.h>
#include <stdlib.h>

#define _MOD 1000000007

int main() {

	long long int _T, _A, _B, _N, result, _temp, _sum;

	scanf("%lld", &_T);

	while (_T--) {
		result = 1;
		scanf("%lld%lld%lld", &_A, &_B, &_N);
		
		for (long long int i = 0; i < _A; i++) {
			result = (result*_N) % _MOD;
		}
		_temp = result;
		for (long long int i = 0; i < (_B - _A); i++) {
			_temp = (_temp * _N) % _MOD;
			result = ((result + _temp) % _MOD);
		}
		printf("%lld\n", result);
	}
	return 0;
}