#ifndef DP_LIN_H
#define DP_LIN_H
#include <algorithm>
void find_area_dp_lin(int** mat, int m, int n, int k, int* startr, int* startc, int* endr, int* endc) {
	int* buffer = new int[n+1];
	int max_area, last, int endj, endi;
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			int temp = buffer[j];
			if (mat[i - 1][j - 1] >=k) {
				buffer[j] = std::min(std::min(buffer[j - 1], last), buffer[j]) + 1;
				if (buffer[j] > max_area) {
					max_area = buffer[j];
					endj = j;
					endi = i;
				}
			}
		}
	}
	*startr = endi - max_area - 1;
	*startc = endj - max_area - 1;
	*endr = endi;
	*endc = endj;
}
#endif // !DP_LIN_H

