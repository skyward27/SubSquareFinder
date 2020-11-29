#ifndef DPRECT_H
#define DPRECT_H
#include <algorithm>
#include <vector>


template<typename TwoD>
void dp_rect(TwoD& mat, int m, int n, int k, int* startr, int* startc, int* endr, int* endc) {
	int** buffer = new int*[m];
	for (int i = 0; i < m; i++) {
		buffer[i] = new int[n];
		for (int j = 0; j < n; j++) buffer[i][j] = -1;
	}
	int max_area = 0;
	std::vector<int> left(n), right(n,n);
	for (int i = 0; i < m; i++) {
		int pos = 0;
		for (int j = 0; j < n; j++) {
			if (mat[i][j] < k) {
				mat[i][j] = 0;
				left[j] = 0;
				pos = j + 1;
			}
			else {
				left[j] = std::max(left[j], pos);
				if (i == 0) mat[i][j] = 1;
				else {
					mat[i][j] = mat[i-1][j]+1;
				}
			}
		}
		pos = n;
		for (int j = n-1; j >= 0; j--) {
			if (mat[i][j] == 0) {
				pos = j;
				right[j] = n;
			}
			else {
				right[j] = std::min(right[j], pos);
			}
			if (mat[i][j] * (right[j] - left[j]) > max_area) {
				max_area = mat[i][j] * (right[j] - left[j]);
				buffer[i][j] = max_area;
				*endr = i+1;
				*endc = right[j];
				*startr = i - mat[i][j]+2;
				*startc = left[j]+1;
			}

		}
	}
}
#endif // !DPRECT_H

