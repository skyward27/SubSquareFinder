#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	int rows, cols, height;
	string input;
	stringstream parse;
	cout << "Please input the required information:" << endl;
	getline(cin, input);
	parse << input;
	parse >> rows;
	parse >> cols;
	parse >> height;
	int** mat = new int* [rows];
	for (int i = 1; i < rows; i++) {
		mat[i] = new int[cols];
	}
	int i = 1;
	parse.str(string());
	while (i <= rows) {
		getline(cin, input);
		parse << input;
		for (int j = 0; j < cols; j++) {
			parse >> mat[i][j];
		}
		parse.str(string());
		i++;
	}
	//Insert code here for calling various algorithms.
	return 0;
}