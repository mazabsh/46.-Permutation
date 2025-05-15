#include<iostream> 
#include<algorithm> 
#include<vector> 

using namespace std; 

class Solution{
public: 
      vector<vector<int>> permute(vector<int>& nums){
        vector<vector<int>> res; 
        backtracking(nums,0,res); 
        return res; 
      }
private: 
      void backtracking(vector<int>& nums, int start, vector<vector<int>>& res){
        if(start==nums.size()){
          res.push_back(nums); 
          return; 
        }
        for(int i=start; i<nums.size(); ++i){
          swap(nums[start] ,nums[i]); 
          backtracking(nums, start+1, res); 
          swap(nums[start], nums[i]); 
        }
      }
};
int main(){
  vector<int> nums = {1,2,3}; 
  Solution sol; 
  vector<vector<int>> res = sol.permute(nums); 
  for(auto& vec:res){
    for(auto num: vec){
      cout << num << " " ; 
    }
    cout  << endl; 
  }
  return 0; 
}
