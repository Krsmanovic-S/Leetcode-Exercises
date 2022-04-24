#include <unordered_map>
#include <string>

using namespace std;

class UndergroundSystem {
private:
// Key for first map is the id, for the second its
// a string representing starting + ending station name.
unordered_map<int, pair<string, int>> checkInTime;
unordered_map<string, pair<long long, int>> totalTime;

public:
    UndergroundSystem() {
        totalTime.clear();
        checkInTime.clear();
    }

    void checkIn(int id, string stationName, int t) {
        // Only map the check-ins that we don't already
        // have.
        if(checkInTime.find(id) != checkInTime.end()) 
            return;
        else
            checkInTime[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        // First parameter is the station from which the person
        // came from, second is the time when they came to the station.
        auto& info = checkInTime[id];
        
        int timePassed = t - info.second;
        string key = info.first + ":" + stationName;
        
        // If time for this customer already exists,
        // we want to adjust it according to timePassed.
        if(totalTime.find(key) != totalTime.end()) 
        {
            auto& oldTime = totalTime[key];
            oldTime.first += timePassed;
            oldTime.second++;
        } 
        // Otherwise we just assign it as the end time,
        // with a starting time of 1 second.
        else
            totalTime[key] = {timePassed, 1};
        
        // Erase this id from the check-ed in people since
        // they just checked-out.
        checkInTime.erase(id);
    }

    double getAverageTime(string startStation, string endStation) {
        // Exercise said this will always exist when the function is
        // called so no need to do any checks, just use the key and get
        // the average time.
        string key = startStation + ":" + endStation;
        return double(totalTime[key].first) / double(totalTime[key].second);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

int main()
{
    return 0;
}