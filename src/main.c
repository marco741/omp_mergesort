/*
 * Course: High Performance Computing 2020/2021
 *
 * Lecturer: Francesco Moscato    fmoscato@unisa.it
 *
 * Group:
 * De Stefano Alessandro   0622701470  a.destefano56@studenti.unisa.it
 * Della Rocca Marco   0622701573  m.dellarocca22@studenti.unisa.it
 *
 * OMP implementation of mergesort algorithm
 * Copyright (C) 2021 Alessandro De Stefano (EarendilTiwele) Marco Della Rocca
 * (marco741)
 *
 * This file is part of OMP Mergesort implementation.
 *
 * OMP Mergesort implementation is free software: you can redistribute it
 * and/or modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3 of the License,
 * or (at your option) any later version.
 *
 * OMP Mergesort implementation is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OMP Mergesort implementation.  If not, see <http:
 * //www.gnu.org/licenses/>.
 */

/**
 * @file main.c
 * @brief measures the execution time of a parallel implementation of the merge_sort algorithm
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "main.h"

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "merge_sort.h"

/**
 * @brief calls and measure the execution time of merge_sort function
 * 
 * @param argc number of arguments
 * @param argv arguments. Accept task_size as first argument. Defaults to 100.
 * @return int status code
 */
int main(int argc, char* argv[]) {
  DEBUG_PRINT("argc: %d\n", argc);
  int task_size = (argc > 1) ? atoi(argv[1]) : TASK_SIZE;
  char* filename = (argc > 2) ? argv[2] : FILENAME;
  DEBUG_PRINT("task_size: %d\n", task_size);
  size_t size;
  int *arr;
  read_file(&arr, &size, filename);

  debug_print_array(arr, size);

  omp_set_dynamic(0);

  double end, start = omp_get_wtime();
#pragma omp parallel
  {
#pragma omp single
    merge_sort_tasksize(arr, size, task_size);
  }
  end = omp_get_wtime();
  printf("%f", end - start);
  debug_print_array(arr, size);

  free(arr);
  return EXIT_SUCCESS;
}

/**
 * @brief Allocates and populates an array with data in file FILENAME
 * 
 * @param arr the array to be filled with the data from the file FILENAME
 * @param size the size of the array
 * @param filename the name of the input file
 */
void read_file(int** arr, size_t* size, char* filename) {
  FILE* fp;
  if ((fp = fopen(filename, "r")) == NULL) {
    puts("Input file not found");
    exit(EXIT_FAILURE);
  }

  fscanf(fp, "%ld\n", size);
  *arr = malloc(*size * sizeof(int));
  if (*arr == NULL) {
    puts("Memory could not be allocated");
    exit(EXIT_FAILURE);
  }

  DEBUG_PUTS("Reading from file...");
  for (size_t i = 0; i < *size; i++) {
    fscanf(fp, "%d", &(*arr)[i]);
  }
  fclose(fp);
}

/**
 * @brief Print for debug of the elements of an array
 * 
 * @param arr the array to be printed
 * @param size the size of the array
 */
void debug_print_array(int* arr, size_t size) {
  if (DEBUG) {
    for (size_t i = 0; i < size; i++) {
      printf("%d\n", arr[i]);
    }
  }
}
