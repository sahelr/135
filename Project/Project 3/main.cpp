#include "Account.hpp"
int main() {
    Account a;
    a.setFirstName("Bob");
    std::cout << a.getFirstName();
    return 0;
}