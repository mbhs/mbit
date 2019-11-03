#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<string, int> strToInt = {{"January", 1}, {"February", 2}, {"March", 3}, {"April", 4}, {"May", 5}, {"June", 6},
    {"July", 7}, {"August", 8}, {"September", 9}, {"October", 10}, {"November", 11}, {"December", 12}};
    unordered_map<int, string> intToStr = {{1, "January"}, {2, "February"}, {3, "March"}, {4, "April"}, {5, "May"}, {6, "June"},
    {7, "July"}, {8, "August"}, {9, "September"}, {10, "October"}, {11, "November"}, {12, "December"}};

    int n;
    map<pair<int, int>, set<string>> calendar;
    unordered_map<string, pair<int, int>> query;
    cin >> n;
    for (int i=0; i<n; i++) {
        string op, eventName;
        cin >> op >> eventName;
        if (op == "ADD") {
            string month;
            int day;
            cin >> month >> day;
            if (!query.count(eventName)) {
                pair<int, int> date = make_pair(strToInt[month], day);
                calendar[date].insert(eventName);
                query.insert(make_pair(eventName, date));
            }
        } else if (op == "DELETE") {
            calendar[query[eventName]].erase(eventName);
            query.erase(eventName);
        } else if (op == "RESCHEDULE") {
            string month;
            int day;
            cin >> month >> day;
            if (query.count(eventName)) {
                pair<int, int> date = make_pair(strToInt[month], day);
                calendar[query[eventName]].erase(eventName);
                calendar[date].insert(eventName);
                query[eventName] = date;
            }
        } else {
            if (query.count(eventName)) {
                pair<int, int> date = query[eventName];
                cout << intToStr[date.first] << " " << date.second << endl;
            } else
                cout << "NOT SCHEDULED" << endl;
        }
    }

    bool first = true;
    for (auto day : calendar)
        for (string event : day.second) {
            if (first) first = false;
            else cout << " ";
            cout << event;
        }
    cout << endl;

    return 0;
}