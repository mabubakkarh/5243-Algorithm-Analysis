/*
	Name: Md Abubakkar
	Class: 5243 Algorithm Analysis
	Date: 25/02/2022
	PROGRAM 2: Implementing 3 sorting Algorithm
        O(nlogn) sorting  -- Quick sort
*/




// including header files
#include<iostream>
#include<vector>
#include<iomanip>
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


// declaring global veriables
int cnt=0,swapno=0;

/**
      * Function Name: swap
      *
      * Description:
      *      swap two numbers
      *
      * Params:
      *     - int * a - pointer of variable first
      *     - int * b - pointer of variable second
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
      * Function Name: partation
      *
      * Description:
      *      partition the array
      *
      * Params:
      *     - vector of int
      *     - int to store left index
      *     - int to store right index
      *
      * Returns:
      *     - int the exact position of number
      */
int partation(vector<int> &arr,int l,int r)
{
    int pivot =arr[r];
    int p=l,i;

    // loop from left to right
    for(i=p;i<r;i++)
    {
        if(arr[i]<pivot)
        {
            // calling swap function
            if(i!=p)    swap(&arr[p],&arr[i]),swapno++;
            p++;
            // incrementing the counter
            cnt++;
        }
    }
     if(r!=p) swap(&arr[p],&arr[r]),swapno++;

     // returning the index
    return p;
}

void sortArray2(vector<int> &arr,int l,int r)
{
    // return if left is grater then right
    if(l>=r)    return;

    // calling partation function
    int p =partation(arr,l,r);

    // sorting both the parts except the position p
    sortArray2(arr,l,p-1);
    sortArray2(arr,p+1,r);
}


void average20(int &totalCount ,double &totalTime)
{
    cnt =0;
    int mod = 10000;
    vector<int> arr(5000,0);
    // cnt - initialize global variable to zero to start from it
    // mod - to take mode of random generated value
    //arr  - vector to store the array
    //start, end - time_t to store the starting and ending timer

    // loop to store random values in array
    for(int i=0;i<5000;i++)
    {
        arr[i] = rand()%mod;
    }


    // starting timer
    auto start = high_resolution_clock::now();

    // calling function
    sortArray2(arr,0,arr.size()-1);

    // ending timer
    auto end =high_resolution_clock::now();

    // calculating time taken
    double time_taken = duration_cast<microseconds>(end - start).count();

    cout<<"Printing array after sorting :\n";
    printArray(arr);

    cout<<"Count :"<<cnt<<"\n"
        <<"Time taken :"<<time_taken<<" Microseconds"<<endl;

    totalTime +=time_taken;
    totalCount += cnt;

}


int main()
{

    int repeat = 20;
    // repeat  - to store number of times we want to call function
    int totalCount =0;
    double totalTime=0;

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
    cout<<"\n Name : Md Abubakkar\n Class: 5243 Algorithm Analysis\n Date: 25/02/2022\n PROGRAM 2: Implementing 3 sorting Algorithm\n O(nlogn) sorting  -- Quick sort\n\n";

    //print the average count and time	
    cout<<" Average Number of Count :"<<totalCount<<endl<<" Average Time Taken :"<<totalTime<<" microseconds";
}
