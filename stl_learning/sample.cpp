#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define REP(i,n) for(int i=0; i < n; i++)

int main (void) {
  int a = 3;
  vector <int> s1;

  REP(i, 10) {
    int k = i *2;
    s1.push_back(k);
  }

  REP(i, s1.size()) {
    cout << s1.at(i) << endl;
  }

  return 0;
}