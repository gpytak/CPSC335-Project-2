#include <iostream>
#include <string>
using namespace std;

const int SIZE = 4;
string arrayOutput[SIZE], test;
int orderOutput[SIZE], index = 0;

void findWords (string inputArray, string *names)
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
    // Initalizing variables
    //string longArray =  "hemetoaklandrialtofullertonmarcolongchinofresnovallejoclovissimithousand";
    //string namesArray[SIZE] = {"clovis", "vallejo", "rialto", "marco"};
    string longArray = "sanoaklandrialtofullertonmarcolongbreacoronamodestoclovissimithousand";
    string namesArray[SIZE] = {"brea", "modesto", "clovis", "corona"};
    //string longArray = "marcopolmonafremontrialtofullertonmarcolongfresnochinoclovissimisalinas";
    //string namesArray[SIZE] = {"fullerton", "chino", "fremont", "fresno"};
    //string longArray = "torranceoaklandrialtomarcooxnardchinofresnoirvineclovissimiorange";
    //string namesArray[SIZE] = {"oxnard", "irvine", "orange", "marco"};

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