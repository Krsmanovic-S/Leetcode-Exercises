#include <iostream>
#include <string>

using namespace std;

string interpret(string command) {
    string result;
    
    for(int i = 0; i < command.length(); i++)
    {
        // Handles the brackets.
        if(command[i] == '(' && command[i + 1] == ')')
        {
            result += "o"; 
            i++;
        }
        // If there is no brackets then just add that char.
        else if(command[i] != '(' && command[i] != ')')
            result += command[i];
    }
    return result;
}

int main()
{
    string command = "G()()()()(al)";
    cout << interpret(command);
    
    return 0;
}