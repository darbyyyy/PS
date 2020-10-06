#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAXIMUM_VALUE 999

using namespace std;

typedef struct coord{
	int r;
	int c;
	coord(int R, int C){
		r = R; c= C;
	}
}coord;
vector<coord> backtrack(int r, int c, int dir);

int costmap[51][51];
int bfsmap[51][51];
int dr[4] = {0, -1, 0, 1};
int dc[4] = {1, 0, -1, 0};

int N, fromR, fromC, destR, destC, k;
int num_circuits, num_points;

int main(){

	for(int i = 0 ; i < 51; i ++){
		for(int j = 0 ; j < 51; j++){
			costmap[i][j] = 1;
			bfsmap[i][j] = MAXIMUM_VALUE;
		}
	}

	cin >> N >> fromR >>fromC >> destR >> destC >> k;
	cin >> num_circuits;
	bfsmap[fromR][fromC] = 1;
	while( num_circuits--){
		cin >> num_points;
		vector <coord> v;
		int r, c, v_size;

		//get inputs
		for(int i =0; i < num_points; i++){
			cin>> r >> c;
			v.push_back(coord(r, c));
		}
		//mark circuits
		v_size = v.size();
		int prev_r = v[0].r;
		int prev_c = v[0].c;
		for(int i = 1; i<v_size; i++){
			r = v[i].r;
			c = v[i].c;
			if(r == prev_r){
				int init_idx, dest_idx;
				if(prev_c > c){
					init_idx = c;
					dest_idx = prev_c;
				}
				else{
					init_idx = prev_c;
					dest_idx = c;
				}
				for(; init_idx <= dest_idx; init_idx++)
					costmap[r][init_idx]=k;
			}
			else{
				int init_idx, dest_idx;
				if(prev_r > r){
					init_idx = r;
					dest_idx = prev_r;
				}
				else{
					init_idx = prev_r;
					dest_idx = r;
				}
				for(; init_idx <= dest_idx; init_idx++)
					costmap[init_idx][c]=k;
			}
		}
	}

	/*BFS*/
	queue <coord> q;
	q.push(coord(fromR, fromC));

	while(!q.empty()){
		int r, c, nr, nc;
		r = q.front().r;
		c = q.front().c;
		q.pop();

		for(int i = 0 ; i < 4 ; i ++){
			nr = r + dr[i];
			nc = c + dc[i];
			if(nr >0 && nc > 0 && nr <= N && nc <= N && bfsmap[nr][nc]> bfsmap[r][c] + costmap[nr][nc]){
				bfsmap[nr][nc] = bfsmap[r][c] + costmap[nr][nc];
				q.push(coord(nr, nc));
			}
		}
	}

	vector<coord> result = backtrack(destR, destC, -1);
	result.push_back(coord(destR, destC));

	cout<< bfsmap[destR][destC] <<endl;
	cout<< result.size();
	for(int i = 0 ; i < result.size(); i++){
		cout << " " << result[i].r << " " << result[i].c;
	}
	cout<<endl;

}

vector<coord> backtrack(int r, int c, int dir){
	vector <coord> result;
	vector <coord> tempresult;
	
	if(r==fromR && c ==fromC){
		result.push_back(coord(r, c));
		return result;
	}
	/*backtrack*/
	int nr, nc;
	int prev_cost = bfsmap[r][c] - costmap[r][c];
	for(int i =0 ; i < 4; i++){
		nr = r + dr[i];
		nc = c + dc[i];
		if(nr >0 && nc > 0 && nr <= N && nc <= N && prev_cost == bfsmap[nr][nc]){
			tempresult = backtrack(nr, nc, i);
			if(dir!= -1 && i != dir)
				tempresult.push_back(coord(r, c));
			if(result.size()==0 || result.size() > tempresult.size())
				result = tempresult;
		}
	}
	return result;
}