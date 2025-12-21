class Solution {
public:
    string simplifyPath(string path) {
        string s = "";
        
        vector<string>dq;
        path += "/"; // handle last s . ex  /..   , /xxx

        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/') {
                if (!s.empty() && s != ".") {

                    if (s == "..") {
                        if (!dq.empty())
                            dq.pop_back();
                    } 
                    else {
                        dq.push_back(s);
                    }
                }
                s = "";
            } else {
                s += path[i];
            }
        }

        s = "";
        s.reserve(path.size());
        for (auto it : dq) {
            s = s + "/" + it;
        }
        return s.empty() ? "/" : s;
    }
};
