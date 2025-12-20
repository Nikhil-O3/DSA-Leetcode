class Solution {
public:
   
    string countAndSay(int n) {
        if(n==1)return "1";

        string str=countAndSay(n-1);
        string res="";

        int i=0,count=0;
        while(i<str.size())
        {
            count=0;
            char ch=str[i];
            while(i<str.size() && ch==str[i])
            {
                count++;i++;
            }
            res=res+to_string(count)+ch;
            
        }

        return res;
    }
};
