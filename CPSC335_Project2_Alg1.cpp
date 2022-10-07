#include <iostream>
#include <string>
using namespace std;

string runEncode (string input)
{
    string encoded;
    int repeat = 0, index = 0;
     for(int i = 0; i < input.size(); i++){
        if(input[i] == input[i+1]){
            index = i;
            while(input[index] == input[i])
            {
                repeat++;
                i++;
            }
            i--;
            string num = to_string(repeat);
            encoded += num + input[index];
            repeat = 0;
        }
        else{
            encoded += input[i];
        }
    }
    return encoded;
}

int main()
{
    // Initialize variables
    string input, output;
    int check = 0;

    // User inputs string
    cout << "Input a string of lowercase letters: ";
    getline(cin, input);

    // Check input for uppercase or digit violations
    while(check < input.size())
    {
        if(isupper(input[check]) || isdigit(input[check]))
        {
            cout << "Input a string of lowercase letters: ";
            getline(cin, input);
            check = 0;
        }else{
            check++;
        }
    }

    output = runEncode(input);

    // Print ouput
    cout << "Output: " << output << endl;

    return 0;
}