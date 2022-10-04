#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Initalizing variables
    const int SIZE = 4;
    string longArray =  "hemetoaklandrialtofullertonmarcolongchinofresnovallejoclovissimithousand";
    string namesArray[SIZE] = {"clovis", "vallejo", "rialto", "marco"};
    //string longArray = "sanoaklandrialtofullertonmarcolongbreacoronamodestoclovissimithousand";
    //string namesArray[SIZE] = {"brea", "modesto", "clovis", "corona"};
    //string longArray = "marcopolmonafremontrialtofullertonmarcolongfresnochinoclovissimisalinas";
    //string namesArray[SIZE] = {"fullerton", "chino", "fremont", "fresno"};
    //string longArray = "torranceoaklandrialtomarcooxnardchinofresnoirvineclovissimiorange";
    //string namesArray[SIZE] = {"oxnard", "irvine", "orange", "marco"};

    string arrayOutput[SIZE], test;
    int orderOutput[SIZE], index = 0;

    for(int i = 0; i < longArray.size(); i++){
        for(int j = 0; j < SIZE; j++){
            if(namesArray[j][0] == longArray[i] && namesArray[j][(size(namesArray[j])-1)] == longArray[(i+(size(namesArray[j])-1))])
            {
                test = "";
                for(int k = 0; k < size(namesArray[j]); k++){
                    test += longArray[(i+k)];
                }
                //cout << namesArray[j] << "\t" << test << endl;
                if(namesArray[j] == test){
                    orderOutput[index] = i;
                    arrayOutput[index] = test;
                    index++;
                }
            }
        }
    }
    for(int i = 0; i < SIZE; i++){
        cout << orderOutput[i] << "\t" << arrayOutput[i] << endl;
    }

    return 0;
}