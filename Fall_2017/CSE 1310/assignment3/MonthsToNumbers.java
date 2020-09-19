
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
public class MonthsToNumbers
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)
    {
        Scanner Alfred = new Scanner(System.in);
        System.out.printf("Please enter a month: ");
        String G = Alfred.next();
        String N = G.toLowerCase();
        
        
        if ("january".equals(N))
        {
            System.out.printf("January is the first month.\n");
        }   
        else if ("february".equals(N))
        {
            System.out.printf("February is the second month.\n");
        }
        else if ("march".equals(N))
        {
            System.out.printf("March is the third month.\n");
        }           
        else if (N.equals("april"))
        {
            System.out.printf("April is the fourth month.\n");
        }   
        else if (N.equals("may"))
        {
            System.out.printf("May is the fifth month.\n");
        }
        else if (N.equals("june"))
        {
            System.out.printf("June is the sixth month.\n");
        }      
        else if (N.equals("july"))
        {
            System.out.printf("July is the seventh month.\n");
        }   
        else if (N.equals("august"))
        {
            System.out.printf("August is the eigth month.\n");
        }
        else if (N.equals("september"))
        {
            System.out.printf("September is the ninth month.\n");
        }           
        else if (N.equals("october"))
        {
            System.out.printf("October is the tenth month.\n");
        }   
        else if (N.equals("november"))
        {
            System.out.printf("November is the eleventh month.\n");
        }
        else if (N.equals("december"))
        {
            System.out.printf("December is the twelth month.\n");
        }
        else
        {
            System.out.printf("Unknown month.\n");
        }
    }
    
}
