//https://algospot.com/judge/problem/read/ANNIETIBBER#

#include <stdio.h>
#define _MAX_STAR_CNT 100000

int _P[_MAX_STAR_CNT], _Q[_MAX_STAR_CNT];	// sorted sequence based on gradients between P,Q and stars




double _P_grad[_MAX_STAR_CNT], _Q_grad[_MAX_STAR_CNT];	// Gradients between P,Q and stars
bool exist[_MAX_STAR_CNT];
void quicksort(int *sortary, double*gradary, int start, int end);

int main() {
	int _T, _N;
	unsigned long long int sum, cnt;
	double _p, _q;	// x coordinates of ANNIE and TIBBER(P and Q)
	double star[_MAX_STAR_CNT][2];	// x, y coordinate of the stars
	scanf("%d", &_T);

	while (_T--) {
		sum = 0; cnt = 0;
		scanf("%d%lf%lf", &_N, &_p, &_q);
		for (int i = 0; i < _N; i++) {
			scanf("%lf%lf", &star[i][0], &star[i][1]);		//read inputs
			if (star[i][1] == _p)
				_P_grad[i] = 0;
			else
				_P_grad[i] = star[i][1] / (star[i][0] - _p);	//calculate gradients
			if (star[i][1] == _q)
				_Q_grad[i] == 0;
			else
				_Q_grad[i] = star[i][1] / (star[i][0] - _q);
			exist[i] = false;								//exist array init;
		}
		for (int i = 0; i < _N; i++) {_P[i] = i; _Q[i] = i;}
		quicksort(_P, _P_grad, 0, _N - 1);
		quicksort(_Q, _Q_grad, 0, _N - 1);
		
		for (int i = 0; i < _N; i++) {
			if (_P[i] == _Q[i])
				sum += cnt;
			else {
				if (exist[_P[i]]) {
					sum += cnt - 1;
					cnt--;
				}
				exist[_P[i]] = !exist[_P[i]];
				if (exist[_Q[i]]) {
					sum += cnt - 1;
					cnt--;
				}
				exist[_Q[i]] = !exist[_Q[i]];
				cnt = cnt + exist[_Q[i]] + exist[_P[i]];
			}
		}
		printf("%lld\n", sum);
	}
	return 0;
}
void quicksort(int *sortary, double*gradary, int start, int end) {
	int i, j, temp; double pivot;
	if (start <end) {
		pivot = gradary[sortary[end]];
		i = start; j = end - 1;
		if (pivot > 0) {		//Grads of star[end] is positive value
			while (i <= j) {
				if ((gradary[sortary[i]] < 0) || (gradary[sortary[i]] > pivot) || (gradary[sortary[i] == 0])) //C
					i++;
				else {
					temp = sortary[j];			//swap the value between i-th and j-th
					sortary[j] = sortary[i];
					sortary[i] = temp;
					j--;
				}
			}
		}
		else {		//Grads of star[end] is negative value(or zero?)
			while (i <= j) {
				if ((gradary[sortary[i]] > 0) || (gradary[sortary[i]] < pivot) || (gradary[sortary[i] == 0]) ) {	//C
					temp = sortary[j];				//swap the value between i-th and j-th
					sortary[j] = sortary[i];
					sortary[i] = temp;
					j--;
				}
				else
					i++;
			}
		}
		temp = sortary[end];
		sortary[end] = sortary[i];
		sortary[i] = temp;
		quicksort(sortary, gradary, start, i - 1);
		quicksort(sortary, gradary, i + 1, end);
	}
	return;
}