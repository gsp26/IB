#include<iostream>
#include<climits>

using namespace std;

//prototype of utility function to swap to integers
void swap(int *x, int *y);

//A class for Min Heap
class MinHeap
{
	int * harr; // pointer to array of elements in heap
	int capacity; // max possible size of heap
	int heap_size; // current number of elements in heap

	public:
	//constructor
	MinHeap(int capacity);

	//to heapify a sub tree with the root at a given index
	void MinHeapify(int);

	int parent(int i) {return (i-1)/2;}

	//to get left child of the node at index i
	int left(int i) {return 2*i+1; }

	//to get right child of the node at index i 
	int right(int i) { return 2*i+2;}

	//to extract the root which is the minimum element
	int extractMin();

	//decrease a key stored at index i
	void decreaseKey(int i,int new_val);

	//returns the minimum key(key at root) from min heap
	int getMin() { return harr[0];}

	//delete a key stored at index i
	void deleteKey(int i);

	//insert a new key
	void insertKey(int k);
};

//contructor : builds a heap from a given a[] of given size
MinHeap::MinHeap(int cap)
{
	heap_size = 0;
	capacity = cap;
	harr = new int[cap];
}

void MinHeap::insertKey(int k)
{
	if(heap_size == capacity)
	{
		cout << "\n Over FLow could not insertKey" << endl;
		return;
	}

	//first insert the new key at the end
	heap_size++;
	int i=heap_size-1;
	harr[i] = k;

	//Fix the heap property if it is violated 
	while(i!= 0 && harr[parent(i)] > harr[i])
	{
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
}

//decrease value of key at index i to new_val. it is assumed
//that new_val is smaller than harr[i]
void MinHeap::decreaseKey(int i, int new_val)
{
	harr[i] = new_val;
	while(i !=0 && harr[parent(i)] > harr[i])
	{
		swap(&harr[i],&harr[parent(i)]);
		i = parent(i);
	}
}

//method to remove minimum element (or root ) from min Heap
int MinHeap::extractMin()
{
	if(heap_size <= 0)
		return INT_MAX;
	if(heap_size == 1)
	{
		heap_size--;
		return harr[0];
	}

	//store the minimum value and remove it from heap
	
	int root = harr[0];
	harr[0]  = harr[heap_size-1];
	heap_size--;
	MinHeapify(0);

	return root;
}

//This function deletes key at index i . it firxt reduces the vlaue to 
//minus infinite, then calls extract min

void MinHeap::deleteKey(int i)
{
	decreaseKey(i,INT_MIN);
	extractMin();
}

//A recursive function to heapify a subtree with the root at given index	
//this method assumes that the subtree are already heapified
void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if(l < heap_size  && harr[l] < harr[i])
		smallest  = l;
	if(r < heap_size && harr[r] < harr[smallest])
		smallest = r;

	if(smallest != i)
	{
		swap(&harr[i],&harr[smallest]);
		MinHeapify(smallest);
	}
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
	MinHeap h(11);
	h.insertKey(3);
	h.insertKey(2);
	h.deleteKey(1);
	h.insertKey(15);
	h.insertKey(5);
	h.insertKey(4);
	h.insertKey(45);

	cout << h.extractMin() << " ";
	cout << h.getMin() << " ";

	h.decreaseKey(2,1);

	cout << h.getMin() ; 
	return 0;
}



