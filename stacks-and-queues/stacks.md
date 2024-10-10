A Stack is a linear data structure that follows the **LIFO (Last-In-First-Out)** principle. Stack has one end, whereas the Queue has two ends (**front and rear**). It contains only one pointer **top pointer** pointing to the topmost element of the stack. Whenever an element is added in the stack, it is added on the top of the stack, and the element can be deleted only from the stack. In other words, a **_stack can be defined as a container in which insertion and deletion can be done from the one end known as the top of the stack._**

It uses the following operations: 
- pop() : Remove the top item from the stack. 
- push(item): Add an item to the top of the stack. 
- peek(): Return the top of the stack. 
- isEmpty(): Return true if and only if the stack is empty

Unlike an array, a stack does not offer constant-time access to the 'ith' item. However, it does allow constant time adds and removes, as it doesn't require shifting elements around.

#### Implement Stack using Queues

- Using 2 queues
```cpp
class MyStack {

    queue<int> q1; //main stack

    queue<int> q2; //helper

public:

    MyStack() {

    }

    void push(int x) {

        q2.push(x);

        while(!q1.empty()){

            int temp = q1.front();

            q1.pop();

            q2.push(temp);

        }

  

        while(!q2.empty()){

            int temp = q2.front();

            q2.pop();

            q1.push(temp);

        }

    }

    int pop() {

        int temp = q1.front();

        q1.pop();

        return temp;

    }

    int top() {

        return q1.front();

    }

    bool empty() {

        return q1.empty();

    }

};
```

- using 1 queue
```cpp
class MyStack {

    queue<int> q1; //main stack

public:

    MyStack() {

    }

    void push(int x) {

        q1.push(x);

        int size = q1.size()-1;

        while(size--){

            int temp = q1.front();

            q1.pop();

            q1.push(temp);

        }

    }

    int pop() {

        int temp = q1.front();

        q1.pop();

        return temp;

    }

    int top() {

        return q1.front();

    }

    bool empty() {

        return q1.empty();

    }

};
```

#### Implement Queue Using Stacks
```cpp
```cpp
class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {}
    void push(int x) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    int pop() {
        int temp = s1.top();
        s1.pop();
        return temp;
    }
    int peek() {
        return s1.top();
    }
    bool empty() {
        return s1.empty();
    }
};
```

#### Min Stack

```cpp
class MinStack {

    //using the formula "newVal = 2*val - mini" & "mini = 2*mini - st.top()"
    
public:

    stack<long long> st;

    long long mini;

    MinStack() {

        mini = INT_MAX;

    }

    void push(int val) {

        long long val2 = (long long) val;

        if(st.empty()){

            mini = val2;

            st.push(val2);

        }

        else{

            if(val2>mini) st.push(val2);

            else{

                st.push(2*val2*1LL - mini);

                mini = val2;

            }

        }

    }

    void pop() {

        if(st.empty()) return;

  

        long long x = st.top();

        st.pop();

        if(x<mini){

            mini = 2*mini - x;

        }

    }

    int top() {

        if(mini < st.top()) return st.top();

        return mini;

    }

    int getMin() {

        return mini;

    }

};
```

We use the formulas  `newVal = 2*val - mini` & `mini = 2*mini - st.top()`. In the second formula =, we try to calculate the previousMini that was calculated before the current mini. In this formula, the mini on the right actually represents val from the left formula, as val gets updated to mini after we calculate the newVal and push it into the stack in the new code. Similarly, as newVal is pushed into the stack, when we do st.top(), we get newVal(in case where mini is modified), and hence in the second formula, we use st.top() to correspond for newVal from the first formula. 

