//
// Created by sasha on 11/8/2022.
//
#ifndef TWOSORT_H
#define TWOSORT_H
#include "printVec.h"
#include <vector>
#include "air_pollution.h"
#include "selectionSort.h"

template <typename Comparable>
void twoSort(vector<Comparable> &vec, int &reads, int &writes) {
    cout << "sort by selection" << endl;
    selectionSort(vec, reads, writes);
    cout << "sort by insertion" << endl;
    secondSort(vec, reads, writes);
}
//second sort method is just insertion method but Airpollution data type
void secondSort(vector<Air_Pollution> vec, int &reads, int &writes) {
    int unsortedStartIndex, insertIndex;
    Air_Pollution toBeInserted;
    for (unsortedStartIndex = 1; unsortedStartIndex < vec.size(); ++unsortedStartIndex) {
        toBeInserted = vec[unsortedStartIndex];
        ++reads;
        ++writes;
        // Loop to shift over the larger elements
        insertIndex = unsortedStartIndex - 1;
        reads += 2;
        while (insertIndex >= 0 && toBeInserted.getNo2() < vec[insertIndex].getNo2()) {
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
#endif //TWOSORT_H
