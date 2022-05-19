#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string times(string num1, char ch) {
    string result = "";
    int carry = 0, sum, currentDigit = ch - '0';

    // Go from the end of the bigger number(in our case num1)
    // and do the multiplication of num1 with the current digit
    // from num2.
    for(int i = num1.length() - 1; i >= 0; i--)
    {
        sum = int(num1[i] - '0') * currentDigit + carry;
        result = to_string(sum % 10) + result;
        carry = sum / 10;                
    }

    if(carry)
        result = to_string(carry) + result;
    return result;
}

string add(string num1, string num2) {
    // Indexes should start at the 
    // last char of each string.
    int i = num1.size() - 1, j = num2.size() - 1, carry = 0, sum;
    string result = "";
    
    // Adding two strings together, loop until
    // all indexes have reached -1 and carry
    // is equal to 0.
    while(i >= 0 || j >= 0 || carry)
    {
        sum = 0;
        if(i >= 0) 
        {
            sum += (num1[i] - '0'); 
            i--;
        }
        if(j >= 0) 
        {
            sum += (num2[j] - '0'); 
            j--;
        }
        
        sum += carry;
        carry = sum / 10;
        result += to_string(sum % 10);
    }
    
    // Remember to reverse the string at the end.
    reverse(result.begin(),result.end());
    return result;          
}

string multiply(string num1, string num2) {
    if(num1.length() < num2.length())
        swap(num1, num2);

    string result = "", x, n;

    // Loop through the shorter string and call the
    // appropriate functions.
    for(int i = 0; i < num2.length(); i++)
    {
        // This is so that we add zeroes to the end of
        // num1 depending on what i is.
        n = num1 + string(i, '0');

        x = times(n, num2[num2.length() - 1 - i]);
        result = add(result, x);                
    }

    return result[0] == '0' ? "0" : result;
}

int main()
{
    string num1 = "123", num2 = "456";
    cout << multiply(num1, num2);

    return 0;
}