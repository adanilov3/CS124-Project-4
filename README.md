# CS 124 Project 4

For this project, you will sort the 1000 objects from your data set. You will modify each sorting algorithm to collect data. You will analyze the results from the different sorting algorithms.

## Implement
You should have your 1000+ objects stored in a vector, initially unsorted.
Use these five sorting algorithms:
1. Bubble Sort
2. Selection Sort or Insertion Sort
3. Merge Sort or Quick Sort
4. Heap Sort
5. Two-sort: sort by any algorithm (except Bubble Sort), then sort on a different field using a stable sorting algorithm (again, except Bubble Sort).
   * Hint for implementing two-sort: for the second stable algorithm, make a copy of the stable sorting function and take out the template part. That way you will be able to call a getter on your custom-type objects to compare a second field of your class.

Modify each sorting algorithm to record the number of reads. This is the number of times you use a Comparable object. This could be using it to store somewhere else, using it to compare to another object, etc. Temporary Comparable objects count towards the reads. 
* Example code:
  ```cpp
  if (vec[i] > vec[i+1]) // This counts as two reads, which should
      // be counted whether the if statements evaluates to true or false.
  Comparable temp = vec[i]; // This is one read.
  smaller.push_back(vec[i]); // This is one read.
  ```
Modify each sorting algorithm to record the number of writes. This is the number of times you assign into a Comparable object. This could be to store a temporary Comparable, to overwrite an item in a Comparable vector, to push_back onto a Comparable vector, etc.
* Example code:
  ```cpp
  Comparable temp = vec[i]; // This is one write (and one read).
  smaller.push_back(vec[i]); // This is one write (and one read).
  vec[i] = vec[i+1]; // This is one write (and one read).
  ```
Use a loop to record the number of reads and writes needed to sort a vector of size 100, 200, 300, 400, 500, 600, 700, 800, 900, and 1000.
* Hint: start with 1000 and then use the resize method to make it smaller. 

Keep all output in the console (and not files). Each of the five sorting algorithms should be given identical unsorted vectors to begin with. 
* If your data is already sorted by the attribute you use to overload your operators, change how you overload your operators.

## Extra Credit
To earn up to 10 extra credit points (at the grader’s discretion), you can get more thorough results. This can include, but is not limited to:
* Setting timers to record how long it takes you to sort the objects with each algorithm.
* Performing the same experiment, except double the size of the data set each time (instead of having it grow linearly).
* Using more sorting algorithms.

Note that if you add this logic to your code but do not analyze it in your report, it will not count towards extra credit. If you complete extra credit, analyze it in this section of your README.md file.

## Report
Include the following in this section of your README.md file:
* Information about your data set (you will be assigned a different grader for this project).
* About this file
  Dataset is about what is the level of Air Pollution around the globe. The dataset contains 10 columns. These columns are as follows:
Country Name - It includes the names of the countries.
City - It includes the name of the town.
Year - It includes the year in which data is.
PM2.5 (μg/m3) - The Particulate Matter 2.5 pollution level in micrograms per cubic meter.
PM10 (μg/m3) - The Particulate Matter is 10 levels in microgram per cubic meter.
NO2 (μg/m3) - The Nitrogen Dioxide level in microgram p per cubic meter.
Updated Year - Year in which data is updated.
Id - # of row
* Analyze the data. Graph the number of reads and writes for each sorting algorithm and look at how the number of reads and writes grows when the size of the data set grows. Compare and contrast the different sorting algorithms and draw conclusions about which sorting algorithms are more efficient. Discuss complexities and their effects.
* ![bubble sort](charts/bubble sort.png)
  ![merge sort](charts/merge sort.png)
  ![selection sort](charts/selection.png)
  ![heap sort](charts/heap.png)
  ![two sort](charts/twosort.png)
* bubble sort - time: O(N^2) auxiliary: O(1)
* selection sort - time: O(N^2) auxiliary: O(1)
* merge sort - time: O(logN) auxiliary: O(N)
* heap sort - time: O(N log N) auxiliary: O(1)
* comparing all the graphs and timers, it seems that selection sort would be the most efficient as it has the least writes per vector and took the shortest amount of time for the vector of 1000 objects.
* Answers to the following questions: 
  * If you need to sort a contacts list on a mobile app, which sorting algorithm(s) would you use and why? 
  * I would use insertion sort as it works very well on smaller data sets, and is built one entry at a time.
  * What about if you need to sort a database of 20 million client files that are stored in a datacenter in the cloud?
  * i would use merge sort as it works well for very large datasets and its average complexity will be much lower for 20 million.

**Note: Any code that was not authored by yourself or the instructor must be cited in your report. This includes the use of concepts not taught in lecture.**

## Submit
You must include your source (all .cpp and .h) files, your data (.csv) file(s), CMakeLists.txt, and your updated README.md file that contains your report to your repository. Submit to Gradescope using the GitHub repository link, double-check that all the correct files are there, and wait for the autograder to provide feedback.

## Grading
The project is out of 90 points.

| Points Possible | Description of requirement |
|------------------- | ----------------------------- |
| 5 pts | Program compiles and runs. |
| 5 pts | Code style. Readable, naming style is consistent, comments where appropriate. |
| 5 pts | Use five sorting algorithms according to the directions above. |
| 15 pts | Sort the 100, 200, … 1000 objects according to the directions above. |
| 40 pts | Record the correct number of reads and writes for each sort. |
| 20 pts | Report: content, formatting, professional, grammatically correct, cites sources. |