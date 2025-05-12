//9���� 2������. �׳� 9������ ���迡 ������ �ΰ����� �����ϸ� �ȴ�.

//1. push, pop�� PQ���¸� �����ϵ�, ¦��,Ȧ�� ������ main�Լ����� �����Ѵ�.
//2. push�� iterator, pop�� for���� �̿��Ͽ� erase 

#include <iostream>
#include <vector>
using namespace std;

class PQueue
{
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
		vector<int>::iterator i;
		for (i = v.begin(); i != v.end(); i++)
		{
			if (*i > e) // i��°���� ������ ���� ����? 
			{
				v.insert(i, e);
				return;
			}
		}
		v.push_back(e);
	}
	//pop���� ���� ���� �켱������ ������ ���� -> ���� ������ ���� 
	int pop()
	{
		if (isEmpty())
		{
			return -1;
		}
		
		int Maxval = v.front();
		v.erase(v.begin());

		return Maxval;
		
	}
	void print_all()
	{
		if (isEmpty())
		{
			cout << "\n";
			return;
		}

		vector<int>::iterator i;
		for (i = v.begin(); i != v.end(); i++)
		{
			cout << *i << " ";
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

	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (x % 2 == 0)
		{
			pq.push(x);
		}
		cout << "PQ: ";
		pq.print_all();
	}

	int Size = pq.size();
	for (int i = 0; i <Size; i++)
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
}