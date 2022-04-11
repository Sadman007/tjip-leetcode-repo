class Solution {
public:
    int myAtoi(string s) {
        bool minus = false;
        int i=0;
        int len = s.length();
        long long ans = 0;
        while(i<len and s[i] == ' ') i++; // প্রথম থেকে যত ফাকা জায়গা আছে সব গুলা স্কিপ করতে থাকবো যথক্ষন না ক্যারেক্টার পাই 
        if(i<len and s[i] == '-') minus = true; 
        if(i<len and (s[i] == '-' or s[i] == '+')) i++; // এখানে - আর + একসাথে থাকলে আমরা জিরো রিটার্ন করে দিব , তাই শুধু মাত্র একটা কেই কাউন্ট করবো 
        bool overflow = false;                          // মাইনাস এর পরে আবার মাইনাস কিংবা প্লাস এর পরে আবার প্লাস হলেও জিরো রিটার্ন করতে হবে 
        while(i<len)
        {
            long long value = s[i]-'0';
            if(value < 0 or value >9) break; // এখানে আসকি ভ্যালু ০ আর ৯ এর বাইরে হলে তা ইন্টিজার না , তাই ব্রেক করে দিবো 
            else
            {
                ans = ans*10 + value;;
                if(ans > 2147483647) // আন্সার যদি আমাদের ৩২ বিট ইন্টিজার লিমিট ক্রস করে তাহলেও ব্রেক করবো , হোক সেটা পজিটিভ বা নেগেটিভ 
                {
                    overflow = true;
                    break;
                }
            }
            i++;
        }
        if(overflow)
        {
            if(minus) return INT_MIN;
            else return INT_MAX;
        }
        return minus == true?ans*(-1):ans; // যদি মাইনাস থেকে থাকে সামনে তাহলে শুধু মাইনাস দিয়ে গুন করে আন্সার রিটার্ন করবো । নইলে শুধু আন্সার ।         
    }
};
