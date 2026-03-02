# HPC Parallel Programming Basics

This repository contains simple OpenMP and MPI programs that I implemented while exploring basic parallel programming concepts using the Argonne National Lab HPC training resources.

## System Setup

- OS: Ubuntu 24.04 (VM)
- Compiler: GCC with OpenMP support
- MPI Implementation: MPICH

---

## OpenMP Examples

### 1. Hello World (Threads)

Demonstrates:
- Parallel region creation
- Thread ID retrieval
- Number of threads

Compile: gcc -fopenmp openmp_hello.c -o openmp_hello
Run: ./openmp_hello

---

### 2. Parallel Sum (Reduction)

Demonstrates:
- Loop-level parallelism
- Reduction clause
- Avoiding race conditions

Compile: gcc -fopenmp openmp_parallel_sum.c -o openmp_parallel_sum
Run: ./openmp_parallel_sum

---

## MPI Examples

### 1. Hello World (Processes)

Demonstrates:
- MPI initialization
- Rank and size retrieval
- Distributed execution

Compile: mpicc mpi_hello.c -o mpi_hello
Run: mpirun -np 4 ./mpi_hello

---

### 2. Distributed Parallel Sum (MPI_Reduce)

Demonstrates:
- Work partitioning across processes
- Collective communication (MPI_Reduce)
- Global aggregation

Compile: mpicc mpi_parallel_sum.c -o mpi_parallel_sum
Run: mpirun -np 4 ./mpi_parallel_sum

---

## Concepts Explored

- Shared-memory vs distributed-memory models
- Thread-level parallelism (OpenMP)
- Process-level parallelism (MPI)
- Reduction and race condition handling
- Collective communication
- Basic workload partitioning