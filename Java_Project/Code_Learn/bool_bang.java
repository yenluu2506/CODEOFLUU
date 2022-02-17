package Java_Project.Code_Learn;

import java.util.Scanner;

public class bool_bang {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        if(a>=b){
            System.out.println("a is greater than or equal to b");
        }
        else{
            System.out.println("a is smaller than b");
        }
    }
}
