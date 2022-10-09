class KthLargest {

    PriorityQueue<Integer> pq;
    int capacity;
    public KthLargest(int k, int[] nums) {
        this.capacity = k;
        this.pq = new PriorityQueue<>();
        for(int n: nums) {
            this.pq.offer(n);
        }
    }
    
    public int add(int val) {
        pq.offer(val);
        while(pq.size()>capacity) {
            pq.poll();
        }
        return pq.peek();
    }
}
