package Regex;

import java.util.regex.Pattern;

public class Quantifiers {
    public static void main(String[] args) {
        
        System.out.println("? Quantifier");
        System.out.println(Pattern.matches("[ayz]?", "a"));
        System.out.println(Pattern.matches("[ayz]?", "aaa"));
        System.out.println(Pattern.matches("[ayz]?", "aaayyyzzz"));
        System.out.println(Pattern.matches("[ayz]?", "amnta"));
        System.out.println(Pattern.matches("[ayz]?", "ayz"));
        
        System.out.println("+ Quantifier"); // Occurence can be 1 or more than 1 times
        System.out.println(Pattern.matches("[ayz]+", "a")); 
        System.out.println(Pattern.matches("[ayz]+", "aaa"));
        System.out.println(Pattern.matches("[ayz]+", "aaayyyzzz"));
        System.out.println(Pattern.matches("[ayz]+", "amnta"));
         
        System.out.println("* Quantifier"); // occurence can be 0 or more
        System.out.println(Pattern.matches("[ayz]*", "")); 
        System.out.println(Pattern.matches("[ayz]*", "a")); 
        System.out.println(Pattern.matches("[ayz]*", "aaa"));
        System.out.println(Pattern.matches("[ayz]*", "aaayyyzzz"));
        System.out.println(Pattern.matches("[ayz]*", "yz"));
        System.out.println(Pattern.matches("[ayz]*", "yyyzz"));
        System.out.println(Pattern.matches("[ayz]*", "yyyzzsd"));
    }
}
