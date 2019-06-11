#include <iostream>

//SWEA woc님의 답안 참조
using namespace std;


int N, K, T;
long long M, result, G[35][35], Sum_result[35][35], Multiplier[35][35], Sum[35][35], Swap[35][35];

void matmul(long long matA[][35], long long matB[][35]){
	long long temp[35][35] = {0,};
	for( int row=0; row<N; row++) for(int col=0; col<N; col++)for(int k=0; k<N; k++){
		temp[row][col] = temp[row][col] + (matA[row][k] * matB[k][col])%M;
		temp[row][col]%=M;
	}

	for( int row=0; row<N; row++ )for(int col=0; col<N; col++)
		matA[row][col] = temp[row][col];
}

int main(){

	cin >>T;
	for(int test_case = 1 ; test_case <= T ; test_case++){
		result = 0;
		cin >> N >> K >> M;
		int k = K-1;
		char input;

		for(int i = 0 ;i < N; i ++) for(int j = 0 ; j < N ; j ++){
			cin >> input;
			input=='Y'? G[i][j]=1 : G[i][j]=0;
		}

		for(int i =0; i< N ; i ++)for(int j= 0 ; j < N ; j ++){
			Sum_result[i][j] = 0;
			Multiplier[i][j] = G[i][j];
			Sum[i][j] = G[i][j];
		}

		while(k){
			if(k%2 == 1){
				matmul(Sum_result, Multiplier);					//matmul
				for(int i = 0 ; i < N ; i ++)for(int j = 0 ; j < N ; j++)	//add
					Sum_result[i][j] = (Sum_result[i][j] + Sum[i][j])%M;
			}
			for(int i=0 ; i<N ; i++)for(int j= 0 ; j< N; j++)	//copy
				Swap[i][j] = Sum[i][j];
			
			matmul(Sum, Multiplier);						//matmul
			for(int i=0; i<N; i++)for(int j=0;j<N;j++)		//add
				Sum[i][j] = (Sum[i][j] + Swap[i][j])%M;

			matmul(Multiplier, Multiplier);					//matmul

			k /=2;
		}
		for(int i=0;i<N;i++) result = (result + Sum_result[i][i])%M;
		cout << "#" << test_case<< " " << result << endl;
	}
}