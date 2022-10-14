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
    vector<vector<int>> all_lists;
    int numClasses = 0;
    //int numRows = 0, temp;
    //bool input = true;
    //vector<vector<int>> all_lists = {
    //    {2, 5, 9, 21},
    //    {-1, 0, 2},
    //    {-10, 81, 121},
    //    {4, 6, 12, 20, 150}};
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

    //cout<< "Please enter the classes grades in non-decreasing order, seperating each grade with an enter." << endl
    //    << "Seperate each class by pressing enter without inputting a grade." << endl
    //    << "When finished, please press enter again: ";

    //Doesn't work, keep getting read access violations.
    //Also doesn't work if I try and read it in like a string and turn that into an int
    //At this rate, might need to do the merge as we read in the user input

    //while(true)
    //{
    //    for(int i = 0; ; i++)
    //    {
    //        cin >> temp;
    //        if(!temp)
    //            break;
    //        all_lists[numRows].push_back(temp);
    //    }
    //    if(!cin)
    //        break;
    //    numRows++;
    //}
    cout << "Please enter the number of classes: ";
    cin >> numClasses;
    while(numClasses > 0)
    {
        int x = 0, y = 0, z = 0;
        vector<int> hold;
        cout << "Please input the number of grades this class has: ";
        cin >> y;
        while(y <= 0)
        {
            cout << "Please input a positive number for the number of class grades: ";
            cin >> y;
        }
        cout << "Now please input the grades in non-decreasing order, seperating each grade with the enter key." << endl;    
        while(z < y)
        {
            cin >> x;
            hold.push_back(x);
            z++;
        }
        all_lists.push_back(hold);
        numClasses--;
        //numRows++;
    }
    
    

    //all_lists.push_back(hold);

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