
// C++ program for the
// above approach
#include <bits/stdc++.h>
using namespace std;

// Structure for the heap
struct Heap {
	vector<int> v;
	int n; // Size of the heap

	Heap(int i = 0)
		: n(i)
	{
		v = vector<int>(n);
	}
};

// Generic function to
// swap two integers
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

// Returns the index of
// the parent node
inline int parent(int i)
{
	return (i - 1) / 2;
}

// Returns the index of
// the left child node
inline int left(int i)
{
	return 2 * i + 1;
}

// Returns the index of
// the right child node
inline int right(int i)
{
	return 2 * i + 2;
}

// Maintains the heap property
void heapify(Heap& h, int i)
{
	int l = left(i), r = right(i), m = i;
	if (l < h.n && h.v[i] < h.v[l])
		m = l;
	if (r < h.n && h.v[m] < h.v[r])
		m = r;
	if (m != i) {
		swap(h.v[m], h.v[i]);
		heapify(h, m);
	}
}

// Extracts the maximum element
int extractMax(Heap& h)
{
	if (!h.n)
		return -1;
	int m = h.v[0];
	h.v[0] = h.v[h.n-- - 1];
	heapify(h, 0);
	return m;
}

int kThGreatest(Heap &h, int k)
{
	for (int i = 1; i < k; ++i)
		extractMax(h);
	return extractMax(h);
}

// Driver Code
int main()
{
	Heap h(7);
	h.v = vector<int>{ 20, 15, 18, 8, 10, 5, 17 };
	int k = 4;
	
	cout <<"\nThe greatest kth element is "<< kThGreatest(h, k)<<endl;
	return 0;
}

