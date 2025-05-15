#include "heap.h"
#include <climits>

//constructor that allocates and initializes heap arrays
MinHeap::MinHeap(int capacity)
{
	this->capacity = capacity;
	size = 0;

	heapArray = new int[capacity];
	keyArray = new int[capacity];
	position = new int[capacity];

	for (int i = 0; i < capacity; i++)
    {
		heapArray[i] = i;
		keyArray[i] = INT_MAX;
		position[i] = i;
	}

	size = capacity;
}

//deconstructor to free memory
MinHeap::~MinHeap()
{
	delete[] heapArray;
	delete[] keyArray;
	delete[] position;
}

//swaps two values
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

//maintains min heap property by pushing down the element at idx
void MinHeap::minHeapify(int idx)
{
	int smallest = idx;
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;

	//if left child is smaller than the current smallest
	if (left < size && keyArray[heapArray[left]] < keyArray[heapArray[smallest]])
    {
		smallest = left;
	}

	//if right child is smaller than the current smallest
	if (right < size && keyArray[heapArray[right]] < keyArray[heapArray[smallest]])
    {
		smallest = right;
	}

	//if the smallest is not the current node, swap and continue heapifying
	if (smallest != idx)
    {
		int smallestVertex = heapArray[smallest];
		int idxVertex = heapArray[idx];

		swap(position[smallestVertex], position[idxVertex]);
		swap(heapArray[smallest], heapArray[idx]);

		minHeapify(smallest);
	}
}

//removes and returns the vertex with the smallest key value
int MinHeap::extractMin()
{
	//if heap is empty, return -1
	if (size <= 0)
    {
		return -1;
	}

	int root = heapArray[0];
	int lastNode = heapArray[size - 1];

	heapArray[0] = lastNode;
	position[root] = size - 1;
	position[lastNode] = 0;

	size--;
	minHeapify(0);

	return root;
}

//updates the key value of a vertex and fixes its position in the heap
void MinHeap::decreaseKey(int vertex, int newKey)
{
	int i = position[vertex];
	keyArray[vertex] = newKey;

	//while current key is less than its parent's key, bubble up
	while (i > 0 && keyArray[heapArray[i]] < keyArray[heapArray[(i - 1) / 2]])
    {
		int parentIdx = (i - 1) / 2;
		int parentVertex = heapArray[parentIdx];

		swap(position[vertex], position[parentVertex]);
		swap(heapArray[i], heapArray[parentIdx]);

		i = parentIdx;
	}
}

//returns true if vertex is still in heap
bool MinHeap::isInMinHeap(int vertex)
{
	return position[vertex] < size;
}

//returns true if heap is empty
bool MinHeap::isEmpty()
{
	return size == 0;
}