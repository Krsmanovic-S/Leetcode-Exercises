#include <iostream>
#include <string>

using namespace std;

int divisorSubstrings(int num, int k) {
    string n = to_string(num), sub = "";
    int size = n.size(), result = 0;
    
    for(int i = 0; i - 1 + k != size; i++)
    {
        sub = n.substr(i, k);
        
        while(!sub.empty() && sub[0] == '0')
            sub.erase(sub.begin());
        
        if(sub.empty())
            continue;
        else if(num % stoi(sub) == 0)
            result++;
    }
    return result;
}

int main()
{
    int num = 430043, k = 2;

    cout << divisorSubstrings(num, k);

    return 0;
}