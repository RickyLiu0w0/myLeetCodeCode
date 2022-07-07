/*
 * @lc app=leetcode.cn id=2236 lang=swift
 *
 * [2236] 判断根结点是否等于子结点之和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init() { self.val = 0; self.left = nil; self.right = nil; }
 *     public init(_ val: Int) { self.val = val; self.left = nil; self.right = nil; }
 *     public init(_ val: Int, _ left: TreeNode?, _ right: TreeNode?) {
 *         self.val = val
 *         self.left = left
 *         self.right = right
 *     }
 * }
 */
/*
    Accepted
    309/309 (4 ms)    
    Your runtime beats 85.71 % of swift submissions
    Your memory usage beats 42.86 % of swift submissions (13.8 MB)
*/
class Solution {
    func checkTree(_ root: TreeNode?) -> Bool {
        // root为可选类型，可以使用如下if判断是否为非空
        if let constantNode : TreeNode = root {
            // 由于从题目知道一定有左右节点，故使用!强制解析
            return constantNode.val == constantNode.left!.val + constantNode.right!.val;
        }

        return false;
    }
}
// @lc code=end

