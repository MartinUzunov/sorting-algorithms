/*
Time Complexity:
    Best Case: O(n)
    Average Case: O(n^2)
    Worst Case: O(n^2)

Space Complexity: O(1)
*/
template <class T>
void insertionSort(std::vector<T>& arr, size_t size) {
    for (size_t i = 1; i < size; i += 1) {
        T current = arr[i];
        size_t j = i;
        while (j > 0 && arr[j - 1] > current) {
            arr[j] = arr[j - 1];
            j -= 1;
        }
        arr[j] = current;
    }
}