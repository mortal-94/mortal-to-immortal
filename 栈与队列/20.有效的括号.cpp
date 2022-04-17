class Solution
{
public:
    bool isValid(string s)
    {
        if (s.size() % 2 != 0) // s的元素个数不是偶数，直接返回false
            return false;

        stack<char> stk; //定义一个栈，用于存在左括号。

        for (char ch : s) //开始遍历
        {
            if (ch == '(' || ch == '[' || ch == '{') //遇到左括号，压进栈中
                stk.push(ch);
            else //遇到右括号，进行判断、弹出操作。
            {
                //没有闭合
                //对于判断操作，查一下ASCII码可知，')'='('+1, ']'='['+2, '}'='{'+2
                //即，左右括号之间ASCII码要么相差1要么相差2 （不同类型括号之间相差很远，所以不影响
                if (stk.empty() || (ch != stk.top() + 1 && ch != stk.top() + 2)) //此处判定条件要把stk.empty()放在前面，否则会栈中无数据时另一个判定语句执行会报错
                    return false;

                //闭合了
                stk.pop();
            }
        }

        //若仅是左括号多余，则也会来到这里。
        //所以还要执行一次判定：
        //若都两两闭合了，stk必为空。
        return stk.empty();
    }
};