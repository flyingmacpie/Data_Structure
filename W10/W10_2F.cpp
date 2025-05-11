#include <iostream>
#include <vector>
using namespace std;

class Heap
{
public:
	vector <int> v;
	int size = 0;
	int rootIdx = 1; //기본 틀은 똑같은데, compare연산 활용법을 이해하면되는 문제.

	Heap()
	{
		v.push_back(-1);
	}
	bool compare(int a, int b)
	{
		int suma = 0; //자릿수를 받는 연산을 먼저.
		int sumb = 0;
		int aVal = v[a];
		int bVal = v[b];

		while (aVal >= 10)
		{
			suma += aVal % 10;
			aVal = aVal / 10;
		}
		suma += aVal;

		while (bVal >= 10)
		{
			sumb += bVal % 10;
			bVal = bVal / 10;
		}
		sumb += bVal;

		if (suma != sumb) //1.자릿수가 다를 때
		{
			return suma < sumb; 

		}
		else //2.자릿수가 같을 때
		{
			return v[a] > v[b];
		}


	}
	bool isEmpty()
	{
		return size == 0;
	}
	int getSize()
	{
		return size;
	}
	void swap(int a, int b)
	{
		v[0] = v[a];
		v[a] = v[b];
		v[b] = v[0];
	}

	void UpHeap(int idx)
	{
		if (idx == rootIdx)
		{
			return;
		}

		int parentIdx = idx / 2;

		if (compare(idx,parentIdx)) //여기에 넣으면 자연스럽게 heap이 만들어짐. 
		{
			swap(idx, parentIdx);
			UpHeap(parentIdx);
		}
	}
	void DownHeap(int idx)
	{
		int left = idx * 2;
		int right = idx * 2 + 1;
		int maxIdx = idx;

		if (left <= size && compare(left,maxIdx)) 
		{
			maxIdx = left;
		}
		if (right <= size && compare(right,maxIdx))
		{
			maxIdx = right;
		}
		if (idx != maxIdx)
		{
			swap(idx, maxIdx);
			DownHeap(maxIdx);
		}

	}

	void insert(int x)
	{
		v.push_back(x); 
		size++;
		UpHeap(size);
	}
	int pop()
	{
		if (isEmpty())
		{
			return -1;
		}
		int popval = v[rootIdx];
		v[rootIdx] = v[size];
		v.pop_back();
		size --;
		DownHeap(rootIdx);

		return popval;
	}

	void printall()
	{
		if (isEmpty())
		{
			return;
		}
		for (int i = 1; i <= size; i++)
		{
			cout << v[i] << " ";
		}
		cout << "\n";
	}


}; 



int main()
{
	int N;
	cin >> N;
	Heap heap = Heap();
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		heap.insert(x);
	}

	heap.printall();

	int s = heap.getSize();
	for (int i = 0; i < s; i++)
	{
		cout << heap.pop() << " ";
	}
	cout << "\n";

	

}