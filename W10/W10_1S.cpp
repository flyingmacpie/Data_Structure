#include <iostream>
#include <vector>
using namespace std;

class Heap
{
public:
	vector<int> v;
	int size = -1;
	int rootIdx = 1;

	void insert(int x)
	{
		v.push_back(x);
		size++;
	}

};

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		Heap heap = Heap();

		int isfine = 0;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			heap.insert(x); //넣고 
		}
		for (int i = 1; i < n; i++)
		{
			int left = i * 2;
			int right = i * 2 + 1; //바로 조건 검사 

			if (left <= heap.size && heap.v[i] > heap.v[left])
			{
				isfine++;
			}
			if (right <= heap.size && heap.v[i] > heap.v[right])
			{
				isfine++;
			}
		}

		cout << isfine << endl;



	}
}