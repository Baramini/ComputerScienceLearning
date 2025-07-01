#include <stdio.h>
#include <stdlib.h>

void insert_array(int** array, int* n, int* size, int index, int item) {
    if (index > (*size)-1) {
        printf("Out of Range\n");
        return;
    }
    if (*n <= *size) {
        (*n) += 5;
        *array = (int*)realloc(*array, *n * sizeof(int));
    }
    for (int i = (*size)-1; i >= index; i--) (*array)[i+1] = (*array)[i];
    (*array)[index] = item;
    (*size)++;
}
int delete_array(int** array, int* n, int* size, int index) {
    if (index > (*size)-1) {
        printf("Out of Range\n");
        return 0;
    }
    int item = (*array)[index];
    for (int i = index; i < *size; i++) (*array)[i] = (*array)[i + 1];
    (*size)--;
    return item;
}
void print_array(int** array, int size) {
    for (int i = 0; i < size-1; i++) {
        printf("%d ", (*array)[i]);
    }
    printf("%d\n", (*array)[size-1]);
}

int main() {
    int n, size;
    printf("Array Size(up 10): ");
    scanf("%d", &n);

    int *array = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < 10; i++) array[i] = i;
    size = 10;

    insert_array(&array, &n, &size, 2, 20);
    insert_array(&array, &n, &size, 8, 80);
    print_array(&array, size);
    printf("%d 삭제\n", delete_array(&array, &n, &size, 5));
    printf("%d 삭제\n", delete_array(&array, &n, &size, 8));
    print_array(&array, size);

    free(array);
}