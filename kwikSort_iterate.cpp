/**
 * @file kwikSort_iterate.cpp
 * @brief Implementation of a non-recursive (iterative) quicksort algorithm using a stack.
 *
 * @details
 * This program demonstrates an iterative version of the quicksort algorithm. 
 * It replaces recursion with an explicit stack to manage subarray partitions.
 * The user enters how many integers to sort and then the integers themselves.
 * The program displays the original array and the sorted array in ascending order.
 * 
 * @author
 * - David J. Devney
 *
 * @date 2025-02-15
 * @version 1.1
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
 * @param[in,out] set The vector of integers to partition.
 * @param[in] start The starting index of the subarray to partition.
 * @param[in] end The ending index of the subarray to partition.
 *
 * @return The index position of the pivot after partitioning.
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
 * @param[in,out] set The vector of integers to be sorted.
 * @param[in] start The starting index of the vector (typically 0).
 * @param[in] end The ending index of the vector (typically `set.size() - 1`).
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
 * @brief Entry point of the program with user interaction.
 *
 * @details
 * Prompts the user to enter the number of integers to sort,
 * then reads the integers, displays the original list,
 * sorts it using iterative quicksort, and displays the sorted result.
 *
 * @return Returns 0 upon successful completion.
 */
int main()
{
    int n;
    cout << "Enter the number of elements to sort: ";
    cin >> n;

    // Validate input
    if (n <= 0)
    {
        cerr << "Error: The number of elements must be positive." << endl;
        return 1;
    }

    vector<int> set(n);
    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> set[i];
    }

    cout << "\nOriginal array:" << endl;
    for (int num : set)
    {
        cout << num << " ";
    }
    cout << endl;

    quickSort(set, 0, set.size() - 1);

    cout << "\nSorted array (ascending):" << endl;
    for (int num : set)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
