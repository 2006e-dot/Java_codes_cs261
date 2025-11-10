package Lab6;

class CharacterToggle {
    private char ch;

    CharacterToggle(char ch) {
        this.ch = ch;
    }

    void toggle() {
        if (ch >= 'A' && ch <= 'Z')
            ch = (char)(ch + 32);
        else if (ch >= 'a' && ch <= 'z')
            ch = (char)(ch - 32);
    }

    void display() {
        System.out.println("Character: " + ch);
    }
}

public class three {
    public static void main(String[] args) {
        CharacterToggle c1 = new CharacterToggle('a');
        CharacterToggle c2 = new CharacterToggle('Z');

        System.out.print("Before toggle -> "); c1.display();
        c1.toggle();
        System.out.print("After toggle  -> "); c1.display();

        System.out.print("\nBefore toggle -> "); c2.display();
        c2.toggle();
        System.out.print("After toggle  -> "); c2.display();
    }
}
