package Regex;

public class Split {
    public static void main(String[] args) {
        // String str = "GeeksforforGeeksfor   ";
        // String[] arrOfStr = str.split("for");
  
        // for (String a : arrOfStr)
        //     System.out.println(a);

        String str = "word1, word2 word3@word4?word5.word6";
        String[] arrOfStr = str.split("[, ?.@]+");
  
        for (String a : arrOfStr)
            System.out.println(a);
    }
}
