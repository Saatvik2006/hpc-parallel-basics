#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
MPI_Init(&argc,&argv);

int rank, size;
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Comm_size(MPI_COMM_WORLD, &size);

int N = 1000000;
double local_sum=0.0;

//Each process works on its chunk
for(int i = rank; i<N; i += size) {
local_sum += i*0.5;
}

double global_sum;

MPI_Reduce(&local_sum, &global_sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

if(rank==0) {
printf("Global Sum= %f\n", global_sum);
}

MPI_Finalize();
return 0;
}
