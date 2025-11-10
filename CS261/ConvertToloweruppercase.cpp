#include<bits/stdc++.h>
using namespace std;
class Character{
private:
    char ch;

public:
    Character(char c){
        ch=c;
    }
    void display(){
        cout<<ch<<endl;
    }

    friend Character operator!(Character &c);
};
Character operator!(Character &c){
    if(c.ch>='a' && c.ch<='z'){
        c.ch=c.ch-'a'+'A';
    } 
    else{
        c.ch=c.ch-'A'+'a';
    }
    return c;
}
int main(){
    Character c('b');
    c.display();
    !c;
    c.display();
}