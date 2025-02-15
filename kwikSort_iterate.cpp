# HW_3_331

/* quickSort without recursion. 
   02/15/2025
   David J. Devney
   CSCI 331
*/

#include <iostream>
#include <stack>
#include <vector>


using namespace std;




// Function for partition.
int partition(vector<int>& set, int start, int end)
{
    int pivotValue, pivotIndex, mid;

    mid = (start + end) / 2;
    swap(set[start], set[mid]);
    pivotIndex = start;
    pivotValue = set[start];

        for(int scan = start + 1; scan <= end; scan++)
        {
            if(set[scan] < pivotValue)
            {
                pivotIndex++;
                    swap(set[pivotIndex], set[scan]);
            }
        }
        swap(set[start], set[pivotIndex]);
        return pivotIndex;

}

// Non-recursive quicksort using stack
void quickSort(vector<int>& set, int start, int end) 
{
    stack<pair<int, int>> s;
    s.push({start, end});
    
    while (!s.empty()) {
        // Pop the current subarray's indices
        int start = s.top().first;
        int end = s.top().second;
        s.pop();

        if (start < end) 
        {
            // Perform partition
            int p = partition(set, start, end);

            // Push subarray indices to stack
            s.push({start, p - 1});
            s.push({p + 1, end});
        }
    }
}
    

int main()
{
    // Example array to sort
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



