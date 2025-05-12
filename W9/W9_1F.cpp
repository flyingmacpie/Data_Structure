#include <iostream>
#include <vector>
using namespace std;
//���ĵ�, ���ĵ������� ť�� �����ϱ� 

class PQueue
{
public:
	vector<int> v;
	bool isEmpty()
	{
		return v.size() == 0;
	}
	void Push(int x)
	{ // ���ĵ�������, selection sort ��� ��ť ����
		v.push_back(x);
	}

	//popó�� ��ť�� for������ ������ ������� �� 
	void Top() 
	{
		if (isEmpty())
		{
			cout << "-1\n";
			return;
		}

		int max = v[0];
		
		vector<int>::iterator i;
		for (i = v.begin(); i != v.end(); i++)
		{
			if (*i > max)
			{
				max = *i;
			}
		}

		cout << max << "\n";
	}
	void Pop()
	{
		if (isEmpty())
		{
			cout << "empty\n";
			return;
		}

		int max = v[0];
		int index = 0;

		//������ ��� int i �� ������ ���������� erase�� ���� 
		int i = 0;
		for (; i <v.size(); i++)
		{
			if (v[i] > max)
			{
				max = v[i];
				index = i;

			}
		}
		v.erase(v.begin() + index);
	}
	void Print_avg()
	{
		if (isEmpty())
		{
			cout << "0\n";
			return;
		}

		int sum = 0;
		for (int i = 0; i < v.size(); i++)
		{
			sum += v[i];
		}

		cout << sum / v.size() << "\n";
	}

	void Print_all()
	{
		if (isEmpty())
		{
			cout << "empty\n";
			return;
		}

		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << "\n";
	}
	void Sum_low()
	{
		if (isEmpty())
		{
			cout << "0\n";
			return;
		}

		int sum = 0;
		for (int i = 0; i < v.size(); i++)
		{
			sum += v[i];
		}
		int avg = sum / v.size();

		int result = 0;

		for (int i = 0; i < v.size(); i++)
		{
			if (avg > v[i])
			{
				result += v[i];
			}
		}
		cout << result << "\n";
	}
};

int main()
{
	int N;
	cin >> N;
	PQueue pq = PQueue();
	while (N--)
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
		else if (str == "Sum_low")
		{
			pq.Sum_low();
		}
	}
}

