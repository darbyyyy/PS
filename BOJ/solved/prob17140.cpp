#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 1<= r, c, k <= 100
int main(){
	int r, c, k;
	int row=3, col=3, ary[100][100]={0,}, cnt100, max_row=3, max_col=3;
	int i, j, t;
	string s;

	
	cin >> r>> c>> k;
	r--;c--;
	for(int i = 0 ; i< 3; i++)
		for(int j= 0 ; j < 3; j++)
			cin >> ary[i][j];
	cnt100=0;
	while(cnt100<100 && ary[r][c] != k){
		cnt100++;
		
		//R
		if(row >= col){
			max_col = 0;
			for(i=0 ;i<row; i++){
				vector<pair<int, int> > v;
				int cnt[101]={0,};
				for(j= 0 ; j< col; j++) cnt[ary[i][j]]++;
				for(t = 1 ; t <=100; t++) if(cnt[t]) v.push_back(make_pair(cnt[t], t));

				sort(v.begin(), v.end());
				int v_size = v.size();
				for(j = 0 ; j < 50; j++){
					if(j<v.size()){
						ary[i][2*j]=v[j].second;
						ary[i][2*j+1]=v[j].first;
					}
					else{
						ary[i][2*j] = 0;
						ary[i][2*j+1]=0;
					}
				}
				if(max_col < 2*(v.size()))
					max_col = 2*(v.size());
			}
			col =max_col;
		}
		//C
		else{
			for(int j=0 ;j<col; j++){
				vector <pair<int, int> > v;
				int cnt[101]={0,};
				for(i= 0 ; i< row; i++) cnt[ary[i][j]]++;
				for(t = 1 ; t <=100; t++) if(cnt[t]) v.push_back(make_pair(cnt[t], t));

				sort(v.begin(), v.end());
				int v_size = v.size();
				for(i = 0 ; i < 50; i++){
					if(i<v.size()){
						ary[2*i][j]=v[i].second;
						ary[2*i+1][j]=v[i].first;
					}
					else{
						ary[2*i][j] = 0;
						ary[2*i+1][j]=0;
					}
				}
				if(max_row < 2*(v.size()))
					max_row = 2*(v.size());
			}
			row = max_row;
		}
	}
	if(cnt100 > 100 || ary[r][c] != k)
		cout << -1<<endl;
	else
		cout << cnt100 <<endl;
	return 0;
}