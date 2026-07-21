// Using stack 
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string curr;
//get each string store in temp variable curr and push it to stack
        for(int i =0; i<=path.size(); i++){
            // if / found or size of path reached push it to stack
            if(i == path.size() || path[i] == '/'){
            // we have  in begining so that check if curr is empty or not if empty ignore
                if(curr == "" ||  curr =="."){

                }
            // if .. found and stack is not empty pop the last element from the stack
                else if (curr == ".."){
                    if(!st.empty()){
                        st.pop();
                    }
                }
            // else push the element to stack
                else{
                    st.push(curr);
                }
                // empty the curr variable 
                curr.clear();
            }
            //add each elemnt to the string curr = h+o+m+e
            else{
                curr +=path[i];
            }
        }
// push all the stack elemnts into array and reverse it 
        vector<string> dirs;
        while(!st.empty()){
            dirs.push_back(st.top());
            st.pop();
        }
        if(dirs.empty()){
            return "/";
        }
        reverse(dirs.begin(), dirs.end());
        string ans;
    // add /string/string for all the elemnts in the array 
        for(string dir : dirs){
            ans += "/" + dir;
        }
        return ans;
    }
};