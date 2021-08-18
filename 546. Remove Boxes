#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeBoxes(vector<int>& boxes)
    {
        int DP[100][100][100] = {0};

        return CalPoint(boxes, DP, 0, boxes.size() - 1, 0);
    }

    int CalPoint(vector<int> &boxes, int (*DP)[100][100], int l, int r, int k)
    {
        if (l > r)
            return 0;

        if (DP[l][r][k] != 0)
            return DP[l][r][k];

        int iCount = k;
        int i = r;
        while (i >= l && boxes[i] == boxes[r])
        {
            i--;
            iCount++;
        }

        DP[l][r][k] = max(DP[l][r][k], iCount * iCount + CalPoint(boxes, DP, l, i, 0));

        for (int j = i; j >= l; j--)
        {
            if (boxes[j] != boxes[r])    continue;
            if (boxes[j] == boxes[r] && boxes[j + 1] == boxes[r])    continue;
            DP[l][r][k] = max(DP[l][r][k], CalPoint(boxes, DP, l, j, iCount) + CalPoint(boxes, DP, j + 1, i, 0));
        }

        return DP[l][r][k];
    }

};

int main()
{
    vector<int> ListInput = { 1,2,3,3,2,2,2,3,4 };
    Solution A;

    cout << A.removeBoxes(ListInput) << endl;

    return 0;
}
