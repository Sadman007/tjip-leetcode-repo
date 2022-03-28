
Video Explanation link : https://youtu.be/EhTRqv81CQI
<br>
LeetCode Profile Link : https://leetcode.com/nahin_cdr/
<br>
<br>
NAZMUL HAQUE NAHIN  <br>
      
 ///Explanation : <br> <br>
       
first we saw that 
       we need find such two integers from our given array that their sum will be exactly equal to our target value  <br>
       then we should return their 2 indices in any order as vector ; <br> <br>
       
theme 1 :  <br>
       if we apply bruteforce method and take a single integer then make sum for rest of the elements of our given array then <br>
       it should cost O(n^2) time complexity and its not optimal solution <br>
        ///Time Complexity : O(n^2) <br>
       ///Space Complexity : O(1) <br>
        <br> <br> <br>
       
theme 2 :  <br>
       here we can take a container like MAP and keep every single element of our array which is not equal to our (target - current)  <br>
       we will be looking for such an element in our map which is equal to the difference between our current element and target element; <br>
       if we find such 2 then just store their index no in 2 different variable and break the loop  <br>
       then return those values as a vector .
       ///Time Complexity : O(n) <br>
       ///Space Complexity : O(n) <br>
        <br> <br>
       
