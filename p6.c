#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 100
#define SUBJECTS 3

typedef struct {
	char name[NAME_LENGTH];
	int rollNumber;
	float grades[SUBJECTS];
} Student;

static void clearInputBuffer(void) {
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF) {
		/* discard */
	}
}

static void readLine(char *buffer, size_t size) {
	if (fgets(buffer, (int)size, stdin) != NULL) {
		buffer[strcspn(buffer, "\n")] = '\0';
	}
}

static int findStudentIndex(const Student students[], int count, int rollNumber) {
	for (int i = 0; i < count; ++i) {
		if (students[i].rollNumber == rollNumber) {
			return i;
		}
	}
	return -1;
}

static void printStudent(const Student *student) {
	printf("Roll Number: %d\n", student->rollNumber);
	printf("Name: %s\n", student->name);
	for (int i = 0; i < SUBJECTS; ++i) {
		printf("Grade %d: %.2f\n", i + 1, student->grades[i]);
	}
	printf("--------------------------\n");
}

static void addStudent(Student students[], int *count) {
	if (*count >= MAX_STUDENTS) {
		printf("Student list is full. Cannot add more records.\n");
		return;
	}

	int numberOfStudents;
	printf("How many students do you want to add? ");
	if (scanf("%d", &numberOfStudents) != 1 || numberOfStudents <= 0) {
		printf("Invalid number.\n");
		clearInputBuffer();
		return;
	}
	clearInputBuffer();

	for (int i = 0; i < numberOfStudents && *count < MAX_STUDENTS; ++i) {
		Student student;
		int duplicateIndex;

		printf("\nEnter roll number: ");
		if (scanf("%d", &student.rollNumber) != 1) {
			printf("Invalid roll number.\n");
			clearInputBuffer();
			return;
		}
		clearInputBuffer();

		duplicateIndex = findStudentIndex(students, *count, student.rollNumber);
		if (duplicateIndex != -1) {
			printf("A student with this roll number already exists.\n");
			--i;
			continue;
		}

		printf("Enter name: ");
		readLine(student.name, sizeof(student.name));

		for (int j = 0; j < SUBJECTS; ++j) {
			printf("Enter grade %d: ", j + 1);
			if (scanf("%f", &student.grades[j]) != 1) {
				printf("Invalid grade.\n");
				clearInputBuffer();
				return;
			}
		}
		clearInputBuffer();

		students[*count] = student;
		++(*count);
		printf("Student record added successfully.\n");
	}

	if (*count >= MAX_STUDENTS) {
		printf("Student list reached maximum capacity.\n");
	}
}

static void displayStudents(const Student students[], int count) {
	if (count == 0) {
		printf("No student records available.\n");
		return;
	}

	printf("\nStored Student Records:\n");
	printf("--------------------------\n");
	for (int i = 0; i < count; ++i) {
		printStudent(&students[i]);
	}
}

static void searchStudent(const Student students[], int count) {
	int rollNumber;

	printf("Enter roll number to search: ");
	if (scanf("%d", &rollNumber) != 1) {
		printf("Invalid roll number.\n");
		clearInputBuffer();
		return;
	}
	clearInputBuffer();

	int index = findStudentIndex(students, count, rollNumber);
	if (index == -1) {
		printf("Student record not found.\n");
		return;
	}

	printf("Student record found:\n");
	printStudent(&students[index]);
}

static void modifyStudent(Student students[], int count) {
	int rollNumber;

	printf("Enter roll number to modify: ");
	if (scanf("%d", &rollNumber) != 1) {
		printf("Invalid roll number.\n");
		clearInputBuffer();
		return;
	}
	clearInputBuffer();

	int index = findStudentIndex(students, count, rollNumber);
	if (index == -1) {
		printf("Student record not found.\n");
		return;
	}

	printf("Enter new name: ");
	readLine(students[index].name, sizeof(students[index].name));

	for (int i = 0; i < SUBJECTS; ++i) {
		printf("Enter new grade %d: ", i + 1);
		if (scanf("%f", &students[index].grades[i]) != 1) {
			printf("Invalid grade.\n");
			clearInputBuffer();
			return;
		}
	}
	clearInputBuffer();

	printf("Student record updated successfully.\n");
}

static void deleteStudent(Student students[], int *count) {
	int rollNumber;

	printf("Enter roll number to delete: ");
	if (scanf("%d", &rollNumber) != 1) {
		printf("Invalid roll number.\n");
		clearInputBuffer();
		return;
	}
	clearInputBuffer();

	int index = findStudentIndex(students, *count, rollNumber);
	if (index == -1) {
		printf("Student record not found.\n");
		return;
	}

	for (int i = index; i < *count - 1; ++i) {
		students[i] = students[i + 1];
	}
	--(*count);

	printf("Student record deleted successfully.\n");
}

int main(void) {
	Student students[MAX_STUDENTS];
	int count = 0;
	int choice;

	while (1) {
		printf("\nStudent Record System\n");
		printf("1. Add student records\n");
		printf("2. Display all records\n");
		printf("3. Search by roll number\n");
		printf("4. Modify a record\n");
		printf("5. Delete a record\n");
		printf("6. Exit\n");
		printf("Enter your choice: ");

		if (scanf("%d", &choice) != 1) {
			printf("Invalid choice.\n");
			clearInputBuffer();
			continue;
		}
		clearInputBuffer();

		switch (choice) {
			case 1:
				addStudent(students, &count);
				break;
			case 2:
				displayStudents(students, count);
				break;
			case 3:
				searchStudent(students, count);
				break;
			case 4:
				modifyStudent(students, count);
				break;
			case 5:
				deleteStudent(students, &count);
				break;
			case 6:
				printf("Exiting program.\n");
				return 0;
			default:
				printf("Invalid choice. Please try again.\n");
				break;
		}
	}

	return 0;
}
