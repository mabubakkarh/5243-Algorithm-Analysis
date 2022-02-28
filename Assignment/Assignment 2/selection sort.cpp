/*
	Name: Md Abubakkar
	Class: 5243 Algorithm Analysis
	Date: 25/02/2022
	PROGRAM 2: Implementing 3 sorting Algorithm
        O(n*2) sorting -- selection sort
*/


// including header files
#include<iostream>
#include<vector>
#include<iomanip>
#include <ctime>
#include<chrono>

using namespace std;
using namespace std::chrono;


/**
      * Function Name: printArray
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
      * Function Name:  swap
      *
      * Description:
      *      swap two values
      *
      * Params:
      *     - pointer of integer first
      *     - pointer of integer second
      *
      * Returns:
      *     - NULL
      */
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

/**
      * Function Name: sortArray1
      *
      * Description:
      *      sort the given array
      *
      * Params:
      *     - vector of int
      *
      * Returns:
      *     - int count
      */
int sortArray1(vector<int> &arr)
{

    int size = arr.size();
    int count,minVal,minIndx;



    // size - store the size of array
    // count - store the number of times condition is checked
    // minVal - to store the min val in each iteration
    // minIndx -to store the min index in each iteration

    count =0;
    for(int i=0;i<size;i++)  // outer loop
    {
        minVal =arr[i];
        for(int j=i+1;j<size;j++)  // inner loop
        {
            count++;
            if(arr[j]<minVal)   // condition check
            {
                minVal = arr[j];
                minIndx = j;
            }
        }

        // swapping values of arr[i] and arr[minIndx]
        swap(&arr[i],&arr[minIndx]);
    }



        return count;
}



void average20(int &totalCount ,double &totalTime)
{
    int mod = 100000;
    vector<int> arr(5000,0);
    int count =0;
    // mod - to take mode of random generated value
    //arr  - vector to store the array
    // count - to store the number of comarison

    // loop to store random values in array
    for(int i=0;i<5000;i++)
    {
        arr[i] = rand()%mod;
    }


     // starting timer
    auto start = high_resolution_clock::now();

    // calling function
    count = sortArray1(arr);

     // ending timer
    auto end = high_resolution_clock::now();

     // calculating time taken
    double time_taken = duration_cast<microseconds>(end - start).count();

    cout<<"Printing array after sorting :\n";
    printArray(arr);

    cout<<"Count :"<<count<<"\n"
        <<"Time taken :"<<time_taken<<" microseconds "<<endl;

    totalTime +=time_taken;
    totalCount += count;

}


int main()
{

    int repeat = 20;
    int totalCount =0;
    double totalTime=0;
    // repeat  - to store number of times we want to call function
    // totalCount - to store the global counter
    // totalTime - varible to store the total time taken

    // for loop to call the average20 repeat times
    for(int i=0;i<20;i++)
    {
        average20(totalCount,totalTime);
    }

    // dividing by 20 to take average
    totalCount = totalCount/20;
    totalTime = totalTime/20;

    //print the program title
    cout<<"\n Name : Md Abubakkar\n Class: 5243 Algorithm Analysis\n Date: 25/02/2022\n PROGRAM 2: Implementing 3 sorting Algorithm\n O(n*2) sorting -- selection sort\n\n";

    //print the average time and count
    cout<<"\n\nAverage Number of Count :"<<totalCount<<endl<<"Average Time Taken :"<<totalTime<<" microseconds";
}
