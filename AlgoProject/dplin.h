#ifndef DP_LIN_H
#define DP_LIN_H
#include <algorithm>
#include <math.h>

/*Algorithm to find the max area of a matrix subsquare whose elemts are all >= k. This is done by checking the elements to the left, up, and upper left of the element
in question for each element in the original matrix. If the number at the element is greater than or equal to k, it adds 1 to the minimum of the three adjacent cells
and checks to see if that area is greater than the current max area. The space complexity is kept down to 'n' because we really only need to keep the previous row 
in memory when calculating the current row. We do not need information for the whole matrix constantly. Only two for loops are nested, thus the time complexity is
O(nm).*/
void find_area_dp_lin(int** mat, int m, int n, int k, int* startr, int* startc, int* endr, int* endc) {
	int* buffer = new int[n+1] {};
	int max_area=0, last=0, endj=0, endi=0;
	for (int i = 1; i <= m-1; i++) {
		for (int j = 1; j <= n-1; j++) {
			int temp = buffer[j];
			if (mat[i-1][j-1] >=k) {
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

