
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
public class WordStart
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)
    {
        Scanner Snow = new Scanner(System.in);
        System.out.printf("Please enter a word: ");
        String Jon = Snow.next();
        String HotPie = Jon.toLowerCase();
        String RobertDaBruce = HotPie.substring(0,1);
        String vowels = "aeiou";
        String consonants = "qwrtyuoplkjhgfdszxcvbnm";
        int result = vowels.indexOf(RobertDaBruce);
        int result1 = consonants.indexOf(RobertDaBruce);
        
        if (result != -1)
        {
            System.out.printf("%s starts with a vowel.\n", Jon);
        }
        else if (result1 !=-1)
        {
            
            System.out.printf("%s starts with a consonant.\n", Jon);
        }
        else
        {
            System.out.printf("%s starts with neither a vowel nor a consonant.\n", Jon);
        }
              

    }
    
}
