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
public class SkipMultiples
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)
    {
        Scanner Rickity = new Scanner(System.in);
        System.out.printf("Enter low: ");
        int low = Rickity.nextInt();
        System.out.printf("Enter high: ");
        int high = Rickity.nextInt();
        if ( low <= high)
        {
            for (int i = low; i <= high; i++)
                    {
                      if (i % 4 ==0) 
                      {  
                      }
                      else if (i % 4 != 0)
                      {
                          System.out.printf("%d\n", i);
                      }
                    }
        }
        else
        {
            System.out.println("no numbers found");
        }
    
    }
}