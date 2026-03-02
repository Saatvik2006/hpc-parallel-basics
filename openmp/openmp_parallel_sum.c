#include <stdio.h>
#include <omp.h>

int main() {
int N = 1000000;
double sum = 0.0;

#pragma omp parallel for reduction(+:sum)
for(int i=0; i< N; i++) {
sum += i*0.5;
}

printf("Sum = %f\n", sum);
return 0;
}
