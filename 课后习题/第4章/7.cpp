/*
分析：
设str是输入字符串，m[i][j]表示str的第i个字符到第j个字符需要添加的最少括号数，regs[i][j]表示str的第i个字符到第j个字符经过添加m[i][j]个括号后所得的正则字符序列。
为建立状态转移方程，需考察m[i][j]与regs[i][j]。
分i = j与i < j 进行讨论
情况1：i = j。 
  令m[i][j] = 1；同时对str[i]配一个配对的括号，以使regs[i][j]是正则的。 
情况2：i < j。考虑str[i] 与str[j]的配对情况。下一页进一步分析
（1）若str[i] 与str[j]配对，则m[i][j]=min{m[i + 1][j - 1]，m[i][j]}；
在m[i + 1][j - 1]<m[i][j]的情况下，对regs[i][j]只需考察字符串str[i+1..j-1]的情况，于是可令 
      regs[i][j]为str[i]、regs[i + 1][j - 1]与str[j]的合并。
处理方式：
          regs[i][j] = "(" + regs[i + 1][j - 1] + ")“
      或regs[i][j] = "[" + regs[i + 1][j - 1] + "]"。

（2）若str[i] 与str[j]不配对，则考察str[i]…str[k]与str[k+1]…str[j]的情况 
对str[i]…str[k]可得m[i][k]与regs[i][k]；
对str[k+1]…str[j]可得m[k+1][j]与regs[k+1][j]。
综合可得
     m[i][j]=min{i?k<j}{m[i][k]+ m[k + 1][j ]，m[i][j]}。  


*/