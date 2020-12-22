#ifndef DPRECTLIN_H
#define DPRECTLIN_H
#include <vector>


/*Improves on the previous dp rectangle method by acknowleding two vectors to hold the left and right indices of the rectangle are not needed.
Instead, a single stack is used, lowering the additional space to just n. Total time complexity remains the same.*/
void find_area_rect_lin(int** mat, int m, int n, int k, int* startr, int* startc, int* endr, int* endc) {
	int sr = 0, sc = 0, er = 0, ec = 0;
	//Initialize the first row to be either 1 or 0 depending on whether or not the element is >=k.
	for (int l = 0; l < n; l++) {
		mat[0][l] = (mat[0][l] < k) ? 0 : 1;
	}
	
	std::vector<int> stack;
	//Find maxarea in the first row by using the stack method
	int val = 0, area= 0, maxAreaR = 0, maxArea = 0;
	int i = 0;
	while (i < n) {
		//Check if current element is greater than the element on the back of the stack. If it is, push it to the stack.
		if (stack.empty() || mat[0][stack.back()] <= mat[0][i])
			stack.push_back(i++);
		else {
			/*If it isn't, check to see if the rectangle formed by using i as the right index, the back of the stack as the height, and the item to 
			the left of the back of the stack as the left index, has an area greater than the current max area.*/
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
	//Now check every rectangle formed by the elements left in the stack with i now as the max possible column index.
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
	/*The area process from before is repeated for every row. First it initializes the current row based on whether or now the current
	element fits the criteria, and based on the last row's height value for each element. Then, it repeats the same area calculation as
	the last loop. */
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

