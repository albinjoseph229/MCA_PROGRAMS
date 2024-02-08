import java.io.BufferedReader;
import java.io.InputStreamReader;

class twofive {
    public static void main(String args[]) {
        System.out.println("Albin Joseph");
        int arr[][] = new int[10][10];
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int rno, cno, rsum, csum, i, j;
        try {
            System.out.println("Enter the number of columns");
            cno = Integer.parseInt(reader.readLine());
            System.out.println("Enter the number of rows");
            rno = Integer.parseInt(reader.readLine());
            for (i = 0; i < rno; i++) {
                for (j = 0; j < cno; j++) {
                    System.out.println("Enter the [" + i + "][" + j + "] element");
                    arr[i][j] = Integer.parseInt(reader.readLine());
                }
            }
            System.out.println("Row sums are:");
            for (i = 0; i < rno; i++) {
                rsum = 0;
                for (j = 0; j < cno; j++) {
                    rsum = rsum + arr[i][j];
                    System.out.print(arr[i][j] + " ");
                }
                System.out.println("| " + rsum);
            }
            System.out.println("Column sums are:");
            for (i = 0; i < cno; i++) {
                csum = 0;
                for (j = 0; j < rno; j++) {
                    csum = csum + arr[j][i];
                }
                System.out.print(" " + csum);
            }
        } catch (Exception e) {
            System.out.println("Error: " + e);
        }
    }
}
