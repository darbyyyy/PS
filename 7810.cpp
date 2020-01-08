#include <stdio.h>

#define NUM_LIMIT 1000000
int cnt[NUM_LIMIT+1];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	scanf("%d", &T);

	int N, input, H, counter;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d", &N);
		for(int i=1; i<=NUM_LIMIT; ++i)
			cnt[i]=0;

		for(int i=0; i<N; ++i){
			scanf("%d", &input);
			cnt[input]++;
		}
		H=0;
        counter=0;	
		for(int i=NUM_LIMIT; i>0;--i){
			counter = counter+cnt[i];
			if(i <= counter){ 
				H=i;
				break;

			}
			
		}

		printf("#%d %d\n", test_case, H);
	}
	return 0;
}