class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return n;
        int ans=1;
        while(ans<=n) ans<<=1;
        return ans;
    }
};

/*Intuition
We need to find the xor of the triplets
in the qu we are give that the permuatation is given
which itself is the bigeest hint (unique nummbers + range of continuous numbers)

So instead of calculating and trying the permuatations of xors of tripletes we would try to find out a formula or a method with which it would be solved in 0(1) time complexity

Approach
We know that xor of a^a is 0
and now a^a^a=a
a^b^b=a
a^a^b=b
So we could see that the xor is repeated
if you carefully notice
then for size<2 the xors that can come would be n itself (no triplets)
for n=3 ,there are 8 xor
(1 is always repeated that is the number itself becaue in the question we are given i<=j<=k means that the numbers used in tripltes could be repeated) so from 0 to n is always possible
and for n=3 , we have 8 such xors unique tripltes
for n=4 we have 8
for n=5 we have 16
which means 2 raised to power (log2(n)+1) ;
but now logn gives double values , infact power gives floating values
so we need to calculate this somehow
for that we would use a while loop
which is already exlained in the code
ans<<=1 will give us 2 power everytime
when ans is 01 so ans<<=1 will be 010 so now it is 4
then again ans<<=1 would be 100 which is 2 power 3 which is 8
this loop will continue till ans<=n

Complexity
Time complexity: 0(logn)
We have just used a single loop where answer is incemented by power of 2
Space complexity: 0(1)
Since no extra space is used */