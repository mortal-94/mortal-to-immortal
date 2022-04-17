class MyQueue
{
public:
    stack<int> stackIn;  //用于存储输入的栈
    stack<int> stackOut; //用于存储输出的栈
    MyQueue()
    {
    }

    void push(int x)
    { //输入
        stackIn.push(x);
    }

    int pop()
    { //输出
        if (stackOut.empty())
        { //如果存储输出的栈为空了，就把存储输入的栈一个个压进输出栈
            while (!stackIn.empty())
            {
                stackOut.push(stackIn.top());
                stackIn.pop();
            }
        }
        int Out = stackOut.top();
        stackOut.pop();
        return Out;
    }

    int peek()
    {                            //获取第一个元素，注意是拷贝一份返回，与弹出不同
        int Front = this->pop(); //可以使用已实现的输出功能
        //不过这样输出后，该元素就会被删除，所以还要加回去。
        stackOut.push(Front);
        return Front;
    }

    bool empty()
    { //判断是否为空。
        //两个栈都为空时，队列为空。
        return stackOut.empty() && stackIn.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

//思路来源：
// https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0225.%E7%94%A8%E9%98%9F%E5%88%97%E5%AE%9E%E7%8E%B0%E6%A0%88.md

//本人在注释中加了点个人理解  ( mortal-94