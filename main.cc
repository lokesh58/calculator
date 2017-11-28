#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

class Stack {
	public :
		long pop();
		void insert(long x);

	private :
		vector<long> st;
};

long Stack::pop() {
	long ret = st[st.size()-1];
	st.pop_back();
	return ret;
}

void Stack::insert(long x) {
	st.push_back(x);
}

class Calculator {
	public :
		long calculate();

	private :
		vector<pair<long, char>> postfix;
};

long Calculator::calculate() {
	Stack stack;
	long res = 0;
	for (auto ele : postfix) {
		if (ele.second == '0') {
			stack.insert(ele.first);
		} else {
			long n1 = stack.pop(), n2 = stack.pop();
			switch (ele.second) {
				case '+' :
					res += n1+n2;
					break;
				case '-' :
					res += n2-n1;
					break;
				case '*' :
					res += n2*n1;
					break;
				case '/' :
					res += n2/n1;
					break;
				case '%' :
					res += n2%n1;
					break;
				default :
					break;
			}
		}
	}
	return res; 
};

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


	Calculator calc;
	for (int i = 0; i < expr.length(); ++i) {
		char c = expr.length();
		if (c == '(') {
			
		} else if (c == ')') {
			
		} else if (c >= '0' && c <= '9') {
			long num = c-'0';
			++i;
			while (i < expr.length() && expr[i] >= '0' && expr[i] <= '9') {
				num = num*10 + (expr[i]-'0');
				++i;
			}
			--i;
			calc.
		} else /*Must be a operator*/ {
			
		}
	}
	cout << calc.calculate() << endl;
	
	return 0;
}
