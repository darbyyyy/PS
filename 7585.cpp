#include <iostream>
#define ull unsigned long long int
#define mod 1000000007
using namespace std;

int multi(int base, int exponent, int modular){
	ull num = 1; ull multiplier=base;
	while(exponent){
		if(exponent & 1) num = (num * multiplier) % modular;
		exponent /=2;
		multiplier = (multiplier*multiplier)% modular;
	}
	return num;
}

int main(){
	ull T, A, B, N, K, result, remains, same_i_j, events, cycle, N_or_K, pow_bf, pow_gf;
	unsigned int weight_bf[100000], weight_gf[100000];
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case ++){
		cin >> A >> B >> N >> K;

		same_i_j=0; result=0;
		N_or_K = (N<K) ? N : K;
		cycle = N/K; remains = N%K;
		for(int i = 0; i < K; i++){
			weight_bf[i]=0;
			weight_gf[i]=0; 
		}
		for(ull i = 1 ; i <= N_or_K; i++){
			pow_bf = multi(i%K, A, K);
			pow_gf = multi(i%K, B, K);

			events = (i<=remains) ? (cycle + 1)%mod : cycle % mod; 
			if((pow_bf + pow_gf) % K == 0)
				same_i_j = (same_i_j + events)%mod;

			weight_bf[pow_bf] = (weight_bf[pow_bf] + events)%mod;
			weight_gf[pow_gf] = (weight_gf[pow_gf] + events)%mod;
		}
		for(int i=0; i< K; i++)
			result = (result + ((ull)weight_bf[i]*(ull)weight_gf[(K-i)%K])%mod)%mod;

		result = ((result - same_i_j) + mod)% mod;
		cout << "#" << test_case << ' ' << result << endl;
	}

	return 0;
}