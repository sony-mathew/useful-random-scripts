/*

Problem Statement for PaperFold


Problem Statement
      
You have a piece of paper that you need to fold to fit into a box with a given width and length. Each time you fold the paper, you can fold it in half across either its width or length, but you can only fold the paper 8 times (after 8 times, the paper is too dense to fold again).

You will be given a int[] paper, which contains the width and length of the paper in inches, and a int[] box, which contains the width and length of the box in inches. In both cases, the first element is the width and the second element is the length. Your method should return the fewest number of folds which would allow you to fit the paper into the box. You can rotate the paper 90 degrees if it will fit with fewer folds, but the paper must lie completely flat inside the box. If the paper cannot be fit into the box with 8 folds or fewer, return -1.

 
Definition
      
Class:  PaperFold
Method: numFolds
Parameters: int[], int[]
Returns:  int
Method signature: int numFolds(int[] paper, int[] box)
(be sure your method is public)
    
 
Notes
- After the paper is folded, it is possible that it has fractional dimensions.
- The paper will fit into the box even if one or both of the dimensions are exactly the same as the corresponding box dimensions.
 
Constraints
- paper will contain exactly two elements.
- box will contain exactly two elements.
- Each element of paper and box will be between 1 and 10000, inclusive.
 
Examples
0)  
      
{8, 11}
{6, 10}
Returns: 1
By folding the paper so that the length is reduced from 11 to 5.5 inches, it will fit inside the box if you rotate it 90 degrees.
1)  
      
{11, 17}
{6, 4}
Returns: 4
There are two ways to fold the paper so that it fits within the box.

First, you could fold the width in half to get 5.5 inches, and then fold the length in half three times to get 2.125 inches.

Second, you could fold the width in half twice to get 2.25 inches, and then fold the length in half twice to get 4.25 inches. In this case, you must also rotate 90 degrees to fit the paper in.

2)  
      
{11, 17}
{5, 4}
Returns: 4
Now, you must use the second method to get it to fit: Fold the width and length each twice, and rotate 90 degrees. If you try fitting without rotating, it would take 5 folds.
3)  
      
{1000,1000}
{62,63}
Returns: -1
Folding in each direction 4 times, you can get the paper down to 62.5 x 62.5. However, this will not fit into the box because neither dimension fits in 62.
4)  
      
{100,30}
{60,110}
Returns: 0
5)  
      
{1895, 6416}
{401, 1000}
Returns: 5

*/

#include <iostream>
#include <algorithm>

using namespace std;

#define REP(i,n) for(int i = 1; i < n; i++)

class PaperFold
{
  public:

    int foldCount(vector<int> pap, vector<int> box)
    {
      int a, b;
      a = getCount((float)pap[0], box[0]) + getCount((float)pap[1], box[1]);
      b = getCount((float)pap[0], box[1]) + getCount((float)pap[1], box[0]);
      return (a > b ? b : a);
    }

    int getCount(float a, int b, int times = 0)
    {
      if (b >= a) return times;
      if (times > 8)  return times;
      return getCount(a/2, b, times+1);
    }

    int numFolds(vector<int> paper, vector <int> box)
    {
      int fold;

      fold = foldCount(paper, box);
      return (fold > 8 ? -1 : fold);
    }
};
