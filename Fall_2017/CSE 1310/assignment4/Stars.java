
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
public class Stars
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)
    {
        Scanner Conly = new Scanner(System.in);
        System.out.printf("Enter a positive integer N > 0: ");
        int N = Conly.nextInt();
        String initial = "*";
        String star = "*";
        if (N > 0)
        {
            for (; initial.length() <= N ; initial += star)
            {
                System.out.printf("%s\n", initial);
            }
            System.out.printf("Exiting...\n");
            System.exit(0);
        } 
        else
        {
           System.out.printf("Exiting...\n");
           System.exit(0); 
        }
            
    }
    
}
