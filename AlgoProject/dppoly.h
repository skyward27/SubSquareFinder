#ifndef DP_POLY_H
#define DP_POLY_H
#include <algorithm>
#include <math.h>
#include <vector>


/*Recursive formula to find the maximum area square that can be formaed at matrix coordinates m n. To save on processing time, a DP matrix is stored and checked to see if a 
certain cell has already been calculated. If it has, that answer is used rather then going through with the recursion.*/
int find_area_dp_poly(int **mat, int m, int n, int k, int **ans) {
	if (m == 0 || n == 0) {
		if (mat[m][n] >= k) {
			return 1;
			
		}
		
		else return  0;
	}
	else {
		int left = 0, right = 0, corner = 0;
		if (ans[m][n - 1] != -1) {
			left = ans[m][n - 1];
		}
		else {
			ans[m][n - 1] = find_area_dp_poly(mat, m, n - 1, k, ans);
			left = ans[m][n - 1];
		}
		if (ans[m - 1][n] != -1) {
			right = ans[m - 1][n];
		}
		else {
			ans[m - 1][n] = find_area_dp_poly(mat, m - 1, n, k, ans);
			right = ans[m - 1][n];
		}
		if (ans[m - 1][n - 1] != -1) {
			corner = ans[m - 1][n - 1];
		}
		else {
			ans[m - 1][n - 1] = find_area_dp_poly(mat, m - 1, n - 1, k, ans);
			corner = ans[m - 1][n - 1];
		}
		if (mat[m][n] >= k) {
			return std::min(std::min(left, right), corner) + 1;
			
		}
		else {
			return 0;
		}
	}
}
/*The caller function for the DP memoization recursion. Creates a DP matrix of size m*n and starts recurring on the last element. As such, space complexity is m*n. 
Each element in the original matrix is visited once and each element in the DP matrix is visted at most 3 times, so total time complexity is 1*(m*n)n+3*(m*n) = 4*m*n = O(m*n)*/
void get_area(int** mat, int m, int n, int k, int* startr, int* startc, int* endr, int* endc) {
	int maxArea= 0;
	int** buffer = new int*[m];
	for (int i = 0; i < m; i++) {
		buffer[i] = new int[n];
		for (int j = 0; j < n; j++) buffer[i][j] = -1;
	}
	buffer[m - 1][n - 1] = find_area_dp_poly(mat, m - 1, n - 1, k, buffer);
	//Traverse the array again to find the max area.
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (buffer[i][j] > maxArea) {
				maxArea = buffer[i][j];
				*endr = i+1;
				*endc = j+1;
			}
		}
	}
	*startr = *endr - maxArea+1;
	*startc = *endc - maxArea+1;
}
#endif // !DP_POLY_H

