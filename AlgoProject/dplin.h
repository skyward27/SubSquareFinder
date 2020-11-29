#ifndef DP_LIN_H
#define DP_LIN_H
#include <algorithm>
#include <math.h>
void find_area_dp_lin(int** mat, int m, int n, int k, int* startr, int* startc, int* endr, int* endc) {
	int* buffer = new int[n] {};
	int max_area=0, last=0, endj=0, endi=0;
	for (int i = 0; i <= m-1; i++) {
		for (int j = 0; j <= n-1; j++) {
			int temp = buffer[j];
			if (mat[i][j] >=k) {
				buffer[j] = std::min(std::min(buffer[j - 1], last), buffer[j]) + 1;
				if (buffer[j] > max_area) {
					max_area = buffer[j];
					endj = j;
					endi = i;
				}
			}
			else {
				buffer[j] = 0;
			}
			last = temp;
		}
	}
	*startr = endi - max_area + 2;
	*startc = endj - max_area + 2;
	*endr = endi+1;
	*endc = endj+1;
}
#endif // !DP_LIN_H

