#include <stdio.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int LinearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}


int BinarySearch(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;
    int mid;
    while (high >= low) {
        mid = (low + high) / 2; 
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;    
}


void BubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) { 
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]); 
            }
        }
    }
}

void SelectionSort(int arr[],int n){
	for(int i=0;i<n;i++){
		int min=i;
		for(int j=i+1;j<n;j++){
			if(arr[min]>arr[j]){
				min=j;
			}
		}
		swap(&arr[i],&arr[min]);
	}
}

void InsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int temp = arr[i];
        while (j >= 0 && arr[j] > temp) { 
            arr[j + 1] = arr[j]; 
            j--;
        }
        arr[j + 1] = temp;
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    

    BubbleSort(arr, n);
    

    int key = 22;
    int index = LinearSearch(arr, n, key);
    if (index != -1) {
        printf("Element %d found at index %d\n", key, index);
    } else {
        printf("Element %d not found\n", key);
    }


    key = 90;
    index = BinarySearch(arr, n, key);
    if (index != -1) {
        printf("Element %d found at index %d\n", key, index);
    } else {
        printf("Element %d not found\n", key);
    }

    return 0;
}
