#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
int firstMissingPositive(vector<int>& nums){
	int len = nums.size();
    for (int i=0; i<len; i++) {
        if (nums[i]>=0)
        nums[i]--;
	    if (nums[i] > len || nums[i]<0) {
	    	nums[i] = len;
	    }
	}

	int marker = len+1;
    int prev;
    int next;

    for (int i=0; i<len; i++) {
        if (nums[i]<0 || nums[i]>=len || nums[i]==marker || nums[i]==len) {
            continue;
        }
        prev = nums[i];
        while (prev<len && nums[prev] != marker && prev>i) {
            next = nums[prev];
            nums[prev] = marker;
            prev = next;
        }
        if (prev < len) {
            nums[prev] = marker;
        }
    }

    for (int i=0; i<len; i++) {
        if (nums[i]!=marker) {
            return i+1;
        }
    }
    return len+1;
}
};

int main()
{
    Solution s;
    vector<int> input{1,2,5,0};
    cout<<s.firstMissingPositive(input)<<endl;
    input = {0,1,2,3,4,5};
    cout<<s.firstMissingPositive(input)<<endl;
    input = {1,2,3,4,5};
    cout<<s.firstMissingPositive(input)<<endl;
    input = {0,0,0,0};
    cout<<s.firstMissingPositive(input)<<endl;
    input = {1,0,100,2};
    cout<<s.firstMissingPositive(input)<<endl;
    input = {3,4,-1,1};
    cout<<s.firstMissingPositive(input)<<endl;
}
