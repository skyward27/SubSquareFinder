#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "dprect.h"
#include "bfrect.h"
#include "dplin.h"
#include "dppoly.h"
#include "dprectlin.h"

using namespace std;

int main(int argc, char* argv[]) {
	
	int rows, cols, height;
	string input;
	stringstream parse;
	ifstream myfile("blocks.txt");
	getline(myfile, input);
	parse << input;
	parse >> rows;
	parse >> cols;
	parse >> height;
	int** mat = new int* [rows];
	for (int i = 0; i < rows; i++) {
		mat[i] = new int[cols] {};
	}
	std::vector<std::vector<int>> mat2(rows,std::vector<int> (cols,0));
	int i = 0;
	parse.str(string());
	while (i < rows) {
		getline(myfile, input);
		stringstream parse2(input);
		for (int j = 0; j < cols; j++) {
			int k;
			parse2 >> mat[i][j];
		}
		parse.str(string());
		i++;
	}
	//Insert code here for calling various algorithms.
	int  startr = 0, startc = 0, endr = 0, endc = 0;
	char testType = argv[2][0];
	switch (testType) {
	case '1':
		get_area(mat, rows, cols, height, &startr, &startc, &endr, &endc);
		break;
	case '2':
		find_area_dp_lin(mat, rows, cols, height, &startr, &startc, &endr, &endc);
		break;
	case '3':
		bf_rect(mat, rows, cols, height, &startr, &startc, &endr, &endc);
		break;
	case '4':
		dp_rect(mat, rows, cols, height, &startr, &startc, &endr, &endc);
		break;
	case '5':
		find_area_rect_lin(mat, rows, cols, height, &startr, &startc, &endr, &endc);
		break;
	default:
		cout << "No test chosen. Exiting the program.\n";
		return 0;
	}
	cout << startr << " " << startc << " " << endr << " " << endc << endl;
	return 0;
}