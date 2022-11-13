# Matrix-Multiplication-openMP-cpp

OpenMP: Open Multi-Processing - used for loop level parallelism

Program to read in two matrices (A and B) from a text file (using a command line argument with the file path and name) and output the multiplication of A and B to a text file

The input file format is shown below:

4 2
1.35477 8.35009
9.68868 2.21034
3.08167 5.47221
1.88382 9.92881
2 3
9.96461 9.67695 7.25839
9.8111 1.09862 7.98106

Program compiles correctly in both OpenMP mode (using openMP flag) and non-OpenMP mode (without the OpenMP flag) amd the output text file MatrixOut.txt uses the same format as the input file.
