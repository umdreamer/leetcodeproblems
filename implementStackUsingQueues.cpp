/**
 * https://leetcode.com/problems/implement-stack-using-queues/
 */

class Stack {
public:
    Stack() {
        m_bufferSize = 10;
        m_buffer = new int[m_bufferSize];
        m_stackSize = 0;
        m_topCursor = -1;
    }
    ~Stack() {
        if (m_buffer) {
            delete[] m_buffer;
        }
    }
//Push element x onto stack.
    void push(int x) {
        m_topCursor++;
        if (m_topCursor >= m_bufferSize) {
            int* newBuffer = newint[m_bufferSize * 2];
            memcpy(newBuffer, m_buffer, sizeof(int) * m_bufferSize);
            m_bufferSize = m_bufferSize * 2;
            int* temp = m_buffer;
            m_buffer = newBuffer;
            newBuffer = temp;
            delete[] newBuffer;
        }
        m_buffer[m_topCursor] = x;
        m_stackSize++;
    }
    
//Removes the element on top of the stack.
    void pop() {
        if (m_stackSize > 0) {
            m_topCursor--;
            m_stackSize--;
        }
    }
    
//Get the top element.
    int top() {
        if(m_stackSize > 0) {
            return m_buffer[m_topCursor];
        }
        return-1;
    }
    
//Return whether the stack is empty.
    bool empty() {
        return (m_stackSize == 0);
    }
    
private:
    int* m_buffer;
    int m_bufferSize;
    int m_stackSize;
    int m_topCursor;
};
