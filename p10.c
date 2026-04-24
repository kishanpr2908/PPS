#include <limits.h>
#include <stdio.h>

/*
 * Reads one integer from stdin.
 * Returns 1 on success, 0 on failure.
 */
static int read_int(const char *prompt, int *out_value) {
	if (prompt != NULL) {
		printf("%s", prompt);
	}

	if (scanf("%d", out_value) != 1) {
		return 0;
	}

	return 1;
}

int main(void) {
	int n;
	long long sum = 0;

	if (!read_int("Enter array size: ", &n)) {
		printf("Error: invalid input for array size.\n");
		return 1;
	}

	if (n < 0) {
		printf("Error: array size cannot be negative.\n");
		return 1;
	}

	if (n == 0) {
		printf("Array is empty. Sum = 0\n");
		return 0;
	}

	for (int i = 0; i < n; ++i) {
		int value;
		char prompt[64];

		snprintf(prompt, sizeof(prompt), "Enter element %d: ", i + 1);
		if (!read_int(prompt, &value)) {
			printf("Error: invalid input at element %d.\n", i + 1);
			return 1;
		}

		if ((value > 0 && sum > LLONG_MAX - value) ||
			(value < 0 && sum < LLONG_MIN - value)) {
			printf("Error: integer overflow while summing values.\n");
			return 1;
		}

		sum += value;
	}

	printf("Sum = %lld\n", sum);
	return 0;
}
