#pragma once
#ifndef LABA5_1_USERCLASS_H
#define LABA5_1_USERCLASS_H

#include <iostream>

class UserClass {
public:
    int Number;
};

std::ostream &operator<<(std::ostream &out, const UserClass &num);

#endif //LABA5_1_USERCLASS_H
