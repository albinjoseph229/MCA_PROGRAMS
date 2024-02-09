/*Create a class for employee having eno,ename and esal as data members. 
Provide functions for reading and displaying employee details. (Accept information of
 n employees in the main function, display the same and search for an emp (using eno)).*/
 import java.util.Scanner;

 class employee {
     int eno;
     String ename;
     double esal;
 
     // public employee() {
     // this(0, " ", 0.0);
     // }
 
     // public employee(int no, String name, double sal) {
     // eno = no;
     // ename = name;
     // esal = sal;
     // }
 
     public void read() {
         Scanner scanner = new Scanner(System.in);
         System.out.print("EmployeeNo: ");
         eno = scanner.nextInt();
         scanner.nextLine();
         System.out.print("EmployeeName: ");
         ename = scanner.nextLine();
         System.out.print("EmployeeSalary: ");
         esal = scanner.nextDouble();
     }
 
     public void disp() {
 
         System.out.println("EmployeeNo: " + eno + "\tEmployeeName: " + ename);
         System.out.println("EmployeeSalary: " + esal);
         System.out.println("_____________________________________");
 
     }
 }
 
 public class FiveTwo{
 
     public static void main(String[] args) {
         Scanner scanner = new Scanner(System.in);
         System.out.print("Enter how many employees: ");
         int n = scanner.nextInt();
         employee employees[] = new employee[n];
         for (int i = 0; i < n; i++) {
             employees[i] = new employee();
             System.out.println("_____________________________________");
             System.out.println("Enter details of employee " + (i + 1));
             employees[i].read();
         }
         System.out.println("\nList of Employees: ");
         for (int i = 0; i < n; i++) {
             System.out.print(i + 1 + ". ");
             employees[i].disp();
         }
         System.out.print("Enter EmpNo to search: ");
         int x = scanner.nextInt();
         searchemp(n, x, employees);
         scanner.close();
     }
 
     public static void searchemp(int n, int x, employee emp[]) {
 
         for (int i = 0; i < n; i++) {
             if (emp[i].eno == x) {
                 System.out.println("Employee found: ");
                 emp[i].disp();
                 return;
             }
         }
         System.out.println("Employee not found/Invalid EmployeeNo");
 
     }
 
 }