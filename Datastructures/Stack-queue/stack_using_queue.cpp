//stack implemented using two queue's
//from gfg
void push(struct Queue *q1,struct Queue *q2,int num)
{
    //code here
    if(isEmpty(q1))
    {
        enqueue(q1,num);
    }
    else
    {
        while(!isEmpty(q1))
        {
            enqueue(q2,front(q1));
            dequeue(q1);
        }
        enqueue(q1,num);
        while(!isEmpty(q2))
        {
            enqueue(q1,front(q2));
            dequeue(q2);
        }
    }
}

//Function to pop an element from stack using two queues. 
int pop(struct Queue *q1)
{
    //code here
    int ele=-1;
    if(!isEmpty(q1))
    {
        ele=front(q1);
        dequeue(q1);
    }
    return ele;
}