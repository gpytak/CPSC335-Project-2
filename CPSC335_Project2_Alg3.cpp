#include <iostream>
#include <sstream>
#include <vector>
#include <string>
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
    int numClasses = 0, currClass = 1;

    cout << "Please enter the number of classes: ";
    cin >> numClasses;
    cin.ignore();
    while(numClasses > 0)
    {
        int x = 0, y = 0, z = 0;
        vector<int> hold;
        cout << "\nClass "<< currClass << endl;
        cout << "Input the grades in non-decreasing order, separating each grade with a comma: ";
        string grades;
        getline(cin, grades);

        while(z < grades.length())
        {
            stringstream ss;
            string temp = "";
            int index, num;
            if(isdigit(grades[z])){
                index = z;
                if(grades[z-1] == '-'){
                    index = z-1;
                }
                while(isdigit(grades[z])){
                    z++;
                }
                for(int i = index; i < z; i++){
                    temp += grades[i];
                }
                ss << temp;
                ss >> num;
                hold.push_back(num);
            }else{
                z++;
            }
        }
        all_lists.push_back(hold);
        numClasses--;
        currClass++;
    }

    int rowNum = 0;
    while(rowNum < size(all_lists))
    {
        vector<int> hold = all_lists[rowNum]; // to hold the current row
        
        mergeSort(hold, mergedList);
        
        // If last interation of while loop, print elements in mergedList
        if((rowNum+1) == size(all_lists)){
            cout << "\nOutput: [";
            for(int p = 0; p < mergedList.size()-1; p++){
                cout << mergedList[p] << ", ";
            }
            cout << mergedList[mergedList.size()-1] << "]" << endl;
        }
        rowNum++;
    }
   
    return 0;
}
