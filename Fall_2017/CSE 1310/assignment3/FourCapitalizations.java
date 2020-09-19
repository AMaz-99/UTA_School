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
public class FourCapitalizations
{

    public static void main(String[] args)
    {
        Scanner joffrey = new Scanner(System.in);
        System.out.printf("Please enter a string: ");
        String k = joffrey.nextLine();
        int e = k.length(); 
        String l = k.toUpperCase();
        String m = k.toLowerCase();
        char a = l.charAt(0);
        String d = m.substring(1,e);
        String f = a + d;
        System.out.printf("1st Version: %s\n", k);
        System.out.printf("2nd Version: %s\n", l);
        System.out.printf("3rd Version: %s\n",m);
        System.out.printf("4th Version: %s\n", f);
        
        
           
    }
    
}
