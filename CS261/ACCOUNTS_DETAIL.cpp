#include<bits/stdc++.h>
using namespace std;
class setAccount{
    public:
    int accno;
    float balance;
    setAccount(int a,float b){
        accno=a;
        balance=b;
    }
    void setDetails(int a,float b){
        accno=a;
        balance=b;
    }
    void displayDetails(){
        cout<<"Account No: "<<accno<<" Balance: "<<balance<<endl;
    }
};
class SavingAccount:virtual public setAccount{
    public:
    float interestrate;
    SavingAccount(int a,float b,float r):setAccount(a,b){
        accno=a;
        balance=b;
        interestrate=r;
    }
    void setSaving(int a,float b,float r){
        setDetails(a,b);
        interestrate=r;
    }
    void displaySaving(){
        displayDetails();
        cout<<"Interest Rate: "<<interestrate<<endl;
    }
};
class CreatedAccount:virtual public setAccount{
    public:
    float overdraftlimit;
    CreatedAccount(int a,float b,float l):setAccount(a,b){
        accno=a;
        balance=b;
        overdraftlimit=l;
    }
    void setCurrent(int a,float b,float l){
        setDetails(a,b);
        overdraftlimit=l;
    }
    void displayCurrent(){
        displayDetails();
        cout<<"Overdraft Limit: "<<overdraftlimit<<endl;
    }
};
class PremiumAccount:public SavingAccount,public CreatedAccount{
    public:
    int rewardpoints;
    PremiumAccount(int a,float b,float r,float l,int c):SavingAccount(a,b,r),CreatedAccount(a,b,l),setAccount(a,b){
        accno=a;
        balance=b;
        interestrate=r;
        overdraftlimit=l;
        rewardpoints=c;
    }
    void setPremium(int a,float b,float r,float l,int c){
        setDetails(a,b);
        interestrate=r;
        overdraftlimit=l;
        rewardpoints=c;
    }
    void displayPremium(){
        displayDetails();
        cout<<"Interest Rate: "<<interestrate<<" Overdraft Limit: "<<overdraftlimit<<" Reward Points: "<<rewardpoints<<endl;
    }
};
int main (){
    PremiumAccount p(12345,1000000.50,3.5,500.00,200);
    p.displayPremium();
    p.setPremium(67890,2000000.75,4.0,1000.00,500);
    p.displayPremium();
    return 0;
}