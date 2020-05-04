// Vector.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Vector.h"
#include <atlcomcli.h>
#include <stdint.h>
#include <stdbool.h>
using namespace std;

int main()
{
    /*Vector<int> vector(5);

    for (int i = 0; i < 8; i++)
    {
        vector.Add(i);
    }*/

    Vector<int> vector = { 3, 4, 5, 6, 7, 8 };

    vector.Print();
    cout << "Vector size: " << vector.GetSize() << endl;

    if (!vector.IsEmpty())
    {
        cout << "Vector is not empty." << endl;
    }
    else
    {
        cout << "Vector is empty." << endl;
    }

    cout << "Copy vector." << endl;
    Vector<int> copyVector(3);
    copyVector = vector;
    copyVector.Print();

    cout << "Move vector." << endl;
    Vector<int> moveVector(6);
    moveVector = std::move(vector);
    moveVector.Print();
    cout << "Vector size: " << vector.GetSize() << endl;
    cout << "Allocated size: " << vector.GetAllocatedSize() << endl;

    cout << "Update elem at position []." << endl;
    vector[1] = 100;
    vector.Print();

    /*  copyVector.Clear();

      cout << "Add elem at index." << endl;
      vector.AddAtIndex(2, vector[4]);
      vector.Print();

      cout << "Get front: "<< vector.GetFront() << endl;
      vector.GetFront() = 5;
      cout << "Get front updated: " << vector.GetFront() << endl;

      cout << "Get back: " << vector.GetBack() << endl;

      cout << "Add vector at back: " << endl;
      Vector<int> vectorToAdd(3);*/

      /* for (int i = 100; i < 102; i++)
       {
           vectorToAdd.Add(i);
       }

       vectorToAdd.Print();

       vector.Add(vectorToAdd);
       vector.Print();

       cout << "New size: " << vector.GetSize() << endl;

       cout << "Compare content of 2 vectors: " << endl;
       Vector<int> vector1(2);
       Vector<int> vector2(2);*/

       //for (int i = 500; i < 502; i++)
       //{
       //    vector1.Add(i);
       //    vector2.Add(i);
       //}

       //if (vector1 == vector2)
       //{
       //    cout << "Vector1 is equal with vector2." << endl;
       //}
       //else
       //{
       //    cout << "Vector1 is not equal with vector2." << endl;
       //}

       //if (vector1 == vector)
       //{
       //    cout << "Vector1 is equal with vector2." << endl;
       //}
       //else
       //{
       //    cout << "Vector1 is not equal with vector2." << endl;
       //}

       //if (vector1 != vector2)
       //{
       //    cout << "Vector1 is equal with vector2." << endl;
       //}
       //else
       //{
       //    cout << "Vector1 is not equal with vector2." << endl;
       //}

       //if (vector1 != vector)
       //{
       //    cout << "Vector1 is equal with vector2." << endl;
       //}
       //else
       //{
       //    cout << "Vector1 is not equal with vector2." << endl;
       //}

       //cout << "Replace at index: " << endl;
       //vector.Replace(5, 1);
       //vector.Print();

       //cout << "Remove at index: " << endl;
       //vector.Remove(1);
       //vector.Print();
       //cout << "New size after remove: " << vector.GetSize() << endl;

       //cout << "Fast remove: " << endl;
       //vector.FastRemove(2);
       //vector.Print();
       //cout << "New size after fast remove: " << vector.GetSize() << endl;

       //cout << "Remove back: " << endl;
       //vector.RemoveBack();
       //vector.Print();
       //cout << "New size after remove back: " << vector.GetSize() << endl;

       //Vector<int> v = { 3, 4, 5, 6, 7 };
       //v.Print();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
