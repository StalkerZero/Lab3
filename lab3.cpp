#include <iostream>
#include <stack>
using namespace std;

int main(){
  stack <int> numb;
  string a, b;
  cout <<  "Enter" << '\n';
  getline(cin, a);
  int numb1, numb2, i=0;
  while(a[i]!=0){
    switch (a[i]) {
      default:
      b+=a[i];
      // cout << "Default" <<'\n';
      break;
      case 32:
      if(a[i-1]>47)numb.push(stoi(b));
      b='0';
      // cout << "Space" << '\n';
      break;
      case '+':
      numb1=numb.top();
      numb.pop();
      numb2=numb.top();
      numb.pop();
      numb.push(numb1+numb2);
      // cout << "+" << '\n';
      break;
      case '-':
      numb2=numb.top();
      numb.pop();
      numb1=numb.top();
      numb.pop();
      numb.push(numb1-numb2);
      // cout << "-" << '\n';
      break;
      case '*':
      numb1=numb.top();
      numb.pop();
      numb2=numb.top();
      numb.pop();
      numb.push(numb1*numb2);
      // cout << "*" << '\n';
      break;
      case '/':
      numb2=numb.top();
      numb.pop();
      numb1=numb.top();
      numb.pop();
      try{
        if(numb2==0) throw "Cannot be divided by zero!";
        numb.push(numb1/numb2);
      }
      catch(const char* error){
        cout << error << '\n';
        return 0;
      }
      // cout << "/" << '\n';
      break;
    }
    i++;
  }
  cout << "Answer" << numb.top();
}
