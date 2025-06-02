class Solution {
public:
    bool isPalindrome(int x) {
        string s=to_string(x);

        vector<int>ans1;
        vector<int>ans2;

if (x<0)
return false;

        for(int i=0;i<s.size();i++){
            ans1.push_back(s[i]-'0');
        }
        for(int j=s.size()-1;j>=0;j--){
            ans2.push_back(s[j]-'0');

        }
        return (ans1==ans2);

    }
};