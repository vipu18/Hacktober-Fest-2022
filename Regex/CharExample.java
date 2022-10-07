package Regex;

import java.util.regex.*;

public class CharExample {
    public static void main(String[] args) {
        
        System.out.println(Pattern.matches("[xyz]", "wbcd"));  // false (not x or y or z)
        System.out.println(Pattern.matches("[xyz]", "x")); // true (x is present)
        System.out.println(Pattern.matches("[xyz]", "xxyyyzzz")); // false (x or y or z comes more than once)
        System.out.println(Pattern.matches("[xyz]", "xyz")); // false (x or y or z come once)
    }
}
