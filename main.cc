#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cassert>

using namespace std;

template <typename T>
class Stack {
	public :
		T pop();
		void insert(T x);
		T top() const;

	private :
		vector<T> st;
};

template <typename T>
T Stack<T>::pop() {
	assert(st.size() > 0);
	T ret = st[st.size()-1];
	st.pop_back();
	return ret;
}

template <typename T>
void Stack<T>::insert(T x) {
	st.push_back(x);
}

template <typename T>
T Stack<T>::top() const {
	assert(st.size() > 0);
	return st.at(st.size()-1);
}

class Calculator {
	public :
		long calculate();
		void insert(pair<long, char> e);

	private :
		vector<pair<long, char>> postfix;
};

long Calculator::calculate() {
	Stack<long> stack;	
	for (auto ele : postfix) {
		if (ele.second == '0') {
			stack.insert(ele.first);
		} else {
			long n1 = stack.pop(), n2 = stack.pop(), res;
			switch (ele.second) {
				case '+' :
					res = n1+n2;
					break;
				case '-' :
					res = n1-n2;
					break;
				case '*' :
					res = n1*n2;
					break;
				case '/' :
					res = n1/n2;
					break;
				case '%' :
					res = n1%n2;
					break;
				default :
					break;
			}
			stack.insert(res);
		}
	}
	return stack.top(); 
};

void Calculator::insert(pair<long, char> e) {
	postfix.push_back(e);
}

int precedence(char op) {
	switch (op) {
		case '%' :
			return 30;
		case '/' :
			return 20;
		case '*' :
			return 20;
		case '+' :
			return 10;
		case '-' :
			return 10;
		default :
			return 0;
	}
}

int main() {
	string expr;
	cout << "----Welcome to expression calculator-----\n"
	     << "Currently supported operations are : +, -, *, /, %\n"
	     << "Enter the expression you want to calculate : ";
	cin >> expr;
	expr.push_back(')');

	Stack<char> stack;
	Calculator calc;
	
	stack.insert('(');
	
	for (int i = 0; i < expr.length(); ++i) {
		char c = expr[i];
		if (c == ' ') {
			continue;
		} else if (c == '(') {
			stack.insert('(');
		} else if (c == ')') {
			char ele;
			while ((ele = stack.pop()) != '(') {
				calc.insert(make_pair(0, ele));
			}
		} else if (c >= '0' && c <= '9') {
			long num = c-'0';
			++i;
			while (i < expr.length() && expr[i] >= '0' && expr[i] <= '9') {
				num = num*10 + (expr[i]-'0');
				++i;
			}
			--i;
			calc.insert(make_pair(num, '0'));
		} else /*Must be a operator*/{
			int curr_prec = precedence(c);
			char ele = stack.top();
			int prec = precedence(ele);
			while (ele != '(' && prec >= curr_prec) {
				calc.insert(make_pair(0, stack.pop()));
				ele = stack.top();
				prec = precedence(ele);
			}
			stack.insert(c);
		}
	}
	cout << calc.calculate() << endl;
	
	return 0;
}
