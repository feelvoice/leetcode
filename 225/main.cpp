class Stack {
public:
    queue<int> q[2];
    int cur, prev;
    
    Stack():cur(0), prev(1) {}
    // Push element x onto stack.
    void push(int x) {
        q[prev].push(x);
        while (!q[cur].empty()) {
            q[prev].push(q[cur].front());
            q[cur].pop();
        }
        swap(cur, prev);
    }

    // Removes the element on top of the stack.
    void pop() {
        q[cur].pop();
    }

    // Get the top element.
    int top() {
        return q[cur].front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q[cur].empty();
    }
};