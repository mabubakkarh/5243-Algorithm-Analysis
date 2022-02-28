/*
	Name: Md Abubakkar
	Class: 5243 Algorithm Analysis
	Date: 25/02/2022
	PROGRAM 2: Implementing 3 sorting Algorithm
        O(n) sorting   -- Counting Sort
*/




// including header files
#include<iostream>
#include<vector>
#include<iomanip>
#include<chrono>

using namespace std;
using namespace std::chrono;

/**
      * Function name: printArray
      *
      * Description:
      *      print the given array
      *
      * Params:
      *     - vector of int
      *
      * Returns:
      *     - NULL
      */
void printArray(vector<int> arr)
{
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl<<endl;
}


/**
      * Function name:sortArray3
      *
      * Description:
      *      sort the given array in O(n)
      *
      * Params:
      *     - vector of int
      *     - maximum value of array
      *
      * Returns:
      *     - counter to count number of comparison
      */

int sortArray3(vector<int> &arr,int maxNum)
{
    vector<int> sortedArr(maxNum+1,0);
    int temp =0,counter =0;
    int val;
    int size = arr.size();

    // sortedArr - vector to store the count of each occurrence of a number in array
    // temp - temporary variable
    // counter - to count the number of comparison
    // size - to store the size of array


    // loop to store the occurrence of a number in array
    for(int i=0;i<size;i++)
    {
        sortedArr[arr[i]] += 1;
    }

    // outer loop to refill the array
    for(int i=0;i<=maxNum;i++)
    {
        counter++;
        if(sortedArr[i]>0)
        {
            // inner loop for duplicate varibles
            for(int j=0;j<sortedArr[i];j++)
            {
                arr[temp] = i;
                temp++;
            }

        }
    }

    // return counter
    return counter;
}

/**
      * Function name: sortingHelper
      *
      * Description:
      *      call the sorting3 function
      *      calculate time taken
      *      calculate counter
      *
      * Params:
      *     - vector of int
      *     - maximum value of array
      *
      * Returns:
      *     - counter to count number of comparison
      */
void sortingHelper(int &totalCount ,int &totalTime)
{
    int mod = 100000;
    vector<int> arr(5000,0);
    int counter =0;
    int maxNum =0;
    // mod - to take mode of random generated value
    //arr  - vector to store the array
    // counter - to store the number of comarison
    // maxNum - int to store maximum number in array

    // loop to store random values in array
    for(int i=0;i<5000;i++)
    {
        arr[i] = rand()%mod +100000;

        if(arr[i]>maxNum)   maxNum = arr[i];
    }


    // starting timer
    auto start = high_resolution_clock::now();

    // calling function
    counter = sortArray3(arr,maxNum);

    // ending timer
    auto end = high_resolution_clock::now();

    // calculating time taken
    auto time_taken = duration_cast<microseconds>(end - start).count();

    // printing array
    cout<<"Printing array after sorting :\n";
    printArray(arr);

    totalTime +=time_taken;
    totalCount += counter;

}


int main()
{

    int repeat = 20;
    int totalCount =0;
    int totalTime=0;
    // repeat  - to store number of times we want to call function
    // totalCount - to store the global counter
    // totalTime - variable to store the total time taken

    // for loop to call the average20 repeat times
    for(int i=0;i<20;i++)
    {
        sortingHelper(totalCount,totalTime);
    }

    // dividing by 20 to take average
    totalCount = totalCount/20;
    totalTime = totalTime/20;

     //print the header
	cout<<"\n Name : Md Abubakkar\n Class: 5243 Algorithm Analysis\n Date: 25/02/2022\n PROGRAM 2: Implementing 3 sorting Algorithm\n O(n) sorting  -- Counting Sort\n\n";
	
    // printing answer
    cout<<"Average Number of Count :"<<totalCount<<endl
        <<"Average Time Taken :"<<totalTime<<" microseconds ";
}
