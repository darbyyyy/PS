#include <stdio.h>
#include <string.h>
#define MAX_NUM 10000001
char input[MAX_NUM];
int iinput[MAX_NUM];
int main() {
	int i, j, N, temp, pari, idx, len;
	scanf("%s", input);scanf("%d", &N);
	len = strlen(input);
	pari = 0;
	iinput[0] = 0;
	for (int idx = 1; idx < len; idx++) {
		if (input[idx] != input[idx - 1]) pari++;
		iinput[idx] = pari;
	}
	while (N--) {
		scanf("%d%d", &i, &j);
		(iinput[i] == iinput[j]) ? printf("Yes\n") : printf("No\n");
	}
	return 0;
}