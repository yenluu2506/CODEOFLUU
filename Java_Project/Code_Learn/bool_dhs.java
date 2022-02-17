package Java_Project.Code_Learn;

import java.util.Scanner;

public class bool_dhs {
    public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		double diem = sc.nextDouble();
		if( diem<0 || diem > 10){
			System.out.println("The score is not valid");
		}
		else{
			System.out.println("The score is valid");
		}
	}
}
