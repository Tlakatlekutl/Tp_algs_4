/*
Во всех задачах из следующего списка следует написать структуру данных, обрабатывающую команды
push* и pop*.
Формат входных данных.
В первой строке количество команд n. n ≤ 1000000.
Каждая команда задаётся как 2 целых числа: a b.
a = 1  push front
a = 2  pop front
a = 3  push back
a = 4  pop back
Для очереди используются команды 2 и 3. Для дека используются все четыре команды.
Если дана команда pop*, то число b  ожидаемое значение.Если команда pop вызвана для пустой структуры
данных, то ожидается “-1”.
Формат выходных данных.
Требуется напечатать YES  если все ожидаемые значения совпали. Иначе, если хотя бы одно ожидание не
оправдалось, то напечатать NO.
4_1. Реализовать очередь с динамическим зацикленным буфером.
*/
#include <iostream>
#define MUL_BUFFER 2
using namespace std;
class myQueue {
    public:
        explicit myQueue(int size = 0):head(0), tail(0), bufferSize(size) {
            buf = new int[bufferSize];
        }
        ~myQueue(){
            delete[] buf;
        }
        int Pop() {
            if (isEmpty())
                return -1;
            int result = buf[head];
            head = ( head + 1 ) % bufferSize;
            return result;
        }
        void Push(int value) {
            buf[tail] = value;
            if ((tail+1) % bufferSize == head )
                addBuffer();
            else
               tail = ( tail + 1 ) % bufferSize;
        }
        bool isEmpty() const{
            return head == tail;
        }
        void printQueue() {
            for (int i = 0; i < bufferSize; i++)
                cout<<buf[i];
            cout<<endl;
        }
    private:
        int head;
        int tail;
        int *buf;
        int bufferSize;
        void addBuffer() {
            //printQueue();
            int * newBuf = new int[bufferSize*MUL_BUFFER];
            for (int i = 0, j = head; i < bufferSize; i++, j=(j+1)%bufferSize)
                newBuf[i] = buf[j];
            delete[] buf;
            buf = newBuf;
            head = 0;
            tail = bufferSize;
            bufferSize*=MUL_BUFFER;
            // printQueue();
        }
};

int main() {
    int command_size = 0;
    cin >> command_size;
    int command = 0, input = 0, out_result = 0;
    myQueue que(4);
    for (int i = 0; i  < command_size; i++) {
        cin >> command >> input;
        switch (command) {
            case 3: que.Push(input); break;
            case 2:
            out_result = que.Pop();
                if ( out_result != input) {
                    cout<<"NO";//<<command<<" "<<input;
                    return 0;
                }
            break;
        }
    }
    cout<<"YES";
    return 0;
}