//
//  main.cpp
//  cpptess
//
//  Created by 苏树祥 on 2020/1/30.
//  Copyright © 2020 苏树祥. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#include <string>

using namespace std;
class BitOperate
{
public:
    vector<vector<int>> subset(vector<int>&nums){
        vector<vector<int>> result;
        int all_set = 1 << nums.size();
        
        for(int i=0; i<all_set; i++){
            vector<int> item;
            for(int j=0; j<nums.size(); j++){
                if( i & (1<<j)){
                    item.push_back(nums[j]);
                }
            }
            result.push_back(item);
        }
        return result;
    }
};

class Recall{
public:
    void recall(int i, vector<int>&nums, vector<int>&items, vector<vector<int>>&result)
    {
        if(i >= nums.size())
            return;
        items.push_back(nums[i]);
        result.push_back(items);
        recall(i+1, nums, items, result);//
        items.pop_back();
        recall(i+1, nums, items, result);
    }
};

class LeectCode90 //leetcode 90
{
public:
    vector<vector<int>> subsetsWithDup(vector<int>&nums){
        vector<vector<int>> result;
        vector<int> item;
        set<vector<int>> res_set;
        sort(nums.begin(),nums.end());
        result.push_back(item);
        generate(0, nums, result, item, res_set);
        return result;
    }
private:
    void generate(int i, vector<int>&nums, vector<vector<int>>&result, vector<int>&item, set<vector<int>>&res_set){
        if(i >= nums.size())
            return;
        item.push_back(nums[i]);
        if(res_set.find(item)==res_set.end()){ //查重
            result.push_back(item);//
            res_set.insert(item);
        }
        generate(i+1, nums, result, item, res_set);
        item.pop_back();
        generate(i+1, nums, result, item, res_set);
    }
};
class LeetCode40{
public:
    vector<vector<int>> combinationSum2(vector<int>&candidates, int target){
        vector<vector<int>> result;
        set<vector<int>> res_set;
        vector<int> item;
        sort(candidates.begin(), candidates.end());
        generate(0, candidates, target, 0,item, result, res_set);
        return result;
    }
    
private:
    void generate(int i, vector<int>&candidates, int target, int sum, vector<int>&item, vector<vector<int>>&result, set<vector<int>>&res_set){
        if(i>=candidates.size() || sum>target)
            return;
        if(sum==target && res_set.find(item) == res_set.end())
        {
            result.push_back(item);
            res_set.insert(item);
        }
        item.push_back(candidates[i]);
        generate(i+1, candidates, target, sum+candidates[i], item, result, res_set);
        item.pop_back();
        generate(i+1, candidates, target, sum, item, result, res_set);
        
    }
};

class LeetCode22{
public:
    vector<string> generateParenthesis(int n){
        vector<string> result;
        
        return result;
    }
};

class LeetCode51 //N皇后
{
public:
    
    vector<vector<string>> solveNQueue(int n)
    {
        //对于 N*N 棋盘， 每行只能放一个皇后
        //递归每一行放置，若可以放置皇后，则按列顺序递归放置皇后，并更新mark数组
        //递归进行下一行的皇后放置，该递归结束后，恢复mark数组，并尝试下一个可能放置皇后的列
        //当递归可以完成N个皇后的放置，则该结果保存并返回。
        vector<vector<int>> mark;
        vector<vector<string>> result;
        vector<string> location;
        for (int i=0; i<n; i++)
        {
            mark.push_back((vector<int>()));
            for(int j=0; j<n; j++)
            {
                mark[i].push_back(0);
            }
            location.push_back("");
            location[i].append(n, '.');
        }
        generate(0, n, location, result, mark);
        return result;
    }

    void generate(int k, int n, vector<string> &location, vector<vector<string>> &result, vector<vector<int>> &mark)
    {
        if( k == n)
        {
            result.push_back(location);
            return;
        }
        for( int i=0; i<n; i++)
        {
            if( mark[k][i] == 0 )
            {
                vector<vector<int>> temp_mark = mark;
                location[k][i] = 'Q';
                put_down_the_queue(k, i, mark);
                generate(k+1, n, location, result, mark);
                mark = temp_mark;
                location[k][i] = '.';
            }
        }
    }

    void put_down_the_queue(int x, int y, vector<vector<int>>&mark)
    {
        static const int dx[] = {-1,1,0,0,-1,-1,1,1};
        static const int dy[] = {0,0,-1,1,-1,1,-1,1};
        mark[x][y] = 1;
        for(int i=1; i<mark.size(); i++)
        {
            for(int j=0; j<8; j++)
            {
                int newX = x + i * dx[j];
                int newY = y + i * dy[j];
                if(newX>=0 && newX<mark.size() && newY>=0 && newY<mark.size())
                {
                    mark[newX][newY] = 1;
                }
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    
    vector<vector<string>> result;
    
    LeetCode51 solve;
    result = solve.solveNQueue(4);

    for(int i=0; i<result.size(); i++)
    {
        cout<<"i = "<<i<<endl;
        for(int j=0; j< result[i].size(); j++){
            cout<<result[i][j]<<endl;
        }
        cout<<endl;
    }

    return 0;
}
