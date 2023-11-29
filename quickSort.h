#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "printVec.h"

template<typename Comparable>
void quickSortUnstableRec(vector<Comparable> &vec, int startIndex, int endIndex) {
    int reads, writes = 0;
    // Recursive base case
    if (startIndex >= endIndex) {
        return;
    }

    // Choose a partition element
    Comparable partition = vec[startIndex];
    ++reads;
    ++writes;

    // Loop through vec from startIndex to endIndex
    // Keep track of where the > partition elements start
    int i;
    int largerElementIndex = startIndex+1;
    Comparable temp;
    for (i = startIndex+1; i <= endIndex; ++i) {
        reads+=2;
        if (vec[i] <= partition) {
            // Swap the smaller/equal item to the left of the larger items
            temp = vec[i];
            ++reads;
            ++writes;
            vec[i] = vec[largerElementIndex];
            ++reads;
            ++writes;
            vec[largerElementIndex] = temp;
            ++reads;
            ++writes;
            // Update largerElementIndex
            ++largerElementIndex;
        }
    }
    // Swap the partition element into place
    temp = vec[startIndex];
    ++reads;
    ++writes;
    vec[startIndex] = vec[largerElementIndex-1];
    ++reads;
    ++writes;
    vec[largerElementIndex-1] = temp;
    ++reads;
    ++writes;

    printVec(vec);

    // Recursive calls for two halves
    quickSortUnstableRec(vec, startIndex, largerElementIndex-2);
    quickSortUnstableRec(vec, largerElementIndex, endIndex);
}

template<typename Comparable>
void quickSortUnstable(vector<Comparable> vec) {
    quickSortUnstableRec(vec, 0, vec.size() - 1);
}

template<typename Comparable>
void quickSortStableRec(vector<Comparable> &vec) {
    int reads, writes = 0;
    // Recursive base case
    reads +=2;
    if (vec.size() <= 1) {
        return;
    }

    // Choose a partition element
    Comparable partition = vec[0];
    ++reads; //vec[0]
    ++writes; //partition

    vector<Comparable> smaller, equal, larger;
    ++writes;
    ++writes;
    ++writes; //three in a row for smaller, equal and larger
    // Loop through vec and populate smaller, equal, larger
    int i;
    for (i = 0; i < vec.size(); ++i) {
        reads +=2;
        if (vec[i] < partition) {
            ++reads;
            ++reads;
            smaller.push_back(vec[i]);
            ++reads;
            ++writes;
        } else if (vec[i] > partition) {
            reads += 2;
            larger.push_back(vec[i]);
            ++reads;
            ++writes;
        } else {
            equal.push_back(vec[i]);
            ++reads;
            ++writes;
        }
    }

    // Recursive calls
    quickSortStableRec(smaller);
    quickSortStableRec(larger);

    // Copy elements from smaller, equal, and larger back into vec
    for (i = 0; i < vec.size(); ++i) {
        if (i < smaller.size()) {
            vec[i] = smaller[i];
            ++reads;
            ++writes;
        } else if (i < smaller.size() + equal.size()) {
            vec[i] = equal[i - smaller.size()];
            ++reads;
            ++writes;
        } else {
            ++reads;
            vec[i] = larger[i - smaller.size() - equal.size()];
            ++reads;
            ++writes;
        }
    }
    printVec(vec);
    cout <<"Reads: " + std::to_string(reads) << endl;
    cout<<"Writes: " + std::to_string(writes) << endl;
}

template<typename Comparable>
void quickSortStable(vector<Comparable> vec) {
    quickSortStableRec(vec);
}

#endif