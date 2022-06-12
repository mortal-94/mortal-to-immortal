class MyStack
{
public:
    //思路： 把queue1的数据弹出顺序弄成和mystack一样
    //此时便需要一个辅助queue2，（大部分时间为空
    queue<int> queue1;
    queue<int> queue2;

    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x) //压入
    {
        queue2.push(x); //先压进辅助队列，辅助队列每次模拟栈进行压进时其实都为空
        //再把queue1的元素逐个压进辅助队列
        while (!queue1.empty())
        {
            queue2.push(queue1.front());
            queue1.pop();
        }
        //此时queue1为空了，而辅助队列的数据弹出顺序与mystack一样了
        //交换两者，恢复成辅助队列为空，queue1达到需求的状态。
        swap(queue1, queue2);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() //弹出
    {
        //据前面压进操作，直接取出queue1的第一个元素即可。
        //不过要注意 取出queue1的第一个元素是拷贝操作，还有另行删除该元素。
        int r = queue1.front();
        queue1.pop();
        return r;
    }

    /** Get the top element. */
    int top()
    {
        int r = queue1.front();
        return r;
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return queue1.empty();
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/implement-stack-using-queues/solution/yong-dui-lie-shi-xian-zhan-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// 本人加了个人理解注释。( mortal-94