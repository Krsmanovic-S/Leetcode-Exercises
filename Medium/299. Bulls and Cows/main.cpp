#include <iostream>
#include <string>
#include <vector>

using namespace std;

string getHint(string secret, string guess) {
    string hint;
    int size = secret.size();
    int bulls = 0, cows = 0;
    char current, guessed;
    
    // Vectors to hold the occurence of digits in the 
    // secret and the guess for the cows calculation.
    vector<int> remainingSecret(10, 0);
    vector<int> remainingGuess(10, 0);
    
    // Bulls
    for(int i = 0; i < size; i++)
    {
        current = secret[i] - '0';
        guessed = guess[i] - '0';
    
        if(current == guessed)
        {
            bulls++;
            continue;
        }
        else
        {
            remainingSecret[current]++;
            remainingGuess[guessed]++;
        }
    }
    
    // Cows
    for(int j = 0; j < 10; j++)
    {
        current = remainingSecret[j];
        guessed = remainingGuess[j];
        
        if(current != 0 && guessed != 0)
        {
            cows += (current > guessed ? guessed : current);
        }
    }
    
    hint = to_string(bulls) + 'A' + to_string(cows) + 'B';
    return hint;
}

int main()
{
    string secret = "1807", guess = "7810";
    string result = getHint(secret, guess);

    cout << result;

    return 0;
}