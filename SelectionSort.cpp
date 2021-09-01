/*
Time Complexity:
    Best Case: O(n^2)
    Average Case: O(n^2)
    Worst Case: O(n^2)

Space Complexity: O(1)
*/
template <class T>
void selectionSort(std::vector<T>& arr, size_t size) {
    for (size_t i = 0; i < size - 1; i += 1) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < size; j += 1) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            T temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}