#ifndef BFRECT_H
#define BFRECT_H
#include <algorithm>

/*Brute force algorithm for computing the largest sub-rectangle in a matrix whose elements are all >=k. Loops through each element of the original matrix and checks for the
largest area that can be made using that cell as the upper left corner of the matrix, then creates all possible rectangles that can be made with that corner. Has four nested for
loops, three of which are indexed on the rows while the other three are indexed on the columns. Time complexity is thus O(m^3*n^3). No additional space is needed.*/
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

