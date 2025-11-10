#include <iostream>
using namespace std;

class Matrix {
private:
    int m[3][3];
public:
    Matrix() {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                m[i][j]=0;
    }

    void read() {
        cout << "Enter 3x3 matrix:\n";
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                cin >> m[i][j];
    }

    void display() {
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++)
                cout << m[i][j] << " ";
            cout << endl;
        }
    }
    Matrix operator+(Matrix &other) {
        Matrix temp;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                temp.m[i][j]=m[i][j]+other.m[i][j];
        return temp;
    }
    friend Matrix operator*(Matrix a, Matrix b);
};

Matrix operator*(Matrix a,Matrix b) {
    Matrix temp;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++) {
            temp.m[i][j]=0;
            for(int k=0;k<3;k++)
                temp.m[i][j]+=a.m[i][k]*b.m[k][j];
        }
    return temp;
}

int main() {
    Matrix A,B,C;
    A.read();
    B.read();
    cout<<"A+B="<<endl;
    C = A + B;
    C.display();
    cout<<"A*B="<<endl;
    C = A * B;
    C.display();
    return 0;
}