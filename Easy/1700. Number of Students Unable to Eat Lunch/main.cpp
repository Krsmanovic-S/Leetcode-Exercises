#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> s, q;
    int fullCircle = 0, currentStudent;
    
    // Populate the two queue's with respective vectors.
    int size = students.size();
    for(int i = 0; i < size; i++)
    {
        s.push(sandwiches[i]);
        q.push(students[i]);
    }
    
    // Run until the queue is empty or we made a full circle without
    // any student taking a sandwich.
    while(!q.empty() && fullCircle <= q.size())
    {
        if(q.front() == s.front())
        {
            q.pop();
            s.pop();
            fullCircle = 0;
        }
        else
        {
            currentStudent = q.front();
            q.pop();
            q.push(currentStudent);
            fullCircle++;
        }
    }
    return q.size();
}

int main()
{
    vector<int> students = {1, 1, 0, 0}, sandwiches = {0, 1, 0, 1};
    cout << countStudents(students, sandwiches);
    
    return 0;
}