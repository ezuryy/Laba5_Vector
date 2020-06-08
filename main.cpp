#include "Vector.h"
#include "UserClass.h"

int main() {
    ///Vector 1 <int>
    int n = 5;
    int *numbers = new int[n];
    for (int i = 0; i < n; ++i) {
        numbers[i] = i;
    }
    Vector<int> v1(n, numbers);
    cout << "Vector 1 =";
    v1.print();
    for (int i = 5; i < 10; ++i) {
        v1.insert(i, i);
    }
    cout << "Vector 1 insert(i, i) =";
    v1.print();
    cout << "Vector 1 [7] = " << v1[7] << endl;
    cout << "Vector 1 at(7) = " << v1.at(7) << endl;
    cout << "Vector 1 front() = " << v1.front() << endl;
    cout << "Vector 1 back() = " << v1.back() << endl;
    cout << "Vector 1 data() = " << v1.data() << endl;
    cout << "Vector 1 empty() = " << v1.empty() << endl;
    cout << "Vector 1 size() = " << v1.size() << endl;
    cout << "Vector 1 capacity() = " << v1.capacity() << endl << endl;

    ///Vector 2 <int>
    Vector<int> v2(v1);
    cout << "Vector 1 =";
    v1.print();
    cout << "Vector 2 (Vector 1) =";
    v2.print();
    v2.insert(10, 5);
    cout << "Vector 2 insert(10, 5) =";
    v2.print();
    v1.swap(v2);
    cout << "v1.swap(v2);\n";
    cout << "Vector 1 =";
    v1.print();
    cout << "Vector 2 =";
    v2.print();
    v2.erase(0, 3);
    cout << "Vector 2 erase(0, 3) =";
    v2.print();
    cout << endl;


    ///Vector 3 <char>
    Vector<char> v3;
    for (int i = 0; i < 3; ++i) {
        v3.push_back('A');
    }
    cout << "Vector 3 push_back('A') x3 =";
    v3.print();
    v3.pop_back();
    cout << "Vector 3 pop_back() =";
    v3.print();
    cout << endl;

    ///Vector 4 <double>
    Vector<double> v4(4);
    double j = 1.123;
    for (int i = 0; i < 4; ++i) {
        v4.push_back(j);
        j += 1;
    }
    cout << "Vector 4 push_back(j) =";
    v4.print();
    v4.resize(5);
    cout << "Vector 4 resize(5) =";
    v4.print();
    v4.resize(3);
    cout << "Vector 4 resize(3) =";
    v4.print();
    v4.clear();
    cout << "Vector 4 clear() =";
    v4.print();
    cout << endl;

    ///User class Vector 5 <UserClass>
    UserClass ElemClass1, ElemClass2;
    ElemClass1.Number = 7;
    ElemClass2.Number = 8;
    Vector<UserClass> v5;
    v5.push_back(ElemClass1);
    cout << "User class Vector 5 push_back(ElemClass1) =";
    v5.print();
    v5.insert(0, ElemClass2);
    cout << "User class Vector 5 insert(0, ElemClass2) =";
    v5.print();
    cout << "User class Vector 5 [0] = " << v5[0] << endl;
    cout << "User class Vector 5 at(1) = " << v5.at(1) << endl;
    cout << "User class Vector 5 front() = " << v5.front() << endl;
    cout << "User class Vector 5 back() = " << v5.back() << endl;
    cout << "User class Vector 5 data() = " << v5.data() << endl;
    cout << "User class Vector 5 empty() = " << v5.empty() << endl;
    cout << "User class Vector 5 size() = " << v5.size() << endl;
    cout << "User class Vector 5 capacity() = " << v5.capacity() << endl;
    v5.push_back(ElemClass1);
    v5.push_back(ElemClass1);
    cout << "User class Vector 5 push_back(ElemClass1) x2 =";
    v5.print();
    v5.erase(2, 3);
    cout << "User class Vector 5 erase(2, 3) =";
    v5.print();
    v5.resize(6);
    cout << "User class Vector 5 resize(6) =";
    v5.print();
    cout << endl;

    ///User class Vector 6 <UserClass>
    Vector<UserClass> v6;
    v6 = v5;
    cout << "User class Vector 6 (= Vector 5) =";
    v6.print();
    v6.pop_back();
    cout << "User class Vector 6 pop_back() =";
    v6.print();
    v6.clear();
    cout << "User class Vector 6 clear() =";
    v6.print();
    cout << endl;

    ///User class Vector 7 <UserClass>
    UserClass ElemClass3;
    ElemClass3.Number = 1;
    UserClass *array = new UserClass[5];
    for (int i = 0; i < 5; ++i) {
        array[i] = ElemClass3;
    }
    Vector<UserClass> v7(5, array);
    cout << "User class Vector 7 =";
    v7.print();
    v7.swap(v5);
    cout << "v7.swap(v5)\n";
    cout << "User class Vector 5 =";
    v5.print();
    cout << "User class Vector 7 =";
    v7.print();
    return 0;
}

