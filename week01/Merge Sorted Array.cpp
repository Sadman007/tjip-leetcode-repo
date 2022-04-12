//problem link:
//solve status:
//learnings:
#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz size()
#define all(a)  a.begin(), a.end()
#define mem(a, b)     memset(a, b, sizeof(a))
#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f2(i,a,b) for(int i=(a);i<=(b);i++)
#define fr(i,b,a) for(int i=(b);i>=(a);i--)
#define rep(i,a,b,c) for(int i=(a);i!=(b);i+=(c))


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int total = m+n;
        int arr[total];
        std::vector<int> new_vec;

        if(m>0 && n>0){
            for (int i = 0; i < m; ++i)
            {
                new_vec.push_back(nums1[i]);
            }

            new_vec.insert( new_vec.end(), nums2.begin(), nums2.end() );
            sort(new_vec.begin(),new_vec.end());
        }
        if( m==0){
           new_vec.insert( new_vec.end(), nums2.begin(), nums2.end() );
           sort(new_vec.begin(),new_vec.end()); 
        }
        if(n==0){
            new_vec.insert( new_vec.end(), nums1.begin(), nums1.end() ); 
            sort(new_vec.begin(),new_vec.end());
        }


        for (int i=0; i<total; i++){
            nums1[i]=new_vec[i];
        }
        




        for(auto x: nums1){
            cout<<x<<endl;
        }

        

    }
};


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

	Solution a;
    vector<int> v1 = {0};
	vector<int> v2 = {5};

	a.merge(v1,0,v2,1);
	//cout<<a.func()<<endl;


	
    


        
}



    //     int total = m+n;
    //     int arr[total];
    //     int index=0,i = 0,index2=0;

    //     while(i<total){
    //         if(nums1[index]<=nums2[index]){
    //             arr[i]= nums1[index];
    //             arr[i+1]= nums2[index2];
    //             i++,index++; index2++;
    //         }
    //         else{
    //             arr[i]= nums2[index2];
    //             arr[i+1]= nums1[index];
    //             i++,index++;index2++;
    //         }
    //     }


    //     for (int i = 0; i < total; ++i)
    //     {
    //         cout<<arr[i]<<" ";
    //     }
        
        

    // }