/**
 * https://leetcode.com/problems/implement-queue-using-stacks/
 */
class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        m_queueSize++;
        if (m_queueSize > m_bufferSize) {
            int* newBuffer = new int[m_bufferSize*2];
            if (m_backCursor >= m_frontCursor) {
                memcpy(newBuffer, m_buffer + m_frontCursor, sizeof(int)*(m_queueSize-1));
            } else {
                memcpy(newBuffer, m_buffer + m_frontCursor, sizeof(int)*(m_bufferSize-m_frontCursor));
                memcpy(newBuffer + (m_bufferSize-m_frontCursor), m_buffer, sizeof(int)*(m_backCursor));
            }
            m_bufferSize = m_bufferSize * 2;
            m_frontCursor = 0;
            m_backCursor = m_queueSize;
            
            int* temp = m_buffer;
            m_buffer = newBuffer;
            newBuffer = temp;
            delete[] newBuffer;
        }
        m_backCursor = (m_backCursor + 1) % m_bufferSize;
        int index = (m_backCursor-1 < 0) ? (m_backCursor-1+m_bufferSize) : (m_backCursor-1);
        m_buffer[index] = x;
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (m_queueSize > 0) {
            m_frontCursor = (m_frontCursor + 1) % m_bufferSize;
            m_queueSize--;
        }
    }

    // Get the front element.
    int peek(void) {
        if (m_queueSize > 0) {
            return m_buffer[m_frontCursor];
        }
        return -1;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return (m_queueSize == 0);
    }

    Queue() {
        m_bufferSize = 10;
        m_buffer = new int[m_bufferSize];
        m_frontCursor = 0;
        m_backCursor = 0;
        m_queueSize = 0;
    }
    ~Queue() {
        if (m_buffer) {
            delete[] m_buffer;
        }
    }
private:
    int* m_buffer;
    int m_bufferSize;
    int m_frontCursor; // [begin, 
    int m_backCursor;  // end)
    int m_queueSize;   // size = back-front
};

