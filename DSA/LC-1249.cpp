class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        string answer;

        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(ch=='('){
                st.push(i); //store index at which we have (
            }
            else if(ch==')'){
                if(!st.empty()){
                    st.pop();
                }
                else{
                    s[i]='*'; //mark for removal of ')'
                }
            }
        }

        //for '(' we will be left with top of stack indices
        while(!st.empty()){
            s[st.top()]='*';
            st.pop();
        }

        for(int i=0;i<s.size();i++){ //simply put stack char into answer string and return it
            char ch=s[i];
            if(ch!='*'){
                answer.push_back(ch);
            }
        }
        return answer;
    }
};
