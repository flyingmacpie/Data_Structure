#include <iostream>
#include <vector>
using namespace std;

class PQueue
{//삽입 후 main함수에서 홀수 판정하는 시스템 
public:
	vector <int> v;
	int size()
	{
		return v.size();
	}
	bool isEmpty()
	{
		return v.size() == 0;
	}

	void push(int e)
	{
		v.push_back(e);
	}
	int pop() // 높은값부터 삭제 
	{
		if (isEmpty())
		{
			return -1;
		}

		//erase할때는 iterator가 아닌 for문으로. tree erase를 생각하기 
		int max = v.front();
		int index = 0;
		for (int i = 0; i < size(); i++)
		{
			if (max < v[i])
			{
				max = v[i];
				index = i;
			}
		}
		
		v.erase(v.begin() + index);
		return max;

	}

	void print_all()
	{
		if (isEmpty())
		{
			cout << "\n";
			return;
		}

		for (int i = 0; i < size(); i++)
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

	vector <int> seq;
	PQueue pq = PQueue();

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		if (x % 2 == 1)
		{
			pq.push(x);
		}
		cout << "PQ: ";
		pq.print_all();
	}

	int Size = pq.size(); // 이걸 좀 더 와닿게 표현 할수 있을까 /// 
	for (int i = 0; i < Size; i++)
	{
		seq.push_back(pq.pop());
		cout << "PQ: ";
		pq.print_all();
	}

	cout << "S: ";
	for (int i = 0; i < seq.size(); i++)
	{
		cout << seq[i] << " ";
	}
	cout << "\n";
}