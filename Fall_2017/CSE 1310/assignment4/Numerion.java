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
public class Numerion
{

    public static void main(String[] args)
    {
       Scanner Johnny_Cash = new Scanner(System.in);
       System.out.printf("Enter an integer N: ");
       int N = Johnny_Cash.nextInt();
       
       boolean N_is_holy = false;
       int i = 1;
       while (i < N)
       {
        int Spongebob = i * i + i;
            if ((Spongebob == N))
           {
            N_is_holy = true;
            break;  
           }
             i++;

       }
       if (N_is_holy)
       {
           System.out.printf("%d is a holy number in Numerion.\n", N);
           System.out.printf("Exiting...\n");
           System.exit(0);
       }
       else 
       {
           System.out.printf("%d is not a holy number in Numerion.\n", N);
           System.out.printf("Exiting...\n");
           System.exit(0);
       }
    }
    
}
