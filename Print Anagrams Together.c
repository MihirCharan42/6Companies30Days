// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    bool anagram(string s1,string s2){
        if(s1.length()!=s2.length())
            return false;
        unordered_map<char,int> m;
        for(int i=0;i<s1.length();i++)
        {
            m[s1[i]]++;
            m[s2[i]]--;
        }
        for(int i=0;i<s1.length();i++)
        {
            if(m[s1[i]]!=0)
                return false;
        }
        return true;
    }

    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        vector<vector<string>> ans;
        for(int i=0;i<string_list.size();i++)
        {
            vector<string> temp;
            if(string_list[i]!="\0")
            {
            temp.push_back(string_list[i]);
            for(int j=i+1;j<string_list.size();j++)
            {
                if(string_list[j]!="\0" && anagram(string_list[i],string_list[j]))
                {
                    temp.push_back(string_list[j]);
                    string_list[j]="\0";
                }
            }
            ans.push_back(temp);
        }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i];
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends
