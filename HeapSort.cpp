/*
Time Complexity:
    Best Case: O(n*log(n))
    Average Case: O(n*log(n))
    Worst Case: O(n*log(n))

Space Complexity: O(1)

Usage : When very fast performance is not necessarily needed, but guaranteed O(n*log(n)) performance (e.g. in a game),
        because Quicksort's O(n^2) can be very slow and because Mergesort takes O(n) extra memory.
*/
template <class T>
void swapHeap(std::vector<T>& arr, int left, int right) {
    T temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}

template <class T>
void heapify(std::vector<T>& arr, int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swapHeap(arr, i, largest);
        heapify(arr, size, largest);
    }
}

template <class T>
void heapSort(std::vector<T>& arr, int size) {
    for (int i = size / 2 - 1; i >= 0; i -= 1) {  // building max heap
        heapify(arr, size, i);
    }

    for (int i = size - 1; i >= 0; i -= 1) {
        swapHeap(arr, 0, i);
        heapify(arr, i, 0);
    }
}
