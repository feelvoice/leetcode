class Queue {
public:
    stack<int> sta[2];
    int cur, prev;

    Queue():cur(0), prev(1) {}
    
    // Push element x to the back of queue.
    void push(int x) {
        while (!sta[cur].empty()) {
            sta[prev].push(sta[cur].top());
            sta[cur].pop();
        }
        sta[cur].push(x);
        while (!sta[prev].empty()) {
            sta[cur].push(sta[prev].top());
            sta[prev].pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        sta[cur].pop();
    }

    // Get the front element.
    int peek(void) {
        return sta[cur].top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return sta[cur].empty();
    }
};