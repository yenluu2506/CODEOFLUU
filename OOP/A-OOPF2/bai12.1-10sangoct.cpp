////hãy chuyển n thành mã bac phân và in chuỗi đó ra màn hình.
//
//#include <iostream>
//#include <stack>
//
//using namespace std;
//
//int main() {
//	stack<char> st;
//	int n;
//	cin >> n;
//	while (n > 0) {
//		st.push(n % 8 + '0');
//		n /= 8;
//	}
//	while (!st.empty()) {
//		cout << st.top();
//		st.pop();
//	}
//	return 0;
//}