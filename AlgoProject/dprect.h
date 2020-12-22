#ifndef DPRECT_H
#define DPRECT_H
#include <algorithm>
#include <vector>

/*Dynamic programming method to find the max area of a matrix sub rectangle whose elements are all >=k. To do this, I create two additional 
vectors, one which holds the left index of the largest rectangle that can be formed using the current element of the current row, and one
which holds the right index. The original matrix holds the current height by first checking if the current
element is greater than or equal to k. If it is, it adds 1 to the same column element in the previous row and stores it at the current element.
If it is not, the current element is set to 0. The maximum area is then calculated from all these rectangles, before moving on to the next row.
Two for loops indexed to m are separately nested in a for loop indexed to m, giving a total time complexity of O(m*2*n), or
O(m*n). Two additional vectors of size n are created, giving a space complexity of n^2.*/
template<typename TwoD>
void dp_rect(TwoD& mat, int m, int n, int k, int* startr, int* startc, int* endr, int* endc) {
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
				*endr = i+1;
				*endc = right[j];
				*startr = i - mat[i][j]+2;
				*startc = left[j]+1;
			}

		}
	}
}
#endif // !DPRECT_H

