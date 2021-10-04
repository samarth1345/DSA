void push(int x)
{
    // Your Code
    if(s1.empty())
    {
        s1.push(x);
    }
    else
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
}

//Function to pop an element from queue by using 2 stacks.
int pop()
{
        // Your Code 
        int ret=-1;
        if(!s1.empty())
        {
            ret=s1.top();
            s1.pop();
        }
        return ret;
}