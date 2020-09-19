
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
public class PrintPowers
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)
    {
        Scanner Bran = new Scanner(System.in);
        System.out.printf("Enter a positive integer N > 1: ");
        int N = Bran.nextInt();
        if (N > 1)
        { 
          int i = 0; 
          int d = 0;
          while (d < 40000)
          {
              d = (int) Math.pow(N, i);
              if (d < 40000)
              {
              System.out.printf("%d\n", d);
              i++;
              }
              else
              {
                  System.out.printf("Exiting...\n");
                  System.exit(0);
              }
          }
        }
        else 
        {
            System.out.printf("Exiting...\n");
            System.exit(0);
        }
    }
    
}
