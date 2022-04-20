#include <iostream>
#include <vector>

std::pair<std::size_t, std::size_t> two_sum(const std::vector<int>& numbers, int target) {
    
    size_t index1, index2;

    for(size_t i = 0; i < numbers.size(); i++)
    {
        int tempNumber = numbers[i];
        for(size_t j = 0; j < numbers.size(); j++)
        {
            if(numbers[j] != tempNumber)
            {
                if(numbers[j] + tempNumber == target && i != j)
                {
                    index1 = i;
                    index2 = j;
                }
            }
        }
    }
    std::pair<std::size_t, std::size_t> result { index1, index2 };

    return result;
}

int main()
{
    auto result = two_sum({1, 2, 3}, 4);

    return 0;
}