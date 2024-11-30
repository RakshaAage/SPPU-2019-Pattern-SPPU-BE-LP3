// Write a program to solve a 0-1 Knapsack problem using dynamic programming
//bottom up
#include<iostream>
using namespace std;
int dp[101][1001];

class Solution
{
public:
    int knapsack(int capacity, int wt[], int val[], int n)
    {
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < capacity + 1; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }


        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < capacity + 1; j++)
            {
                if (wt[i - 1] <= j)
                {
                    int choose = val[i - 1] + dp[i - 1][j - wt[i - 1]];
                    int skip = dp[i - 1][j];
                    dp[i][j] = max(choose, skip);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][capacity];
    }
};

int main()
{
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the maximum capacity of the knapsack: ";
    cin >> capacity;

    int wt[n];
    int val[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value and weight for item " << i + 1 << ": ";
        cin >> val[i] >> wt[i];
    }

    Solution ob;
    cout << "Maximum value in 0/1 Knapsack = " << ob.knapsack(capacity, wt, val, n);
}

// Enter the number of items: 4
// Enter the maximum capacity of the knapsack: 5
// Enter value and weight for item 1: 3 2
// Enter value and weight for item 2: 4 3
// Enter value and weight for item 3: 5 4
// Enter value and weight for item 4: 6 5


// Maximum value in 0/1 Knapsack = 7
