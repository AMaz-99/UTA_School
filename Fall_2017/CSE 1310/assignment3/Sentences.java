
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
public class Sentences
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)
    {
        Scanner Khaleesi = new Scanner(System.in);
        System.out.printf("Enter the first noun: ");
        String first_noun = Khaleesi.next();
        System.out.printf("Enter the second noun: ");
        String second_noun = Khaleesi.next();
        System.out.printf("Enter a first verb: ");
        String verb = Khaleesi.next();
        System.out.printf("The %s %s over the %s.\n", first_noun, verb, second_noun);
    }
}
