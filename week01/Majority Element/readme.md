here we used 2 approaches <br>
our first Approach costs O(n) memory <br>
how ?
<br>

video explanation link : https://youtu.be/75Jj3LR9YAg

/******************** first Approach ************************/
   
//Time Complexity = O(n) <br>
//Space Complexity = O(n) <br>
           
        int mx = -1;
        int maxTimes;
        
        map<int,int>mp;
        
        for(int i=0; i<nums.size(); i++)
        {
            
            ++mp[nums[i]];
            
            if(mx<=mp[nums[i]])
            {
                mx = mp[nums[i]];
                maxTimes = nums[i];
            }
        }
        
        
        
        return maxTimes;
        
        
we took a map and store the number of appearance of every element and return a result based on it .
<br>


But at 2nd Approach we didn't take any container for counting frequency . randomly we took a majority element from the first of array then started traversing <br>
when same element appeares twice we have just incremented its count then go forward but if it doesnot appear then we decrement our counter variable . <br>
when counter becomes zero then we take new mejority element from our current element of array which is now pointing . <br>
In this way we traverse the whole array and thats how we got our majority element of our array and return it <br>

our Second Approach took just O(1) memory <br>


/******************** Second Approach ************************/

//Time Complexity = O(n) <br>
//Space Complexity = O(1) <br>
        
        
           int appear = 0;
           int majority = 0;
        
           for(int i=0; i<nums.size(); i++)
           {
               if(appear == 0)
               {
                   majority = nums[i];
                   appear++;
               }
               else if(majority != nums[i])
               {
                   appear--;
               }
               else
               {
                   appear++;
               }
           }
            
           return majority;
       
        
        
        


