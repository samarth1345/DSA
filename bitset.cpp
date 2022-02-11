#include <bits/stdc++.h>
using namespace std;
class Bitset
{
public:
    unordered_set<int> ones;
    int size;
    bool flag;
    Bitset(int size)
    {
        this->size = size;
        flag = false;
    }

    void fix(int idx)
    {
        if (flag)
        {
            if (ones.find(idx) != ones.end())
                ones.erase(idx);
        }
        else
        {
            if (ones.find(idx) == ones.end())
                ones.insert(idx);
        }
    }

    void unfix(int idx)
    {
        if (flag)
        {
            if (ones.find(idx) == ones.end())
                ones.insert(idx);
        }
        else
        {
            if (ones.find(idx) != ones.end())
                ones.erase(idx);
        }
    }

    void flip()
    {
        flag = !flag;
    }

    bool all()
    {
        if (flag)
            return ones.size() == 0;
        return ones.size() == size;
    }

    bool one()
    {
        if (!flag)
            return ones.size() >= 1;
        return ones.size() < size;
    }

    int count()
    {
        if (flag)
            return size - ones.size();
        return ones.size();
    }

    string toString()
    {
        string ans = "";
        if (flag)
        {
            for (int i = 0; i < size; i++)
            {
                if (ones.find(i) != ones.end())
                    ans += "0";
                else
                    ans += "1";
            }
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                if (ones.find(i) != ones.end())
                    ans += "1";
                else
                    ans += "0";
            }
        }
        return ans;
    }
};