/*
 Problem Statement for PassingGrade


Problem Statement
      
You are studying for the final exam in a tough course, and want to know how many points you need to score on the final to pass the course. You know how many points you earned on each assignment (pointsEarned), how many points were possible on each assignment (pointsPossible), and how many points are possible on the final exam (finalExam). You need to earn a minimum of 65% of the total possible points to pass the course. Assume your score on the final exam will be an integral number of points between 0 and finalExam, inclusive. Return the number of points you need to score on the final to pass the course, or -1 if it is impossible for you to pass the course.

 
Definition
      
Class:  PassingGrade
Method: pointsNeeded
Parameters: int[], int[], int
Returns:  int
Method signature: int pointsNeeded(int[] pointsEarned, int[] pointsPossible, int finalExam)
(be sure your method is public)
    
 
Constraints
- pointsEarned contains between 1 and 20 elements, inclusive.
- pointsPossible contains the same number of elements as pointsEarned.
- Each element of pointsPossible is between 1 and 1000, inclusive.
- Element i of pointsEarned is between 0 and element i of pointsPossible, inclusive.
- finalExam is between 1 and 3000, inclusive.
 
Examples
0)  
      
{55,77,82,60}
{100,100,100,100}
300
Returns: 181
If you score 181 points on the final, then you will finish the course with exactly 65% of the possible points.
1)  
      
{ 1, 2, 3, 4 }
{ 2, 3, 4, 5 }
7
Returns: 4
If you score 4 points on the final, then you pass with 66.7% of the total possible points, but if you score 3 points on the final, then you fail with 61.9% of the possible points.
2)  
      
{ 1, 2, 2, 1 }
{ 9, 9, 9, 9 }
9
Returns: -1
Even if you score 9 points on the final, you still fail with 33.3% of the possible points.
3)  
      
{ 7, 8, 7, 6 }
{ 8, 8, 8, 8 }
9
Returns: 0
You will pass even if you score 0 points on the final.
4)  
      
{ 17, 23, 50, 200, 19, 56, 83, 91, 77, 9, 0 }
{ 20, 30, 50, 250, 20, 70, 100, 100, 100, 10, 10 }
400
Returns: 129
5)  
      
{600,600,600,600,600,600,600,600,600,600,
 600,600,600,600,600,600,600,600,600,600}
{1000,1000,1000,1000,1000,1000,1000,1000,
 1000,1000,1000,1000,1000,1000,1000,1000,
 1000,1000,1000,901}
3000
Returns: 2886

*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)

class PassingGrade
{
  public:
    int pointsNeeded(vector <int> pointsEarned, vector <int> pointsPossible, int finalExam)
    {
      int totalEarned = 0, totalPossible = 0, num_65, required;
      double cent_65;
      REP(i, pointsEarned.size())
      {
        totalEarned += pointsEarned[i];
        totalPossible += pointsPossible[i];
      }

      totalPossible += finalExam;

      cent_65 = totalPossible*0.65;
      num_65 = (int)(ceil(cent_65));
      required = num_65 - totalEarned;

      if(required < 0) return 0;
      if(required > finalExam) return -1;
      return required;
    }
};