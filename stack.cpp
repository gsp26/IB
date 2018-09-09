#include<iostream>

using namespace std;


class List
{
    public:
    int data;
    List * next;
    List(int d)
    {
        data = d;
        next = NULL;
    }
};

class stack
{
    List * node;
    List * head;
    int size;
    public:
    stack(int d)
    {
        node = new List(d);
        head = node;
    }
    stack()
    {
        node = NULL;
        head = NULL;
    }
    void push(int d)
    {
        if(head == NULL) //first element
        {
            node = new List(d);
            head = node;
        }
        else
        {
            List * temp = new List(d);
            temp->next = head;
            head = temp;
        }
        size++;
    }
    int pop()
    {
        if(head == NULL)
            return -1;

        int res = head->data;
        List *temp = head;
        head = head->next;
        delete temp;
        return res;
    }
    int getSize(){return size;}
    void printStack()
    {
        List * temp = head;
        cout << "Stack elements are :- " << endl;
        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};




int main()
{
    cout << "Implementation of stack >> " << endl;
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.printStack();
    cout << "POP :  " << st.pop() << endl;
    st.printStack();


    return 0;
}

