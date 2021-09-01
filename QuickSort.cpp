/*
Time Complexity:
    Best Case: O(n*log(n))
    Average Case: O(n*log(n))
    Worst Case: O(n^2)

Space Complexity: O(log(n))
*/
template <class T>
void swap(std::vector<T>& arr, int left, int right) {
    T temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}

template <class T>
int choosePivot(std::vector<T>& arr, int left, int right) {
    int middle = (left + right) / 2;
    if (arr[right] < arr[left]) {
        swap(arr, left, right);
    }

    if (arr[middle] < arr[left]) {
        swap(arr, middle, left);
    }

    if (arr[right] < arr[middle]) {
        swap(arr, right, middle);
    }

    return right;
}

template <class T>
int partition(std::vector<T>& arr, int left, int right) {
    int pivot = choosePivot(arr, left, right);
    int i = left - 1;
    for (int j = left; j < right; j += 1) {
        if (arr[j] < arr[pivot]) {
            i += 1;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, right);
    return i + 1;
}

template <class T>
void quickSortHelper(std::vector<T>& arr, int left, int right) {
    if (left < right) {
        int part = partition(arr, left, right);
        quickSortHelper(arr, left, part - 1);
        quickSortHelper(arr, part + 1, right);
    }
}

template <class T>
void quickSort(std::vector<T>& arr, int size) {
    quickSortHelper(arr, 0, size - 1);
}