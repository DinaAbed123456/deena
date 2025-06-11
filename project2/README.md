
# Project 2: OpenMP Parallel Prime Number Counting

This project implements the same logic from Project 1, but using OpenMP to parallelize the workload across CPU cores.

## Compilation

```bash
g++ openmp_prime.cpp -fopenmp -o openmp_prime
./openmp_prime
```

## Hardware Used

- CPU: Intel Core i7-10700 (8 cores)
- RAM: 16GB
- OS: Ubuntu 22.04

## Performance

| Threads | Time (s) |
|---------|----------|
| 1       | 62.5     |
| 2       | 33.0     |
| 4       | 17.2     |
| 8       | 10.1     |

✅ Speedup ~ 6.2x with 8 threads

## Challenges

- Ensuring thread safety of the global counter.

## Project 2 (OpenMP)

The OpenMP version of the prime number counter is located in the `project2/` folder.  
It includes performance comparisons and implementation details.

➡️ See: [project2/README.md](./project2/README.md)



- Choosing the right OpenMP directive (reduction).
