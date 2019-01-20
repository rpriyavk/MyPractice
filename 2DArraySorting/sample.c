#include <stdio.h>
#include <stdlib.h>

void simple_sort(int *arr, int arr_size)
{
    int i, j;
    int tmp;
    for (i = 0; i < arr_size; i++) {
        for (j = i + 1; j < arr_size; j++) {
            if (arr[i] < arr[j]) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

int main() {
    int num_of_studs;
    int *arr = NULL;
    int f_idx, m_idx;
    int i;
    int fm, level;

    scanf("%d", &num_of_studs);
    if (num_of_studs <= 0) {
        goto err;
    }

    arr = malloc(sizeof(int *) * num_of_studs);
    if (!arr) {
        goto err;
    }

    f_idx = 0;
    m_idx = num_of_studs - 1;
    for (i = 0; i < num_of_studs; i++) {
        scanf("%d %d", &fm, &level);
        if (!fm) {
            /* If female */
            arr[f_idx] = level;
            f_idx++;
        } else {
            /* If male */
            arr[m_idx] = level;
            m_idx--;
        }
    }
    printf("Received %d female entries\n", f_idx);
    printf("Received %d male entries\n", (num_of_studs - 1) - m_idx);
    simple_sort(arr, f_idx);
    simple_sort(arr + m_idx + 1, (num_of_studs - 1) - m_idx);
    for (i = 0; i < num_of_studs; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
err:
    return -1;
}
