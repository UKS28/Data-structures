#include <iostream> 
#include <bits/stdc++.h>
using namespace std;

class minheap{
    public:

    vector<int> v;
    int cap=0;  // capacity
    
    int parent(int i) 
    {
        return (i-1)/2;
    }

    int left(int i)
    {
        return (2*i+1);
    }

    int right(int i)
    {
        return (2*i+2);
    }

   void print()
   {
    for(int i=0;i<cap;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
   }
};



//insert bottom to top
//correct
void insert(int val, minheap & h)
{
   h.cap++;
   h.v.push_back(val);
   int idx=h.cap-1;
   int par=h.parent(idx);

   while(idx>0 && h.v[idx] < h.v[par])
   {
    swap(h.v[idx],h.v[par]);
    idx=h.parent(idx);
    par=h.parent(idx);
   }
}

//compare with both childrens
//correct
void heapify(int i, minheap &h)
{
    int l=h.left(i);
    int r=h.right(i);
    int mn_idx=i;
    if(h.v[mn_idx]>h.v[l])mn_idx=l;
    if(h.v[mn_idx]>h.v[r])mn_idx=r;

    if(mn_idx!=i && mn_idx<h.cap)
    {
        swap(h.v[mn_idx],h.v[i]);
        heapify(mn_idx,h);
    }
}

//correct
int extractMin(minheap &h)
{
    if(h.cap==0)return -1;
    if(h.cap==1){h.cap--;return h.v[h.cap];}

    swap(h.v[0],h.v[h.cap-1]);
    h.cap--;
    //h.print();
    heapify(0,h);
    return h.v[h.cap];
    
}

void decrease(int i,int x,minheap& h)
{
   h.v[i]=x;
   int idx= i;
    int par=h.parent(idx);

   while(idx>0 && h.v[idx] < h.v[par])
   {
    swap(h.v[idx],h.v[par]);
    idx=h.parent(idx);
    par=h.parent(idx);
   }
   
}

//correct
void delet(int i,minheap &h)
{
  h.v[i] = INT_MIN;
    int idx= i;
    int par=h.parent(idx);

   while(idx>0 && h.v[idx] < h.v[par])
   {
    swap(h.v[idx],h.v[par]);
    idx=h.parent(idx);
    par=h.parent(idx);
   }

  extractMin(h);

}



int main()
{
  minheap heap;
    insert(2,heap);
     heap.print();
    insert(3,heap);
     heap.print();
    insert(4,heap);
     heap.print();
    insert(5,heap);
     heap.print();
    insert(6,heap);
     heap.print();
    insert(1,heap);
     heap.print();
    insert(12,heap);

    heap.print();
    delet(3,heap);// take index as parameter
    heap.print();

    decrease(4,0,heap);
    heap.print();


}





