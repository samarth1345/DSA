bool find132pattern(vector<int>& nums) {
        stack<pair<int,int>> Stack;
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(i>1){
              //we are not checking if element on top has min value with it less than nums[i]
              //because all elements below this in stack would have min value greater than or equal to this
                while(!Stack.empty() && Stack.top().first<=nums[i])
                    Stack.pop();
              //so we check it here
                if(!Stack.empty() && Stack.top().second<nums[i]){
                    return true;
                }
                else
                    Stack.push({nums[i],mini});
            }
            else{
                Stack.push({nums[i],mini});
            }
          //we need to have min vlaue with all elements because we have to make sure that
          //the min value has occured before this element in array and we are not considering the global min
            mini=min(mini,nums[i]);
        }
        return false;
    }
