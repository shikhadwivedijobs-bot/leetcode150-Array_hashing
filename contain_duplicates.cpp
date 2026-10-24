// //solution1:
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void print(vector<int>& nums) 
{
    for(int i =0; i < nums.size(); i++)
    {
        cout<<nums[i]<<endl;
    }
}

bool hasDuplicate(vector<int> &nums)
{
    for(int i =1; i <nums.size(); i++)
    {
        for(int j =i +1; j <nums.size(); j++)
        {
            if(nums[i]==nums[j])
                return true;
        }
    }
    return false;
}
int main()
{
    vector<int>v{1,3,2,5,6};
    print(v);
    cout<<"duplicate:"<<hasDuplicate(v);
    return 0;
}
//time: O(n^2), space:O(1)
// //solution2:
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void print(vector<int>& nums) 
{
    for(int i =0; i < nums.size(); i++)
    {
        cout<<nums[i]<<endl;
    }
}

bool hasDuplicate(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    for(int i =1; i <nums.size(); i++)
    {
        if(nums[i]==nums[i-1])
            return true;
    }
    return false;
}
int main()
{
    vector<int>v{1,3,2,5,6,3};
    print(v);
    cout<<"duplicate:"<<hasDuplicate(v);
    return 0;
}
// //time: O(nlogn+n), space: O(n)or O(1) depends on sorting

// //solution3:
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
void print(vector<int>& nums) 
{
    for(int i =0; i < nums.size(); i++)
    {
        cout<<nums[i]<<endl;
    }
}

bool hasDuplicate(vector<int> &nums)
{
    unordered_set<int> seen;
    for(int no: nums)
    {
        if(seen.count(no))
        {
            return true;
        }
        seen.insert(no);
    }
    return false;
}
int main()
{
    vector<int>v{1,3,2,5,6,3,2};
    print(v);
    cout<<"duplicate:"<<hasDuplicate(v);
    return 0;
}
// //time: O(n), space:O(n)

//solution4:
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
void print(vector<int>& nums) 
{
    for(int i =0; i < nums.size(); i++)
    {
        cout<<nums[i]<<endl;
    }
}

bool hasDuplicate(const vector<int> &nums)
{
    unordered_set<int> seen(nums.begin(),nums.end());
    return (seen.size()<nums.size());
}
int main()
{
    vector<int>v{1,3,2,5,6};
    print(v);
    cout<<"duplicate:"<<hasDuplicate(v);
    return 0;
}
// //time: O(n), space:O(n)


// Important notes:

// 1. Read a vector without modifying it	const vector<int>& nums, so in above example be can pass this const
// 2. Modify the original vector	vector<int>& nums
// 3. Need an independent copy	vector<int> nums
