# turing_machine
board game turing machine
# introduction
图灵机（turing machine）是一款桌游，通过逻辑分析和验证结果推理出最后的密码

密码为三位数字，每一位为1-5，111-555总共125种组合

每一个谜题有若干个验证器（verifier），每个验证器有若干个条件，其中只有一个真实生效

当确定了每一个验证器的真实条件后，题目能够保证只存在唯一解。

玩家可以选取不同的密码，用来测试次密码是否能够验证器，用来推理出真实生效的条件

例如有验证器A 为 blue = 1 和 blue > 1
可以用blue 为 1 的密码进行测试，如果验证器A返回true，则真实条件为blue=1，相反若为false，说明真实条件为blue > 1

# self thinking





