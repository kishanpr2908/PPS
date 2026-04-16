#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LEN 100

// Define the structure for a student
typedef struct {
    int roll_number;
    char name[MAX_NAME_LEN];
    float grades;
} Student;

// Global array and counter to store students
Student students[MAX_STUDENTS];
int num_students = 0;

// Function prototypes
void add_student();
void display_students();
void search_student();
void modify_student();
void delete_student();
void clear_input_buffer();

int main() {
    int choice;
    while (1) {
        printf("\n=== Student Record System ===\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Modify Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clear_input_buffer();
            continue;
        }

        switch (choice) {
            case 1: add_student(); break;
            case 2: display_students(); break;
            case 3: search_student(); break;
            case 4: modify_student(); break;
            case 5: delete_student(); break;
            case 6: 
                printf("Exiting the program...\n");
                return 0;
            default: 
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Utility function to clear standard input buffer
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void add_student() {
    if (num_students >= MAX_STUDENTS) {
        printf("Error: Maximum number of students reached (%d).\n", MAX_STUDENTS);
        return;
    }
    
    Student new_student;
    printf("Enter roll number: ");
    if (scanf("%d", &new_student.roll_number) != 1) {
        printf("Invalid roll number.\n");
        clear_input_buffer();
        return;
    }

    // Check if roll number already exists
    for (int i = 0; i < num_students; i++) {
        if (students[i].roll_number == new_student.roll_number) {
            printf("Error: Student with roll number %d already exists.\n", new_student.roll_number);
            return;
        }
    }

    // To consume the trailing newline after %d
    clear_input_buffer();
    
    printf("Enter name: ");
    fgets(new_student.name, MAX_NAME_LEN, stdin);
    // Remove trailing newline from fgets
    new_student.name[strcspn(new_student.name, "\n")] = 0;

    printf("Enter grades: ");
    if (scanf("%f", &new_student.grades) != 1) {
        printf("Invalid grade input.\n");
        clear_input_buffer();
        return;
    }

    students[num_students++] = new_student;
    printf("Student added successfully.\n");
}

void display_students() {
    if (num_students == 0) {
        printf("No records found.\n");
        return;
    }
    printf("\n%-10s %-30s %-10s\n", "Roll No", "Name", "Grades");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < num_students; i++) {
        printf("%-10d %-30s %-10.2f\n", students[i].roll_number, students[i].name, students[i].grades);
    }
}

void search_student() {
    int roll;
    printf("Enter roll number to search: ");
    if (scanf("%d", &roll) != 1) {
        printf("Invalid roll number.\n");
        clear_input_buffer();
        return;
    }
    
    for (int i = 0; i < num_students; i++) {
        if (students[i].roll_number == roll) {
            printf("\n--- Record Found ---\n");
            printf("Roll No: %d\nName: %s\nGrades: %.2f\n", students[i].roll_number, students[i].name, students[i].grades);
            return;
        }
    }
    printf("Student with roll number %d not found.\n", roll);
}

void modify_student() {
    int roll;
    printf("Enter roll number to modify: ");
    if (scanf("%d", &roll) != 1) {
        printf("Invalid roll number.\n");
        clear_input_buffer();
        return;
    }
    
    for (int i = 0; i < num_students; i++) {
        if (students[i].roll_number == roll) {
            printf("Current Record - Roll No: %d, Name: %s, Grades: %.2f\n", students[i].roll_number, students[i].name, students[i].grades);
            
            clear_input_buffer();
            printf("Enter new name: ");
            fgets(students[i].name, MAX_NAME_LEN, stdin);
            students[i].name[strcspn(students[i].name, "\n")] = 0;
            
            printf("Enter new grades: ");
            if (scanf("%f", &students[i].grades) != 1) {
                printf("Invalid grade input. Modifications partially applied.\n");
                clear_input_buffer();
                return;
            }
            
            printf("Record updated successfully.\n");
            return;
        }
    }
    printf("Student with roll number %d not found.\n", roll);
}

void delete_student() {
    int roll;
    printf("Enter roll number to delete: ");
    if (scanf("%d", &roll) != 1) {
        printf("Invalid roll number.\n");
        clear_input_buffer();
        return;
    }
    
    for (int i = 0; i < num_students; i++) {
        if (students[i].roll_number == roll) {
            // Shift elements to fill the gap
            for (int j = i; j < num_students - 1; j++) {
                students[j] = students[j + 1];
            }
            num_students--;
            printf("Record deleted successfully.\n");
            return;
        }
    }
    printf("Student with roll number %d not found.\n", roll);
}
