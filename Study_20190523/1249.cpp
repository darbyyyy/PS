/*
https://swexpertacademy.com
problem no. 1249
*/

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main(){
	int T, N, map[100][100], cost[100][100];
	char input;
	queue <pair<int, int>> q;
	pair<int, int> coord;	// coord.first - row , coord.second - column

	cin >> T;

	for(int test_case=1; test_case<=T; test_case++){

		cin >> N;
		for(int i = 0 ; i < N ; i ++){
			for(int j = 0 ; j < N ; j++) {
				cin>>input;
				map[i][j] = input - '0';
				cost[i][j]=-1;
			}
		}

		q.push(make_pair(0, 0));
		cost[0][0]=0;

		while(!q.empty()){
			coord = q.front(); q.pop();
			int x = coord.first, y = coord.second;

			//간소화도 가능하지만 귀찮다.
			if((x-1 >=0) &&  ((cost[x-1][y] == -1) || (cost[x-1][y] > cost[x][y]+ map[x-1][y])) )	//left dir
				{cost[x-1][y] = cost[x][y] + map[x-1][y]; q.push(make_pair(x-1, y));				}
			if((x+1 <N)  &&  ((cost[x+1][y] == -1) || (cost[x+1][y] > cost[x][y]+ map[x+1][y])) )	//right dir
				{cost[x+1][y] = cost[x][y] + map[x+1][y]; q.push(make_pair(x+1, y));}
			if((y-1 >=0) &&  ((cost[x][y-1] == -1) || (cost[x][y-1] > cost[x][y]+ map[x][y-1])) )	//up dir
				{cost[x][y-1] = cost[x][y] + map[x][y-1]; q.push(make_pair(x, y-1));}
			if((y+1 <N)  &&  ((cost[x][y+1] == -1) || (cost[x][y+1] > cost[x][y]+ map[x][y+1])) ) 	//down dir
				{cost[x][y+1] = cost[x][y] + map[x][y+1]; q.push(make_pair(x, y+1));}
		}

		cout << '#' << test_case << ' ' << cost[N-1][N-1] << endl;
	}
	return 0;
}