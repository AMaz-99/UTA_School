
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
public class CountDigits
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)
    {
        Scanner Alfred = new Scanner(System.in);
        System.out.printf("Please enter an integer: ");
        int disco = Alfred.nextInt();
        
        
        if (disco < 0)
        {
            System.out.printf("%d is negative.\n", disco);
        }   
        else if ((disco >= 0) && (disco < 1000000))
        {
            String fire = Integer.toString(disco);
            int foontie = fire.length();
            System.out.printf("%d has %d digits.\n", disco, foontie);
        }
        else
        {
            System.out.printf("%d has more than six digits.\n", disco);
        }
    }
    
}
