/*

Problem Statement
      
When evaluating a mathematical expression, there is the possibility of ambiguity. If you wanted to know the result of "3 + 5 * 7", you might first evaluate the (3+5) and get 56, or first evaluate the (5*7) and get 38. This ambiguity can be resolved by using the order of operations: first do multiplication and division (from left to right), and then after all those are done, do addition and subtraction (again from left to right). Here, the correct result would be the 38.

While this is unambiguous, it certainly is somewhat annoying. You think it would be easier if people did all math from left to right, all the time, and want to make a simple expression evaluator to do so.

The expression will be given to you as a String expr. It will consist of one digit numbers (0 through 9) alternating with operators (+, -, or *), with no spaces between them. Thus, expr would follow the format Digit Operator Digit Operator .... Digit. For example, the expression given above would be given as "3+5*7".

Your method should return an int representing the value of the expression when evaluated from left to right.

 
Definition
      
Class:  NoOrderOfOperations
Method: evaluate
Parameters: String
Returns:  int
Method signature: int evaluate(String expr)
(be sure your method is public)
    
 
Constraints
- expr will be between 1 and 17 characters in length, inclusive.
- expr will contain an odd number of characters.
- expr will follow the format Digit Operator Digit Operator ... Digit, where each Digit is a single character from '0' to '9', and each Operator is either +, -, or *.
 
Examples
0)  
      
"3+5*7"
Returns: 56
First we add 3 + 5 to get 8. Then, we multiply 8 by 7 to get 56.
1)  
      
"4-8*9*1"
Returns: -36
Results can be negative.
2)  
      
"0"
Returns: 0
3)  
      
"1*2*3*4*5*6*7*8*9"
Returns: 362880

*/

#include <iostream>
#include <stack>
#include <cstring>
#include <string>

using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)

class NoOrderOfOperations {
  public:
    int evaluate(string expr)
    {
      const char *b = expr.c_str();
      char op;
      int prevResult = 0, k = 0;

      while(*b) {
        int ia = *b - '0';
        if(ia > -1 && ia < 10 )
        {
          if(k == 0) {
            prevResult = ia;
            k++;
          } else {
            switch(op){
              case '/': prevResult = prevResult / ia; break;
              case '*': prevResult = prevResult * ia; break;
              case '+': prevResult = prevResult + ia; break;
              case '-': prevResult = prevResult - ia; break;
            }
          }
        }
        else
        {
          op = *b;
        }
        b++;
      }
      return prevResult;
    }
};