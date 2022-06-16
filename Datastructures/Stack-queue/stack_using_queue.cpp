//stack implemented using one queue
MyStack() {
        
    }
    void push(int x) {
        Main.push(x);
        for(int i=0;i<Main.size()-1;i++){
            Main.push(Main.front());
            Main.pop();
        }
    }
    int pop() {
        int temp=top();
        Main.pop();
        return temp;
    }
    int top() {
        return Main.front();
    }
    bool empty() {
        return Main.empty();
    }
