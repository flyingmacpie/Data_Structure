#include <iostream>
#include <vector>
using namespace std;

class PQueue
{//���� �� main�Լ����� Ȧ�� �����ϴ� �ý��� 
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
	int pop() // ���������� ���� 
	{
		if (isEmpty())
		{
			return -1;
		}

		//erase�Ҷ��� iterator�� �ƴ� for������. tree erase�� �����ϱ� 
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

	int Size = pq.size(); // �̰� �� �� �ʹ�� ǥ�� �Ҽ� ������ /// 
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