// TC: O(N)
// MC: O(N)

class Solution {
public:
    string last_line(int cur_len, vector<string>& cur_line, int maxWidth, int n)
    {
        string res = "";
        for(int i = 0; i < cur_line.size(); i++)
        {
            res += cur_line[i];
            if(i + 1 == cur_line.size()) continue;
            res.push_back(' ');
        }
        while(res.size() < maxWidth) res.push_back(' ');
        return res;
    }
    string generate(int cur_len, vector<string>& cur_line, int maxWidth, int n)
    {
        if(cur_line.size() == 1)
        {
            string res = "";
            res += cur_line[0];
            while(res.size() < maxWidth) res.push_back(' ');
            
            return res;
        }
        
        int tot_gap = maxWidth - cur_len;
        int tot_word_gap = cur_line.size() - 1;
        int avg_gap = tot_gap / tot_word_gap;
        int extra_gap = tot_gap % tot_word_gap;
        
        string res = "";
        for(int i = 0; i < cur_line.size(); i++)
        {
            res += cur_line[i];
            if(i + 1 == cur_line.size()) continue;
            for(int j = 0; j < avg_gap; j++)
            {
                res.push_back(' ');
            }
            if(extra_gap > 0)
            {
                res.push_back(' ');
                extra_gap--;
            }
        }
        return res;
    }
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>cur_line;
        vector<string>res_string;
        int cur_len = 0;
        int n = words.size();
        
        for(int i = 0; i < n; i++)
        {
            if(cur_len + (int)cur_line.size() - 1 + words[i].size() >= maxWidth)
            {
                res_string.push_back(generate(cur_len, cur_line, maxWidth, n));
                cur_len = words[i].size();
                cur_line.clear();
            }
            else
            {
                cur_len += words[i].size();
            }
            cur_line.push_back(words[i]);
        }
        res_string.push_back(last_line(cur_len, cur_line, maxWidth, n));
        return res_string;
    }
};