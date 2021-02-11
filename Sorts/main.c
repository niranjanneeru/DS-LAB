# include <stdio.h>
# include <string.h>
# include <math.h>
# include <stdlib.h>
# include <time.h>

int n;

typedef struct {
    char name[200];
    float height;
    float weight;
} student;

student **L, **R;


# define MAX 255

void list(student **s, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s %f %f\n", s[i]->name, s[i]->height, s[i]->weight);
    }
    printf("End\n");
}

void swap(student **s, int i, int j) {
    student *temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

int partition(student **s, int start, int end) {
    int pivot = end;
    int j = start;
    for (int i = start; i < end; ++i) {
        if (s[i]->height < s[pivot]->height) {
            if (i != j)
                swap(s, i, j);
            j++;
        }
    }
    swap(s, j, pivot);
    return j;

}

void quicksort(student **s, int start, int end) {
    if (start < end) {
        int div = partition(s, start, end);
        quicksort(s, start, div - 1);
        quicksort(s, div + 1, end);
    }
}

void deepcopy(student **new, student **s, int start, int limit) {
    int k = 0;
    for (int i = start; i < limit; ++i) {
        strcpy(new[k]->name, s[i]->name);
        new[k]->height = s[i]->height;
        new[k]->weight = s[i]->weight;
        k++;
    }
}

void merge(student **s, int start, int mid, int end) {
    int size_1 = mid - start + 1;
    int size_2 = end - mid;
    deepcopy(L, s, start, mid + 1);
    deepcopy(R, s, mid + 1, end + 1);
    int i = 0, j = 0;
    int k = start;
    while (i < size_1 && j < size_2) {
        if (L[i]->height < R[j]->height) {
            strcpy(s[k]->name, L[i]->name);
            s[k]->height = L[i]->height;
            s[k]->weight = L[i]->weight;
            i++;
        } else {
            strcpy(s[k]->name, R[j]->name);
            s[k]->height = R[j]->height;
            s[k]->weight = R[j]->weight;
            j++;
        }
        k++;
    }
    while (i < size_1) {
        strcpy(s[k]->name, L[i]->name);
        s[k]->height = L[i]->height;
        s[k]->weight = L[i]->weight;
        i++;
        k++;
    }
    while (j < size_2) {
        strcpy(s[k]->name, R[j]->name);
        s[k]->height = R[j]->height;
        s[k]->weight = R[j]->weight;
        j++;
        k++;
    }

}

void mergesort(student **s, int start, int end) {
    if (start < end) {
        int div = (start + end) / 2;
        mergesort(s, start, div);
        mergesort(s, div + 1, end);
        merge(s, start, div, end);
    }
}

int get_number_of_lines(FILE *fp) {
    int i = 0;
    char arr[100];
    while (fgets(arr, MAX, fp)) {
        i++;
    }
    rewind(fp);
    return i;
}

student **get_data(FILE *fp) {
    student **s = (student **) malloc(sizeof(student *) * n);
    int k = 0;
    int flag, j, end;
    char arr[256];
    while (fgets(arr, MAX, fp)) {
        flag = 0;
        j = 0;
        end = 0;
        s[k] = (student *) malloc(sizeof(student));
        s[k]->height = 0;
        s[k]->weight = 0;
        for (int i = 0; i < strlen(arr); i++) {
            if (arr[i] == '\n') {
                continue;
            }
            if (arr[i] == '\t') {
                arr[i] = ' ';
            }
            if (arr[i] == ' ') {
                if ('0' < arr[i + 1] && arr[i + 1] < '9') {
                    flag += 1;
                    if (!end) {
                        end = 1;
                    }
                    continue;
                }
            }
            if (end) {
                (s[k]->name)[i - 1] = '\0';
            }
            if (!flag) {
                (s[k]->name)[i] = arr[i];
            } else if (flag == 1) {
                if (arr[i] == '.') {
                    flag = 2;
                    j++;
                } else {
                    s[k]->height = s[k]->height * 10 + arr[i] - '0';
                }
            } else if (flag == 2) {
                s[k]->height = s[k]->height + (arr[i] - '0') / pow(10, j++);
            } else if (flag == 3) {
                if (arr[i] == '.') {
                    flag = 4;
                    j++;
                } else {
                    s[k]->weight = s[k]->weight * 10 + arr[i] - '0';
                }
            } else if (flag == 4) {
                s[k]->weight = s[k]->weight + (arr[i] - '0') / pow(10, j++);
            }
        }
        k++;
    }
    return s;
}


student **allocate_memory(int size) {
    student **s = (student **) malloc(sizeof(student *) * size);
    for (int i = 0; i < size; ++i) {
        s[i] = (student *) malloc(sizeof(student));
    }
    return s;
}

void write_into_file(char file[], student **new, double time) {
    FILE *fp;
    fp = fopen(file, "w");
    fprintf(fp, "Time Elapsed : %.1f ms\n", time * 1000);
    for (int i = 0; i < n; ++i) {
        fprintf(fp, "\n%s %.1f %.0f", new[i]->name, new[i]->height, new[i]->weight);
    }
    fclose(fp);
}

int main() {
    FILE *fp;
    double time_spend;
    clock_t begin, end;

    fp = fopen("data/input.txt", "r");
    if (fp == NULL) {
        printf("FILE NOT FOUND");
    }
    n = get_number_of_lines(fp);
    student **s = get_data(fp);

    student **new = allocate_memory(n);
    L = allocate_memory((int) (n / 2) + 1);
    R = allocate_memory((int) (n / 2) + 1);

    for (int i = 0; i < 5; ++i) {
        deepcopy(new, s, 0, n);
        begin = clock();
        quicksort(new, 0, n - 1);
        end = clock();
        time_spend += ((double) (end - begin)) / CLOCKS_PER_SEC;
    }

    write_into_file("data/output_quicksort.txt", new, (double) time_spend / 5);

    printf("Data Set:- %d\n",n);

    printf("Quick Sort: %.1f ms\n", time_spend * 1000 / 5);

    for (int i = 0; i < 5; ++i) {
        deepcopy(new, s, 0, n);
        begin = clock();
        mergesort(new, 0, n - 1);
        end = clock();
        time_spend += ((double) (end - begin)) / CLOCKS_PER_SEC;
    }

    write_into_file("data/output_mergesort.txt", new, (double) time_spend / 5);

    printf("Merge Sort: %.1f ms", time_spend * 1000 / 5);

    for (int i = 0; i < n; i++) {
        free(s[i]);
        free(new[i]);
    }
    free(s);
    free(new);
    fclose(fp);
}