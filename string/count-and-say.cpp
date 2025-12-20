class Solution {
public:
    string rec(int n)
    {
        if(n==1)return "1";

        string str=rec(n-1);
        string res="";

        int i=0;
        while(i<str.size())
        {
            int count=0;
            char ch=str[i];
            while(i<str.size() && ch==str[i])
            {
                count++;i++;
            }
            res=res+char(count+'0')+ch;
            
        }

        return res;
    }
    string countAndSay(int n) {
        return rec(n);
    }
};
