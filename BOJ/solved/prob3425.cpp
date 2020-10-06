#include <iostream>
#include <vector>
#include <string>
//#include <stdlib.h>
#define LIMIT 1000000000

using namespace std;

vector <string> commands;
vector <int> num_vector;
vector <long long int> v;


int main(){
	string s="";
	long long int error_flag=0, num, tmp1, tmp2;
	int N, cmd_idx, num_idx;


	while(1){
		commands.clear();
		num_vector.clear();
		s="";
		while(s != "END" && s!= "QUIT"){
			cin>> s;
			if(s == "NUM"){
				cin >> num;
				commands.push_back(s);
				num_vector.push_back(num);
			}
			else{
				commands.push_back(s);

			}
		}
		if(s=="QUIT"){
			break;
		}

		cin >> N;
		
		while(N>0){
			
			v.clear();
			num_idx=0;
			
			cin >> num;
			v.push_back(num);
			
			error_flag=0;
			for(int i =0 ; i < commands.size(); i++){
				s = commands[i];
				num = v.back();
				if(abs(num) >LIMIT){
					error_flag=1;
					break;
				}
				else if(s == "NUM"){
					v.push_back(num_vector[num_idx]);
					num_idx++;
				}
				else if(s == "POP"){
					if(v.size() < 1){
						error_flag=1;
						break;
					}
					v.pop_back();
				}
				else if(s == "INV"){
					if(v.size() < 1){
						error_flag=1;
						break;
					}
					num = v.back();
					v.pop_back();
					v.push_back(-1*num);
				}
				else if(s == "DUP"){
					if(v.size() < 1){
						error_flag=1;
						break;
					}
					v.push_back(v.back());
				}
				else if(s == "SWP"){
					tmp1 = v.back(); v.pop_back();
					tmp2 = v.back(); v.pop_back();
					v.push_back(tmp1);
					v.push_back(tmp2);
				}
				else if(s == "ADD"){
					if(v.size() < 2){
						error_flag=1;
						break;
					}
					tmp1 = v.back(); v.pop_back();
					tmp2 = v.back(); v.pop_back();
					v.push_back(tmp2+tmp1);
				}
				else if(s == "SUB"){
					if(v.size() < 2){
						error_flag=1;
						break;
					}
					tmp1 = v.back(); v.pop_back();
					tmp2 = v.back(); v.pop_back();
					v.push_back(tmp2-tmp1);
				}
				else if(s == "MUL"){
					if(v.size() < 2){
						error_flag=1;
						break;
					}
					tmp1 = v.back();
					v.pop_back();
					tmp2 = v.back();
					v.pop_back();
					v.push_back(tmp2*tmp1);
				}
				else if(s == "DIV"){
					if(v.size() < 2){
						error_flag=1;
						break;
					}
					tmp1 = v.back(); v.pop_back();
					tmp2 = v.back(); v.pop_back();
					if(tmp1 == 0){
						error_flag =1;
						break;
					}
					num = abs(tmp2) / abs(tmp1);
					if((tmp1 < 0 && tmp2 > 0) || (tmp1 > 0 && tmp2 < 0) )
						num *= -1;
					v.push_back(num);
					
				}
				else if(s == "MOD"){
					if(v.size() < 2){
						error_flag=1;
						break;
					}
					tmp1 = v.back(); v.pop_back();
					tmp2 = v.back(); v.pop_back();
					if(tmp1 == 0){
						error_flag =1;
						break;
					}
					num = abs(tmp2) % abs(tmp1);
					if( tmp2 <0)
						num *=-1;
					v.push_back(num);		
				}
				else if(s == "END"){
					 break;
				}
			}
			if(v.size()!=1 || error_flag==1){
				cout << "ERROR"<<endl;
			}
			else{
				cout << v[0] << endl;
			}
			N--;
		}
		cout << endl;
	}
	return 0;
}