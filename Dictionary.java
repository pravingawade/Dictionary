package src;

import java.util.HashMap;
import java.util.Scanner;

public class Dictionary {
	
	static String word="";
	static String definition="";
	
	public static void main(String []args)
	{
		//hashmap
			HashMap<String, String> hashmap = new HashMap<String,String>();
			Scanner sc = new Scanner(System.in);
			String choice,ch;
			System.out.println("Welcome to the self-learning dictionary!");
			do{
			System.out.println("Please enter a word");
			word = sc.nextLine();
			
				if(hashmap.containsKey(word))
				{
					System.out.print("Meaning   =>  ");
					System.out.println(hashmap.get(word));
				
				}
				else
				{
					System.out.println("Sorry, not found. Add to Dictionary? (y / n):");
					choice = sc.nextLine();
					
					if(choice.equalsIgnoreCase("y"))
					{
						System.out.println("Enter Definition");
						definition = sc.nextLine();
						hashmap.put(word, definition);
					}	
				}
			
				System.out.println("Do You Want To Continue? (y / n):");
				ch=sc.nextLine();
				
			}while(ch.equals("y"));
	}
}
