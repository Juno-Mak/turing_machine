# turing_machine
board game turing machine
official website:https://turingmachine.info/

## introduction
图灵机（turing machine）是一款桌游，通过逻辑分析和验证结果推理出最后的密码
https://turingmachine.info/files/rules/rules_EN.pdf

密码为三位数字（blue-yellow-purple），每一位为1-5，111-555总共125种组合

每一个谜题有若干个验证器（verifier），每个验证器有若干个条件，其中只有一个真实生效
https://turingmachine.info/files/rules/TuringMachine_The_X_Paradox_EN.pdf

当确定了每一个验证器的真实条件后，题目能够保证只存在唯一解。

玩家可以选取不同的密码，用来测试次密码是否能够验证器，用来推理出真实生效的条件

例如有验证器A 为 blue = 1 和 blue > 1
可以用blue 为 1 的密码进行测试，如果验证器A返回true，则真实条件为blue=1，相反若为false，说明真实条件为blue > 1

## to do list

| Work                                             | Current Progress |
| ------------------------------------------------ | ---------------- |
| Find possible passwords based on given verifiers | done             |
| self password verification function              | done             |
| find final solution based on possible passwords  | done             |
| optimal path for verification                    | doing            |
| puzzle create function                           |                  |
| support extreme&nightmare mode                   |                  |
| Interactive functions                            |                  |



## self thinking
1.由于存在唯一解，所以求三位密码的目标 也可以转换成 测试出每一个验证器的真实条件

2.验证器中的条件 不一定互补也不一定相斥
  例如验证器32的三个条件分别为 
  1）blue > 3
  2）yellow > 3
  3）purple > 3
  对于密码 144 来说 既满足2也满足3
  对于密码 111 来说 不满足任何一个条件

3.由2得出：最后的密码必须每一个真实条件
  如果一个密码，不满足验证器中的所有条件，那么一定不是最终密码

4.由1和2得出：验证条件存在唯一解
  假设 带有验证器32的谜题中，144为最后正确解
  那么验证条件的唯一解能说明：假若使用另一个条件，则不存在唯一解（存在复数解）

5. 综合1-4点可以将谜题原本的思路  **求出三位密码**
   转换为： **求出存在唯一解的条件组合**







![image-20231010205013327](image/image-20231010204815453.png)

### Sample:

## #C64 FRS A

![image-20231014001729255](image/image-20231014001729255.png)

![image-20231014001748371](image/image-20231014001748371.png)



![image-20231014001918708](image/image-20231014001918708.png)
