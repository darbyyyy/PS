#include <iostream>
#include <vector>
#include <algorithm>

#define init_nutrients 5

using namespace std;

typedef struct cell{
	vector <int> age;
	int nutrients;
	cell(){
		nutrients = init_nutrients;
	}
}cell;


int adj[3][3][2];

int N, M, K;
int A[11][11];
cell treemap[11][11];

void spring_summer();//나이만큼 양분섭취. 어린거부터. sort 하고 popback바로.
//void summer();//죽은 나무 나이의 1/2가 양분으로.
void fall();//번식. 나무의 나이가 5의 배수일때. 대각선 포함 인접
void winter();//양분 추가. 각 셀의 양분의 양은 입력으로 주어짐.
int cnt_tree();

int  main(){
	for(int i = 0; i < 3 ; i++){
		for(int j = 0 ; j < 3; j++){
			adj[i][j][0] = i -1;
			adj[i][j][1] = j -1;
		}
	}

	int r, c, age, result;
	cin >> N >> M >> K;

	// A 배열 입력
	for(int i = 1 ; i <= N ; i++){
		for(int j = 1 ; j <= N ; j++){
			cin >> A[i][j];
		}
	}

	for(int i = 0 ; i < M ; i++){
		cin >> r >> c >> age;
		treemap[r][c].age.push_back(age);
	}

	for(int i = 1 ; i <= N ; i++){
		for(int j = 1 ; j <= N ; j++){
			sort(treemap[i][j].age.begin(), treemap[i][j].age.end());
		}
	}

	while(K>0){
		spring_summer();
		fall();
		winter();

		result = cnt_tree();
		K--;
	}
	result = cnt_tree();
	cout << result<< endl;
	return 0;
}


//나이만큼 양분섭취. 어린거부터. sort 하고 popback바로.
//죽은 나무 나이의 1/2가 양분으로.
void spring_summer(){

	cell tempcell;
	int v_idx;
	for(int i = 1; i <= N ; i++){
		for(int j = 1 ; j <= N ; j++){
			sort(treemap[i][j].age.begin(), treemap[i][j].age.end());
			tempcell = treemap[i][j];
			int v_size = treemap[i][j].age.size();
			int nutrients = treemap[i][j].nutrients;
			
			for(v_idx = 0 ; v_idx < v_size; v_idx++){
				if(nutrients >= treemap[i][j].age[v_idx]){
					nutrients -= treemap[i][j].age[v_idx];
					treemap[i][j].age[v_idx]++;
				}
				else{
					break;
				}
			}
			v_size --;
			for(; v_idx <= v_size; v_size--){
				nutrients += (treemap[i][j].age[v_size])/2;
				treemap[i][j].age.pop_back();
				
			}

			treemap[i][j].nutrients = nutrients;
		}
	}

}
//번식. 나무의 나이가 5의 배수일때. 대각선 포함 인접
void fall(){
	int v_idx, v_size, nr, nc;
	for(int i = 1 ; i <= N ; i++){
		for(int j = 1 ; j <= N ; j++){
			v_size = treemap[i][j].age.size();
			for(v_idx = 0 ; v_idx < v_size; v_idx++){
				if(!(treemap[i][j].age[v_idx]%5)){
					for(int r = 0 ; r < 3; r++){
						for(int c = 0 ; c < 3; c++){
							nr = i +adj[r][c][0];
							nc = j +adj[r][c][1];

							
							if(nr > 0 && nc > 0 && nr <= N && nc <= N &&  !(nr ==i && nc == j)){
								treemap[nr][nc].age.push_back(1);
							}
						}
					}
				}
			}
		}
	}

}
//양분 추가. 각 셀의 양분의 양은 입력으로 주어짐.
void winter(){
	for(int i = 1; i <= N ; i++){
		for(int j = 1 ; j <= N ; j++){
			treemap[i][j].nutrients += A[i][j];
		}
	}
}

int cnt_tree(){
	int cnt=0;
	for(int i = 1; i <= N ; i++){
		for(int j = 1 ; j <= N ; j++){
			cnt = cnt + treemap[i][j].age.size();
		}
	}
	return cnt;
}
