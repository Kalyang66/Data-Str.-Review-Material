#ifndef STACK_H
#define STACK_H
#include <algorithm>
#include <cctype>
#include <cmath>
#include <vector>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
// change to template
 struct node {
// change to template
  double data;
  string s; 
  node *next;
  node(double val) : data(val), next(nullptr) {}
};
// change to template
class Stack {
private:
  node *top;

public:
  Stack() : top(nullptr) {}
 // change to template
  void push(double val) {
    node *temp = new node(val);
    temp->next = top;
    top = temp;
  }
// change to template
  double pop() {
    if (isEmpty()) {
      return 0;
    }
    double val = top->data;
    node *temp = top;
    top = top->next;
    delete temp;
    return val;
  }

  bool isEmpty() { return top == nullptr; }

  bool peek() {
    if (isEmpty()) {
      return 0;
    }
    return top->data;
  }
  bool isOperator(char c){
     return ((c == '+' || c == '-' || c == '*' || c == '/' || c == '^')); 
  }
  int order(char op) {
    if (op == '^') {
      return 3;
    } else if (op == '*' || op == '/') {
      return 2;
    } else if (op == '+' || op == '-') {
      return 1;
    } else {
      return 0;
    }
  }
// change to template
double PostFix(string exp) {
    Stack opernad;
    stringstream ss(exp);
    string key;
    while (ss >> key) {
      if (isdigit(key[0])) {
        cout << key << endl;
        push(stod(key));
      } else {
        double oprand2 = pop();
        double oprand1 = pop();
        switch (key[0]) {
        case '+':
          push(oprand1 + oprand2);
          break;
        case '-':
          push(oprand1 - oprand2);
          break;
        case '*':
          push(oprand1 * oprand2);
          break;
        case '/':
          push(oprand1 / oprand2);
          break;
        case '^':
          push(pow(oprand1, oprand2));
          break;
        default:
          cerr << "Invalid ope:" << key << endl;
          break;
          // exit(1);
        }
      }
    }
    cout << top->data << endl;
    return top->data;
  }

  double prefix(string exp) {
    stringstream ss(exp);
    string key;
    Stack operand;
    while (ss >> key) {
      if (isdigit(key[0])) {
        cout << key << endl;
        push(stod(key));
      } else {
        double oprand1 = pop();
        double oprand2 = pop();
        switch (key[0]) {
        case '+':
          push(oprand1 + oprand2);
          break;
        case '-':
          push(oprand1 - oprand2);
          break;
        case '*':
          push(oprand1 * oprand2);
          break;
        case '/':
          push(oprand1 / oprand2);
          break;
        case '^':
          push(pow(oprand1, oprand2));
          break;
        default:
          cerr << "Invalid ope:" << key << endl;
          break;
          // exit(1);
        }
      }
    }
    cout << top->data << endl;
    return top->data;
  }
// change to template
  string Infix(string exp) {
    vector<char> Opstack;
    string postfix = "";
    for (char c: exp){
      if (isspace(c)){
        continue; 
      } else if (isdigit(c)){
        postfix += c; 
        //postfix += ' ';
      } else if (isOperator(c)){
        while (!Opstack.empty() && order(Opstack.back()) >= order(c)){
          postfix += ' ';
          postfix += Opstack.back();
          Opstack.pop_back(); 
        }
        Opstack.push_back(c);
        postfix += ' ';
      } else if (c == '('){
        Opstack.push_back(c); 
      } else if (c == ')'){
        while (!Opstack.empty() && Opstack.back() != '('){
          postfix += ' ';
          postfix += Opstack.back();
          Opstack.pop_back(); 
        }
        Opstack.pop_back();
      } else {
        return ""; 
      }
    }
    for (char op: Opstack){
      postfix += ' ';
      postfix += op; 
    }
    return postfix; 
  }

};
#endif