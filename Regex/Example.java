package Regex;

import java.util.regex.*;

public class Example {
    public static void main(String[] args) {
        
        Pattern pattern = Pattern.compile(".xx.");

        Matcher matcher = pattern.matcher("sxxd");

        System.out.println("Matcher matches the given pattern or not : " + matcher.matches());
    }
}
