#ifndef SORTING_INSERTIONSORT_H
#define SORTING_INSERTIONSORT_H

#include "printVec.h"

template<typename Comparable>
void insertionSort(vector<Comparable> vec, int &reads, int &writes) {
    int unsortedStartIndex, insertIndex;
    reads = 0;
    writes = 0;
    Comparable toBeInserted;
    for (unsortedStartIndex = 1; unsortedStartIndex < vec.size(); ++unsortedStartIndex) {
        toBeInserted = vec[unsortedStartIndex];
        ++reads;
        ++writes;
        // Loop to shift over the larger elements
        insertIndex = unsortedStartIndex - 1;
        reads += 2;
        while (insertIndex >= 0 && vec[insertIndex] > toBeInserted) {
            vec[insertIndex + 1] = vec[insertIndex];
            ++reads;
            ++writes;
            --insertIndex;
        }
        // Put toBeInserted back into vec
        vec[insertIndex + 1] = toBeInserted;
        ++reads;
        ++writes;
    }
    printVec(vec);
    cout <<"Reads: " + std::to_string(reads) << endl;
    cout<<"Writes: " + std::to_string(writes) << endl;
}

#endif
