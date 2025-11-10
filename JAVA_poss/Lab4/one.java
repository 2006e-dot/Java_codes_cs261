package Lab4;

interface Participant {
    void displayParticipant();
}

interface Team {
    void displayTeam();
}

class ParticipantRecord implements Participant, Team {
    private String name;
    private String email;
    private String teamName;
    private String projectTitle;

    public ParticipantRecord(String name, String email, String teamName, String projectTitle) {
        this.name = name;
        this.email = email;
        this.teamName = teamName;
        this.projectTitle = projectTitle;
    }

    public ParticipantRecord(ParticipantRecord o) {
        this.name = o.name;
        this.email = o.email;
        this.teamName = o.teamName;
        this.projectTitle = o.projectTitle;
    }

    public void displayParticipant() {
        System.out.println("Name: " + name + ", Email: " + email);
    }

    public void displayTeam() {
        System.out.println("Team: " + teamName + ", Project: " + projectTitle);
    }

    void display() {
        displayParticipant();
        displayTeam();
        System.out.println();
    }
}

public class one {
    public static void main(String[] args) {
        ParticipantRecord p1 = new ParticipantRecord("Ayush", "ayush@gmail.com", "CodeForce", "AI Assistant");
        ParticipantRecord p2 = new ParticipantRecord(p1);

        System.out.println("Original Participant:");
        p1.display();

        System.out.println("Copied Participant:");
        p2.display();
    }
}
