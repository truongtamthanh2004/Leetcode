class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        Queue<Integer> q = new LinkedList<>();
        for (int s : students) q.offer(s);

        Deque<Integer> s = new ArrayDeque<>();
        for (int i = sandwiches.length - 1; i >= 0; i--) s.push(sandwiches[i]);

        while (!q.isEmpty()) {
            int nq = q.size();
            for (int i = 0; i < nq; i++) {
                if (q.peek() == s.peek()) {
                    q.poll();
                    s.pop();
                } else {
                    int tmp = q.poll();
                    q.offer(tmp);
                }
            }
            if (nq == q.size()) return nq;
        }

        return 0;
    }
}