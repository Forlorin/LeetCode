#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        if (m == 0)
        {
            nums1 = nums2;
        }
        else if (n != 0)
        {
            nums1.erase(nums1.begin() + m, nums1.end());
            int i = 0, j = 0;
            while (i < nums1.size() && j < n)
            {
                if (nums2[j] < nums1[i])
                {
                    nums1.insert(nums1.begin() + i, nums2[j]);
                    j++;
                    i++;
                }
                else
                {
                    i++;
                }
            }
            if (j<n)
            {
                nums1.insert(nums1.end(), nums2.begin()+j,nums2.begin()+n);
            }
        }
    }
};

int main(){
    vector<int> n1 = {4,0,0,0,0,0}, n2 = {1,2,3,5,6};
    int m = 1, n = 5;
    Solution solution;
    solution.merge(n1, m, n2, n);
    for (vector<int>::iterator it = n1.begin(); it != n1.end(); it ++){
        cout<<*it<<'\t';
    }
}

