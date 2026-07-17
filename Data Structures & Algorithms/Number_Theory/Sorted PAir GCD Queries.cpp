// https://leetcode.com/problems/sorted-gcd-pair-queries/solutions/8402571/simple-approach-and-intution-by-veronica-wnrw

// Intuition
// First of all,think abt we just need the gcds of pairs , so why to go to each pair and find the gcd (beacsue that will result in n^2 TC)
// so first of all keep in mind that just count the gcds how many times each gcd exist
// In worst case, the gcd value could the max element that exist in the nums array
// So just try to think in this direction
// for eg you have 1->4times , gcd of 2->3 times
// so when a query is given to find gcd at index 7 you will know that first 4 indices are covered by 1 ,so obviously in this case the answer to the query would be 2.
// Now lets look at the approach to this question

// Approach
// for eg you have 2,4,6,8
// so first of all find all values divisble by 2 which is 2,4,6,8
// so total pairs where 2 is divisble is 4*(4+1)/2;
// but not all pairs formed means that the gcd is 2 (it is divisble by 2)
// in one pair(4,8) the gcd is 4
// so subtract exact[4] from here
// exact [4] means the pairs where gcd is exactly 4
// so at first just calculate the pairs with divisibilty part
// and then again traverse from gcd max to 1
// and then again just go through all the multiples of that element
// and then just subtract all the pairs formed where the gcd of bigger elment still exists
// and then w=jsut do pref sum of pairs
// beacuse lets say that 4 disnt even existed
// so in place of 4 you would still have the pref values at 3 (thats i how i would be able to apply binary search on prefix array ), it will be sorted and the indices of pref array will denote he gcds

// Now apply binary search on pref array
// as discussed in the intutuion part .

// Complexity
// Time complexity:
// for loop 1 :O(n)
// for loop 2 (harmonic series): O(MlogM) where M is max element
// for loop 3: O(MlogM)
// for loop 4: O(M);
// for loop5(loop over queries): O(NlogM) where N is size of queries array
// so overall TC will be :O(n + MlogM + NlogM );

// Space complexity:
// We have used 3 arrays of size M and one map of size M
// so SC will be O(4M) which is ~ O(M);

// Code
#include <bits/stdc++.h> 
using namespace std;
class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& qu) {
        int mx=nums[0];
        unordered_map<int,int> m;
        for(int x:nums) {
            mx=max(mx,x);
            m[x]++;
        }
        vector<long long> exact(mx+1,0);
        vector<long long> pref(mx+1,0);
        vector<long long> pairs(mx+1,0);
        for(int i=1;i<=mx;i++){
            long long count=0;
            for(int j=i;j<=mx;j+=i){
                if(m.count(j)) count+=m[j];
            }
            long long pair=(count*(count-1))/2;
            pairs[i]=pair;
        }
        exact=pairs;
        for(int i=mx;i>=1;i--){
            int first=i+i;;
            for(int j=first;j<=mx;j+=i){
                exact[i]-=exact[j];
            }
        }
        for(int i=1;i<=mx;i++){
            pref[i]=pref[i-1]+exact[i];
        }
        vector<int> ans;
        for(int i=0;i<qu.size();i++){
            long long idx=qu[i];
            int index=upper_bound(pref.begin(),pref.end(),idx)-pref.begin();
            ans.push_back(index);
        }
        return ans;
    }
};