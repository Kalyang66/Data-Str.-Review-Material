#include <iostream>
using namespace std;
#include <fstream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "ArgumentManager.h"
#include <queue>
bool isValid2(string &a)
{
  if(a.find('[')!= std::string::npos)
  {

    string inside = a.substr(a.find('['),a.find_last_of(']')-a.find('[')+1);

    if(inside.find('{')!= std::string::npos)
    {
      return false;
    }
  }
  if(a.find('(')!= std::string::npos)
  {

    string inside = a.substr(a.find('('),a.find_last_of(')')-a.find('(')+1);

    if(inside.find('{')!= std::string::npos)
    {
      return false;
    }
    else if(inside.find('[')!=std::string::npos)
    {
      return false;
    }
  }
    return true;
}
bool isValid(const string &s){
  stack<char> st;
  for(char c : s){
    if(c == '{' || c == '[' || c == '('){
      st.push(c);
  } else if(c == '}' || c == ']' || c == ')'){
      if(st.empty()){
        return false; 
      }

    char op = st.top();
    st.pop();
    if(c == '}' && op != '{'){
      return false;
    } else if(c == ']' && op != '['){
      return false;
    } else if (c == ')' && op != '('){
      return false; 
    }
  }
  }
  // if(!isVaild2(s))
  // {
  //   return false;
  // }
    return st.empty(); 
}
int main(int charc, char * argv[]) {
  ArgumentManager am(charc, argv);
  string input(am.get("input"));
  string output(am.get("output"));

  // string input = "input3.txt";
  // string output = "output3.txt"; 

  ifstream ifs(input);
  ofstream ofs(output);

  string inputline; 
  int scount = 0;
  int tcount = 0;
  queue<string> s;
  queue<string> t; 

  while(getline(ifs, inputline)){
    inputline.erase(remove(inputline.begin(), inputline.end(), '\n'), inputline.end());  
    inputline.erase(remove(inputline.begin(), inputline.end(), '\r'), inputline.end());
    inputline.erase(remove(inputline.begin(), inputline.end(), ' '), inputline.end());
     if (isValid(inputline)) {
       cout<<inputline<<endl;
       if(isValid2(inputline))
       {
         s.push(inputline);
         scount++;
       }
       else{
       t.push(inputline);
       tcount++;}
     } else {
       t.push(inputline);
       tcount++;
     }
  }
  if(!t.empty()){
    int tcount2=0;
    ofs << "Invalid" << endl; 
    while (!t.empty()){
      if(tcount2 == tcount-1&& scount==0)
      {
        ofs << t.front(); 
        t.pop();
        break;
      }
      ofs << t.front() << endl; 
      t.pop();
      tcount2++;
    }
  }
  if(!s.empty()){
    int scount2 = 0;
    ofs << "Valid" << endl; 
    while (!s.empty()){
      if(scount2 == scount-1)
      {
        ofs << s.front(); 
        s.pop();
        break;
      }
      ofs << s.front() << endl; 
      s.pop();
      scount2++;
    }
  }

  return 0; 
}