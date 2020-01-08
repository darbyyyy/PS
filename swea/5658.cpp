/*
https://swexpertacademy.com
problem no. 5658
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
int main(){
	int T, answer, N, K, length, to_decimal, ints[48];
	char input[48];
	vector <int> numbers;
	cin >> T;

	for(int test_case =1; test_case<=T; test_case++){
		cin >> N >> K;
		length = N / 4;
		for(int i = 0 ; i < N ; i++){		//Chars into ints
			cin>>input[i];
			if(input[i] >= 'A')
				ints[i] = input[i]-'A' +10;
			else
				ints[i] = input[i]-'0';
		}

		for(int itr = 0 ; itr < length; itr++){	//hexadecimal into decimal
			for(int i = 0 ; i < 4; i++){
				to_decimal = ints[length*i+itr];
				for(int j = 1 ; j < length; j++){
					to_decimal *= 16;
					to_decimal+= ints[(length*i + itr + j)%N];
				}
				numbers.push_back(to_decimal);
			}
		}
		sort(numbers.begin(), numbers.end());

		set<int> s( numbers.begin(), numbers.end() );
		numbers.assign( s.begin(), s.end() );


		cout << "#" << test_case << " "<<numbers[numbers.size() - K]<<endl;
		numbers.clear();
	}
	return 0;

}