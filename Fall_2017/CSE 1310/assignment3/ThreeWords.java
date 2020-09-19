
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Brocard
 */

public class ThreeWords
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)
    {
      Scanner Ned = new Scanner(System.in);
      System.out.printf("Please enter an integer N: ");
      int N = Ned.nextInt();
      System.out.printf("Please enter a word with at least 3 letters and at most 20 letters: ");
      String a = Ned.next();
      System.out.printf("Please enter a second word with at least 3 letters and at most 20 letters: ");
      String b = Ned.next();
      System.out.printf("Please enter a third word with at least 3 letters and at most 20 letters: ");
      String c = Ned.next();
      System.out.printf("%20s starts with %s.\n", a, a.substring(0,N));
      System.out.printf("%20s starts with %s.\n", b, b.substring(0,N));
      System.out.printf("%20s starts with %s.\n", c, c.substring(0,N)); 
    }
    
}
