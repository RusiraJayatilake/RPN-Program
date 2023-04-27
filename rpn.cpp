#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
  stack<int> numberStack;
  string expression;
  int oper1, oper2, result, i;

  getline(cin, expression);

  if(expression.empty()){
    cout << "INVALID EXPRESSION" << endl;
    exit(1);
  }

  for(i = 0; i < expression.length(); i++){
    if(expression[i] == ' '){
      continue;
    }
    else if(isdigit(expression[i])){
      int num = 0;

      while(i < expression.length() && isdigit(expression[i])){
        num = num * 10 + (expression[i] - '0');
        i++;
      }
      i--;
      numberStack.push(num);
    }
    else if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/'){
      oper2 = numberStack.top();
      numberStack.pop();
      oper1 = numberStack.top();
      numberStack.pop();

      if(expression[i] == '+'){
        result = oper1 + oper2;
      }
      else if(expression[i] == '-'){
        result = oper1 - oper2;
      }
      else if(expression[i] == '*'){
        result = oper1 * oper2;
      }
      else if(expression[i] == '/'){
        if(oper2 == 0){
          cout << "INVALID EXPRESSION" << endl;
          exit(1);
        }
        result = oper1 / oper2;
      }
      else{
        cout << "INVALID EXPRESSION" << endl;
      }

      numberStack.push(result);

    }
    else{
      cout << "INVALID EXPRESSION" << endl;
      continue;
    }

  }

  if(numberStack.size() == 1){
    cout << numberStack.top() << endl;
  }
  else{
    cout << "INVALID EXPRESSION" << endl;
    exit(1);
  }


  return 0;

}
