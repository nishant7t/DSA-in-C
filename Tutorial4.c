#include <stdio.h>

struct student {
    char name[10];
    int roll;
} s[100];

void create(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter name: ");
        scanf("%9s", s[i].name);

        printf("Enter Roll: ");
        scanf("%d", &s[i].roll);
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s ", s[i].name);
        printf("%d\n", s[i].roll);
    }
}

void search(int a[], int key, int n) {
    for (int i = 0; i < n; i++) {
        if (key == s[i].roll) {
            printf("Yes, student found: %s\n", s[i].name);
            return;
        }
    }

    printf("Student not found\n");
}

void sort(int a[], int n) {
    struct student temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].roll > s[j + 1].roll) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[100];

    create(arr, 3);

    printf("\nBefore sorting:\n");
    display(arr, 3);

    sort(arr, 3);

    printf("\nAfter sorting by roll number:\n");
    display(arr, 3);

    search(arr, 2, 3);

    return 0;
}
