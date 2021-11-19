//Ho va Ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn
#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

int getWeight(char ch) {
	switch (ch) {
    case '^': return 3;  
	case '/': return 2;       
	case '*': return 2;
	case '+': return 1;      
	case '-': return 1;
	default : return 0;
	}
}

void infix2postfix(char infix[], char postfix[], int size) {
	stack<char> s;
	int weight;
	int i = 0;
	int k = 0;
	char ch;
	while (i < size) {
		ch = infix[i];
		if (ch == '(') {
			s.push(ch);
			i++;
			continue;
		}
		if (ch == ')') {
			
			while (!s.empty() && s.top() != '(') {
				postfix[k++] = s.top();
				s.pop();

			}
			
			if (!s.empty()) {
				s.pop();
			}
			i++;
			continue;
		}
		weight = getWeight(ch);
		if (weight == 0) {
			
			postfix[k++] = ch;

		}
		else {
			if (s.empty()) {
			
				s.push(ch);
			}
			else {
				
				while (!s.empty() && s.top() != '(' &&
						weight <= getWeight(s.top())) {
					postfix[k++] = s.top();
					s.pop();

				}
				s.push(ch);
			}
		}
		i++;
	}
	
	while (!s.empty()) {
		postfix[k++] = s.top();
		s.pop();
	}
	postfix[k] = 0; // null kết thúc biểu thức hậu tố
}

// main
int main() {
	char infix[100];//"A*(B+C)/D";
	cout<<"\nENter Infix Operation:";
	cin>>infix;
	int size = strlen(infix);
	char postfix[size];
	infix2postfix(infix,postfix,size);
	cout<<"\nInfix Expression :: "<<infix;
	cout<<"\nPostfix Expression :: "<<postfix;
	cout<<endl;
	return 0;
}