/*
Author: Sahel Reja
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab Quiz #10
The purpose of this program is to see if timeslots overlap.
*/
class Money {
    public:
    int dollars;
    int cents;
};
Money withdraw_money(Money balance, Money withdrawal) {
    balance.dollars -= withdrawal.dollars;
    balance.cents -= withdrawal.cents;
    int current = balance.dollars * 100 + balance.cents;
    if(current <= 0) {
        balance.dollars = 0;
        balance.cents = 0;
    }
    else {
        balance.dollars = current/100;
        balance.cents = current % 100;
    }
    return balance;
}