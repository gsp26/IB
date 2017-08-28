/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) – Push element x onto stack.
pop() – Removes the element on top of the stack.
top() – Get the top element.
getMin() – Retrieve the minimum element in the stack.
Note that all the operations have to be constant time operations.

Questions to ask the interviewer :

Q: What should getMin() do on empty stack? 
A: In this case, return -1.

Q: What should pop do on empty stack? 
A: In this case, nothing. 

Q: What should top() do on empty stack?
A: In this case, return -1
 NOTE : If you are using your own declared global variables, make sure to clear them out in the constructor. 
 */
 
 int stackMin = -1;
int top= -1;
vector<int> st;
vector<int> mini;
MinStack::MinStack() {
    if(stackMin !=-1)
        stackMin = -1;
    st.clear();
    mini.clear();
    ::top = -1;
    
}

void MinStack::push(int x) {
    if(st.empty())
    {
        //stackMin = x;
        mini.push_back(x);
        st.push_back(x);
        ::top = 0;
        return;
    }
 
    if(x < mini[mini.size()-1])
        mini.push_back(x);
    st.push_back(x);
    ::top++;
}

void MinStack::pop() {
    if(st.empty())
        return;
    int s = st.size();
    int x = st[s-1];
    st.erase(st.begin()+s-1);
    ::top--;
    if( x== mini[mini.size()-1])
    {
        mini.erase(mini.begin()+mini.size()-1);
        
    }
        
}

int MinStack::top() {
    if(st.empty())
        return -1;
    return st[::top];
}

int MinStack::getMin() {
    if(st.empty())
        return -1;
    return mini[mini.size()-1];
}

