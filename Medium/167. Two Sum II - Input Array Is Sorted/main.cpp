#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int size = numbers.size();
    vector<int> result;
    int start = 0, end = size - 1;
    
    while(start <= end)
    {
        // If this ever checks we have found what we needed.
        if(numbers[start] + numbers[end] == target)
        {
            result.push_back(start + 1);
            result.push_back(end + 1);
            return result;
        }
        
        // Move the two pointers accordingly. We can 
        // do this because the array is sorted.
        if(target - numbers[start] < numbers[end])
            end--;
        if(target - numbers[start] > numbers[end])
            start++;
    }  
    return result;
}

int main()
{
    vector<int> numbers = {2 ,7 , 11, 15};
    int target = 9;

    vector<int> result = twoSum(numbers, target);
    for(auto x : result)
        cout << x << " ";

    return 0;
}