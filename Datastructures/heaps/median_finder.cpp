#include <bits/stdc++.h>
using namespace std;
//we just use two heaps(min and max) and keep pushing element into heaps
//according to requirement.
class MedianFinder
{
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    MedianFinder()
    {
        /*do nothing*/
    }
    void balance()
    {
        if (maxheap.size() > minheap.size())
        {
            while ((maxheap.size() - minheap.size()) > 1)
            {
                minheap.push(maxheap.top());
                maxheap.pop();
            }
        }
        else
        {
            while ((maxheap.size() - minheap.size()) > 1)
            {
                maxheap.push(minheap.top());
                minheap.pop();
            }
        }
    }
    void addNum(int num)
    {
        if (maxheap.empty())
            maxheap.push(num);
        else if (minheap.empty())
        {
            if (num < maxheap.top())
            {
                minheap.push(maxheap.top());
                maxheap.pop();
                maxheap.push(num);
            }
            else
                minheap.push(num);
        }
        else
        {
            if (num < findMedian())
                maxheap.push(num);
            else
                minheap.push(num);
        }
        if ((maxheap.size() - minheap.size()) > 1 || (minheap.size() - maxheap.size()) > 1)
            balance();
    }

    double findMedian()
    {
        double m1 = 0.0, m2 = 0.0;
        if (!maxheap.empty())
            m1 = maxheap.top();
        if (!minheap.empty())
            m2 = minheap.top();
        if (maxheap.size() > minheap.size())
            return m1;
        else if (minheap.size() > maxheap.size())
            return m2;
        return (m1 + m2) / 2;
    }
};