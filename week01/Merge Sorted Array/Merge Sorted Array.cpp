
/// First Approach ----------------------

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(nums2.size() == 0)
        {
            return;
        }
        if(m == 0)
        {
            nums1.clear();
            for(auto i: nums2)
            {
                nums1.push_back(i);
            }
            return;
        }
        vector<int>temp;
        for(auto i : nums1)
        {
            if(i == 0 and n>0)
            {
                --n;
            }
            else
            {
                temp.push_back(i);
            }
        }
        for(auto i : nums2)
        {
           
            temp.push_back(i);
            
        }
        sort(temp.begin(),temp.end());
        nums1.clear();
        for(int i=0; i<temp.size(); i++)
        {
            nums1.push_back(temp[i]);
        }
    }
};

//Second Approach ----------------

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       
        int LastCount = (m+n)-1;
        int cnt1 = m-1;
        int cnt2 = n-1;
        
        while(cnt1 >= 0 and cnt2 >= 0)
        {
            if(nums1[cnt1] < nums2[cnt2])
            {
                nums1[LastCount] = nums2[cnt2];
                cnt2--;
                LastCount--;
            }
            else
            {
                nums1[LastCount] = nums1[cnt1];
                cnt1--;
                LastCount--;
            }
        } 
        
        while(cnt2 >= 0)
        {
            nums1[LastCount--] = nums2[cnt2--];
        }   
    }
};


