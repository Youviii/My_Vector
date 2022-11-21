#pragma once
#include <iostream>

template <typename TypeOfElement>
class MyVector
{
public:
    MyVector()
    {
        dataPointer = new TypeOfElement[1];
        length = 0;
        capacity = 1;
    }
    MyVector(const MyVector& rhs)
    {
        if (this != &rhs)
        {
            dataPointer = new TypeOfElement[rhs.capacity];
            for (int i = 0; i < rhs.length; i++)
                dataPointer[i] = rhs.dataPointer[i];
            length = rhs.length;
            capacity = rhs.capacity;
        }
    }
    ~MyVector() { delete[] dataPointer; }
    MyVector& operator= (const MyVector& rhs)
    {
        if (this != &rhs)
        {
            delete[] dataPointer;
            dataPointer = new TypeOfElement[rhs.capacity];
            for (int i = 0; i < rhs.length; i++)
                dataPointer[i] = rhs.dataPointer[i];
            length = rhs.length;
            capacity = rhs.capacity;
        }
        return *this;
    }


    void Print()
    {
        std::cout << "\nBegin----print----InVector\n";
        for (int i = 0; i < length; i++)
            std::cout << dataPointer[i] << " ";

        std::cout << "\nEnd----print----InVector\n";
    }
    void PushBack(TypeOfElement newElement) //����� ��������� ����� ������� � ����� ������� � ����������� ���������� ����� �� 1
    {
        if (capacity <= length) UpCapacity(capacity + 1);
        dataPointer[length] = newElement;
        length++;
    }

    MyVector& operator+= (const MyVector& rhs)
    {
        UpCapacity(capacity + rhs.capacity);

        for (int i = 0; i < rhs.length; i++)
            dataPointer[i + length] = rhs.dataPointer[i];
        length += rhs.length;
        capacity += rhs.capacity;
        return *this;
    }

    MyVector operator+ (const MyVector& rhs) const
    {
        MyVector new_vec(*this);
        new_vec.UpCapacity(new_vec.capacity + rhs.capacity);

        for (int i = 0; i < rhs.length; i++)
            new_vec.dataPointer[i + length] = rhs.dataPointer[i];
        new_vec.length += rhs.length;
        return new_vec;
    }

    TypeOfElement& operator[] (int index) { return dataPointer[index]; } //�������� ��������������
    const TypeOfElement& operator[](int index) const { return dataPointer[index]; } //�������� ��������������
    const TypeOfElement& At(int index) const { return dataPointer[index]; } //����� ��������������

    void Clear()
    {
        delete[] dataPointer;
        dataPointer = new TypeOfElement[1];
        length = 0;
        capacity = 1;
    }
    void DeleteIndex(int index)
    {
        for (int i = index; i < length; i++)
        {
            dataPointer[i] = dataPointer[i + 1];
        }
        length--;
    }
    void DeleteAllElem(TypeOfElement element)
    {
        for (int i = 0; i < length; i++)
            if (dataPointer[i] == element) DeleteIndex(i);
    }
    void DeleteOneElem(TypeOfElement element)
    {
        for (int i = 0; i < length; i++)
            if (dataPointer[i] == element)
            {
                DeleteIndex(i);
                break;
            }
    }

    void Insert(TypeOfElement element, int index)
    {
        if (capacity <= length) UpCapacity(capacity + 1);
        for (int i = length; i >= index; i--)
        {
            dataPointer[i] = dataPointer[i - 1];
        }
        dataPointer[index] = element;
        length++;
    }

    bool IsEmpty() const { return length == 0; }
    int Length() const { return length; } //����� ���������� ���������� �����
    int Capacity() const { return capacity; } //����� ���������� ���������� �����
private:

    void UpCapacity(int newCapacity) //����� ���������� ������� ����� ������
    {
        if (newCapacity > capacity)
        {
            TypeOfElement* newDataPointer = dataPointer;
            dataPointer = new TypeOfElement[newCapacity];
            for (int i = 0; i < length; i++) dataPointer[i] = newDataPointer[i];
            delete[] newDataPointer;
            capacity = newCapacity;
        }
    }

    int length; //������� ���������� ���������� ��������� ������� (���������� �����)
    int capacity; //���������� ��������� ������������� ����� ������ (���������� �����)
    TypeOfElement* dataPointer; //��������� �� ������������ ���� ������
};

template <typename TypeOfElement>
inline std::ostream& operator<< (std::ostream& os, const MyVector<TypeOfElement>& vec)
{
    for (int i = 0; i < vec.Length(); ++i)
        os << vec[i] << " ";
    return os;
}
