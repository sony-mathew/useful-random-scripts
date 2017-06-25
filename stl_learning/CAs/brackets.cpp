#include <iostream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

#define REP(i,n) for(int i=0; i < n; i++)

typedef pair<char,int> pi;
typedef pair<char, char> pc;
typedef vector<pi> vpi;
typedef vector<pc> vpc;

vpc bracketPairs;

bool validBracket(char a)
{
  REP(i, bracketPairs.size()){
    if (bracketPairs[i].first == a) {
      return true;
    }
  }
  return false;
}

char getPairp(char a)
{
  REP(i, bracketPairs.size()) {
    if (bracketPairs[i].first == a) {
      return bracketPairs[i].second;
    }
  }
  return 'a';
}


int main(int argc, char *argv[]) 
{
  char *input = argv[1];

  char bps[6][2] = {
    {'[', ']'},
    {']', '['},
    {'(', ')'},
    {')', '('},
    {'{', '}'},
    {'}', '{'}
  };

  REP(i, 6) bracketPairs.push_back(make_pair(bps[i][0], bps[i][1]));

  int length = 0;
  stack<char> str;
  stack<int> index;

  for(int i = 0; *(input+i); i++)
  {
    char elem = *(input + i);
    if (validBracket(elem)) {
      if(!str.empty() && (str.top() == getPairp(elem))) {
        str.pop();
        index.pop();
      } else {
        str.push(elem);
        index.push(i);
      }
    }
  }
    
  if (str.empty()) {
    cout << "Success";
  } else {
    cout << index.top();
  }

  return 0;
}
