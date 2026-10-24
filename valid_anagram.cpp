//Solution1
#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

bool isAnagram(string s, string t) {
    if(s.size()!=t.size())
        return false;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return (s==t);
}
int main()
{
    string str1 ="abscd";
    string str2="dabsc";
    if(isAnagram(str1,str2))
    {
        cout<<"ANAGRAM";
    }
    else
    {
        cout<<"No";
    }
    return 0;
}

//time: O(nlogn+mlogm), space:O(1)
// Important points:
// Compile with: g++ valid_anagram.cpp -o valid_anagram

// meaning :
// g++ complier: it complier your code

// valid_anagram.cpp: input file that you eant to complile

// -o: output option , it specifies the name of executable file that will be generated after compilation.

// valid_anagram: name of the executable file that will be generated after compilation.


// we can also use this "g++ valid_anagram.cpp" to compile the code and generate an executable file with the default name "a.out"

// run the executable file with "./valid_anagram" or "./a.out" depending on the name of the executable file generated after compilation.

//Solution2:

#include <iostream>
#include <string>
#include<unordered_map>
#include<algorithm>
using namespace std;

bool isAnagram(const string& s, const string& t) {
    if(s.size()!=t.size())
        return false;
    unordered_map<char, int> charcounts;
    unordered_map<char,int> charcountt;
    for(int i=0; i<s.size(); i++)
    {
        charcounts[s[i]]++;
        charcountt[t[i]]++;
    }
    return charcounts == charcountt;
}
int main()
{
    string str1 ="abscd";
    string str2="absc";
    if(isAnagram(str1,str2))
    {
        cout<<"ANAGRAM";
    }
    else
    {
        cout<<"No";
    }
    return 0;
}

// time: O(n+m), space:O(n+m) where n and m are the lengths of the two strings.

// Solution3:

#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
using namespace std;

bool isAnagram(const string& s, const string& t) {
    if(s.size()!=t.size())
        return false;
    vector<int> charcount(26, 0);
    for(int i=0; i<s.size(); i++)
    {
        charcount[s[i] - 'a']++;
        charcount[t[i] - 'a']--;
    }
    return all_of(charcount.begin(), charcount.end(), [](int count) { return count == 0; });
}
int main()
{
    string str1 ="abscd";
    string str2="dabsc";
    if(isAnagram(str1,str2))
    {
        cout<<"ANAGRAM";
    }
    else
    {
        cout<<"No";
    }
    return 0;
}

// time: O(n+m), space:O(1) where n and m are the lengths of the two strings.



// Important points:
// 1. we can directly compare two map objects in C++ using the equality operator (==). This operator checks if both maps have the same key-value pairs, regardless of the order in which they were inserted. If both maps contain the same keys with the same corresponding values, the comparison will return true; otherwise, it will return false.
// 2. The all_of algorithm is a standard library function in C++ that checks if all elements in a given range satisfy a specified condition. It takes three arguments: the beginning of the range, the end of the range, and a predicate function (or lambda expression) that defines the condition to