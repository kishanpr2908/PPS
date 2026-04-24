#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 256
#define MAX_LINE_LEN 1024

static void remove_trailing_newline(char *str) {
	size_t len = strlen(str);
	if (len > 0 && str[len - 1] == '\n') {
		str[len - 1] = '\0';
	}
}

static int read_line(char *buffer, int size) {
	if (fgets(buffer, size, stdin) == NULL) {
		return 0;
	}
	remove_trailing_newline(buffer);
	return 1;
}

static void read_filename(char *filename) {
	printf("Enter file name: ");
	if (!read_line(filename, MAX_FILENAME_LEN)) {
		filename[0] = '\0';
	}
}

static void create_and_write_file(void) {
	char filename[MAX_FILENAME_LEN];
	char line[MAX_LINE_LEN];
	FILE *fp;

	read_filename(filename);
	if (filename[0] == '\0') {
		printf("Invalid file name.\n");
		return;
	}

	fp = fopen(filename, "w");
	if (fp == NULL) {
		printf("Could not create/open file.\n");
		return;
	}

	printf("Enter text to write (type END on a new line to finish):\n");
	while (1) {
		if (!read_line(line, MAX_LINE_LEN)) {
			break;
		}
		if (strcmp(line, "END") == 0) {
			break;
		}
		fprintf(fp, "%s\n", line);
	}

	fclose(fp);
	printf("File created/written successfully.\n");
}

static void read_and_display_file(void) {
	char filename[MAX_FILENAME_LEN];
	char line[MAX_LINE_LEN];
	FILE *fp;

	read_filename(filename);
	if (filename[0] == '\0') {
		printf("Invalid file name.\n");
		return;
	}

	fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("Could not open file for reading.\n");
		return;
	}

	printf("\n--- File Content Start ---\n");
	while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
		printf("%s", line);
	}
	printf("--- File Content End ---\n\n");

	fclose(fp);
}

static void append_to_file(void) {
	char filename[MAX_FILENAME_LEN];
	char line[MAX_LINE_LEN];
	FILE *fp;

	read_filename(filename);
	if (filename[0] == '\0') {
		printf("Invalid file name.\n");
		return;
	}

	fp = fopen(filename, "a");
	if (fp == NULL) {
		printf("Could not open file for appending.\n");
		return;
	}

	printf("Enter text to append (type END on a new line to finish):\n");
	while (1) {
		if (!read_line(line, MAX_LINE_LEN)) {
			break;
		}
		if (strcmp(line, "END") == 0) {
			break;
		}
		fprintf(fp, "%s\n", line);
	}

	fclose(fp);
	printf("Text appended successfully.\n");
}

static void clear_file_contents(void) {
	char filename[MAX_FILENAME_LEN];
	FILE *fp;

	read_filename(filename);
	if (filename[0] == '\0') {
		printf("Invalid file name.\n");
		return;
	}

	fp = fopen(filename, "w");
	if (fp == NULL) {
		printf("Could not open file to clear contents.\n");
		return;
	}

	fclose(fp);
	printf("File contents deleted successfully.\n");
}

int main(void) {
	int choice;
	char input[32];

	while (1) {
		printf("\n===== Simple Text Editor (File Operations) =====\n");
		printf("1. Create and write to a file\n");
		printf("2. Read and display file contents\n");
		printf("3. Append text to an existing file\n");
		printf("4. Delete the contents of a file\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");

		if (!read_line(input, sizeof(input))) {
			printf("Input error. Exiting.\n");
			break;
		}

		choice = atoi(input);

		switch (choice) {
			case 1:
				create_and_write_file();
				break;
			case 2:
				read_and_display_file();
				break;
			case 3:
				append_to_file();
				break;
			case 4:
				clear_file_contents();
				break;
			case 5:
				printf("Exiting program.\n");
				return 0;
			default:
				printf("Invalid choice. Please enter 1-5.\n");
		}
	}

	return 0;
}
