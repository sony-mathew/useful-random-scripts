#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define REP(i,n) for(int i=0; i < n; i++)

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;

vi parseRow(const char *p)
{
  vi row;
  int num = 0;
  while(*p)
  { 
    if(*p != ' ') {
      num = num*10 + (*p - '0');
    }
    if(*p == ' ' || !*(p+1)) {
      row.push_back(num);
      num = 0;
    }
    p++;
  }

  return row;
}

int main (void) {

  vvi nums;
  vector <string> s1;
  s1.push_back("9 56");
  s1.push_back("10 4");

  REP(i, s1.size()) {
    cout << s1.at(i) << endl;
    nums.push_back(parseRow(s1.at(i).c_str()));
  }

  REP(i, nums.size()) {
    REP(j, nums.at(i).size()) {
      cout << nums.at(i).at(j) << endl;
    }
  }

  return 0;
}