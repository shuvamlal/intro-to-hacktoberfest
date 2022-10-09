class Solution {
    public int closestValue(TreeNode root, double target) {
        int min_val = root.val;
        while(root != null) {
            min_val = Math.abs(root.val-target) < Math.abs(min_val-target)?root.val:min_val;
            if(root.val>=target){
                root = root.left;
            } else if(root.val<target){
                root = root.right;
            }
        }
        return min_val;
    }
}
