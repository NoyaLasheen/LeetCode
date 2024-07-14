class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> stack = new Stack<>();

    for(int i=0; i<asteroids.length; i++) {
        int asteroid = asteroids[i];
        if(!stack.isEmpty() && stack.peek() > 0 && asteroid < 0) {

            // Equal (Both asteroids get destroyed)
            if(Math.abs(asteroid) == Math.abs(stack.peek())) {
                stack.pop();
            }

            // Current asteroid is bigger than one at top of stack
            // Top asteroid in stack gets destroyed
            // Re-check current asteroid with next in stack
            else if(Math.abs(asteroid) > Math.abs(stack.peek())) {
                stack.pop();
                i--;
            }
        }
        else {
            // No collision, add asteroid to stack
            stack.push(asteroid);
        }
    }


    // Build a new array (backwards stack)
    int[] res = new int[stack.size()];
    for(int i=stack.size()-1; i>=0; i--) {
        res[i] = stack.pop();
    }

    return res;
    }
}