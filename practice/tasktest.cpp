#include <bits/stdc++.h>
using namespace std;

class Task{
private:
	static vector<Task*> task_container;
	static int count;
public:
	int x;
	Task(int x):x(x){
		task_container.push_back(this);
		count++;
	}
	Task* getLatestTask(){
		return task_container[count];
	}

	static int getCount(){
		return count;
	}

};

vector<Task*> Task::task_container {NULL};
int Task::count {0};
int main()
{
	cout<<"Hello"<<endl;
	Task a(5), b(6) , c(7);
	cout<<a.getCount()<<endl;
	cout<<c.getLatestTask() -> x;
}