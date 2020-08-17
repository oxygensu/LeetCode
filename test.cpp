//
//  main.cpp
//  cpptess
//
//  Created by 苏树祥 on 2020/1/30.
//  Copyright © 2020 苏树祥. All rights reserved.
//
#include "test.h"
#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <time.h>
using namespace std;
class BitOperate
{
public:
    vector<vector<int>> subset(vector<int> &nums)
    {
        vector<vector<int>> result;
        int all_set = 1 << nums.size();

        for (int i = 0; i < all_set; i++)
        {
            vector<int> item;
            for (int j = 0; j < nums.size(); j++)
            {
                if (i & (1 << j))
                {
                    item.push_back(nums[j]);
                }
            }
            result.push_back(item);
        }
        return result;
    }
};

class Recall
{
public:
    void recall(int i, vector<int> &nums, vector<int> &items, vector<vector<int>> &result)
    {
        if (i >= nums.size())
            return;
        items.push_back(nums[i]);
        result.push_back(items);
        recall(i + 1, nums, items, result); //
        items.pop_back();
        recall(i + 1, nums, items, result);
    }
};

class LeectCode90 //leetcode 90
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> item;
        set<vector<int>> res_set;
        sort(nums.begin(), nums.end());
        result.push_back(item);
        generate(0, nums, result, item, res_set);
        return result;
    }

private:
    void generate(int i, vector<int> &nums, vector<vector<int>> &result, vector<int> &item, set<vector<int>> &res_set)
    {
        if (i >= nums.size())
            return;
        item.push_back(nums[i]);
        if (res_set.find(item) == res_set.end())
        {                           //查重
            result.push_back(item); //
            res_set.insert(item);
        }
        generate(i + 1, nums, result, item, res_set);
        item.pop_back();
        generate(i + 1, nums, result, item, res_set);
    }
};
class LeetCode40
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        set<vector<int>> res_set;
        vector<int> item;
        sort(candidates.begin(), candidates.end());
        generate(0, candidates, target, 0, item, result, res_set);
        return result;
    }

private:
    void generate(int i, vector<int> &candidates, int target, int sum, vector<int> &item, vector<vector<int>> &result, set<vector<int>> &res_set)
    {
        if (i >= candidates.size() || sum > target)
            return;
        if (sum == target && res_set.find(item) == res_set.end())
        {
            result.push_back(item);
            res_set.insert(item);
        }
        item.push_back(candidates[i]);
        generate(i + 1, candidates, target, sum + candidates[i], item, result, res_set);
        item.pop_back();
        generate(i + 1, candidates, target, sum, item, result, res_set);
    }
};

class LeetCode22
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;

        return result;
    }
};

class LeetCode51 //N皇后 base version
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
        for (int i = 0; i < n; i++)
        {
            mark.push_back((vector<int>()));
            for (int j = 0; j < n; j++)
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
        if (k == n)
        {
            result.push_back(location);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (mark[k][i] == 0)
            {
                vector<vector<int>> temp_mark = mark;
                location[k][i] = 'Q';
                put_down_the_queue(k, i, mark);
                generate(k + 1, n, location, result, mark);
                mark = temp_mark;
                location[k][i] = '.';
            }
        }
    }

    void put_down_the_queue(int x, int y, vector<vector<int>> &mark)
    {
        static const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        static const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
        mark[x][y] = 1;
        for (int i = 1; i < mark.size(); i++)
        {
            for (int j = 0; j < 8; j++)
            {
                int newX = x + i * dx[j];
                int newY = y + i * dy[j];
                if (newX >= 0 && newX < mark.size() && newY >= 0 && newY < mark.size())
                {
                    mark[newX][newY] = 1;
                }
            }
        }
    }
};

class LeetCode51_1 //N皇后 base version
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
        for (int i = 0; i < n; i++)
        {
            mark.push_back((vector<int>()));
            for (int j = 0; j < n; j++)
            {
                mark[i].push_back(0);
            }
            location.push_back("");
            location[i].append(n, '.');
        }
        generate(0, 0, n, location, result, mark);
        return result;
    }

    // k is current line, l is current total line
    void generate(int k, int l, int n, vector<string> &location, vector<vector<string>> &result, vector<vector<int>> &mark)
    {
        if (k == n)
        {
            result.push_back(location);
            return;
        }
        if (k = l)
        {
            for (int i = 0; i < n; i++)
            {
                if (mark[k][i] == 0)
                {
                    vector<vector<int>> temp_mark = mark;
                    location[k][i] = 'Q';
                    put_down_the_queue(k, i, mark);
                    generate(k + 1, l + 1, n, location, result, mark);
                    mark = temp_mark;
                    location[k][i] = '.';
                }
            }
        }
        else
        {
            return;
        }
    }

    void put_down_the_queue(int x, int y, vector<vector<int>> &mark)
    {
        static const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        static const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
        mark[x][y] = 1;
        for (int i = 1; i < mark.size(); i++)
        {
            for (int j = 0; j < 8; j++)
            {
                int newX = x + i * dx[j];
                int newY = y + i * dy[j];
                if (newX >= 0 && newX < mark.size() && newY >= 0 && newY < mark.size())
                {
                    mark[newX][newY] = 1;
                }
            }
        }
    }
};

