#include <bits/stdc++.h>
using namespace std;

class participant {
public:
    string name;
    string email;
    participant(string n, string e) : name(n), email(e) {}
};

class Team {
public:
    string teamname;
    string projecttitle;
    Team(string teamname, string projecttitle)
        : teamname(teamname), projecttitle(projecttitle) {}
};

class ParticipantRecord : public participant, public Team {
public:
    ParticipantRecord(string n, string e, string teamname, string projecttitle)
        : participant(n, e), Team(teamname, projecttitle) {}
    ParticipantRecord(ParticipantRecord &p)
        : participant(p.name, p.email), Team(p.teamname, p.projecttitle) {}
    void display() {
        cout << "Participant Name: " << name << endl;
        cout << "Participant Email: " << email << endl;
        cout << "Team Name: " << teamname << endl;
        cout << "Project Name: " << projecttitle << endl;
        cout << endl;
    }
};

int main() {
    ParticipantRecord pr("Ayush","ayush@gmail.com","Boobies","GenAi");
    ParticipantRecord pr2(pr);
    pr.display();
    pr2.display();
    return 0;
}
