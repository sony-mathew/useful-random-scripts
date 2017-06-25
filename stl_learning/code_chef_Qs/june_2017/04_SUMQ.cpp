#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define loadVector(i, n, V) for(int i = 0; i < n ; i++) { cin >> temp; V.push_back(temp); }

typedef long long int lli;
typedef vector<lli> vli;

int vectorSum(vli A, vli B, vli C)
{
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(C.begin(), C.end());
  
  lli sum = 0;

  REP(i, A.size()) {

    REP(j, B.size()) {
      if (A[i] > B[j]) break;
      
      REP(k, C.size()) {
        if (B[j] < C[k]) break;
        sum = (sum + ((A[i] + B[j])*(B[j] + C[k]))) % 1000000007;
      }
    }
  }
  return sum;
}

int main(void)
{
  int t, sizeA, sizeB, sizeC;
  lli temp;
  vli A, B, C;

  cin >> t;
  REP(i, t) {
    cin >> sizeA >> sizeB >> sizeC;
    loadVector(j, sizeA, A);
    loadVector(j, sizeB, B);
    loadVector(j, sizeC, C);
    cout << vectorSum(A, B, C) << endl;
  }

  return 0;
}