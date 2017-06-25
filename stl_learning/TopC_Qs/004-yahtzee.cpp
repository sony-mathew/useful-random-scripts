/*

Problem Statement
      
This task is about the scoring in the first phase of the die-game Yahtzee, where five dice are used. The score is determined by the values on the upward die faces after a roll. The player gets to choose a value, and all dice that show the chosen value are considered active. The score is simply the sum of values on active dice.

Say, for instance, that a player ends up with the die faces showing 2, 2, 3, 5 and 4. Choosing the value two makes the dice showing 2 active and yields a score of 2 + 2 = 4, while choosing 5 makes the one die showing 5 active, yielding a score of 5.

Your method will take as input an int[] toss, where each element represents the upward face of a die, and return the maximum possible score with these values.

 
Definition
      
Class:  Yahtzee
Method: maxPoints
Parameters: int[]
Returns:  int
Method signature: int maxPoints(int[] toss)
(be sure your method is public)
    
 
Constraints
- toss will contain exactly 5 elements.
- Each element of toss will be between 1 and 6, inclusive.
 
Examples
0)  
      
{ 2, 2, 3, 5, 4 }
Returns: 5
The example from the text.
1)  
      
{ 6, 4, 1, 1, 3 }
Returns: 6
Selecting 1 as active yields 1 + 1 = 2, selecting 3 yields 3, selecting 4 yields 4 and selecting 6 yields 6, which is the maximum number of points.
2)  
      
{ 5, 3, 5, 3, 3 }
Returns: 10

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)

class YahtzeeScore
{
  public:
    int maxPoints(vector <int> toss)
    { 
      vector <int> tossMap;

      REP(i, 6) {
        tossMap.push_back(0);
      }

      int max = 0, current;
      REP(i, 5)
      { 
        current = 0;
        ++tossMap[toss[i]-1];
        current = toss[i]*tossMap[toss[i]-1];
        if(current > max) {
          max = current;
        }
      }

      return max;
    }
};

