#include <iostream>
#include <string>
#include <vector>

std::string format_duration(int seconds) {

    // Check if input is 0
    if(seconds == 0)
        return "now";

    std::string result;

    // Initialize all the variables we need
    int second = 0, minutes = 0, hours = 0, days = 0, years = 0;
    int temp = seconds;

    // Minutes
    while(temp >= 60)
    {
        temp -= 60;
        minutes++;
    }

    // What's left is seconds
    second = temp;

    // Hours
    while(minutes >= 60)
    {
        minutes -= 60;
        hours++;
    }

    // Days
    while(hours >= 24)
    {
        hours -= 24;
        days++;
    }

    // Years
    while(days >= 365)
    {
        days -= 365;
        years++;
    }

    // Vector that will hold non-zero values
    std::vector<int> vector1;

    // Format the first part of the result
    if(years != 0)
    {
        vector1.push_back(years);
        
        if(years == 1)
            result += std::to_string(years) + " year, ";
        else
            result += std::to_string(years) + " years, ";
    }

    if(days != 0)
    {
        vector1.push_back(years);

        if(days == 1)
            result += std::to_string(days) + " day, ";
        else
            result += std::to_string(days) + " days, ";
    }

    if(hours != 0)
    {
        vector1.push_back(years);

        if(hours == 1)
            result += std::to_string(hours) + " hour, ";
        else
            result += std::to_string(hours) + " hours, ";
    }

    if(minutes != 0)
    {
        vector1.push_back(years);

        if(minutes == 1)
            result += std::to_string(minutes) + " minute, ";
        else
            result += std::to_string(minutes) + " minutes, ";
    }

    if(second != 0)
    {
        vector1.push_back(years);

        if(second == 1)
            result += std::to_string(second) + " second, ";
        else
            result += std::to_string(second) + " seconds, ";
    }

    // Delete the last two characters since 
    // they are a comma and a space
    result.pop_back();
    result.pop_back();

    // Find how many commas they are in result,
    // store their indexes in commaIndex
    int commaCount = 0;
    std::vector<int> commaIndex;

    for(int i = 0; i < result.size(); i++)
    {
        if(result[i] == ',')
        {
            commaCount++;
            commaIndex.push_back(i);
        }
    }

    if(commaCount != 0)
    {
        // indexLast represents the index of the last comma
        // in result, that's the one we are targeting
        int indexLast = commaIndex[commaIndex.size() - 1];

        // Delete the comma and replace it with " and"
        result.erase(indexLast, 1);
        result.insert(indexLast, " and");
    }

    std::cout << "Result is: " << result;

    return result;
}

int main()
{
    int example = 25654646;

    format_duration(example);

    return 0;
}