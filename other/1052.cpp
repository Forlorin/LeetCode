#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int t = 0, bestT = 0;
        int sum = 0;
        int newSum = 0;
        for (int i = t; i < minutes + t; i++)
        {
            sum += customers[i] * grumpy[i];
        }
        t = 1;
        newSum = sum;
        int time = customers.size();
        while (t < time - minutes+1)
        {
            int end = t + minutes - 1;
            newSum = newSum + customers[end] * grumpy[end] - customers[t - 1] * grumpy[t - 1];
            if (newSum > sum)
            {
                bestT = t;
                sum = newSum;
            }
            t++;
        }
        sum = 0;
        for (int i = 0; i < time; i++)
        {
            if (i >= bestT && i < bestT + minutes)
            {
                sum += customers[i];
            }
            else
            {
                sum += (grumpy[i] == 1) ? 0:customers[i];
            }
        }
        return sum;
    }
};

int main()
{
    vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5}, grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
    int minutes = 3;
    Solution solution;
    cout << solution.maxSatisfied(customers, grumpy, minutes);
}