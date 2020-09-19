
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
public class DivisibilityTests
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)
    {
        Scanner Julia = new Scanner(System.in);
        System.out.printf("Please enter an integer: ");
        int liverpool = Julia.nextInt();
        
        if (liverpool < 0)
        {    
            System.out.printf("The number is negative.\n");    
        }
        else if ((liverpool % 2 == 0) && (liverpool % 3 ==0))        
        {
            System.out.printf("The number is even and divisible by 3.\n");
        }
        else if (!(liverpool % 2 == 0) && (liverpool % 3 ==0))
        {
            System.out.printf("The number is odd and divisible by 3.\n");
        }
        else if ((liverpool % 2 == 0) && !(liverpool % 3 ==0))
        {
            System.out.printf("The number is even and not divisible by 3.\n");
        }                      
         else if (!(liverpool % 2 == 0) && !(liverpool % 3 ==0))
         {
             System.out.printf("The number is odd and not divisible by 3.\n");
         }
    
    }
    
}
