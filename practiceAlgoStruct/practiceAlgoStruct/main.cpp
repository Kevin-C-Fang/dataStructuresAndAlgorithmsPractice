#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

bool linearSearch(int arr[], int arrSize);
bool binarySearch(int arr[], int arrSize);

void bubbleSort(int arr[], int arrSize);
void selectionSort(int arr[], int arrSize);
void mergeSort(int arr[], int arrSize);

void recursion(int arr[], int arrSize);

void generateArray(int arr[], int arrSize)
{
    //initialize random seed
    srand(time(NULL));
    for (int i = 0; i < arrSize; i++)
    {
        // generates rand num from 1 to 10
        int randNum = rand() % 10 + 1;
        arr[i] = randNum;
    }
}

int main()
{
    int arrSize;
    cout << "Enter number of elements for random array: ";
    cin >> arrSize;

    int* randArray = new int[arrSize];
    //int randArray[arrSize];
    generateArray(randArray, arrSize);

    string answer;
    bool tryAgain = true;

    while (tryAgain == true)
    {
        cout << "What operation would you like to do? "
            << "The options are linear, binary, bubble, selection, merge, and recursion." << endl;
        cin >> answer;

        if (answer == "linear") {
            linearSearch(randArray, arrSize);
        }
        else if (answer == "binary") {
            binarySearch(randArray, arrSize);
        }
        else if (answer == "bubble") {
            bubbleSort(randArray, arrSize);
        }
        else if (answer == "selection") {
            selectionSort(randArray, arrSize);
        }
        else if (answer == "merge") {
            mergeSort(randArray, arrSize);
        }
        else if (answer == "recursion") {
            recursion(randArray, arrSize);
        }
        else {
            cout << "You did not enter in the correct answer." << endl;
        }

        for (int i = 0; i < arrSize; i++)
        {
            cout << randArray[i] << " ";
        }

        string againAnswer;
        cout << endl << "Would you like to try again? Yes or No." << endl;
        cin >> againAnswer;
        if (againAnswer == "No")
            tryAgain = false;
    }

    delete[] randArray;

    return 0;
}


// in general the functions would use the bool return type, but i set up the functions,
// so that it gives the confirmation within the function and not the caller.
// works with unsorted and sorted arrays, but time complexity differs
bool linearSearch(int arr[], int arrSize)
{
    int searching;
    cout << "What number would you like to linear search? ";
    cin >> searching;
    cout << endl;

    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] == searching)
        {
            cout << "Found it! It was in the " << i << "th index." << endl;
            return true;
        }
    }
    cout << "Did not find it in the unsorted array." << endl;
    return false;
}

// in general the functions would use the bool return type, but i set up the functions,
// so that it gives the confirmation within the function and not the caller.
// Only works with sorted arrays
bool binarySearch(int arr[], int arrSize)
{
    int searching;
    cout << "What number would you like to binary search? ";
    cin >> searching;
    cout << endl;

    if (arrSize == 0) {
        cout << "Array has no elements to search." << endl;
        return false;
    }

    if (arr[arrSize / 2] == searching)
    {
        cout << "Found it! It was in the " << arrSize / 2 << "th index." << endl;
        return true;
    }
    else if (searching < arr[arrSize / 2])
    {
        for (int i = 0; i < (arrSize / 2); i++)
        {
            if (arr[i] == searching)
            {
                cout << "Found it! It was in the " << i << "th index." << endl;
                return true;
            }
        }
        cout << "Did not find it in the unsorted array." << endl;
        return false;
    }
    else if (searching > arr[arrSize / 2])
    {
        for (int i = (arrSize / 2); i < arrSize; i++)
        {
            if (arr[i] == searching)
            {
                cout << "Found it! It was in the " << i << "th index." << endl;
                return true;
            }
        }
        cout << "Did not find it in the unsorted array." << endl;
        return false;
    }
    return false;
}

void bubbleSort(int arr[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        for (int j = 0; j < arrSize - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int switching = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = switching;
            }
        }
    }
    cout << "Sorted array using bubble sort: ";
}

void selectionSort(int arr[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        for (int j = i + 1; j < arrSize; j++)
        {
            //int stub = arr[i];
            if (arr[i] > arr[j])
            {
                int stub = arr[i];
                arr[i] = arr[j];
                arr[j] = stub;
            }
        }
    }
    cout << "Sorted array using bubble sort: ";
}

void mergeSort(int arr[], int arrSize)
{

}

void recursion(int arr[], int arrSize)
{

}
