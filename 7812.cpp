#include <iostream>

using namespace std;

int main(){


	int T, N, M, cost[10000], money, head, tail, cnt;
	cin >> T;
	//1<=M<=300,000,000
	//1<=N<=10000
	for(int test_case = 1; test_case <= T; test_case++){
		cin >> N >> M;
		for(int i =0 ; i < N ; i ++)
			cin >> cost[i];
		money=0;
		cnt=0;

		head = 0 ; tail =0;
		money = cost[0];
		while( tail < N){


			if(money == M){
				cnt ++;
				money -= cost[head++];
				tail ++;
				if(tail == N)
					break;
				money += cost[tail];
			}
			else if(money < M){
				tail ++;
				if(tail == N)
					break;
				money += cost[tail];
			}
			else	// money > M
			{
				money -= cost[head++];
				if(tail < head){
					tail = head;
					money = cost[tail];
				}
			}

		}

		cout << '#' << test_case << ' ' << cnt << endl;
	}

	return 0;
}



// 2
// 5 3
// 1 1 1 1 1
// 10 6
// 1 3 2 5 4 6 2 1 3 2

// #1 3
// #2 4

