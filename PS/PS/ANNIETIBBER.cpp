//https://algospot.com/judge/problem/read/ANNIETIBBER#

#include <stdio.h>
#include <stdlib.h>

#define _MAX_STAR_CNT 100000

int _P[_MAX_STAR_CNT], _Q[_MAX_STAR_CNT];
int _T, _N;
double _p, _q;	// p, q - x coordinates of ANNIE and TIBBER
double star[_MAX_STAR_CNT][2];	// x, y coordinate of the stars
double _P_grad[_MAX_STAR_CNT];
double _Q_grad[_MAX_STAR_CNT];

void quicksort(int *sortary, double*gradary, int start, int end);

int main() {
	

	scanf("%d", &_T);

	while (_T--) {
		scanf("%d%lf%lf", &_N, &_p, &_q);
		for (int i = 0; i < _N; i++) 
			scanf("%lf%lf", &star[i][0], &star[i][1]);
		for (int i = 0; i < _N; i++) {
			_P_grad[i] = star[i][1] / (star[i][0] - _p);
			_Q_grad[i] = star[i][1] / (star[i][0] - _q);
		}

		for (int i = 0; i < _N; i++) {_P[i] = i; _Q[i] = i;}
		quicksort(_P, _P_grad, 0, _N - 1);
		quicksort(_Q, _Q_grad, 0, _N - 1);

		for (int i = 0; i < _N; i++) printf("%3d%3d\n", _P[i], _Q[i]);
		printf("\n\n");
		for (int i = 0; i < _N; i++) printf("%3lf %3lf\n", _P_grad[_P[i]], _Q_grad[_Q[i]]);
		printf("\n\n");
		system("pause");
	}
	return 0;
}

void quicksort(int *sortary, double*gradary, int start, int end) {
	int i, j, temp;
	if (start == end)			//exit condition
		return;
	
	else if (start == end - 1) {
		if (gradary[end] > 0) {
			if ((gradary[start] < 0)|| (gradary[start]> gradary[end]))
				return;
			else {
				temp = sortary[start];
				sortary[start] = sortary[end];
				sortary[end] = temp;
			}
		}
		else {
			if ((gradary[start] > 0) || (gradary[start] < gradary[end])) {
				temp = sortary[start];
				sortary[start] = sortary[end];
				sortary[end] = temp;
			}
			else
				return;
		}
	}
	else {

		i = start; j = end - 1;

		while (i <= j) {
			if (gradary[end] > 0) {		//Grads of star[end] is positive value
				if ((gradary[i] < 0) || (gradary[i] > gradary[end])) {
					i++;
				}
				else {
					temp = sortary[j];
					sortary[j] = sortary[i];
					sortary[i] = temp;
					j--;
				}
			}
			else {		//Grads of star[end] is negative value(or zero?)
				if ((gradary[i] > 0) || (gradary[i] < gradary[end])) {
					temp = sortary[j];
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

		quicksort(sortary, gradary, start, i);
		quicksort(sortary, gradary, i + 1, end);
	}
	return;

}