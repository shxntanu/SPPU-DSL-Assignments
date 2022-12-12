#include <iostream>
using namespace std;

template <typename P>
struct item
{
    P data;
    int priority;
};

template <typename T>
class Priority
{
    public:
    item<T> pqueue[100];
    int size = -1;

    void enqueue(T d, int p)
    {
        size++;
        pqueue[size].data = d;
        pqueue[size].priority = p;
    }

    int peek()
    {
        int max = 0;
        for(int i=0;i<=size;i++)
        {
            if(pqueue[i].priority > pqueue[max].priority)
                max = i;
        }
    }

    int dequeue()
    {
        int max = peek();
        int temp = pqueue[max].data;
        for(int i=max;i<size;i++)
            pqueue[i] = pqueue[i+1];
        size--;
        return temp;
    }
};

int main()
{
    cout<<"int Queue or float Queue? (1/2): ";
    int choice;
    cin>>choice;
    if (choice==1)
    {
        Priority<int> p;
        int n;
        cout<<endl<<"Enter number of elements: ";
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int d, pri;
            cout<<"Enter data and priority: ";
            cin>>d>>pri;
            p.enqueue(d,pri);
        }
        
    }
    return 0;
}