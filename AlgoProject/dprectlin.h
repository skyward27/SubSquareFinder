#ifndef DPRECTLIN_H
#define DPRECTLIN_H
#include <vector>

void find_area_rect_lin(int** mat, int m, int n, int k, int* startr, int* startc, int* endr, int* endc) {
	int sr = 0, sc = 0, er = 0, ec = 0;
	for (int l = 0; l < n; l++) {
		mat[0][l] = (mat[0][l] < k) ? 0 : 1;
	}
	
	std::vector<int> stack;
	int val = 0, area= 0, maxAreaR = 0, maxArea = 0;
	int i = 0;
	while (i < n) {
		if (stack.empty() || mat[0][stack.back()] <= mat[0][i])
			stack.push_back(i++);
		else {
			val = mat[0][stack.back()];
			stack.pop_back();
			area = mat[0][val] * (stack.empty() ? i : i - stack.back() - 1);
			if (area > maxAreaR) {
				maxAreaR = area;
				*endr = *startr = 0;
				*endc = i;
				*startc = (stack.empty() ? 1 : i - stack.back());
			}
		}
	}
	while (!stack.empty()) {
		val = stack.back();
		stack.pop_back();
		area = mat[0][val] * (stack.empty() ? i : i - stack.back() - 1);
		if (area > maxAreaR) {
			maxAreaR = area;
			*endr = *startr = 0;
			*endc = i;
			*startc = (stack.empty() ? 1 : i - stack.back());
		}
	}
	maxArea = maxAreaR;
	for (int j = 1; j < m; j++) {
		std::vector<int> stack;
		i = maxAreaR = 0;
		for (int l = 0; l< n; l++) {
			if (mat[j][l] >= k) {
				mat[j][l] = mat[j - 1][l]+1;
			}
			else {
				mat[j][l] = 0;
			}
		}
		while (i < n) {
			if (stack.empty() || mat[j][stack.back()] <= mat[j][i])
				stack.push_back(i++);
			else {
				val = stack.back();
				stack.pop_back();
				area = mat[j][val] * (stack.empty() ? i : i - stack.back() - 1);
				if (area > maxAreaR) {
					maxAreaR = area;
					if (stack.empty()) {
						er = j + 1;
						sr = er - (maxAreaR / i)+1;
						ec = i;
						sc = 1;
					}
					else {
						er = j + 1;
						sr = er - (maxAreaR / (i - stack.back() - 1))+1;
						ec = i;
						sc = stack.back()+2;
					}
					
				}
			}
		}
		while (!stack.empty()) {
			val = stack.back();
			stack.pop_back();
			area = mat[j][val] * (stack.empty() ? i : i - stack.back() - 1);
			if (area > maxAreaR) {
				maxAreaR = area;
				if (stack.empty()) {
					er = j + 1;
					sr = er - (maxAreaR / i)+1;
					ec = i;
					sc = 1;
				}
				else {
					er = j + 1;
					sr = er - (maxAreaR / (i - stack.back() - 1))+1;
					ec = i;
					sc = stack.back()+2;
				}
			}
		}
		if (maxAreaR > maxArea) {
			maxArea = maxAreaR;
			*startc = sc;
			*startr = sr;
			*endc = ec;
			*endr = er;
		}
	}
}
#endif // !DPRECTLIN_H

