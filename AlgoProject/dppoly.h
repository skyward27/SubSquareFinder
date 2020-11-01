#ifndef DP_POLY_H
#define DP_POLY_H
#include <algorithm>
void find_area_dp_poly(int **mat, int m, int n, int k,int *startr,int *startc, int *endr, int *endc) {
	int max_area = 0;
	int endi, endj;
	int** buffer = new int* [m];
	for (int i = 0; i < m, ++i) {
		buffer[i] = new int[n];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (mat[i - 1][j - 1] >= k) {
				buffer[i][j] = std::min(std::min(buffer[i][j - 1], buffer[i - 1][j]), buffer[i - 1][j - 1]) + 1;
				if (buffer[i][j] > max_area) {
					endi = i;
					endj = j;
					max_area = buffer[i][j];
				}
			}
		}
	}
	*startr = endi - max_area - 1;
	*startc = endj - max_area - 1;
	*endr = endi;
	*endc = endj;
}
#endif // !DP_POLY_H

