#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

typedef struct student{
    int id;
    int age;
} student_t;

void printStudent (student_t *student) {
    printf("Student ID: %d, Age: %d\n", student->id, student->age);
}

// void updateStudent (student_t *student, int age, int id) {
//     (*student).age = age;
//     (*student).id = id;
// }

student_t *makeStudent(int id, int age) {
    student_t *p_aStudent = 
                (student_t*)malloc(sizeof(student_t));
    p_aStudent -> id = id;
    p_aStudent -> age = age;
    return p_aStudent;
}

int main() {
    student_t *s1 = makeStudent(8888, 23);
    student_t *s2 = makeStudent(9999, 24);

    // updateStudent(&s1, 23, 8888);
    // updateStudent(&s2, 43, 9999);

    printStudent(s1);
    printStudent(s2);

    return 0;
}