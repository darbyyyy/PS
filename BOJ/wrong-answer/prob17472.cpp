#include <iostream>


using namespace std;

int N, M, input[10][10], bfsmap[10][10], graph[7][7], nodecnt=0, nodechk[7];

void traverse();
void bfs(int i, int j);
void ttg();

int dx[]={1, 0, -1, 0};
int dy[]={0, -1, 0, 1};

int main(){
	cin >> N >> M;

	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M; j++){
			cin >> input[i][j];
		}
	}

	traverse();
	for(int i = 0 ; i <= nodecnt; i++){
		nodechk[i]=1;
	}
	ttg();

	return 0;
}


void traverse(){
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			if(input[i][j]==1){
				bfs(i, j);
				nodecnt++;
			}
		}
	}
}

void bfs(int i, int j){
	int nx, ny;
	bfsmap[i][j] = nodecnt;
	input[i][j]=0;

	for(int k = 0 ; k < 4 ; k++){
		nx = i + dx[k];
		ny = j + dy[k];
		if(nx >= 0 && nx < N && ny >= 0 && ny < M && input[i][j]==1){
			bfs(nx, ny);
		}
	}
}

void ttg(){
	int node_idx;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			if(bfsmap){
				
			}
		}
	}
}
