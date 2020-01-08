#include <iostream>

using namespace std;

int trouble[21][21];
int T, N, M, a, b, result;
int in_burger[21];

int return_cnt(int idx){
	if(idx==N){
		for(int i=1; i<=N;i++)
			if(in_burger[i] && trouble[idx][i])
				return 1;
		return 2;
	}
	else{
		int cnt=0;
		cnt+= return_cnt(idx+1);

		for(int i=1; i<=N; i++)
			if(in_burger[i] && trouble[idx][i])
				return cnt;
		in_burger[idx]=1;
		cnt+= return_cnt(idx+1);
		in_burger[idx]=0;

		return cnt;
	}
}

int main(){
	cin >> T;

	for( int test_case=1;  test_case<=T; test_case++){
		cin >> N >> M;

		for(int i=1;i<=N; i++) for(int j=1;j<=N;j++) trouble[i][j]=0;
		for(int i = 0 ; i < M ; i ++){
			cin >> a >> b;
			trouble[a][b]=1;
			trouble[b][a]=1;
		}

		result = return_cnt(1);
		cout << "#"<< test_case<< " "<< result <<endl;
	}

	return 0;
}