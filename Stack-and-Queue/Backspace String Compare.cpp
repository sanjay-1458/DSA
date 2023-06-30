class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> stk1,stk2;
        for(int i=0;i<s.size();++i){
            if(stk1.empty()){
                if(s[i]!='#'){
                    stk1.push(s[i]);
                }
            }
            else{
                if(s[i]=='#'){
                    stk1.pop();
                }
                else{
                    stk1.push(s[i]);
                }
            }
        }
        for(int i=0;i<t.size();++i){
            if(stk2.empty()){
                if(t[i]!='#'){
                    stk2.push(t[i]);
                }
            }
            else{
                if(t[i]=='#'){
                    stk2.pop();
                }
                else{
                    stk2.push(t[i]);
                }
            }
        }
        if(stk2==stk1){
            return true;
        }
        else{
            return false;
        }
    }
};
