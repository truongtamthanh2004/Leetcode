class Solution {
    private String processString(String s) {
        Deque<Character> stack = new ArrayDeque<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != '#') stack.push(s.charAt(i));
            else {
                if (!stack.isEmpty()) stack.pop();
            }
        }

        StringBuilder builder = new StringBuilder();
        while (!stack.isEmpty()) {
            builder.append(stack.pop() + "");
        }

        return builder.toString();
    }

    public boolean backspaceCompare(String s, String t) {
        String sAfter = processString(s);
        String tAfter = processString(t);

        return sAfter.equals(tAfter);
    }
}