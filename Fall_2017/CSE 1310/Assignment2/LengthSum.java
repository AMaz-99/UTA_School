/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Brocard
 */
import java.util.Scanner;
public class LengthSum {

    public static void main(String[] args) {
        Scanner jeff = new Scanner(System.in); 
        
        System.out.printf("Please enter a string: ");
        String a = jeff.nextLine();
        
        System.out.printf("Please enter a second string: ");
        String b = jeff.nextLine();
        
        int La = a.length();
        int Lb = b.length();
        int total = La + Lb; 
        
        System.out.printf("The fisrt string has legenth %d\n", La);
        System.out.printf("The second string has legenth %d\n", Lb);
        System.out.printf("The sum of the two legenths is %d\n", total);
        
        
        
    }
    
}
