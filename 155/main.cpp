class MinStack {
public:

    stack<int> si, msi;
    void push(int x) {
        si.push(x);
        if (msi.empty()) {
            msi.push(x);
        }
        else {
            msi.push(min(x, msi.top()));
        }
    }

    void pop() {
        si.pop();
        msi.pop();
    }

    int top() {
        return si.top();
    }

    int getMin() {
        return msi.top();
    }
};