/* [nm]

https://arena.topcoder.com/#/u/practiceCode/1395/2693/2913/2/1395
https://community.topcoder.com/stat?c=problem_statement&pm=2913&rd=5849&rm=&cr=7446789

Problem Statement
      
You are implementing the member registration system of an online dating site. When a new member signs up, it is possible that she initially chooses the same username as an existing member. The system must then inform the new member of the conflict and suggest a variant of the chosen name with a number attached to the end.

If an existing member is named "FunkyMonkey", for example, and a new member wants the same username, the simplest suggestion the system can make is "FunkyMonkey1". If there is already a member by that name, the system must suggest "FunkyMonkey2", unless that variant is also taken. If all names from "FunkyMonkey1" through "FunkyMonkey9" are taken as well as the original "FunkyMonkey", the system moves on to consider "FunkyMonkey10", and so on. The goal is to use the smallest possible number in the variant. Note that each username consists of letters (the characters from 'a' to 'z' and from 'A' to 'Z') and numerals ('0' to '9').

You are given a String[], existingNames, containing all usernames that have already been registered in the system. You are also given a single String, newName, containing the username that a new member wants to use. In the event of a conflict, this member will accept the suggestion offered by your system in accordance with the principles above. Return a String containing the username finally assigned to the new member.

 
Definition
      
Class:  UserName
Method: newMember
Parameters: String[], String
Returns:  String
Method signature: String newMember(String[] existingNames, String newName)
(be sure your method is public)
    
 
Notes
- The constraints rule out names that end in a number with a leading zero, such as "grokster006" and "bart0".
 
Constraints
- existingNames contains between 1 and 50 elements, inclusive
- each element of existingNames is between 1 and 50 characters long, inclusive
- the only characters permitted in elements of existingNames are 'a' to 'z', 'A' to 'Z', and '0' to '9'
- no element of existingNames ends in a number that has a leading zero
- newName is between 1 and 50 characters long, inclusive
- the only characters permitted in newName are 'a' to 'z' and 'A' to 'Z'
 
Examples
0)  
      
{"MasterOfDisaster", "DingBat", "Orpheus", "WolfMan", "MrKnowItAll"}
"TygerTyger"
Returns: "TygerTyger"
"TygerTyger" is available.
1)  
      
{"MasterOfDisaster", "TygerTyger1", "DingBat", "Orpheus", 
 "TygerTyger", "WolfMan", "MrKnowItAll"}
"TygerTyger"
Returns: "TygerTyger2"
"TygerTyger" and "TygerTyger1" are taken.
2)  
      
{"TygerTyger2000", "TygerTyger1", "MasterDisaster", "DingBat", 
 "Orpheus", "WolfMan", "MrKnowItAll"}
"TygerTyger"
Returns: "TygerTyger"
There are higher-numbered variants of "TygerTyger", but the base name is available.
3)  
      
{"grokster2", "BrownEyedBoy", "Yoop", "BlueEyedGirl", 
 "grokster", "Elemental", "NightShade", "Grokster1"}
"grokster"
Returns: "grokster1"
Note that "Grokster1" is not the same as "grokster1".
4)  
      
{"Bart4", "Bart5", "Bart6", "Bart7", "Bart8", "Bart9", "Bart10",
 "Lisa", "Marge", "Homer", "Bart", "Bart1", "Bart2", "Bart3",
 "Bart11", "Bart12"}
"Bart"
Returns: "Bart13"

*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>
 
using namespace std;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define EACH(i,x) REP(i,(x).size())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
 
typedef long long int lint;
typedef unsigned long long int ull;
typedef pair<int,int> pi;
typedef vector<pi> vp;
typedef vector<int> vi;
typedef vector<string> vs;
 
class UserName
{
  public:
    string newMember(vs exist, string newname)
    {
      set<string> s;
      EACH(i, exist) s.insert(exist[i]);
      int num = 0;
      char candidate[1024];
      while(1)
      {
        if(num > 0)
          sprintf(candidate, "%s%d", newname.c_str(), num);
        else
          sprintf(candidate, "%s", newname.c_str());
        if(s.count(candidate) == 0)
          break;
        ++num;
      }
      return string(candidate);
    }
 
};