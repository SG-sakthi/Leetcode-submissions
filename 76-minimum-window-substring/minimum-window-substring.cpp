class Solution {
public:
    string minWindow(string s, string t) {

        if(t.size()> s.size()){
            return "";
        }
        unordered_map<char,int> freq;
        for(char c:t){
            freq[c]++;
        }
       int left =0;
       int required = t.size();
       int minlen = INT_MAX;
       int start =0;
       for(int right =0 ; right<s.size(); right++){
            if(freq[s[right]]>0){
                required--;
            }
            freq[s[right]]--;
            
            while(required ==0){
                if(right-left+1<minlen){
                    minlen = right -left +1;
                    start = left;
                }
                freq[s[left]]++;
                if(freq[s[left]]>0){
                   required ++;
                }
                left++;
            }
            
       }
       if(minlen == INT_MAX){
                return "";
            }

        return s.substr(start, minlen);
    }

};