/*
https://swexpertacademy.com
problem no. 7258
*/

#include<iostream>
#include<cstring>
#include<algorithm>


using namespace std;

int R, C;
char cmd[20][20];
int chk[20][20][16][4];

int dir_x[4]={0, 1, 0, -1};
int dir_y[4]={-1, 0, 1, 0};

bool simulate(int row, int col, int dir, int memory){
	if(chk[row][col][memory][dir]==1) return false;
	else chk[row][col][memory][dir]=1;
	char symbol = cmd[row][col];
	if(symbol>='0' && symbol<='9') memory = symbol-'0';
	else if(symbol=='<' || (symbol=='_' && memory!=0)) dir = 3;
	else if(symbol=='>' || (symbol=='_' && memory==0)) dir = 1;
	else if(symbol=='^' || (symbol=='|' && memory!=0)) dir = 0;
	else if(symbol=='v' || (symbol=='|' && memory==0)) dir = 2;
	else if(symbol=='+') memory = (memory+1)%16;
	else if(symbol=='-') memory = (memory+15)%16;
	else if(symbol=='@') return true;


	if(symbol=='?'){
		bool possibility=false;

		for(int i = 0 ; i < 4; i ++){
			if(simulate((row + R + dir_y[i])%R, (col + C + dir_x[i])%C, i, memory) ==true){
				possibility = true;
				break;
			}
		}
		return possibility;

	}else{
		row = (row + R + dir_y[dir])%R;
		col = (col + C + dir_x[dir])%C;
		return simulate(row, col, dir, memory);
	}
}


int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{

		cin >> R >> C;
		memset(chk, 0, sizeof(chk));

		for(int i = 0 ; i <R; i++){
			for(int j = 0; j<C; j++){
				cin >> cmd[i][j];
			}
		} 

		cout << "#" << test_case<<" ";
		if(simulate(0, 0, 1, 0)) cout << "YES\n";
		else cout << "NO\n";
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}