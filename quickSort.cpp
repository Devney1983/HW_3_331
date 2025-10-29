/**
 * @file kwikSort_iterate.cpp
 * @brief Iterative implementation of the QuickSort algorithm using an explicit stack.
 *
 * This program demonstrates a non-recursive (iterative) version of QuickSort.
 * Instead of recursive calls, it uses a stack of index pairs to manage
 * subranges that need sorting. This approach prevents stack overflow for
 * large datasets while maintaining the average-case time complexity
 * of O(n log n).
 *
 * The program reads a sequence of integers, sorts them in ascending order,
 * and displays the result.
 *
 * @course CSCI 330
 * @date 2025-02-15
 * @version 1.0
 * @author
 * David J. Devney
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * @brief Partitions a subrange of a vector around a pivot element.
 *
 * The partition function chooses a pivot and rearranges elements in the range
 * `[start, end]` so that all elements less than the pivot appear before it, and
 * all elements greater appear after it. The function returns the final position
 * of the pivot.
 *
 * @param set The vector of integers being sorted.
 * @param start The starting index of the subrange.
 * @param end The ending index of the subrange.
 * @return The final index position of the pivot element.
 *
 * @pre `0 <= start <= end < set.size()`
 * @post Elements before the returned index are ≤ pivot; elements after are ≥ pivot.
 */
int partition(vector<int>& set, int start, int end)
{
    // Choose the middle element as pivot to reduce likelihood of worst-case
    int mid = (start + end) / 2;
    swap(set[start], set[mid]);

    int pivotValue = set[start];
    int pivotIndex = start;

    // Reorder elements based on pivot value
    for (int scan = start + 1; scan <= end; ++scan)
    {
        if (set[scan] < pivotValue)
        {
            ++pivotIndex;
            swap(set[pivotIndex], set[scan]);
        }
    }

    // Move pivot into its correct sorted position
    swap(set[start], set[pivotIndex]);
    return pivotIndex;
}

/**
 * @brief Sorts a vector of integers using an iterative QuickSort algorithm.
 *
 * The function uses a stack to simulate the recursive behavior of QuickSort.
 * Each stack entry represents a subrange `[start, end]` of the vector that
 * still needs sorting. When a range is processed, the pivot is partitioned,
 * and the left and right subranges (if any) are pushed back onto the stack.
 *
 * @param set Reference to the vector of integers to sort.
 * @pre The vector must contain comparable elements.
 * @post The vector is sorted in ascending order.
 * @exception none
 */
void kwikSort_iterate(vector<int>& set)
{
    // Stack holds subrange boundaries (start, end)
    stack<pair<int, int>> indexStack;

    // Initialize with full range
    indexStack.push({0, static_cast<int>(set.size()) - 1});

    // Process until all subranges are sorted
    while (!indexStack.empty())
    {
        auto [start, end] = indexStack.top();
        indexStack.pop();

        // Only process ranges with more than one element
        if (start < end)
        {
            int pivot = partition(set, start, end);

            // Push left subrange if it has two or more elements
            if (pivot - 1 > start)
                indexStack.push({start, pivot - 1});

            // Push right subrange if it has two or more elements
            if (pivot + 1 < end)
                indexStack.push({pivot + 1, end});
        }
    }
}

/**
 * @brief Demonstrates the iterative QuickSort algorithm on a sample dataset.
 *
 * The user can modify the initial vector to test different datasets.
 *
 * @return EXIT_SUCCESS when sorting completes successfully.
 */
int main()
{
    // Example dataset to be sorted
    vector<int> data = {10, 7, 8, 9, 1, 5};

    cout << "Before sorting: ";
    for (int num : data) cout << num << " ";
    cout << endl;

    // Perform iterative QuickSort
    kwikSort_iterate(data);

    cout << "After sorting:  ";
    for (int num : data) cout << num << " ";
    cout << endl;

    return EXIT_SUCCESS;
}
