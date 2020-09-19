
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
public class CountMultiples
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)
    {
        Scanner Arya = new Scanner(System.in);
        System.out.printf("Enter an integer M: ");
        int M = Arya.nextInt();
        System.out.printf("Enter an integer N: ");
        int N = Arya.nextInt();
        
        int counter = 0;
        for (int d = M; d <= N; d++)
        {
            if (d % 11 == 0)
            {
                counter++;
            }

        }
        
        System.out.printf("%d numbers between %d and %d are multiples of 11.\n", counter, M, N);
        System.out.printf("Exiting...\n");
        System.exit(0);
    }
    
}
