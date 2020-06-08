#include "Vector.h"
#include "UserClass.h"

template class Vector<char>;
template class Vector<int>;
template class Vector<double>;
template class Vector<UserClass>;

template<class T>
Vector<T>::Vector(const int &num) {
    Len = 0;
    Cap = static_cast<int>(1.5 * num);
    Data = new T[Cap];
}

template<class T>
Vector<T>::Vector(const int &num, const T *vec) {
    Len = num;
    Cap = static_cast<int>(1.5 * Len);
    Data = new T[Cap];
    for (int i = 0; i < Len; ++i) {
        Data[i] = vec[i];
    }
}

template<class T>
Vector<T>::Vector(const Vector &vector) : Len(vector.Len), Cap(vector.Cap) {
    Data = new T[Cap];
    for (int i = 0; i < Len; ++i) {
        Data[i] = vector.Data[i];
    }
}

template<class T>
Vector<T>::~Vector() {
    delete[] Data;
}

template<class T>
Vector<T> &Vector<T>::operator=(const Vector &vector) {
    Len = vector.Len;
    Cap = vector.Cap;
    Data = new T[Cap];
    for (int i = 0; i < Len; ++i) {
        Data[i] = vector.Data[i];
    }
    return *this;
}

template<class T>
T Vector<T>::operator[](const int &num) {
    if (num <= Len && num >= 0)
        return Data[num];
}

template<class T>
T Vector<T>::at(const int &pos) {
    if (pos >= Len || pos < 0) {
        throw std::out_of_range("");
    } else
        return Data[pos];
}

template<class T>
T Vector<T>::front() {
    if (Data != nullptr)
        return Data[0];
}

template<class T>
T Vector<T>::back() {
    if (Data != nullptr)
        return Data[Len - 1];
}

template<class T>
T *Vector<T>::data() {
    return Data;
}

template<class T>
bool Vector<T>::empty() {
    if (Data == nullptr || Len == 0)
        return true;
    return false;
}

template<class T>
int Vector<T>::size() {
    return Len;
}

template<class T>
void Vector<T>::reserve(const int &cap) {
    if (cap > std::numeric_limits<int>::max())
        throw std::length_error("");
    if (cap > Cap) {
        T *temp = new T[cap];
        for (int i = 0; i < Len; ++i) {
            temp[i] = Data[i];
        }
        delete[] Data;
        Data = temp;
        Cap = cap;
    }
}

template<class T>
int Vector<T>::capacity() {
    return Cap;
}

template<class T>
void Vector<T>::clear() {
    delete[] Data;
    Len = 0;
    Cap = 0;
}

template<class T>
void Vector<T>::insert(const int &pos, const T &val) {
    if (Cap < Len + 1) this->reserve(ceil(1.5 * (Len + 1)));
    if (pos <= Len) {
        for (int i = Len; i > pos; --i) {
            Data[i] = Data[i - 1];
        }
        Data[pos] = val;
        Len++;
    }
}

template<class T>
void Vector<T>::erase(const int &pos) {
    if (pos >= 0 && pos < Len) {
        for (int i = pos; i < Len - 1; ++i) {
            Data[i] = Data[i + 1];
        }
        Len--;
    }
}

template<class T>
void Vector<T>::erase(const int &pos1, const int &pos2) {
    if (pos1 >= 0 && pos1 < Len && pos2 >= 0 && pos2 < Len) {
        T *temp = new T[Cap];
        for (int i = 0, j = 0; i < Len; ++i) {
            if (i == pos1) {
                i = pos2;
            } else {
                temp[j] = Data[i];
                ++j;
            }
        }
        delete[] Data;
        Data = temp;
        int diff = pos2 - pos1 + 1;
        Len -= diff;
    }
}

template<class T>
void Vector<T>::push_back(const T &val) {
    this->insert(Len, val);
}

template<class T>
void Vector<T>::pop_back() {
    this->erase(Len - 1);
}

template<class T>
void Vector<T>::resize(const int &size) {
    if (size > Len) {
        Cap = ceil(1.5 * size);
        this->reserve(Cap);
        Len = size;
    } else {
        Len = size;
    }
}

template<class T>
void Vector<T>::swap(Vector<T> &oth) {
    const Vector<T> temp(oth);
    oth = *this;
    *this = temp;
}

template<class T>
void Vector<T>::print() {
    cout << " { ";
    if (Len > 0) {
        for (int i = 0; i < Len - 1; ++i) {
            cout << Data[i] << ", ";
        }
        cout << Data[Len - 1];
    }
    cout << " } " << endl;
}
