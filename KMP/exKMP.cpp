void exKMP(char *s, char *t, int *f, int *extend){  ///s的每个后缀与t的lcp
    int lens = strlen(s), lent = strlen(t), i, j;

    // extend与s等长, 并且需要初始化为0
    for(i = 0; i < lens; i++) extend[i] = 0;

    f[1] = 0;
    for(i = 1, j = 0; i < lent; f[++i]=j) {
        while(j && t[i] != t[j]) j = f[j];
        if(t[i] == t[j]) j++;
    }

    for(i = 0, j = 0; i < lens; i++) {
        while(j && s[i] != t[j]) {
            extend[i-j] = j; // Tj发生变化前
            j = f[j];
        }
        if(s[i] == t[j]) j++;
        if(j == lent) {extend[i+1-j] = j; j = f[j];} // Tj 发生变化前
    }

    // 最后, 需要求完剩余的部分, 因为匹配的结束是 Si 到结尾, 这时 i-j 还未到末尾
    while(i-j < lens) extend[i-j] = j, j = f[j];
}