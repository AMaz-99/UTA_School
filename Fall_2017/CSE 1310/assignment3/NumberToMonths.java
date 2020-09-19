
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
public class NumberToMonths
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)
    {
        Scanner DamDaniel = new Scanner(System.in);
        System.out.printf("Please indicate an a month as an interger from 1 to 12: ");
        int N = DamDaniel.nextInt();
        
        
        if (N == 1)
        {
            System.out.printf("January.\n");
        }   
         if (N == 2)
        {
            System.out.printf("February.\n");
        }
         if (N == 3)
        {
            System.out.printf("March.\n");
        }           
        if (N == 4)
        {
            System.out.printf("April.\n");
        }   
           if (N == 5)
        {
            System.out.printf("May.\n");
        }
        if (N == 6)
        {
            System.out.printf("June.\n");
        }      
        if (N == 7)
        {
            System.out.printf("July.\n");
        }   
         if (N == 8)
        {
            System.out.printf("August.\n");
        }
         if (N == 9)
        {
            System.out.printf("September.\n");
        }           
        if (N == 10)
        {
            System.out.printf("October.\n");
        }   
           if (N == 11)
        {
            System.out.printf("November.\n");
        }
        if (N == 12)
        {
            System.out.printf("December.\n");
        }
        else
        {
            System.out.printf("This number does not correspond to a month.\n");
        }
    }
    
}

