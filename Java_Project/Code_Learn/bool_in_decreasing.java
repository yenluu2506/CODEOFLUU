package Java_Project.Code_Learn;

import java.util.Scanner;

public class bool_in_decreasing {
    public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		if(a<=b && b<=c){
			System.out.println("increasing");
		}
		else if(a>=b && b>=c){
			System.out.println("decreasing");
		}
		else {
			System.out.println("neither increasing nor decreasing order");
		}
	}
}
