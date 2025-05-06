//9주차 2번문제. 그냥 9주차가 시험에 나오면 두가지만 생각하면 된다.

//1. push, pop은 PQ형태를 유지하되, 짝수,홀수 판정은 main함수에서 진행한다.
//2. push는 iterator, pop은 for문을 이용하여 erase 

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
			if (*i > e) // i번째보다 작으면 삽입 ㅇㅈ? 
			{
				v.insert(i, e);
				return;
			}
		}
		v.push_back(e);
	}
	//pop에선 작은 값이 우선순위가 높은거 유의 -> 작은 값부터 삭제 
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