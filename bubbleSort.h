#ifndef SORTING_BUBBLESORT_H
#define SORTING_BUBBLESORT_H
#include "printVec.h"
using namespace std;

template<typename Comparable>
void bubbleSort(vector<Comparable> vec, int &reads, int &writes) {
    int numPasses = 0;
    int i;
    Comparable temp;
    bool haveSwapped = true;
    while (haveSwapped) {
        haveSwapped = false;
        for (i = 0; i+1 < vec.size()-numPasses; i++) {
            reads += 2;
            if (vec[i] > vec[i + 1]) {
                temp = vec[i];
                ++reads;
                ++writes;
                vec[i] = vec[i + 1];
                ++reads;
                ++writes;
                vec[i + 1] = temp;
                ++reads;
                ++writes;
                // Update haveSwapped
                haveSwapped = true;
            }
        }
        // Update numPasses
        ++numPasses;
    }
    printVec(vec);
    cout <<"Reads: " + to_string(reads) << endl;
    cout<<"Writes: " + to_string(writes) << endl;
}
#endif