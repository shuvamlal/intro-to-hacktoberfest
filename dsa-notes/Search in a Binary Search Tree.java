class Solution {
    public TreeNode searchBST(TreeNode root, int val) {
        // while(root!=null) {
        //     if(root.val == val)
        //         return root;
        //     if(root.val>val)
        //         root = root.left;
        //     else if(root.val<val)
        //         root = root.right;
        // }
        // return null;
        if(root==null || root.val==val)
            return root;
        // if(root.val==val)
        //     return root;
        if(root.val>val)
            root = searchBST(root.left, val);
        else if(root.val<val)
            root = searchBST(root.right, val);
        return root;
    }
}
