
#include"Matrices.h"

#ifdef _OPENMP
    #include <omp.h>
#endif

const Matrices multiply(Matrices& first, Matrices& second)
{
	Matrices result; //local instance of 'Matrices' - to store the final result vector
	result.nRows = first.nRows;
	result.nCols = second.nCols;
	result.vec = vector<vector<double>>(result.nRows, vector<double>(result.nCols));
	
	///*
	//transpose approach
	
	vector<vector<double>> transposeB = vector<vector<double>>(second.nCols, vector<double>(second.nRows));
    	
    for(int i = 0; i < second.nRows; i++)
    {
        for(int j = 0; j < second.nCols; j++)
	    {
	        transposeB[j][i] = second.vec[i][j];
	    }
    }
    //*/
    

    int r1,c1,c2;
    
    #pragma omp parallel for
    for (r1 = 0; r1 < first.nRows; ++r1) //for each row in first matrix
    {
    	vector<double> temp(result.nCols);
    
    	for (c2 = 0; c2 < second.nCols; ++c2) //for each col in second matrix
    	{
    		double sum = 0;
    		for (c1 = 0; c1 < first.nCols; ++c1) // for each col in first OR row in second -> this determines how many products are getting added up
    		{
    			//sum += (first.vec[r1][c1] * second.vec[c1][c2]);
    			sum += (first.vec[r1][c1] * transposeB[c2][c1]); //tranpose approach
    		}
    		temp[c2] = sum; //for each cell in a given row, insert the calculated sum
    	}
    	result.vec[r1] = temp; //insert all result row vectors to make a vector of vectors
    }
    
	return result; //returns the Matrice result
}

fstream& operator>>(fstream& os, Matrices& matrixIn)
{
	string str;
	string rows;
	string cols;

	std::getline(os, rows, ' '); //read nRows
	std::getline(os, cols, '\n'); //read nCols
	vector<double> temp;
	string elem;
	
	for (int r = 0; r < stoi(rows); r++)
	{
		
		std::getline(os, str, '\n'); //read one row 'r' as a string 'str'
		
		for (int c = 0; c < str.length(); c++)
		{
			elem = "";
			while (c< str.length() && str[c] != ' ')
			{
				elem += str[c]; //appends characters to string elem until a whitespace is encountered in str
				c++;
			}
			temp.push_back(stod(elem)); //inserts elem into 1D vector temp
		}
		matrixIn.vec.push_back(temp); //inserts 1D vector temp to our 2D vector matrixIn 
		temp.clear();
	}
	
	matrixIn.nRows = stoi(rows);
	matrixIn.nCols = stoi(cols);
	
	return os;
}

fstream& operator<<(fstream& os, const Matrices& matrixOut)
{
	os << matrixOut.nRows;
	os << " ";
	os << matrixOut.nCols;
	os << endl;
	os << std::scientific; //for calculation precision

	for (int r = 0; r < matrixOut.nRows; r++)
	{
		for (int c = 0; c < matrixOut.nCols; c++)
		{
			os << matrixOut.vec[r][c];
			os << " ";
		}
		os << endl;
	}
	return os;
}