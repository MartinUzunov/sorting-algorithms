/*
Time Complexity:
    Best Case: O(n*log(n))
    Average Case: O(n*log(n))
    Worst Case: O(n*log(n))

Space Complexity: O(n)
*/
template <class T>
void merge(std::vector<T>& arr, size_t left, size_t middle, size_t right) {
    std::vector<T> temp;
    size_t i = left;
    size_t j = middle + 1;

    while (i <= middle && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i += 1;
        } else {
            temp.push_back(arr[j]);
            j += 1;
        }
    }

    while (i <= middle) {
        temp.push_back(arr[i]);
        i += 1;
    }

    while (j <= right) {
        temp.push_back(arr[j]);
        j += 1;
    }

    for (size_t i = left; i <= right; i += 1) {
        arr[i] = temp[i - left];
    }
}

template <class T>
void mergeSortHelper(std::vector<T>& arr, size_t left, size_t right) {
    if (left < right) {
        size_t middle = (left + right) / 2;
        mergeSortHelper<T>(arr, left, middle);
        mergeSortHelper<T>(arr, middle + 1, right);
        merge<T>(arr, left, middle, right);
    }
}

template <class T>
void mergeSort(std::vector<T>& arr, size_t size) {
    mergeSortHelper<T>(arr, 0, size - 1);
}