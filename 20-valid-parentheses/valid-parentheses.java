class Solution {
    public boolean isValid(String s) {
        Deque<Character> stack = new ArrayDeque<>();

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
                continue;
            }

            char peek = stack.isEmpty() ? 'a' : stack.peek();
            if (c == ')' && peek != '(') return false;
            if (c == ']' && peek != '[') return false;
            if (c == '}' && peek != '{') return false;

            stack.pop();
        }

        if (stack.isEmpty()) return true;

        return false;
    }
}