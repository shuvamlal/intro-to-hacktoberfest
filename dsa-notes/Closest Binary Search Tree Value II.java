class Solution {
    public List<Integer> closestKValues(TreeNode root, double target, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>((a,b)->{
            return Math.abs(a-target)<Math.abs(b-target)?1:-1;
        });
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        while(!queue.isEmpty()) {
            TreeNode node = queue.poll();
            pq.offer(node.val);
            if(node.left!=null)
                queue.offer(node.left);
            if(node.right!=null)
                queue.offer(node.right);
        }
        // System.out.println(pq);
        while(pq.size()>k){
            pq.poll();
        }
        List<Integer> ls = new ArrayList<>();
        while(pq.size()>0) {
            ls.add(pq.poll());
        }
        // System.out.println(pq);
        return ls;
    }
}
