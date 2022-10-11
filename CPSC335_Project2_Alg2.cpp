#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int SIZE = 4;
string arrayOutput[SIZE], test;
int orderOutput[SIZE], index = 0;

void findWords (string inputArray, vector<string> names)
{
    for(int i = 0; i < inputArray.size(); i++){
        for(int j = 0; j < SIZE; j++){
            // if the first and last letters of names[j] equal inputArray[i] and inputArray[i+len(names[j]-1)] respectively 
            if(names[j][0] == inputArray[i] && names[j][(size(names[j])-1)] == inputArray[(i+(size(names[j])-1))])
            {
                test = "";
                for(int k = 0; k < size(names[j]); k++){
                    if(names[j][k] != inputArray[i+k]){
                        break;
                    }
                    test += inputArray[i+k];
                }
                if(names[j] == test){
                    orderOutput[index] = i;
                    arrayOutput[index] = test;
                    index++;
                }
            }
        }
    }
}

int main()
{
    string longArray, temp;
    int numWords;
    vector<string> namesArray;

    cout << "Please enter a string of letters with words scattered in it: ";
    cin >> longArray;
    cout << "Please enter the number of words you'd like to look for: ";
    cin >> numWords;
    cout << "Please enter a list of words to find. Seperate each word by pressing enter: ";
    for(int t = 0; t < numWords; t++)
    {
        string hold;
        cin >> hold;
        namesArray.push_back(hold);
    }

    findWords(longArray, namesArray);
    
    cout << "Output_order = [";
    for(int i = 0; i < SIZE; i++){
        cout << orderOutput[i];
        if(i < SIZE-1)
            cout << ", ";
    }
    cout << "]" << endl << "Output_array = [";
    for(int i = 0; i < SIZE; i++){
        cout << "'" << arrayOutput[i] << "'";
        if(i < SIZE-1)
            cout << ", ";
    }   
      
    cout << "]" << endl;

    return 0;
}