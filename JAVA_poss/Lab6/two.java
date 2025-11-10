package Lab6;

class Matrix {
    private int[][] mat;
    private int size = 3;

    Matrix(int[][] mat) {
        this.mat = mat;
    }

    Matrix add(Matrix m2) {
        int[][] res = new int[size][size];
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                res[i][j] = this.mat[i][j] + m2.mat[i][j];
        return new Matrix(res);
    }

    Matrix multiply(Matrix m2) {
        int[][] res = new int[size][size];
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                for (int k = 0; k < size; k++)
                    res[i][j] += this.mat[i][k] * m2.mat[k][j];
        return new Matrix(res);
    }

    void display() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++)
                System.out.print(mat[i][j] + " ");
            System.out.println();
        }
    }
}

public class two {
    public static void main(String[] args) {
        int[][] a = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
        int[][] b = { {9, 8, 7}, {6, 5, 4}, {3, 2, 1} };

        Matrix m1 = new Matrix(a);
        Matrix m2 = new Matrix(b);

        System.out.println("Matrix 1:");
        m1.display();
        System.out.println("Matrix 2:");
        m2.display();

        Matrix sum = m1.add(m2);
        Matrix product = m1.multiply(m2);

        System.out.println("\nAddition Result:");
        sum.display();
        System.out.println("\nMultiplication Result:");
        product.display();
    }
}
