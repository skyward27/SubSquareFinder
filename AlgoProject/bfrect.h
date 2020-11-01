#ifndef BFRECT_H
#define BFRECT_H
#include <algorithm>
void bf_rect(int** mat, int m, int n, int k, int* startr, int* startc, int* endr, int* endc) {
	int max_area = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] < k) continue;
			for (int o = i; o < m; k++) {
				for (int l = j; j < n; j++) {
					if (mat[o][l] < k) continue;
					bool greater = 1;
					for (int x = i; x <= o, x++) {
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
							*startr = i;
							*startc = j;
							*endr = o;
							*endc = l;
						}

					}
				}
			}
		}
	}

}
#endif // !BFRECT_H

