#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int len = cardPoints.size();
        int sum = 0, mysum = 0;
        int start = len - k;
        for (int i = 0; i < k; i++)
        {
            mysum += cardPoints[start+i];
        }
        sum = mysum;
        start++;
        for (int i = 0; i < k; i++)
        {
            mysum = mysum + cardPoints[(start+k-1+i)%len] - cardPoints[(start-1+i)%len];
            sum = mysum > sum ? mysum : sum;
        }
        return sum;
    }
};

int main()
{
    vector<int> cardPoints = {100,40,17,9,73,75};
    int k = 3;
    Solution solution;
    cout << solution.maxScore(cardPoints, k);
}