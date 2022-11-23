#include "Bank.hpp"
Bank::Bank() {
    accountTotal = 0;
}
std::string Bank::createAccount(std::string first, std::string last, std::string p) {
    Account a(first,last,p);
    if(accountTotal > 200) {
        accounts[accountTotal] = a;
        accountTotal++;
    }
    else {
        return "-1";
    }
    return a.getPin();
}
bool Bank::removeAccount(std::string accountNum) {
    
}