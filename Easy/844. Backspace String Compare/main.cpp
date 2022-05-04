#include <iostream>
#include <string>

bool backspaceCompare(std::string& s, std::string& t) {
    int size_1 = s.length(), size_2 = t.length();
    
    for(int i = 0; i < size_1; i++)
    {
        if(s[i] == '#')
        {
            if(i - 1 >= 0)
            {
                s.erase(s.begin() + i);
                s.erase(s.begin() + i - 1);
                size_1--;
                i -= 2;
            }
            else
            {
                s.erase(s.begin() + i);
                size_1--;
                i--;
            }
        }
    }
    
    for(int i = 0; i < size_2; i++)
    {
        if(t[i] == '#')
        {
            if(i - 1 >= 0)
            {
                t.erase(t.begin() + i);
                t.erase(t.begin() + i - 1);
                size_2--;
                i -= 2;
            }
            else
            {
                t.erase(t.begin() + i);
                size_2--;
                i--;
            }
        }
    }        
    return s == t ? true : false;
}

int main()
{
    std::string s = "y#fo##f", t = "y#f#o##f";
    std::cout << std::boolalpha;
    std::cout << backspaceCompare(s, t);
    
    return 0;
}