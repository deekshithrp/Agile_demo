#include <stdio.h>
#include <string.h>

int binary_search(char *arr[], int arr_size, char *target) {
    int left = 0;
    int right = arr_size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcmp(arr[mid], target);

        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    char *sorted_list[] = {"BROWN", "DOG", "FOX", "JUMPS", "LAZY", "OVER", "QUICK", "THE"};
    int arr_size = sizeof(sorted_list) / sizeof(sorted_list[0]);
    char target[50];  // Assuming the target string won't exceed 50 characters
    
    printf("Enter the element you want to search for: ");
    scanf("%s", target);
    
    int result = binary_search(sorted_list, arr_size, target);
    
    if (result != -1) {
        printf("Element '%s' found at index %d.\n", target, result);
    } else {
        printf("Element '%s' not found in the list.\n", target);
    }
    
    return 0;
}
