import java.util.*;

public class Calculator {
    public static void main(String[] args) {
    	Scanner input = new Scanner(System.in);
    	System.out.print("Enter first number: ");
    	int numA = input.nextInt();
    	System.out.print("Enter second number: ");
    	int numB = input.nextInt();
    	System.out.print("Enter operator [+, -, *, /]: ");
    	char oper = input.next().charAt(0);

    	long result = calculate(numA, numB, oper);
    	System.out.println("Result: " + result);
    }
    private static long calculate(int A, int B, char oper) {
    	switch (oper) {
    		case '+':
    			return A + B;
    		case '-':
    			return A - B;
    		case '*':
    		case 'x':
    			return (A * 1l) * (B * 1l);
    		case '/':
    			if (B == 0) return 0;
    			return A / B;
    		default:
    			System.out.println("Wrong Input");
    			return -1;
    	}
    }
}