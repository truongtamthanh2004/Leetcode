func abs(x int) int {
    if x < 0 {
        return -x
    }

    return x
}

func scoreOfString(s string) int {
    res := 0

    for i := 0; i < len(s) - 1; i++ {
        res += abs(int(s[i]) - int(s[i + 1]));
    }
    
    return res;
}