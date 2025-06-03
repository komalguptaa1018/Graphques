class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.length();
        int k=needle.length();

        if (k==0) return 0;

        for(int i=0;i<=n-k;i++){
            int j=0;
  while (j < k && haystack[i + j] == needle[j]) {
                j++;
            }

            if (j == k) return i;  // if all characters matched, return index
             
            
        }
        return -1;

    }
};