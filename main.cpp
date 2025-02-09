#include <iostream>
#include <random>
#include <chrono>
class subvector
{
private:
    int *mas;
    unsigned int top;
    unsigned int capacity;
public:
    subvector()
    {
        this->capacity = 0;
        this->top = 0;
        this->mas = NULL;
    }
    ~subvector()
    {
        delete[] this->mas;
    }
    void resize(unsigned int new_capacity)
    {
        int* new_mas = new int[new_capacity];

        for (int i = 0; i < this->top; i++)
        {
            new_mas[i] = this->mas[i];
        }
        delete[] this->mas;
        this->mas = new_mas;
        this->capacity = new_capacity;
    }

    void push_back(int d)
    {
        if (this->top == this->capacity)
        {
            this->resize(2 * this->capacity + 1);
        }
        this->mas[this->top++] = d;
    }
    int pop_back()
    {
        if (this->top == 0) return 0;
        else
        {
            return this->mas[--this->top];
        }
    }
    void shrink_to_fit()
    {
        if (this->capacity > this->top)
        {
            int* new_mas = new int[this->top];
            int new_capacity = this->top;

            for (unsigned int i = 0; i < this->top; i++)
            {
                new_mas[i] = this->mas[i];
            }

            delete[] this->mas;
            this->mas = new_mas;
            this->top = new_capacity;
            this->capacity = new_capacity;
        }
    }
    unsigned int size()
    {
        return this->capacity + 1;
    }
    void clear()
    {
        this->top = 0;
    }
};

int main()
{
    subvector sv;
    sv.resize(20);
    for (int i = 1; i < 11; i++)
    {
        sv.push_back(i);
    }
    sv.shrink_to_fit();
    unsigned int d = sv.size();
    for (unsigned int i = 1; i < d; i++)
    {
        std::cout << sv.pop_back() << std::endl;
    }
    return 0;
}






