#include <iostream>
#include <string>
#include <queue>

using namespace std;

string predictPartyVictory(string senate) {
    queue<int> dire, radiant;
    
    // Loop throught the string and push
    // indexes of the string in the two queues
    // depending on who we found(dire or radiant).
    for (int i = 0; i < senate.length(); i++) 
    {
        if (senate[i] == 'R') 
            radiant.push(i);
        else
            dire.push(i);
    }
    
    int radiantIndex, direIndex;
    while (!radiant.empty() && !dire.empty()) 
    {
        // We are keeping track of the front
        // of the queue, thats so we get the
        // senator decisions in order.
        radiantIndex = radiant.front();
        direIndex = dire.front();
        
        // Pop them off, they have been selected.
        radiant.pop(), dire.pop();
        
        // Now find who went first, that one goes to
        // the back of his respected queue and gets 
        // a new index.
        if(radiantIndex < direIndex)
            radiant.push(radiantIndex + senate.length());
        else
            dire.push(direIndex + senate.length());
    }
    
    return (radiant.empty() ? "Dire" : "Radiant");
}

int main()
{
    string senate = "RDRDDDDDRDRRRRRDRDRDRDDDDRRRRRRRR";
    cout << predictPartyVictory(senate);

    return 0;
}