// Print file contents in reverse order.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Usage: %s <filename>\n", argv[0]);
		return 1;
	}

	FILE *fp = fopen(argv[1], "rb");
	if (fp == NULL) {
		perror("Error opening file");
		return 1;
	}

	if (fseek(fp, 0, SEEK_END) != 0) {
		perror("Error seeking file");
		fclose(fp);
		return 1;
	}

	long size = ftell(fp);
	if (size < 0) {
		perror("Error determining file size");
		fclose(fp);
		return 1;
	}

	for (long i = size - 1; i >= 0; --i) {
		if (fseek(fp, i, SEEK_SET) != 0) {
			perror("Error seeking file");
			fclose(fp);
			return 1;
		}

		int ch = fgetc(fp);
		if (ch == EOF) {
			perror("Error reading file");
			fclose(fp);
			return 1;
		}

		putchar(ch);
	}

	fclose(fp);
	return 0;
}
