#include <iostream>
using namespace std;

//binary max heap implementation

class BinaryHeap
{
private:
	int* heap;
	int size;//current size
	int capacity;//max capacity

public:
	//constructor
	BinaryHeap(int c)
	{
		capacity = c;
		size = 0;
		heap = new int[capacity];
	}
	//to get to parent of a node
	int parent(int i)
	{
		return (i - 1) / 2;
	}
	//to get to left child of a node
	int left(int i)
	{
		return 2 * i + 1;
	}
	//to get to right child of a node
	int right(int i)
	{
		return 2 * i + 2;
	}
	//inserting new value to heap tree
	void insert(int value)
	{
		if (size == capacity)
		{
			cout << "Maximum capacity is reached.";
			return;
		}
		//store the index of the new insertion
		int i = size;
		//inserting new value in the leftmost lowest slot
		heap[size++] = value;
		//bubble up to maintain the heap property
		while (i != 0 && heap[parent(i)] < heap[i]) 
		{
			//swap i with its parent
			int temp = heap[i];
			heap[i] = heap[parent(i)];
			heap[parent(i)] = temp;
			i = parent(i);
		}
	}
	//top down approach for maintainig heap property
	void MaxHeapify(int i) 
{
		int l = left(i);
		int r = right(i);
		int largest = i;

		if (l < size && heap[l] > heap[i])
			largest = l;
		if (r < size && heap[r] > heap[largest])
			largest = r;

		if (largest != i) {
			//swap A[i] and A[largest]
			int temp = heap[i];
			heap[i] = heap[largest];
			heap[largest] = temp;
			MaxHeapify(largest);
		}
	}
	
	//returns the item with the maximum key value
	int findMax()
	{
		//max value is at root
		return heap[0];
	}
	//deletes the max key value
	int delMax()
	{
		int maxValue = heap[0];
		heap[0] = heap[--size];
		MaxHeapify(0);
		return maxValue;
	}
	//checks if heap is empty
	bool isEmpty()
	{
		return size == 0;
	}
	//return the no of items in the heap
	int findSize()
	{
		return size;
	}
	//converts a given arbitrary array of size n into a max-heap
	void buildMaxHeap()
	{
		//starting index
		int n = (size - 2) / 2;
		//reverse level order traversal and heapifying each node
		for (int i = n; i >= 0; i--)
		{
			MaxHeapify(i);
		}
	}

};

int main() 
{
	BinaryHeap bh(10);

	bh.insert(3);
	bh.insert(4);
	bh.insert(5);
	cout << "Max after insertions: " << bh.findMax() << endl;  // should output 5

	cout << "Max deleted: " << bh.delMax() << endl;  // should output 5
	cout << "New Max: " << bh.findMax() << endl;  // should output 4

	cout << "Is empty (before clearing): " << bh.isEmpty() << endl; // should output 0 (False)
	bh.delMax();
	bh.delMax();
	cout << "Is empty (after clearing): " << bh.isEmpty() << endl;  // should output 1 (True)

	cout << "Size: " << bh.findSize() << endl; // should output 0 since the heap is empty
	bh.insert(10);
	bh.insert(20);
	cout << "Size after 2 insertions: " << bh.findSize() << endl; // should output 2

	int arr[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
	for (int i = 0; i < 8; i++) {
		bh.insert(arr[i]);
	}
	bh.buildMaxHeap();
	cout << "Max after building heap: " << bh.findMax() << endl;  // should output 9

	return 0;
}
