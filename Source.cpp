#include <iostream>

using namespace std;

//Second task, container template
//class template
//dynamic stack

template <typename T>
class DynamicStack
{

    private:

        T* stackArray;       
        int top;             
        int capacity;        

        void resize()
        {
            capacity += 1;   
            T* newStackArray = new T[capacity];
            for (int i = 0; i < top; i++)
            {
                newStackArray[i] = stackArray[i]; 
            }
            delete[] stackArray;
            stackArray = newStackArray;
        }

    public:

        // Конструктор по умолчанию
        DynamicStack() : top(0), capacity(2)
        {
            stackArray = new T[capacity];
        }

        // Деструктор
        ~DynamicStack()
        {
            delete[] stackArray;
        }

        // Метод для добавления элемента в стек
        void push(T value)
        {
            if (top == capacity)
            {
                resize();
            }
            stackArray[top++] = value;
        }

        // Метод для удаления элемента из стека
        void pop() {
            if (top > 0)
            {
                --top; 
            }
            else
            {
               cout << "stack is empty" << endl;
            }
        }

        // Метод для получения элемента на вершине стека
        T peek()
        {
            if (top > 0)
            {
                return stackArray[top - 1];
            }
            throw out_of_range("stack is empty");
        }

        void printStackRow()
        {
            cout << "\n[ ";
            for (int i = top; i >= 1; i--)
            {
                cout << stackArray[top - i] << " ";
            }
            cout << "]\n";
        }

        void printStackCol()
        {
            cout << "\n|---|\n";
            for (int i = 1; i <= top; i++)
            {
                cout << " " << stackArray[top - i] << "\n";
            }
            cout << "|---|\n";
        }
};

int main() {
    DynamicStack<int> intStack;

    //

    intStack.push(5);
    intStack.push(6);
    intStack.push(13);
    intStack.push(89);
    intStack.push(0);
    intStack.push(300);

    intStack.printStackCol();

    cout << "\nStack top: " << intStack.peek() << endl;

    intStack.pop();

    intStack.printStackCol();
    
    cout << "\nStack top after one pop: " << intStack.peek() << endl;

    cout << "\n\n" << endl;

    intStack.pop();
    intStack.pop();
    intStack.pop();
    intStack.pop();
    intStack.pop();

    intStack.pop(); intStack.pop(); intStack.pop(); intStack.pop();

    intStack.printStackCol();

    cout << "\n\n" << endl;

    DynamicStack<char> charStack;

    charStack.push('H');
    charStack.push('e');
    charStack.push('l');
    charStack.push('l');
    charStack.push('o');

    charStack.printStackCol();
    charStack.printStackRow();

    cout << "\n\n" << endl;

    DynamicStack<string> strStack;

    int i = 19;
    while (i > 0)
    {
        strStack.push("Hello");
        i--;
    }

    strStack.printStackCol();
    strStack.printStackRow();

    return 0;
}