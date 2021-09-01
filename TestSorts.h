#ifndef __TESTSORTS_H
#define __TESTSORTS_H

#include <chrono>
#include <exception>
#include <fstream>
#include <iostream>
#include <vector>

#include "BubbleSort.cpp"
#include "HeapSort.cpp"
#include "InsertionSort.cpp"
#include "MergeSort.cpp"
#include "QuickSort.cpp"
#include "SelectionSort.cpp"

std::vector<int> createArray(std::string filename) {
    std::vector<int> vec;
    std::ifstream file;
    file.open(filename);
    if (!file.is_open()) {
        std::cout << "File couldn\'t be opened" << std::endl;
        throw std::invalid_argument("File " + filename + " does not exists");
    }
    int number = 0;
    while (file >> number) {
        vec.push_back(number);
    }
    return vec;
}

template <class T>
bool sorted(const std::vector<T>& arr, size_t size) {
    if (size == 0) {
        return true;
    }
    for (size_t i = 0; i < size - 1; i += 1) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

TEST_CASE("Bubble Sort Test") {
    std::string text = "Bubble";
    std::cout << "=====================================================================" << std::endl;
    std::vector<int> smallDataSet = createArray("small_data_set.txt");    //      100
    std::vector<int> mediumDataSet = createArray("medium_data_set.txt");  //    10000
    //std::vector<int> largeDataSet = createArray("large_data_set.txt");    //   100000 - takes too long

    auto start = std::chrono::high_resolution_clock::now();
    bubbleSort<int>(smallDataSet, smallDataSet.size());
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << text << " Sort (small data set) time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    bubbleSort<int>(mediumDataSet, mediumDataSet.size());
    end = std::chrono::high_resolution_clock::now();
    std::cout << text << " Sort (medium data set) time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    // start = std::chrono::high_resolution_clock::now();
    // bubbleSort<int>(largeDataSet, largeDataSet.size());
    // end = std::chrono::high_resolution_clock::now();
    // std::cout << text << " Sort (large data set) time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    std::cout << "=====================================================================" << std::endl;
    CHECK(sorted<int>(smallDataSet, smallDataSet.size()) == true);
    CHECK(sorted<int>(mediumDataSet, mediumDataSet.size()) == true);
    //CHECK(sorted<int>(largeDataSet,largeDataSet.size()) == true);
}

TEST_CASE("Heap Sort Test") {
    std::string text = "Heap";
    std::cout << "=====================================================================" << std::endl;
    std::vector<int> smallDataSet = createArray("small_data_set.txt");      //      100
    std::vector<int> mediumDataSet = createArray("medium_data_set.txt");    //    10000
    std::vector<int> largeDataSet = createArray("large_data_set.txt");      //   100000
    std::vector<int> massiveDataSet = createArray("massive_data_set.txt");  //  1000000

    auto start = std::chrono::high_resolution_clock::now();
    heapSort<int>(smallDataSet, smallDataSet.size());
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << text << " Sort (small data set) time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    heapSort<int>(mediumDataSet, mediumDataSet.size());
    end = std::chrono::high_resolution_clock::now();
    std::cout << text << " Sort (medium data set) time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    heapSort<int>(largeDataSet, largeDataSet.size());
    end = std::chrono::high_resolution_clock::now();
    std::cout << text << " Sort (large data set) time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    heapSort<int>(massiveDataSet, massiveDataSet.size());
    end = std::chrono::high_resolution_clock::now();
    std::cout << text << " Sort (massive data set) time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    std::cout << "=====================================================================" << std::endl;
    CHECK(sorted<int>(smallDataSet, smallDataSet.size()) == true);
    CHECK(sorted<int>(mediumDataSet, mediumDataSet.size()) == true);
    CHECK(sorted<int>(largeDataSet, largeDataSet.size()) == true);
    CHECK(sorted<int>(massiveDataSet, massiveDataSet.size()) == true);
}

TEST_CASE("Insertion Sort Test") {
    std::string text = "Insertion";
    std::cout << "=====================================================================" << std::endl;
    std::vector<int> smallDataSet = createArray("small_data_set.txt");    //      100
    std::vector<int> mediumDataSet = createArray("medium_data_set.txt");  //    10000
    //std::vector<int> largeDataSet = createArray("large_data_set.txt");  //   100000 - takes too long

    auto start = std::chrono::high_resolution_clock::now();
    insertionSort<int>(smallDataSet, smallDataSet.size());
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << text << " Sort (small data set) time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    insertionSort<int>(mediumDataSet, mediumDataSet.size());
    end = std::chrono::high_resolution_clock::now();
    std::cout << text << " Sort (medium data set) time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    // start = std::chrono::high_resolution_clock::now();
    // insertionSort<int>(largeDataSet, largeDataSet.size());
    // end = std::chrono::high_resolution_clock::now();
    // std::cout << text << " Sort (large data set) time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    std::cout << "=====================================================================" << std::endl;
    CHECK(sorted<int>(smallDataSet, smallDataSet.size()) == true);
    CHECK(sorted<int>(mediumDataSet, mediumDataSet.size()) == true);
    //CHECK(sorted<int>(largeDataSet,largeDataSet.size()) == true);
}

TEST_CASE("Merge Sort Test") {
    std::string text = "Merge";
    std::cout << "=====================================================================" << std::endl;
    std::vector<int> smallDataSet = createArray("small_data_set.txt");      //      100
    std::vector<int> mediumDataSet = createArray("medium_data_set.txt");    //    10000
    std::vector<int> largeDataSet = createArray("large_data_set.txt");      //   100000
    std::vector<int> massiveDataSet = createArray("massive_data_set.txt");  //  1000000

    auto start = std::chrono::high_resolution_clock::now();
    mergeSort<int>(smallDataSet, smallDataSet.size());
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << text << " Sort (small data set) time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    mergeSort<int>(mediumDataSet, mediumDataSet.size());
    end = std::chrono::high_resolution_clock::now();
    std::cout << text << " Sort (medium data set) time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    mergeSort<int>(largeDataSet, largeDataSet.size());
    end = std::chrono::high_resolution_clock::now();
    std::cout << text << " Sort (large data set) time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    mergeSort<int>(massiveDataSet, massiveDataSet.size());
    end = std::chrono::high_resolution_clock::now();
    std::cout << text << " Sort (massive data set) time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    std::cout << "=====================================================================" << std::endl;
    CHECK(sorted<int>(smallDataSet, smallDataSet.size()) == true);
    CHECK(sorted<int>(mediumDataSet, mediumDataSet.size()) == true);
    CHECK(sorted<int>(largeDataSet, largeDataSet.size()) == true);
    CHECK(sorted<int>(massiveDataSet, massiveDataSet.size()) == true);
}

TEST_CASE("Quick Sort Test") {
    std::string text = "Quick";
    std::cout << "=====================================================================" << std::endl;
    std::vector<int> smallDataSet = createArray("small_data_set.txt");      //      100
    std::vector<int> mediumDataSet = createArray("medium_data_set.txt");    //    10000
    std::vector<int> largeDataSet = createArray("large_data_set.txt");      //   100000
    std::vector<int> massiveDataSet = createArray("massive_data_set.txt");  //  1000000

    auto start = std::chrono::high_resolution_clock::now();
    quickSort<int>(smallDataSet, smallDataSet.size());
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << text << " Sort (small data set) time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    quickSort<int>(mediumDataSet, mediumDataSet.size());
    end = std::chrono::high_resolution_clock::now();
    std::cout << text << " Sort (medium data set) time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    quickSort<int>(largeDataSet, largeDataSet.size());
    end = std::chrono::high_resolution_clock::now();
    std::cout << text << " Sort (large data set) time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    quickSort<int>(massiveDataSet, massiveDataSet.size());
    end = std::chrono::high_resolution_clock::now();
    std::cout << text << " Sort (massive data set) time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    std::cout << "=====================================================================" << std::endl;
    CHECK(sorted<int>(smallDataSet, smallDataSet.size()) == true);
    CHECK(sorted<int>(mediumDataSet, mediumDataSet.size()) == true);
    CHECK(sorted<int>(largeDataSet, largeDataSet.size()) == true);
    CHECK(sorted<int>(massiveDataSet, massiveDataSet.size()) == true);
}

TEST_CASE("Selection Sort Test") {
    std::string text = "Selection";
    std::cout << "=====================================================================" << std::endl;
    std::vector<int> smallDataSet = createArray("small_data_set.txt");    //    100
    std::vector<int> mediumDataSet = createArray("medium_data_set.txt");  //  10000
    //std::vector<int> largeDataSet = createArray("large_data_set.txt");  // 100000 - takes too long

    auto start = std::chrono::high_resolution_clock::now();
    selectionSort<int>(smallDataSet, smallDataSet.size());
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << text << " Sort (small data set) time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    selectionSort<int>(mediumDataSet, mediumDataSet.size());
    end = std::chrono::high_resolution_clock::now();
    std::cout << text << " Sort (medium data set) time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    // start = std::chrono::high_resolution_clock::now();
    // selectionSort<int>(largeDataSet, largeDataSet.size());
    // end = std::chrono::high_resolution_clock::now();
    // std::cout << text <<" Sort (large data set) time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    std::cout << "=====================================================================" << std::endl;
    CHECK(sorted<int>(smallDataSet, smallDataSet.size()) == true);
    CHECK(sorted<int>(mediumDataSet, mediumDataSet.size()) == true);
    //CHECK(sorted<int>(largeDataSet,largeDataSet.size()) == true);
}

#endif