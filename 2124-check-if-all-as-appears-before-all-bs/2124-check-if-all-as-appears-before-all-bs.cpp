class Solution {
public:
    bool checkString(string s) {
        int lsta = -1;
        int frstb = -1;
        int n = s.size();
        for (int i = 0; i < n; i++){
            if(s[i]=='a'){
                lsta = i;
            }
            else{
                if(frstb==-1){
                    frstb = i;
                }
            }
        }
        return (lsta == -1)||(frstb==-1)||(lsta<frstb);
    }
};