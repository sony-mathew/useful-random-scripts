/*
Problem Statement for TallPeople


Problem Statement
      A group of people stand before you arranged in rows and columns. Looking from above, they form an R by C rectangle of people. You will be given a String[] people containing the height of each person. Elements of people correspond to rows in the rectangle. Each element contains a space-delimited list of integers representing the heights of the people in that row. Your job is to return 2 specific heights in a int[]. The first is computed by finding the shortest person in each row, and then finding the tallest person among them (the "tallest-of-the-shortest"). The second is computed by finding the tallest person in each column, and then finding the shortest person among them (the "shortest-of-the-tallest").
 
Definition
      
Class:  TallPeople
Method: getPeople
Parameters: String[]
Returns:  int[]
Method signature: int[] getPeople(String[] people)
(be sure your method is public)
    
 
Constraints
- people will contain between 2 and 50 elements inclusive.
- Each element of people will contain between 3 and 50 characters inclusive.
- Each element of people will be a single space-delimited list of positive integers such that: 

1) Each positive integer is between 1 and 1000 inclusive with no extra leading zeros.

2) Each element contains the same number of integers.

3) Each element contains at least 2 positive integers.

4) Each element does not contain leading or trailing whitespace.
 
Examples
0)  
      
{"9 2 3",
 "4 8 7"}
Returns: { 4,  7 }
The heights 2 and 4 are the shortest from the rows, so 4 is the taller of the two. The heights 9, 8, and 7 are the tallest from the columns, so 7 is the shortest of the 3.
1)  
      
{"1 2",
 "4 5",
 "3 6"}
Returns: { 4,  4 }
2)  
      
{"1 1",
 "1 1"}
Returns: { 1,  1 }

*/

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)

typedef vector <int> vi;
typedef vector <string> vs;
typedef vector <vi> vvi;

class TallPeople
{
  public:
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

    vi getPeople(vs people)
    { 
      vvi arr_people;
      vi final;
      int n, m, r_small, c_large, r_largest = numeric_limits<int>::min(), c_smallest = numeric_limits<int>::max();

      REP(i, people.size()) {
        arr_people.push_back(parseRow(people.at(i).c_str()));
      }

      n = arr_people.size();
      m = arr_people.at(0).size();

      REP(i, n) {
        r_small = numeric_limits<int>::max();

        REP(j, m) {
          if(arr_people.at(i).at(j) < r_small)
            r_small = arr_people.at(i).at(j);
        }

        if (r_small > r_largest)
          r_largest = r_small;
      }

      REP(i, m) {
        c_large = numeric_limits<int>::min();

        REP(j, n) {
          if(arr_people.at(j).at(i) > c_large)
            c_large = arr_people.at(j).at(i);
        }

        if (c_large < c_smallest)
          c_smallest = c_large;
      }

      final.push_back(r_largest);
      final.push_back(c_smallest);

      return final;
    }
};
