/**
 * @file kwikSort_iterate.cpp
 * @brief Implementation of a non-recursive (iterative) quicksort algorithm using a stack.
 *
 * @details
 * This program demonstrates an iterative version of the quicksort algorithm. 
 * It replaces recursion with an explicit stack to manage subarray partitions.
 * 
 * @author
 * - David J. Devney
 *
 * @date 2025-02-15
 * @version 1.0
 * @course CSCI 331
 *
 * @see partition()
 * @see quickSort()
 *
 * @warning Ensure sufficient stack capacity for large data sets.
 * @bug None currently known.
 * @todo Extend to support descending order sorting or custom comparators.
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * @brief Partitions a subarray around a pivot for quicksort.
 *
 * @details
 * The partition function selects a pivot value and reorders the subarray
 * such that all elements less than the pivot are moved before it, and all
 * elements greater than or equal to the pivot are moved after it.
 *
 * @param[in,out] set The vector of integers to partition.
 * @param[in] start The starting index of the subarray to partition.
 * @param[in] end The ending index of the subarray to partition.
 *
 * @pre `start` and `end` must be valid indices within the bounds of `set`.
 * @post Elements in `set` are rearranged such that all elements before
 *       the pivot are smaller and all elements after are greater or equal.
 *
 * @return The index position of the pivot after partitioning.
 *
 *
 * @see quickSort()
 * @note Uses median-of-three pivot selection for improved performance.
 */
int partition(vector<int>& set, int start, int end)
{
    int pivotValue, pivotIndex, mid;

    mid = (start + end) / 2;
    swap(set[start], set[mid]);
    pivotIndex = start;
    pivotValue = set[start];

    for (int scan = start + 1; scan <= end; scan++)
    {
        if (set[scan] < pivotValue)
        {
            pivotIndex++;
            swap(set[pivotIndex], set[scan]);
        }
    }
    swap(set[start], set[pivotIndex]);
    return pivotIndex;
}

/**
 * @brief Performs an iterative (non-recursive) quicksort on a vector.
 *
 * @details
 * This function sorts a vector of integers in ascending order using
 * the quicksort algorithm implemented with an explicit stack instead
 * of recursive function calls.
 *
 * @param[in,out] set The vector of integers to be sorted.
 * @param[in] start The starting index of the vector (typically 0).
 * @param[in] end The ending index of the vector (typically `set.size() - 1`).
 *
 * @pre `start` and `end` must be valid indices in `set`, with `start <= end`.
 * @post The vector `set` will be sorted in ascending order.
 *
 * @return void
 *
 * 
 * @see partition()
 * @test Example:
 * @code
 * vector<int> nums = {10, 7, 8, 9, 1, 5};
 * quickSort(nums, 0, nums.size() - 1);
 * // nums is now {1, 5, 7, 8, 9, 10}
 * @endcode
 */
void quickSort(vector<int>& set, int start, int end)
{
    stack<pair<int, int>> s;
    s.push({start, end});
    
    while (!s.empty()) 
    {
        int start = s.top().first;
        int end = s.top().second;
        s.pop();

        if (start < end)
        {
            int p = partition(set, start, end);

            s.push({start, p - 1});
            s.push({p + 1, end});
        }
    }
}

/**
 * @brief Entry point of the program.
 *
 * @details
 * Demonstrates the iterative quicksort algorithm by sorting a small
 * example vector and printing the results before and after sorting.
 *
 * @return Returns 0 upon successful completion.
 *
 * @see quickSort()
 * @example
 * Input:
 * @code
 * Original array: 10 7 8 9 1 5
 * Sorted array:   1 5 7 8 9 10
 * @endcode
 */
int main()
{
    vector<int> set = {10, 7, 8, 9, 1, 5};

    cout << "Original array: ";
    for (int num : set)
    {
        cout << num << " ";
    }
    cout << endl;

    quickSort(set, 0, set.size() - 1);

    cout << "Sorted array: ";
    for (int num : set)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
