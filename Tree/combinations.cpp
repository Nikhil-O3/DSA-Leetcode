class Solution {
public:
    vector<vector<int>>res;
    vector<int>path;

    void bt(int j,int &n,int &k)
    {
        if(k==path.size())
        {
            res.push_back(path);
            return;
        }
        for(int i=j;i<=n- (k - path.size()) + 1;i++)
        {
            path.push_back(i);
            bt(i+1,n,k);
            path.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        
        bt(1,n,k);
        return res;
        
    }
};