#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include "air_pollution.h"
#include "selectionSort.h"
#include "mergeSort.h"
#include "bubbleSort.h"
#include "heapSort.h"
#include "twoSort.h"
using namespace std;
using namespace chrono;


int main() {
    //initialize clock
    steady_clock clock;
    //initialize read
    int reads = 0;
    int writes = 0;
    //air_pollution vector
    vector<Air_Pollution> APVector = vector<Air_Pollution>();
    //load in csv
    string fn = "../air_pollution.csv";
    loadFile(fn, APVector);
    //shuffle
    shuffle(APVector.begin(), APVector.end(), default_random_engine(0));
    //check if vector prints ok (it does)
    //printVec(APVector);
    for (int i=1000; i>99; i-=100){
        cout << "---vector size: " + to_string(i) + "---" << endl;
        APVector.resize(i);
        //printVec(APVector);

        cout << "---bubblesort---" << endl;
        reads = 0;
        writes = 0;
        auto start = clock.now(); //start time
        bubbleSort(APVector, reads, writes);
        auto end = clock.now();
        auto length = static_cast<chrono::duration<double>>(end - start);
        cout << "this took: " << length.count() << " seconds" << endl;


        cout << "---mergesort---" << endl;
        reads = 0;
        writes = 0;
        start = clock.now();
        mergeSort(APVector, reads, writes);
        end = clock.now();
        length = static_cast<chrono::duration<double>>(end - start);
        cout << "this took: " << length.count() << " seconds" << endl;


        cout << "---selectionsort---" << endl;
        reads = 0;
        writes = 0;
        start = clock.now();
        selectionSort(APVector, reads, writes);
        end = clock.now();
        length = static_cast<chrono::duration<double>>(end - start);
        cout << "this took: " << length.count() << " seconds" << endl;


        cout << "---heapsort---" << endl;
        reads = 0;
        writes = 0;
        start = clock.now();
        heapSort(APVector, reads, writes);
        end = clock.now();
        length = static_cast<chrono::duration<double>>(end - start);
        cout << "this took: " << length.count() << " seconds" << endl;

        cout << "---twosort---" << endl;
        reads = 0;
        writes = 0;
        start = clock.now();
        twoSort(APVector, reads, writes);
        end = clock.now();
        length = static_cast<chrono::duration<double>>(end - start);
        cout << "this took: " << length.count() << " seconds" << endl;
    }



    return 0;

}