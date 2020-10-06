#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


vector < pair<int, int> > virus;
vector < pair<int, int> > selection;
queue < pair<int, int> > q; 
int min_time=999999;
int timemap[50][50];
int N, M, map[50][50];

void select_virus(int idx);
void bfs();


int main(){
	cin >> N >> M;

	for(int i = 0 ; i < N ; i++)for(int j =0 ; j < N ; j++){
		cin >> map[i][j];
		if(map[i][j]==2)
			virus.push_back(make_pair(i, j));
	}
	select_virus(0);
	if(min_time==999999)
		cout << -1<<endl;
	else
		cout << min_time<<endl;
	return 0;
}

void select_virus(int idx){
	if(virus.size() == idx){	//out of index condition
		if(selection.size() == M){	//M viruses selected
			for(int i=0; i<M; i++) q.push(selection[i]);
			memset(timemap, -1, sizeof(timemap));
			
			for(int i=0; i<selection.size(); i++){
				int x = selection[i].first;
				int y = selection[i].second;
				timemap[x][y] = 0;
			}
			bfs();
		}
		return;
	}

	selection.push_back(virus[idx]);
	select_virus(idx+1);
	selection.pop_back();
	select_virus(idx+1);
}

void bfs(){

	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx>=0 && nx<N && ny>=0 && ny<N && timemap[nx][ny]==-1){
				if(map[nx][ny] == 2 && timemap[nx][ny] == -1){
					timemap[nx][ny] = timemap[x][y]+1;
					q.push(make_pair(nx,ny));
				}
				if(map[nx][ny] != 1 && timemap[nx][ny] == -1){
					timemap[nx][ny] = timemap[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	
	bool no_blank = true;
	int max_time = 0;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(map[i][j] == 0){
				if(timemap[i][j] == -1){
					no_blank = false;
					break;
				}
				else{
					max_time = max(max_time, timemap[i][j]);
				}
			}

		}
	}
	if(no_blank) min_time = min(min_time, max_time);
}