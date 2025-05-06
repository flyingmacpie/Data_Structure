#include <iostream>
#include <vector>
using namespace std;

class PQueue
{ //정렬된 큐, insertion sort 구현을 위한 PQ구성 
public:
	vector<int> v;

	bool isEmpty()
	{
		return v.size() == 0;
	}
	void Push(int x)
	{
		vector<int>::iterator i;
		for (i = v.begin(); i != v.end(); i++)
		{
			if (*i > x)
			{
				v.insert(i, x);
				return;
			}
		}
		v.push_back(x);
		return;
	}

	void Top()
	{
		if (isEmpty())
		{
			cout << "-1\n";
			return;
		}
		cout << v.back() << "\n";
	}
	
	void Pop()
	{
		if (isEmpty())
		{
			cout << "empty\n";
			return;
		}
		v.pop_back();
	}

	void Print_avg()
	{
		if (isEmpty())
		{
			cout << "0\n";
			return;
		}
		int result = 0;
		for (int i = 0; i < v.size(); i++)
		{
			result += v[i];
		}
		cout << result / v.size() << "\n";
	}
	void Print_all()
	{
		if (isEmpty())
		{
			cout << "empty\n";
			return;
		}
		for (int i = v.size()-1; i >= 0; i--)
		{
			cout << v[i] << " ";
		}
		cout << "\n";
	}
	void Sum_high()
	{
		if (isEmpty())
		{
			cout << "0\n";
			return;
		}
		int result = 0;

		for (int i = 0; i < v.size(); i++)
		{
			result = result+ v[i];
		}
		int avg = result / v.size();

		int sum = 0;
		for (int i = 0; i < v.size(); i++)
		{
			if (avg < v[i])
			{
				sum += v[i];
			}
		}
		cout << sum << "\n";
	}
};

int main()
{
	int n;
	cin >> n;
	PQueue pq = PQueue();
	while (n--)
	{
		string str;
		cin >> str;
		if (str == "Push")
		{
			int x;
			cin >> x;
			pq.Push(x);
		}
		else if (str == "Top")
		{
			pq.Top();
		}
		else if (str == "Pop")
		{
			pq.Pop();
		}
		else if (str == "Print_avg")
		{
			pq.Print_avg();
		}
		else if (str == "Print_all")
		{
			pq.Print_all();
		}
		else if (str == "Sum_high")
		{
			pq.Sum_high();
		}
	}

}