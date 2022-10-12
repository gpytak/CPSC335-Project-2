#include <iostream>
#include <string>
#include <vector>
using namespace std;


string test;
vector<string> arrayOutput;
vector<int> orderOutput;


void findWords (string inputArray, vector<string> names, int words)
{
    for(int i = 0; i < inputArray.size(); i++){
        for(int j = 0; j < words; j++){
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
                    orderOutput.push_back(i);
                    arrayOutput.push_back(test);
                }
            }
        }
    }
}

int main()
{

    string longArray, temp, hold = "";

    int numWords = 0;
    vector<string> namesArray;

    cout << "Please enter a string of letters with words scattered in it: ";
    getline(cin, longArray);

    cout << "Please enter a comma seperated list of words to search for: ";
    getline(cin, temp);
    for(int t = 0; t < temp.size(); t++)
    {
        if(temp[t] != ',' && temp[t+1] != ' ')

        {
            hold += temp[t];
        }
        else
        {
            namesArray.push_back(hold);

            hold = "";
            numWords++;
            t++;
        }
    }
    namesArray.push_back(hold);
    numWords++;

    findWords(longArray, namesArray, numWords);
    
    cout << "Output_order = [";
    for(int i = 0; i < numWords; i++){
        cout << orderOutput[i];
        if(i < numWords-1)
            cout << ", ";
    }
    cout << "]" << endl << "Output_array = [";
    for(int i = 0; i < numWords; i++){
        cout << "'" << arrayOutput[i] << "'";
        if(i < numWords-1)
            cout << ", ";
    }   
      
    cout << "]" << endl;

    return 0;
}