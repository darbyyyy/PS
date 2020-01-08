#include <iostream>

using namespace std;

char map[20][20];
int saw[26];
int T, R, C;

int get_chr(int x, int y){
	return map[x][y] - 'A';
}

int simulate(int row, int col, int cnt){
	saw[get_chr(row, col)]=1;
	cnt++;
	int max_cnt=cnt, temp;
	// cout << row << ' ' << col << " see "<< get_chr(row, col)<< " cnt "<< cnt<< endl;

	//up
	if((col-1) >=0 && (0==saw[get_chr(row, col-1)])){
		temp = simulate(row, col-1, cnt);
		if(temp > max_cnt) max_cnt=temp;
	}

	//down
	if((col+1) < C && (0==saw[get_chr(row, col+1)])){
		temp = simulate(row, col+1, cnt);
		if(temp > max_cnt) max_cnt=temp;
	}

	//left
	if((row-1) >=0 && (0==saw[get_chr(row-1, col)])){
		temp = simulate(row-1, col, cnt);
		if(temp > max_cnt) max_cnt=temp;
	}

	//right
	if((row+1) < R && (0==saw[get_chr(row+1, col)])){
		temp = simulate(row+1, col, cnt);
		if(temp > max_cnt) max_cnt=temp;
	}
	saw[get_chr(row, col)]=0;
	// cout << "return "<< get_chr(row, col) << endl;
	return max_cnt;
}


int main(){

	int result;
	cin >> T;

	for(int test_case = 1 ; test_case<=T; test_case++){
		cin >> R>>C;

		for(int i =0 ; i < 26; i ++) saw[i]=0;
		for(int i = 0 ; i < R ; i++) for(int j= 0 ; j < C; j++) cin >> map[i][j];
		result = simulate(0, 0, 0);



		cout << '#' <<test_case << ' ' << result<<endl;
	}
	return 0;
}