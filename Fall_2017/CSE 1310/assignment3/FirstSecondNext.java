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
public class FirstSecondNext
{
    public static void main(String[] args)
    {
      Scanner ronald = new Scanner(System.in); 
      System.out.printf("Pleas enter a string, at least 5 letters long: ");
      String s = ronald.next();
      char first = s.charAt(0);
      char second = s.charAt(1);
      String next = s.substring(2,5);
      System.out.printf("The first letter of s is %c\n", first);
      System.out.printf("The second letter of s is %c\n", second);
      System.out.printf("The third, fourth, and fifth letters of s are %s.\n", next);
      
    }
    
}
