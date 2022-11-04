
#pragma once
#include<fstream>
#include<string>
#include<vector>
using namespace std;

class Matrices
{
public:
	int nRows;
	int nCols;
	vector<vector<double>> vec;
};

fstream& operator>>(fstream& os, Matrices& matrixIn);
fstream& operator<<(fstream& os, const Matrices& matrixOut);
const Matrices multiply(Matrices& first, Matrices& second);
