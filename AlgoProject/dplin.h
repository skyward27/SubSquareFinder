#ifndef DP_LIN_H
#define DP_LIN_H
#include <algorithm>
#include <math.h>
void find_area_dp_lin(int** mat, int m, int n, int k, int* startr, int* startc, int* endr, int* endc) {
	int* buffer = new int[n+1] {};
	int max_area=0, last=0, endj=0, endi=0;
	for (int i = 1; i <= m-1; i++) {
		for (int j = 1; j <= n-1; j++) {
			int temp = buffer[j];
			if (mat[i-1][j-1] >=k) {
				std::cout << buffer[j - 1] << " " << buffer[j] << "\n";
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
	*startr = endi - max_area+1;
	*startc = endj - max_area+1;
	*endr = endi;
	*endc = endj;
}
#endif // !DP_LIN_H

