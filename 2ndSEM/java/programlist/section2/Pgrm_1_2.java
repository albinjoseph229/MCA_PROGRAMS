import java.util.Scanner;

public class Pgrm_1_2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read matrix1 dimensions from the user
        System.out.print("Enter the number of rows for matrix1: ");
        int rows1 = scanner.nextInt();
        System.out.print("Enter the number of columns for matrix1: ");
        int cols1 = scanner.nextInt();

        // Read matrix2 dimensions from the user
        System.out.print("Enter the number of rows for matrix2: ");
        int rows2 = scanner.nextInt();
        System.out.print("Enter the number of columns for matrix2: ");
        int cols2 = scanner.nextInt();

        // Validate matrix dimensions
        if (cols1 != rows2) {
            System.out.println("Error: The number of columns in matrix1 must be equal to the number of rows in matrix2.");
            return;
        }

        // Read matrix1 elements from the user
        int[][] matrix1 = readMatrixElements(scanner, rows1, cols1, "matrix1");

        // Read matrix2 elements from the user
        int[][] matrix2 = readMatrixElements(scanner, rows2, cols2, "matrix2");

        // Perform matrix multiplication
        int[][] result = multiplyMatrices(matrix1, matrix2);

        // Print the result matrix
        System.out.println("Result:");
        for (int[] row : result) {
            for (int element : row) {
                System.out.print(element + " ");
            }
            System.out.println();
        }

        scanner.close();
    }

    public static int[][] readMatrixElements(Scanner scanner, int rows, int cols, String matrixName) {
        System.out.println("Enter the elements for " + matrixName + ":");
        int[][] matrix = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print(matrixName + "[" + i + "][" + j + "]: ");
                matrix[i][j] = scanner.nextInt();
            }
        }
        return matrix;
    }

    public static int[][] multiplyMatrices(int[][] matrix1, int[][] matrix2) {
        int rows1 = matrix1.length;
        int cols1 = matrix1[0].length;
        int cols2 = matrix2[0].length;

        int[][] result = new int[rows1][cols2];

        for (int i = 0; i < rows1; i++) {
            for (int j = 0; j < cols2; j++) {
                for (int k = 0; k < cols1; k++) {
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }

        return result;
    }
}