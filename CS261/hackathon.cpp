#include<bits/stdc++.h>
using namespace std;    
class participant{
    public:
    string name;
    string email;
    participant(string n,string e){
        name=n;
        email=e;
    }
};
class team{
    public:
    string teamname;
    string projectname;
    team(string tn,string pn){
        teamname=tn;
        projectname=pn;
    }
};
class participantrecord:public participant,public team{
    public:
    participantrecord(string n,string e,string tn,string pn):participant(n,e),team(tn,pn){

    }
    participantrecord(participantrecord &p):participant(p.name,p.email),team(p.teamname,p.projectname){
    }
    void display(){
        cout<<"Participant Name: "<<name<<endl;
        cout<<"Participant Email: "<<email<<endl;
        cout<<"Team Name: "<<teamname<<endl;
        cout<<"Project Name: "<<projectname<<endl;
        cout<<endl;
    }
};
int main(){
    participantrecord p("Jatan Bhatt","jatan12@gmail.com","Team GitrajgoogleSTEP","Project GENAI");
    participantrecord p1(p);
    p.display();
    p1.display();
    return 0;
}