class LeetCodeMergeSort
{
public:
    /**********************************
分治算法：
    1、分解，将要解决的问题划分成若干规模较小的同类问题
    2、求解，当子问题划分的足够小时，用较简单的方法解决
    3、合并，将子问题的解逐层合并，构成原问题的解
**********************************/

    void merge_sort_two_vec(vector<int> &sub_vec1, vector<int> &sub_vec2, vector<int> &vec)
    {
        int i = 0;
        int j = 0;
        while (i < sub_vec1.size() && j < sub_vec2.size())
        {
            if (sub_vec1[i] <= sub_vec2[j])
            {
                vec.push_back(sub_vec1[i]);
                i++;
            }
            else
            {
                vec.push_back(sub_vec2[j]);
                j++;
            }
        }

        for (; i < sub_vec1.size(); i++)
        {
            vec.push_back(sub_vec1[i]);
        }
        for (; j < sub_vec2.size(); j++)
        {
            vec.push_back(sub_vec2[j]);
        }
    }

    void merge_sort(vector<int> &vec)
    {
        if (vec.size() < 2)
        {
            return;
        }
        int mid = vec.size() / 2;
        vector<int> sub_vec1;
        vector<int> sub_vec2;
        for (int i = 0; i < mid; i++)
        {
            sub_vec1.push_back(vec[i]);
        }
        for (int i = mid; i < vec.size(); i++)
        {
            sub_vec2.push_back(vec[i]);
        }

        merge_sort(sub_vec1);
        merge_sort(sub_vec2);
        vec.clear();
        merge_sort_two_vec(sub_vec1, sub_vec2, vec);
    }
};

class LeetCode315
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {
    }
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    /* data */
};

/*
    给定一个二叉树与整数sum，找出所有从根节点到叶结点的路径，这些路径上的节点值累加和为sum。
    叶节点指的是没有子节点的节点。
*/
class LeetCode113
{
public:
    vector<vector<int>> result;
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        clock_t start, end;
        vector<int> currentPath;
        start = clock();
        generate(root, currentPath, sum);
        end = clock();
        cout << "execute time : " << end - start << endl;
        return result;
    }
    /*
    这里出现个问题，在LeetCode网站中测试，如果currentPath 以形参传进来，整体处理的时间比以&currentPath 引用长很多。
    形参不需要pop_back， 引用需要pop_back.
    我的理解是 在很大的一颗树下，以形参传递时候，push_back进来数可能需要在创建vector 的空间，创建vector空间比较耗时，
    然后需要换路的时候，又得重新创建vector空间，所以如果以引用的方式传递，只需要创建最大的vector空间一次就可以了。
    */
    void generate(TreeNode *root, vector<int> &currentPath, int sum)
    {
        if (root == NULL)
        {
            return;
        }
        currentPath.push_back(root->val);
        if (!root->left && !root->right && root->val == sum)
        {
            result.push_back(currentPath);
        }
        generate(root->left, currentPath, sum - root->val);  //继续搜索左节点
        generate(root->right, currentPath, sum - root->val); //继续搜索右节点
        currentPath.pop_back();                              //左右节点搜索完，要弹出该节点。
    }
};

/*
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

*/
/*
因为是递归，使用函数后可认为左右子树已算出结果了，用left 和right 表示
*/
class LeetCode236
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return NULL;
        if (root == p || root == q)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        //因为是递归，这时候左右子树已经算出结果了，用left和right表示
        if (left == NULL)
            return right;
        if (right == NULL)
            return left;
        if (left && right) // p和q在两侧
            return root;

        return NULL; // 必须有返回值
    }
};

int main(int argc, const char *argv[])
{
    TreeNode a(5);
    TreeNode b(4);
    TreeNode c(8);
    TreeNode d(11);
    TreeNode e(13);
    TreeNode f(4);
    TreeNode g(7);
    TreeNode h(2);
    TreeNode x(5);
    TreeNode y(1);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    c.left = &e;
    c.right = &f;
    d.left = &g;
    d.right = &h;
    f.left = &x;
    f.right = &y;
    vector<vector<int>> result;
    LeetCode113 solve;
    result = solve.pathSum(&a, 22);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];
        }
        cout << endl;
    }

    return 0;
}
