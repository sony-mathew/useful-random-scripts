/*



 Problem Statement for WordForm


Problem Statement
      
In English, the letters A, E, I, O and U are the vowels. Y is also considered to be a vowel if it's not preceded by another vowel and is not the first letter in a word (the fact that a vowel is defined to some extent in terms of itself does not make it ambiguous). If a letter is not a vowel then it is a consonant. So in "TOY" the consonants are T and Y, and in "SYZYGY" they are S, Z and G.

A sequence of vowels will be denoted by uppercase letter 'V' and a sequence of consonants will be denoted by uppercase letter 'C'. A word can then be described as an alternating sequence of 'C' and 'V'. For instance, the word "WHEREABOUTS" has the sequence CVCVCVC, and the words "YORK" and "TOY" both have the sequence CVC. It's not permissible to have two or more consecutive 'V' or 'C' in the sequence.

Create a class WordForm containing the method getSequence which takes a String word and returns a String containing the word's sequence as described above. The word may contain both uppercase and lowercase letters, but your method should be case insensitive (see example 2).

 
Definition
      
Class:  WordForm
Method: getSequence
Parameters: String
Returns:  String
Method signature: String getSequence(String word)
(be sure your method is public)
    
 
Notes
- word may not be an English word, or a word in any language at all, but you should still use the rules defined above. See example 3.
 
Constraints
- word will contain between 1 and 50 characters, inclusive.
- word will only contain the characters 'A'-'Z' and 'a'-'z', both inclusive.
 
Examples
0)  
      
"WHEREABOUTS"
Returns: "CVCVCVC"
Here we have consonant-consonant-vowel-consonant-vowel-vowel-consonant-vowel-vowel-consonant-consonant. Putting together consecutive consonants and vowels gives us CVCVCVC.
1)  
      
"yoghurt"
Returns: "CVCVC"
2)  
      
"YipPy"
Returns: "CVCV"
Mixing lowercase and uppercase does not affect the result.
3)  
      
"AyYyEYye"
Returns: "VCVCVCV"
Even though this isn't an English word, we use the rules defined in the statement to find the consonant-vowel pattern.
4)  
      
"yC"
Returns: "C"

*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

typedef vector<char> vc;

const char *VOWEL = "aeiou";

class WordForm
{
  public:
    bool isVowel(char b, bool prev)
    { 
      REP(i, 5) {
        if (b == *(VOWEL+i)) return true;
      }
      if (b == 'y' && !prev) return true;
      return false;
    }

    string getSequence(string word)
    {
      stringstream ss;
      bool prevVowel = true, currentVowel;
      char prevChar, currentChar;

      transform(word.begin(), word.end(), word.begin(), ::tolower);
      REP(i, word.size()) {
        currentVowel = isVowel(word[i], prevVowel);
        currentChar = (currentVowel ? 'V' : 'C');
        if (prevChar != currentChar) ss << currentChar;
        prevChar = currentChar;
        prevVowel = currentVowel;
      }
      return ss.str();
    }
};

int main(void)
{
  WordForm p;
  cout << "yC" << " -- " << p.getSequence("yC") << endl;
  cout << "AyYyEYye" << " -- " << p.getSequence("AyYyEYye") << endl;
  cout << "YipPy" << " -- " << p.getSequence("YipPy") << endl;
  cout << "yoghurt" << " -- " << p.getSequence("yoghurt") << endl;
  cout << "WHEREABOUTS" << " -- " << p.getSequence("WHEREABOUTS") << endl;
  return 0;
}