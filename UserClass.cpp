#include "UserClass.h"

std::ostream &operator<<(std::ostream &out, const UserClass &num) {
    out << num.Number;
    return out;
}
