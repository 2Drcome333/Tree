#include<iostream>
using namespace std;


template<class Type>
class Comp
{
	public:
		static bool Prior(Type a,Type b);
		static void Swap(Type num[],int a,int b);
};


template<class Type>
bool Comp<Type>::Prior(Type a,Type b)
{
	if(a>b)
	{
		return true;
	}
	return false;
}


template<class Type>
void Comp<Type>::Swap(Type* num,int a,int b)
{
	Type temp=num[a];
	num[a]=num[b];
	num[b]=temp;
}




template<class Type>
class maxHeap
{
	private:
		Type* maxheap;
		int currsize;
		int maxsize;
		void siftdown(int pos);
		void BuildHeap();
	public:
		maxHeap(Type* num,int n);
		bool isLeaf(int pos);
		int leftchild(int pos);
		int rightchild(int pos);
		int parent(int pos);
		void insert(Type num);
		Type removeFirst();
		Type remove(int pos);		
		void Traversal();
};



template<class Type>
void maxHeap<Type>::siftdown(int pos)
{
	while(!isLeaf(pos))
	{
		int left=leftchild(pos),right=rightchild(pos);
		if(right<currsize&&Comp<Type>::Prior(maxheap[right],maxheap[left]))
		{
			left=right;
		}
		if(Comp<Type>::Prior(maxheap[pos],maxheap[left]))
		{
			return;
		}
		Comp<Type>::Swap(maxheap,pos,left);
		pos=left;
	}
}



template<class Type>
void maxHeap<Type>::BuildHeap()
{
	for(int i=(currsize-1-1)/2;i>=0;i--)
	{
		siftdown(i);
	}
}


template<class Type>
maxHeap<Type>::maxHeap(Type* num,int n)
{
	maxheap=num;
	currsize=n;
	BuildHeap();
}



template<class Type>
bool maxHeap<Type>::isLeaf(int pos)
{
	if(pos<currsize&&2*pos+1<currsize)
	{
		return false;
	}
	return true;
}



template<class Type>
int maxHeap<Type>::leftchild(int pos)
{
	return 2*pos+1;
}



template<class Type>
int maxHeap<Type>::rightchild(int pos)
{
	return 2*pos+2;
}



template<class Type>
int maxHeap<Type>::parent(int pos)
{
	return (pos-1)/2;
}




template<class Type>
void maxHeap<Type>::insert(Type num)
{
	int pos=currsize;
	maxheap[currsize++]=num;
	while(pos!=0)
	{
		if(Comp<Type>::Prior(maxheap[pos],maxheap[parent(pos)]))
		{
			Comp<Type>::Swap(maxheap,pos,parent(pos)); 
			pos=parent(pos);
		}
		else
		{
			return;
		}
	}
}



template<class Type>
Type maxHeap<Type>::removeFirst()
{
	if(currsize!=0)
	{
		Type temp=maxheap[0];
		Comp<Type>::Swap(maxheap,0,--currsize);
		siftdown(0);
		return temp;
	}
}


template<class Type>
Type maxHeap<Type>::remove(int pos)
{
	if(pos>currsize-1)
	{
		cout<<"The remove position is out of range"<<endl;
	}
	else
	{
		
		Type temp=maxheap[pos];
		if(pos==currsize-1)
		{
			currsize--;
		}
		else
		{
			Comp<Type>::Swap(maxheap,pos,currsize-1);
			while(pos!=0&&Comp<Type>::Prior(maxheap[pos],maxheap[parent(pos)]))
			{
				Comp<Type>::Swap(maxheap,pos,parent(pos));
				pos=parent(pos);
			}
			siftdown(pos);
			currsize--;
		}
		return temp;
	}
}


template<class Type>
void maxHeap<Type>::Traversal()
{
	for(int i=0;i<currsize;i++)
	{
		cout<<maxheap[i]<<"  ";
	}
}











int main(void)
{
	int num[5];
	for(int i=0;i<5;i++)
	{
		num[i]=i+1;
	}
	maxHeap<int> heap(num,5);
	cout<<"Current heap is:";
	heap.Traversal();
	cout<<endl<<endl<<"After we remove first node,we traversal it:";
	heap.removeFirst();
	cout<<endl<<"Current heap is:";
	heap.Traversal();
	cout<<endl<<endl<<"After we insert 2,we traversal it:";
	heap.insert(2);
	cout<<endl<<"Current heap is:";
	heap.Traversal();
	cout<<endl<<endl<<"After we remove position 3,we traversal it:";
	heap.remove(3);
	cout<<endl<<"Current heap is:";
	heap.Traversal();
	return 0;
}






