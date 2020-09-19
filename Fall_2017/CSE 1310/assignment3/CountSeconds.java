
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
public class CountSeconds
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)
    {
        Scanner Jorah = new Scanner(System.in);
        System.out.printf("Please enter an interger, between 1 and 86,400, representing the number of seconds: ");
        int seconds = Jorah.nextInt();
        
        
        if ((seconds > 1) && (seconds < 86400))
        {
            int hours = seconds / 3600;
            int daboo = seconds % 3600;
            int baboo = daboo / 60;
            int rabbit = daboo % 60;
            
            System.out.printf("%d seconds corressponds to %d hours, %d miuntes, %d seconds.\n", seconds, hours, baboo, rabbit);
        }   
        else
        {
            System.out.printf("The number of seconds must be between 1 and 86400.\n");
        }
    } 
    
}
