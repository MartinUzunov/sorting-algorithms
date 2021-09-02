/*
Time Complexity:
    Best Case: O(n)
    Average Case: O(n^2)
    Worst Case: O(n^2)

Space Complexity: O(1)

Usage: Due to its simplicity, bubble sort is often used to introduce the concept of a sorting algorithm. 
*/
template <class T>
void bubbleSort(std::vector<T>& arr, size_t size) {
    for (size_t i = 0; i < size - 1; i += 1) {
        bool swap = false;
        for (size_t j = 0; j < size - i - 1; j += 1) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                swap = true;
            }
        }
        if (!swap) {
            break;
        }
    }
}
