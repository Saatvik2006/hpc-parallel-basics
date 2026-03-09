#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {

    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    long long total_points = 1000000;
    long long local_points = total_points / size;

    int local_inside = 0;

    srand(time(NULL) + rank);

    for(long long i=0;i<local_points;i++){

        double x = (double)rand()/RAND_MAX;
        double y = (double)rand()/RAND_MAX;

        if(x*x + y*y <= 1.0)
            local_inside++;
    }

    int global_inside;

    MPI_Reduce(&local_inside, &global_inside, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if(rank==0){

        double pi = 4.0 * global_inside / total_points;

        printf("Estimated Pi = %f\n", pi);
    }

    MPI_Finalize();

    return 0;
}
