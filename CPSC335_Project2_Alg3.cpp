#include <iostream>
#include <vector>
using namespace std;
vector<int> mergedList;

void mergeSort(vector<int> inputVect, vector<int> inputVect2){
    if(size(mergedList) == 0) // if this is the first loop through
    {
        mergedList = inputVect;
    }
    else
    {
        vector<int> temp;
        int i = 0, j = 0;
        while(i < inputVect.size() && j < inputVect2.size()) // while haven't reached end of either input
        {
            if(inputVect[i] <= inputVect2[j])
            {
                temp.push_back(inputVect[i]);
                i++;
            }
            else
            {
                temp.push_back(inputVect2[j]);
                j++;
            }
        }
        while(i < inputVect.size())
        {
            temp.push_back(inputVect[i]);
            i++;
        }
        while(j < inputVect2.size())
        {
            temp.push_back(inputVect2[j]);
            j++;
        }
        // put the output in mergedList
        mergedList = temp;
    }
}

int main()
{ 
    vector<vector<int>> all_lists = {
        {2, 5, 9, 21},
        {-1, 0, 2},
        {-10, 81, 121},
        {4, 6, 12, 20, 150}};
    // [-10, -1, 0, 2, 2, 4, 5, 6, 9, 12, 20, 21, 81, 121, 150]
    // vector<vector<int>> all_lists = {
    //     {10, 17, 18, 21, 29},
    //     {-3, 0, 3, 7, 8, 11},
    //     {81, 88, 121, 131},
    //     {9, 11, 12, 19, 29}};
    // [-3, 0, 3, 7, 8, 9, 10, 11, 11, 12, 17, 18, 19, 21, 29, 29, 81, 88, 121, 131]
    // vector<vector<int>> all_lists = {
    //     {-4, -2, 0, 2, 7},
    //     {4, 6, 12, 14},
    //     {10, 15, 25},
    //     {5, 6, 10, 20, 24}};
    // [-4, -2, 0, 2, 4, 5, 6, 6, 7, 10, 10, 12, 14, 15, 20, 24, 25]

    int rowNum = 0;
    while(rowNum < size(all_lists))
    {
        vector<int> hold = all_lists[rowNum]; // to hold the current row
        
        mergeSort(hold, mergedList);
        
        // If last interation of while loop, print elements in mergedList
        if((rowNum+1) == size(all_lists)){
            cout << "[";
            for(int p = 0; p < mergedList.size()-1; p++){
                cout << mergedList[p] << ", ";
            }
            cout << mergedList[mergedList.size()-1] << "]" << endl;
        }
        rowNum++;
    }
   
    return 0;
}