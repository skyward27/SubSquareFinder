#ifndef BFRECT_H
#define BFRECT_H
#include <algorithm>
void bf_rect(int** mat, int m, int n, int k, int* startr, int* startc, int* endr, int* endc) {
	int max_area = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] < k) continue;
			for (int o = i; o < m; o++) {
				for (int l = j; l < n; l++) {
					if (mat[o][l] < k) continue;
					bool greater = 1;
					for (int x = i; x <= o; x++) {
						for (int y = j; y <= l; y++) {
							if (mat[x][y] < k) {
								greater = 0;
								break;
							}
						}
						if (!greater) break;
					}
					if (greater) {
						if (max_area < ((o - i + 1) * (l - j + 1))) {
							max_area = ((o - i + 1) * (l - j + 1));
							*startr = i+1;
							*startc = j+1;
							*endr = o+1;
							*endc = l+1;
						}

					}
				}
			}
		}
	}

}
#endif // !BFRECT_H

