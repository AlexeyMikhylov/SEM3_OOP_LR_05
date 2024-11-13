#include <iostream>

using namespace std;

//Second task, container template
//class template
//dynamic stack

template <typename T>
class DynamicStack
{

    private:

        T* stackArray;       // Указатель на массив для хранения элементов стека
        int top;             // Индекс вершины стека
        int capacity;        // Вместимость стека

        // Метод для увеличения размера массива, если это необходимо
        void resize()
        {
            capacity += 1;                      // Увеличиваем в два раза
            T* newStackArray = new T[capacity]; // Создаем новый массив
            for (int i = 0; i < top; i++)
            {
                newStackArray[i] = stackArray[i]; // Копируем старые элементы
            }
            delete[] stackArray;                // Удаляем старый массив
            stackArray = newStackArray;        // Указывает на новый массив
        }

    public:

        // Конструктор по умолчанию
        DynamicStack() : top(0), capacity(2)
        {
            stackArray = new T[capacity]; // Инициализируем массив
        }

        // Деструктор
        ~DynamicStack()
        {
            delete[] stackArray; // Освобождаем память
        }

        // Метод для добавления элемента в стек
        void push(T value)
        {
            if (top == capacity)
            {
                resize(); // Увеличиваем размер, если стек полон
            }
            stackArray[top++] = value; // Добавляем элемент
        }

        // Метод для удаления элемента из стека
        void pop() {
            if (top > 0)
            {
                --top; // Уменьшаем индекс вершины стека
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
                return stackArray[top - 1]; // Возвращаем элемент
            }
            throw out_of_range("stack is empty"); // Исключение при пустом стеке
        }

        // Метод для проверки пустоты стека
        bool isEmpty()
        {
            return top == 0;
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

// Пример использования
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

    int i = 20;
    while (i > 0)
    {
        strStack.push("Hello");
        i--;
    }

    strStack.printStackCol();
    strStack.printStackRow();

    return 0;
}