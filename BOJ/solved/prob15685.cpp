#include <iostream>
#include <vector>
#include <cstring>
#include <stdio.h>


using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main(){
	int N, map[101][101], x, y, d, g;//direction, generation
	int square_cnt = 0;
	memset(map, 0, sizeof(map));

	cin >> N;

	//mark dragon curve;
	for(int i = 0 ; i < N ; i++){
		cin >> x >> y >> d >> g;
		vector <int> v;
		v.push_back(d);
		for(int gen = g; gen>0; gen--){
			for(int v_idx = v.size()-1; v_idx >=0; v_idx--){
				v.push_back((v[v_idx]+1)%4);
			}
		}
		int v_size = v.size();
		map[y][x] = 1;
		for(int v_idx = 0; v_idx < v_size; v_idx++){
			y += dy[v[v_idx]];
			x += dx[v[v_idx]];
			map[y][x] = 1;
		}
	}


	for(int y_coord = 0; y_coord < 100; y_coord++){
		for(int x_coord = 0; x_coord < 100; x_coord++){
			if(map[y_coord][x_coord]&&map[y_coord+1][x_coord]&& map[y_coord][x_coord+1] && map[y_coord+1][x_coord+1]){
				square_cnt++;
			}
		}
	}
	cout << square_cnt << endl;
}