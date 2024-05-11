// who_to_hire.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        double sum = 0, result = INT_MAX;
        vector<pair<double, int>> details;
        for (int i = 0; i < n; i++) {
            details.push_back({ wage[i] / (double)quality[i],quality[i] });
        }
        sort(details.begin(), details.end());
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            pq.push(details[i].second);
            sum += details[i].second;
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == k) {
                result = min(result, sum * details[i].first);
            }
        }
        return result;
    }

int main()
{
    vector<int> quality;
    quality.push_back(3);
    quality.push_back(1);
    quality.push_back(10);
    quality.push_back(10);
    quality.push_back(1);
    vector<int> wage;
    wage.push_back(4);
    wage.push_back(8);
    wage.push_back(2);
    wage.push_back(2);
    wage.push_back(7);
    cout << mincostToHireWorkers(quality, wage, 3);
    return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
