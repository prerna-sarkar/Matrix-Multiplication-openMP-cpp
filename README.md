# Matrix-Multiplication-openMP-cpp

Program to read in two matrices (A and B) from a text file (using a command line argument with the file path and name) and output the multiplication of A and B to a text file

# Usage

The input file format is shown below:

4 2
1.35477 8.35009
9.68868 2.21034
3.08167 5.47221
1.88382 9.92881
2 3
9.96461 9.67695 7.25839
9.8111 1.09862 7.98106

Program compiles correctly in both OpenMP mode (using openMP flag) and non-OpenMP mode (without the OpenMP flag) and the output text file MatrixOut.txt uses the same format as the input file.

# Dependencies

The code uses OpenMP, which is a library that allows for parallel programming. The library is included using the following header file:
#include <omp.h>

# Implementation Details 

1. OpenMP (Open Multi-Processing) is used in this code to parallelize the matrix multiplication loop using the "#pragma omp parallel for" directive. This directive tells the compiler to parallelize the following loop by dividing the iterations of the loop among multiple threads.

2. The #ifdef _OPENMP block is used to ensure that OpenMP is supported by the compiler before attempting to use it. If OpenMP is not supported, then the loop will be executed sequentially.

3. The loop that is parallelized by OpenMP is the outermost loop that iterates over the rows of the first matrix. Inside this loop, each thread calculates a subset of the entries in the output matrix by iterating over the columns of the second matrix.

4. The loop over the columns of the first matrix (or the rows of the transposed second matrix) is not parallelized, since each iteration of this loop must be executed sequentially by a single thread.

5. By parallelizing the outer loop, the matrix multiplication can be performed faster on multi-core processors since the work is divided among multiple threads that can execute in parallel.
