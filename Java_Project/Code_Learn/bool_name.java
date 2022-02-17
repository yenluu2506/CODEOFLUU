package Java_Project.Code_Learn;

import java.util.Scanner;

public class bool_name {
    public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String name1 = sc.next();
		String name2 = sc.next();
		if(name1.equals(name2)){
			System.out.println("two people have the same name");
		}
		else {
			System.out.println("two people don't have the same name");
		}
	}
}
