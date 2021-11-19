//Ho va Ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn
#include<iostream>
#include<stack>
#include<string>

using namespace std;

int EvaluatePostfix(string expression);
int PerformOperation(char operation, int operand1, int operand2);
bool IsOperator(char C);
bool IsNumericDigit(char C);

int EvaluatePostfix(string expression)
{
    stack<int> S;

    for(int i = 0;i< expression.length();i++)
    {
        if(expression[i] == ' ' || expression[i] == ',') continue;
        else if(IsOperator(expression[i]))
        {
            
            int operand2 = S.top(); S.pop();
            int operand1 = S.top(); S.pop();
            int result = PerformOperation(expression[i], operand1, operand2);
            S.push(result);
        }
        else if(IsNumericDigit(expression[i]))
        {
            int operand = 0;
            while(i<expression.length() && IsNumericDigit(expression[i]))
            {
                operand = (operand*10) + (expression[i] - '0');
                i++;
            }
            i--;
            S.push(operand);
        }
    }
    return S.top();
}
bool IsNumericDigit(char C)
{
    if(C >= '0' && C <= '9') return true;
    return false;
}
bool IsOperator(char C)
{
    if(C == '+' || C == '-' || C == '*' || C == '/')
        return true;

    return false;
}

int PerformOperation(char operation, int operand1, int operand2)
{
    if(operation == '+') return operand1 +operand2;
    else if(operation == '-') return operand1 - operand2;
    else if(operation == '*') return operand1 * operand2;
    else if(operation == '/') return operand1 / operand2;

    else cout<<"Unexpected Error \n";
    return -1;
}
int main()
{
    string expression;
    cout<<"Nhập Biểu thức hậu tố: \n";
    getline(cin,expression);
    int result = EvaluatePostfix(expression);
    cout<<"Output = "<<result<<"\n";
}