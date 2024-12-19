#include <stdio.h>
#include <stdlib.h>
// use clang-format -i fib.c to format

#define MAX_MEMO_SIZE 100

long long compute_fibonacci_iterative(int fibonacci_index);
long long compute_fibonacci_recursive(int fibonacci_index);

// memoization arrays, 100 should be enough since 92/93 was the cap for signed
// long long
long long memoization_array_iterative[MAX_MEMO_SIZE];
long long memoization_array_recursive[MAX_MEMO_SIZE];

int main(int argument_count, char *argument_values[]) {
  char computation_method;
  long long computed_result;
  int start_index_argument;
  int file_input_value;
  int combined_index;

  // initialize memoization
  for (int memo_index = 0; memo_index < MAX_MEMO_SIZE; memo_index++) {
    memoization_array_iterative[memo_index] = -1;
    memoization_array_recursive[memo_index] = -1;
  }

  if (argument_count != 4) {
    printf("Input error");
    return 1;
  }

  start_index_argument = atoi(argument_values[1]);
  start_index_argument = start_index_argument - 1;

  computation_method =
      argument_values[2]
                     [0]; //[0] is for accessign character in string, 'i' / 'r'
  char *file_name = argument_values[3];

  FILE *input_file = fopen(file_name, "r");
  if (input_file == NULL) {
    printf("Unable to open file\n");
    return 1;
  }

  fscanf(input_file, "%d", &file_input_value);
  fclose(input_file);

  combined_index = start_index_argument + file_input_value;

  if (computation_method == 'i') {
    computed_result = compute_fibonacci_iterative(combined_index);
  } else {
    computed_result = compute_fibonacci_recursive(combined_index);
  }

  printf("%lld", computed_result);

  return 0;
}

// iternative
long long compute_fibonacci_iterative(int fibonacci_index) {
  if (fibonacci_index <= 0)
    return 0;
  if (fibonacci_index == 1)
    return 1;

  if (memoization_array_iterative[fibonacci_index] != -1 &&
      fibonacci_index < MAX_MEMO_SIZE) {
    return memoization_array_iterative[fibonacci_index];
  }

  long long previous_value = 0;
  long long current_value = 1;
  long long temporary_value;

  for (int iteration_index = 2; iteration_index <= fibonacci_index;
       iteration_index++) {
    temporary_value = previous_value + current_value;
    previous_value = current_value;
    current_value = temporary_value;
  }

  if (fibonacci_index < MAX_MEMO_SIZE) {
    memoization_array_iterative[fibonacci_index] = current_value;
  }
  return current_value;
}

// recursive
long long compute_fibonacci_recursive(int fibonacci_index) {
  if (fibonacci_index <= 0)
    return 0;
  if (fibonacci_index == 1)
    return 1;

  if (memoization_array_recursive[fibonacci_index] != -1 &&
      fibonacci_index < MAX_MEMO_SIZE) {
    return memoization_array_recursive[fibonacci_index];
  }

  memoization_array_recursive[fibonacci_index] =
      compute_fibonacci_recursive(fibonacci_index - 1) +
      compute_fibonacci_recursive(fibonacci_index - 2);

  return memoization_array_recursive[fibonacci_index];
}
