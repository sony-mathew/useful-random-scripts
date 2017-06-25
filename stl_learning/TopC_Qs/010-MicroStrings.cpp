/*
Problem Statement
John couldn't handle long strings so he came up with the idea of MicroStrings.


You are given two positive s: A and D. These determine an infinite decreasing arithmetic progression: A, A-D, A-2D, and so on. Clearly, only finitely many elements of such a progression are non-negative.


Each such progression defines one MicroString, as follows: You take all the non-negative elements, convert each of them into a string, and then concatenate those strings (in order).


For example, let A=12 and D=5. For these values we get the arithmetic progression (12, 7, 2, -3, -8, ...). The non-negative elements are 12, 7, and 2. The corresponding strings are "12", "7", and "2". Their concatenation is the following MicroString: "1272".


Given A and D, return the MicroString they define.

Definition
Class: MicroStrings
Method: makeMicroString
Parameters: int, int
Returns: string
Method signature: string makeMicroString(int A, int D)
(be sure your method is public)
Limits
Time limit (s): 2.000
Memory limit (MB): 256
Notes
- When converting a number to a string, the string must not have unnecessary leading zeros.
Constraints
- A will be between 1 and 200, inclusive.
- D will be between 1 and 200, inclusive.
Examples
0)
12
5
Returns: "1272"
This is the example from the problem statement.
1)
3
2
Returns: "31"
2)
31
40
Returns: "31"
3)
30
6
Returns: "3024181260"
The number 0 is also non-negative. When we convert it into a string, we get the string "0".
*/

#include <iostream>
#include <string>
#include <stack>
#include <cstring>
#include <sstream>

using namespace std;

class MicroStrings
{
  public:

    string makeMicroString(int A, int D)
    { 
      stringstream ss;
      for(int i = A; i > -1; i -= D) {
        ss << i;
      }
      return ss.str();
    }
};