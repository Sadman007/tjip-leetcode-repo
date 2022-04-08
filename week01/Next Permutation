class Solution {
public:
    void nextPermutation(vector<int>& v) {
        int i=v.size()-2;
        while(i>=0 and v[i+1]<=v[i])
            i--;
        int l,j;
        if(i>=0)
        {
             j=v.size()-1;
            
           
            while(j>=0 and v[j]<=v[i])
                j--;
            swap(v[i],v[j]);

        }
                    int k=i+1;
        l=v.size()-1;   
        while(k<l)
            {
                swap(v[k],v[l]);
                k++,l--;
            }

    
    }
};

