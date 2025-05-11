#include <iostream>
#include <vector>
using namespace std;

class Heap
{
public:
	vector <int> v;
	int size = 0;
	int rootIdx = 1;
	Heap()
	{
		v.push_back(-1);
	}
	bool isEmpty()
	{
		return size == 0;
	}
	int getSize()
	{
		return size;
	}
	bool compare(int a, int b)
	{
		int suma, sumb ,ValA,ValB;
		suma = 0;
		sumb = 0;
		ValA = v[a];
		ValB = v[b];
		while (ValA >= 10)
		{
			suma += ValA % 10;
			ValA = ValA / 10;
		}
		suma += ValA;

		while (ValB >= 10)
		{
			sumb += ValB % 10;
			ValB = ValB / 10;
		}
		sumb += ValB;

		if (suma != sumb)
		{
			return suma > sumb;
		}
		else
		{
			return v[a] < v[b];
		}
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

		if (!compare(parentIdx, idx)) //compare에 위배시
		{
			swap(parentIdx, idx);
			UpHeap(parentIdx);
		}
	}
	void DownHeap(int idx)
	{
		int left = idx * 2;
		int right = idx * 2 + 1;
		int maxIdx = idx;
		if (left <= size && compare(left, maxIdx))
		{
			maxIdx = left;
		}
		if (right <= size && compare(right, maxIdx))
		{
			maxIdx = right;
		}
		if (idx != maxIdx)
		{
			swap(idx, maxIdx);
			DownHeap(maxIdx);
		}
	}

	void Insert(int x)
	{
		v.push_back(x);
		size++;
		UpHeap(size);
	}
	int pop()
	{
		int popval = v[rootIdx];
		v[rootIdx] = v[size];
		v.pop_back();
		size--;
		DownHeap(rootIdx);

		return popval;
	}

	void printall()
	{
		for (int i = 1; i <= size; i++)
		{
			cout << v[i] << " ";
		}
		cout << "\n";
	}



 };

 int main()
 {
	 int n;
	 cin >> n;
	 Heap heap = Heap();
	 for (int i = 0; i < n; i++)
	 {
		 int x;
		 cin >> x;
		 heap.Insert(x);
	 }
	 heap.printall();

	 for (int i = 0; i < n; i++)
	 {
		 cout << heap.pop() << " ";
	 }



 }