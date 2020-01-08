#include <iostream>

using namespace std;
int relation[501][501], N, M, cnt, get[501];

void foo(int fnum){

	for(int i = 1 ; i <=N; i ++){
		if(relation[fnum][i]==1 && get[i]==0){
			get[i]=1;
			cnt++;
		}
	}
}

int main(){

	int T, a, b;
	cin >> T;

	for (int test_case=1; test_case<=T; test_case++){
		cnt=0;
		cin >> N >> M;

		for(int i= 1; i <=N; i++) get[i]=0;
		get[1]=1;
		for(int i =1 ; i <= N ; i ++) for (int j = 1 ; j <= N ;  j++) relation[i][j]=0;

		for(int i = 0 ; i < M ; i ++){
			cin >> a >> b;
			relation[a][b]=1;
			relation[b][a]=1; 
		}

		for(int i = 1 ; i <= N ; i++){
			if(relation[1][i] == 1){
				
				if(get[i]==0){	// 1과 친구인 xx의 친구를 체크하는과정에서 1과 친구인 yy가 이미 카운트되었을 수 있기때문에.
					cnt++;
					get[i]=1;
				}
				foo(i);
			}
		}


		cout << "#" << test_case << " " << cnt << endl; 
	}
	return 0;
}