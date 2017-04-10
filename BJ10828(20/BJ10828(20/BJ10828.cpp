#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

class mStack {
private:
	vector<int> stack;
	int pointer;
	int max;
public:
	void push(int num);
	int pop();
	int top();
	int size();
	int isEmpty();

	mStack() {
		max = 100;
		pointer = -1;
	}

	~mStack() {
		stack.clear();
	}
};

void mStack::push(int num) {

	stack.push_back(num);
	pointer++;


}

int mStack::pop() {
	if (pointer < 0) {
		return -1;
	}
	else {
		int temp = stack[pointer];
		pointer--;
		return temp;
	}
}

int mStack::size() {
	return pointer + 1;
}

int mStack::isEmpty() {
	if (pointer < 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int mStack::top() {
	if (pointer < 0) {
		return -1;
	}
	else {
		return stack.at(pointer);
	}
}

int main() {
	int numOfSequence;
	string command[2];
	int num = -1;
	mStack stack = mStack();

	cin >> numOfSequence;
	while (numOfSequence > 1) {
		cin.clear(); cin.ignore(INT_MAX, '\n');
		for (int i = 0; i < 2; i++) {
			getline(cin, command[i], ' ');
		}

		num = atoi(command[1].c_str());

		if (!command[0].compare("push")) {
			stack.push(num);
			cout << stack.pop();
		}
		else if (!command[0].compare("pop")) {
			cout << stack.pop() << endl;
		}
		else if (!command[0].compare("empty")) {
			cout << stack.isEmpty() << endl;
		}
		else if (!command[0].compare("size")) {
			cout << stack.size() << endl;
		}
		else if (!command[0].compare("top")) {
			cout << stack.top() << endl;
		}
		else {
			cout << "wrong command" << endl;
		}

		numOfSequence--;
	}
}