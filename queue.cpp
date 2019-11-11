#include<iostream>
using namespace std;

#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define MP make_pair
#define PB push_back
#define N 100001
#define HOLE 1000000007

class queue
{
    private:
        int queue_size;
        struct queue_node
        {
            ll value;
            queue_node* next_node;
            queue_node* prev_node;
        };
        queue_node* head;
        queue_node* tail;
        queue_node* make_node()
        {
            return (queue_node*)(malloc(sizeof(queue_node)));
        }
    public:
        queue()
        {
            queue_size=0;
            head=NULL;
            tail=NULL;
        }
        bool enqueue(ll data)
        {
            queue_node* new_node=make_node();
            new_node->value=data;
            new_node->next_node=NULL;
            new_node->prev_node=head;
            if(head==NULL)
            {
                tail=new_node;
                head=new_node;
            }
            else
            {
                head->next_node=new_node;
            }
            head=new_node;
            queue_size++;
            return true;
        }
        bool dequeue()
        {
            if(tail==NULL)
            {
                return false;
            }
            else
            {
                queue_node* second_last_node=tail->next_node;
                free(tail);
                if(second_last_node==NULL)
                {
                    tail=NULL;
                    head=NULL;
                }
                else
                {
                    tail=second_last_node;
                    tail->prev_node=NULL;
                }
                queue_size--;
                return true;
            }
        }
        ll front()
        {
            return tail->value;
        }
        ll back()
        {
            return head->value;
        }
        bool isEmpty()
        {
            if(queue_size==0) 
                return true;
            else 
                return false;
        }
        int size()
        {
            return queue_size;
        }
};

int main()
{
    queue q;
    
    

    return 0;
}