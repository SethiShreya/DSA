#include<bits/stdc++.h>
using namespace std;
// Approach 1
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        int n = s.size();
        for (int i=0; i<n; i++){
            if (stk.empty()){
                stk.push(s[i]);
            }else{
                if (stk.top()=='(' && s[i]==')'){
                    stk.pop();
                }
                else if (stk.top()=='[' && s[i]==']'){
                    stk.pop();
                }
                else if (stk.top()=='{' && s[i]=='}'){
                    stk.pop();
                }else{
                    stk.push(s[i]);
                }
            }
        }
        if (stk.empty()){
            return true;
        }
        return false;
    }
};

// Approach 2
class Solution {
public:
    bool isValid(string s) {
        vector<char> v;
        for (int i=0; i<s.size(); i++){
            if (s[i]=='(' || s[i]=='[' || s[i]== '{'){
                v.push_back(s[i]);
                continue;
            }else{
                if(s[i]==')' && v.back()=='('){
                    v.pop_back();
                    continue;
                }
                else if(s[i]==']' && v.back()=='['){
                    v.pop_back();
                    continue;
                }
                else if(s[i]=='}' && v.back()=='{'){
                    v.pop_back();
                    continue;
                }else{
                    return false;
                }
            }
        }
        if (v.size()==0){
            return true;
        }
        return false;
    }
};

int main(){
    Solution s;
    cout<<s.isValid("()")<<endl;
    cout<<s.isValid("{]{]")<<endl;
    cout<<s.isValid("{[]}")<<endl;
    return (0);
}

