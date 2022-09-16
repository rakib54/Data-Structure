#include <bits/stdc++.h>
using namespace std;

class Priority_queue
{
private:
    vector <int> v;
    int leftChild(int i)
    {
        return (2 * i) + 1;
    }
    int rightChild(int i)
    {
        return (2 * i) + 2;
    }
    int parent(int i)
    {
        return (i-1)/2;
    }

    void heapify(int start)
    {
        int left_index = leftChild(start);
        int right_index = rightChild(start);
        int smallest = start;
        if(left_index < v.size() && v[left_index] < v[smallest])
        {
            smallest = left_index;
        }
        if(right_index < v.size() && v[right_index] < v[smallest])
        {
            smallest = right_index;
        }
        swap(v[start], v[smallest]);

        if(start !=smallest)
        {
            heapify(smallest);
        }
    }

public:
    void push(int val)
    {
        v.push_back(val);
        int ami = v.size()-1;

        while(v[ami] < v[parent(ami)])
        {
            swap(v[ami], v[parent(ami)]);
            ami = parent(ami);
        }
    }

    void pop(){
        v[0] = v[v.size() - 1];
        v.pop_back();
        heapify(0);
    }

    int Top(){
        return v[0];
    }
    bool Empty(){
        return v.size() == 0;
    }
};

int main ()
{
    Priority_queue pq;
    pq.push(10);
    pq.push(5);
    pq.push(12);
    pq.push(1);
    pq.push(3);

    while(!pq.Empty()){
        int val = pq.Top();
        cout<<val<<" ";
        pq.pop();
    }

    return 0;
}
