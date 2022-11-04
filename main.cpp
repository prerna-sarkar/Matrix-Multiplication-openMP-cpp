
#include"Matrices.h"

std::fstream inFile;
std::fstream outFile;
Matrices A;
Matrices B;
Matrices result;

int main(int argc, char** argv)
{
	std::string fileName = "";
	if (argc == 2)
	{
		fileName = argv[1];
	}
	else
	{
		printf("Please enter the path for your input file");
		return 1;
	}

	inFile.open(argv[1], ios_base::in);

	if (inFile.fail()) //failed to open file
	{
		printf("Error in opening the file\n");
		return 0;
	}
	inFile >> A; //read Matrix A
	inFile >> B; //read Matrix B

	outFile.open("MatrixOut.txt", ios_base::out);
	outFile << multiply(A, B); //write Matrix result

	inFile.close();
	outFile.close();
}