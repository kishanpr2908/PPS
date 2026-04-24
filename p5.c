#include <errno.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int *data;
	size_t capacity;
	size_t used;
} DynamicArray;

static void print_menu(void) {
	printf("\nDynamic Array Operations:\n\n");
	printf("1 - Create a new dynamic array (malloc)\n");
	printf("2 - Add elements to the array\n");
	printf("3 - Resize the array (realloc)\n");
	printf("4 - Display the array\n");
	printf("5 - Free the allocated memory and exit\n");
}

static int read_int_in_range(const char *prompt, int min, int max, int *out) {
	char buffer[256];
	char *endptr = NULL;
	long value;

	if (min > max || out == NULL) {
		return 0;
	}

	while (1) {
		printf("%s", prompt);

		if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
			return 0;
		}

		errno = 0;
		value = strtol(buffer, &endptr, 10);

		if (endptr == buffer) {
			printf("Invalid input. Please enter an integer.\n");
			continue;
		}

		while (*endptr == ' ' || *endptr == '\t' || *endptr == '\n' || *endptr == '\r') {
			endptr++;
		}

		if (*endptr != '\0') {
			printf("Invalid input. Unexpected characters found.\n");
			continue;
		}

		if (errno == ERANGE || value < min || value > max) {
			printf("Input out of range (%d to %d).\n", min, max);
			continue;
		}

		*out = (int)value;
		return 1;
	}
}

static int create_array(DynamicArray *arr) {
	int n;
	int *new_data;

	if (arr == NULL) {
		return 0;
	}

	if (!read_int_in_range("Enter the number of elements to allocate: ", 1, INT_MAX, &n)) {
		return 0;
	}

	if ((size_t)n > SIZE_MAX / sizeof(int)) {
		printf("Requested size is too large for this system.\n");
		return 1;
	}

	new_data = (int *)malloc((size_t)n * sizeof(int));
	if (new_data == NULL) {
		printf("Memory allocation failed.\n");
		return 1;
	}

	if (arr->data != NULL) {
		free(arr->data);
		arr->data = NULL;
		arr->capacity = 0;
		arr->used = 0;
	}

	arr->data = new_data;
	arr->capacity = (size_t)n;
	arr->used = 0;

	printf("Memory allocated successfully.\n");
	return 1;
}

static int add_elements(DynamicArray *arr) {
	int count;
	int *temp;
	size_t i;
	char prompt[128];

	if (arr == NULL) {
		return 0;
	}

	if (arr->data == NULL) {
		printf("Array is not created yet. Choose option 1 first.\n");
		return 1;
	}

	if (arr->used == arr->capacity) {
		printf("Array is full. Resize the array before adding more elements.\n");
		return 1;
	}

	printf("Available slots: %zu\n", arr->capacity - arr->used);
	if (!read_int_in_range("How many elements do you want to add? ", 1,
						   (int)(arr->capacity - arr->used), &count)) {
		return 0;
	}

	temp = (int *)calloc((size_t)count, sizeof(int));
	if (temp == NULL) {
		printf("Temporary memory allocation failed.\n");
		return 1;
	}

	for (i = 0; i < (size_t)count; i++) {
		snprintf(prompt, sizeof(prompt), "Enter element %zu: ", arr->used + i + 1);
		if (!read_int_in_range(prompt, INT_MIN, INT_MAX, &temp[i])) {
			free(temp);
			return 0;
		}
	}

	for (i = 0; i < (size_t)count; i++) {
		arr->data[arr->used + i] = temp[i];
	}

	arr->used += (size_t)count;
	free(temp);

	printf("%d element(s) added successfully.\n", count);
	return 1;
}

static int resize_array(DynamicArray *arr) {
	int new_size;
	int *resized_data;
	size_t old_capacity;

	if (arr == NULL) {
		return 0;
	}

	if (arr->data == NULL) {
		printf("Array is not created yet. Choose option 1 first.\n");
		return 1;
	}

	if (!read_int_in_range("Enter the new size of the array: ", 1, INT_MAX, &new_size)) {
		return 0;
	}

	if ((size_t)new_size > SIZE_MAX / sizeof(int)) {
		printf("Requested size is too large for this system.\n");
		return 1;
	}

	old_capacity = arr->capacity;
	resized_data = (int *)realloc(arr->data, (size_t)new_size * sizeof(int));
	if (resized_data == NULL) {
		printf("Resize failed. Existing array remains unchanged.\n");
		return 1;
	}

	arr->data = resized_data;
	arr->capacity = (size_t)new_size;

	if (arr->used > arr->capacity) {
		arr->used = arr->capacity;
		printf("Array was shrunk. Extra elements were truncated.\n");
	}

	if (arr->capacity > old_capacity) {
		size_t i;
		for (i = old_capacity; i < arr->capacity; i++) {
			arr->data[i] = 0;
		}
	}

	printf("Array resized successfully to %d element(s).\n", new_size);
	return 1;
}

static void display_array(const DynamicArray *arr) {
	size_t i;

	if (arr == NULL || arr->data == NULL) {
		printf("Array is not created yet.\n");
		return;
	}

	printf("Capacity: %zu, Used: %zu\n", arr->capacity, arr->used);

	if (arr->used == 0) {
		printf("Array is empty.\n");
		return;
	}

	printf("Elements: ");
	for (i = 0; i < arr->used; i++) {
		printf("%d", arr->data[i]);
		if (i + 1 < arr->used) {
			printf(" ");
		}
	}
	printf("\n");
}

static void free_array(DynamicArray *arr) {
	if (arr == NULL) {
		return;
	}

	free(arr->data);
	arr->data = NULL;
	arr->capacity = 0;
	arr->used = 0;
}

int main(void) {
	DynamicArray arr = {NULL, 0, 0};
	int choice;
	int keep_running = 1;

	while (keep_running) {
		print_menu();

		if (!read_int_in_range("Enter your choice: ", 1, 5, &choice)) {
			printf("Input stream closed. Exiting safely.\n");
			break;
		}

		switch (choice) {
			case 1:
				if (!create_array(&arr)) {
					keep_running = 0;
				}
				break;
			case 2:
				if (!add_elements(&arr)) {
					keep_running = 0;
				}
				break;
			case 3:
				if (!resize_array(&arr)) {
					keep_running = 0;
				}
				break;
			case 4:
				display_array(&arr);
				break;
			case 5:
				free_array(&arr);
				printf("Memory freed. Exiting program.\n");
				keep_running = 0;
				break;
			default:
				printf("Invalid option. Please choose between 1 and 5.\n");
				break;
		}
	}

	free_array(&arr);
	return 0;
}
