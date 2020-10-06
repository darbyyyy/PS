//17:24 start
//18:23 debug
//18:26 1st code-clear

#include <iostream>


using namespace std;

int R, C, mark[4]={0,}, map[26][26];
int chr_to_int(char c);

//right, up, left, down
int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};

int block[8][4]= {
	{0, 1, 0, 1}, //|
	{1, 0, 1, 0}, //-
	{1, 1, 1, 1}, //+
	{1, 0, 0, 1}, //1
	{1, 1, 0, 0}, //2
	{0, 1, 1, 0}, //3
	{0, 0, 1, 1}, //4
	{0, 0, 0, 0}  //.
};
char to_symbols[7] = {'|', '-' , '+' , '1', '2', '3', '4'};

// . blank
// |, -, +, 1, 2, 3, 4 for block
// M for moscow, Z for Zagreb

int main(){
	int shape, nr, nc, blank_r, blank_c;
	char c, blank_char;
	cin >> R >> C;

	for(int i =1 ; i <= R ; i++){
		for(int j =1 ; j <= C ; j++){
			cin >> c;
			map[i][j] = chr_to_int(c);
		}
	}

	for(int i = 1 ; i <= R ; i++){
		for(int j = 1 ; j<= C ; j++){
			shape = map[i][j];
			if(shape >=0 && shape < 7){
				for( int k = 0 ; k < 4 ; k++){
					if(block[shape][k]){
						nr = i + dr[k];
						nc = j + dc[k];
						if(nr > 0 && nc > 0 && nr <= R && nc <= C && map[nr][nc]==7){
							blank_r = nr;
							blank_c = nc;
							break;
						}
					}
				}
			}
		}
	}
	for(int i = 0 ; i < 4; i++){
		nr = blank_r + dr[i];
		nc = blank_c + dc[i];
		if(nr > 0 && nc > 0 && nr <= R && nc <= C)
			if(block[map[nr][nc]][(i+2)%4]==1)
				mark[i]=1;
	}


	for(int i = 0; i < 7 ; i++){
		int flag = 0;
		for(int j = 0 ; j < 4 ; j++){
			if(block[i][j] == mark[j]){
				flag++;
			}
		}
		if(flag==4){
			blank_char = to_symbols[i];
			break;
		}
	}
	cout << blank_r <<" " << blank_c << " "<< blank_char <<endl;

	return 0;
}

int chr_to_int(char c){
	if( c == '|')
		return 0;
	else if(c == '-')
		return 1;
	else if(c == '+')
		return 2;
	else if(c == '1')
		return 3;
	else if(c == '2')
		return 4;
	else if(c == '3')
		return 5;
	else if(c == '4')
		return 6;
	else if(c == '.')
		return 7;
	else
		return -1;
}
