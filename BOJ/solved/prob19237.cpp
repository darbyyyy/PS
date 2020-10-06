/*
Problem Description 

상어
- priority: 1~M
- k: 냄새가 지속되는 시간
- 맨 처음에 보고있는 방향
- 각 상어별로 현재 머리의 방향에 기반한 이동 우선순위

이동 우선순위
1. 인접한 칸 중 아무 냄새가 없는 칸
2. 자신의 냄새가 있는 칸

*이동에는 1초가 걸림
*모든 상어가 이동한 후 한 칸에 여러마리가 있으면 가장 작은 번호를 제외하고 쫓겨남

to solve: 1번 상어만 격자에 남게되기까지 몇초가 걸리는지.
*/

#include <iostream>
using namespace std;

struct node{
	int M, time;

	node(){
		M = -1;
		time = 0;
	}

	void init(int MM, int kk){
		M = MM;
		time = kk;
	}
};

struct sharkk{
	int r, c, isalive, headdir;

	void init(int row, int col){
		r = row;
		c = col;
		isalive=1;
	}

	void dead(){
		isalive=0;
	}
};

//up, down, left, right

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int main(){
	int N, M, k, priority[400][4][4], temp, sharkcnt, time=0;
	sharkk c_shark;
	int cr, cc, nr, nc, headdir, priordir, flag;
	node map[20][20];
	sharkk shark[400];
	/*
	N: 격자의 height, width
	M: 상어의 수
	k: 상어의 냄새가 지속되는 시간
	shark_dir: 현재 상어가 보고있는 방향
	priority[shark][headdir][sequence]: 각 상어들의 현재 방향에 따른 이동 우선순위
	map: 
	*/
	cin >> N >> M >> k;
	sharkcnt = M;
	//get inputs and mapping to my data structure

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin>> temp;
			if(temp>0){
				shark[temp-1].init(i, j);
				map[i][j].init(temp-1, k);
			}else{
				map[i][j].init(-1, 0);
			}
		}
	}

	for(int i = 0 ; i < M ; i++){
		cin >> temp;
		shark[i].headdir = temp-1;
	}

	for(int sharknum= 0; sharknum< M ; sharknum++){
		for(headdir=0; headdir < 4 ; headdir++){
			for(int i = 0 ; i < 4 ; i++){
				cin>> temp;
				priority[sharknum][headdir][i]=temp-1;
			}
		}
	}

	//simulation
	while(sharkcnt>1 && time < 1000){
		time++;
		//1. 이동

		for(int sharknum = 0 ; sharknum < M ; sharknum++){
			if(shark[sharknum].isalive){
				flag=0;
				c_shark = shark[sharknum];
				cc = c_shark.c;
				cr = c_shark.r;
				headdir = c_shark.headdir;

				for(int i = 0 ; i < 4 ; i++){
					priordir = priority[sharknum][headdir][i];

					nr = cr + dr[priordir];
					nc = cc + dc[priordir];

					//빈곳이있으면
					if(nr > -1 && nc > -1 && nr < N && nc < N && map[nr][nc].time==0){
						flag=1;

						//이곳으로 이동하려는 다른 상어가있을때.
						if(map[nr][nc].M!=-1){
							int othershark = map[nr][nc].M;

							if(othershark < sharknum)
								shark[sharknum].dead();
							else{
								shark[othershark].dead();
								shark[sharknum].r = nr;
								shark[sharknum].c = nc;
								map[nr][nc].M = sharknum;
							}
							sharkcnt--;
						}else{
							shark[sharknum].r = nr;
							shark[sharknum].c = nc;
							shark[sharknum].headdir = priordir;
							map[nr][nc].M = sharknum;


						}

						break;
					}
				}

				//빈곳이 없었다면 내 냄새가 있는 곳으로.
				if(!flag){
					for(int i = 0 ; i < 4 ; i ++){
						priordir = priority[sharknum][headdir][i];

						nr = cr + dr[priordir];
						nc = cc + dc[priordir];

						if(nr > -1 && nc > -1 && nr < N && nc < N && map[nr][nc].M==sharknum){
							flag=1;

							shark[sharknum].r = nr;
							shark[sharknum].c = nc;
							shark[sharknum].headdir = priordir;
							// map[nr][nc].time = k;

							break;
						}
					}
				}
			}
		}

		//기존 냄새 시간 감소
		for(int i = 0 ; i < N; i ++){
			for(int j = 0 ; j < N ; j++){
				if(map[i][j].time > 0){
					map[i][j].time--;
					if(map[i][j].time==0)
						map[i][j].M = -1;
				}
				
			}
		}


		//이동한 곳 냄새 마킹
		for(int sharknum = 0 ; sharknum < M ; sharknum++){
			if(shark[sharknum].isalive){
				c_shark = shark[sharknum];
				cr = c_shark.r;
				cc = c_shark.c;

				map[cr][cc].M = sharknum;
				map[cr][cc].time = k;
			}
		}
	}
	if(sharkcnt==1)
		cout << time << endl;
	else
		cout << -1 << endl;

	return 0;
}

