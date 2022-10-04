#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Initialize variables
    string input, output;
    int check, repeat = 0, index;

    // User inputs string
    cout << "Input a string of lowercase letters: ";
    cin >> input;

    // Check input for uppercase or digit violations
    while(check < input.size())
    {
        if(isupper(input[check]) || isdigit(input[check]))
        {
            cout << "Input a string of lowercase letters: ";
            cin >> input;
            check = 0;
        }else{
            check++;
        }
    }

    // Find input for repeated characters
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
            output += num + input[index];
            repeat = 0;
        }
        else{
            output += input[i];
        }
    }

    // Print ouput
    cout << "Output: " << output << endl;

    return 0;
}