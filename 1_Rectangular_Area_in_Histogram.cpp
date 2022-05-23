// C++ program to find maximum rectangular area in
// linear time
#include <bits/stdc++.h>
using namespace std;

// The main function to find the maximum rectangular
// area under given histogram with n bars
int getMaxArea(int hist[], int n)
{
    stack<int> s;
    int max_area = 0; // Initialize max area
    cout << "initally max_area=" << max_area << endl;
    int tp; // To store top of stack
    cout << "initally tp=" << tp << endl;
    int area_with_top; // To store area with top bar
    cout << "initally area_with_top=" << area_with_top << endl;
    int i = 0;
    cout << "initally i=" << i << endl;
    while (i < n)
    {
        if (s.empty() || hist[s.top()] <= hist[i])
        {
            s.push(i++);
            cout << "i= " << i << endl;
        }
        else
        {
            tp = s.top(); // store the top index
            s.pop();      // pop the top
            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
            cout << "after area_with_top= " << area_with_top << endl;
            if (max_area < area_with_top)
            {
                max_area = area_with_top;
                cout << "after max_area= " << max_area << endl;
            }
        }
    }

    // Now pop the remaining bars from stack and calculate
    // area with every popped bar as the smallest bar
    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
        cout << "after area_with_top= " << area_with_top << endl;
        if (max_area < area_with_top)
        {
            max_area = area_with_top;
            cout<<"after max_area= "<<max_area<<endl;
        }
    }

    return max_area;
}

// Driver program to test above function
int main()
{
    int hist[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(hist) / sizeof(hist[0]);
    cout << "Maximum area is " << getMaxArea(hist, n);
    return 0;
}
