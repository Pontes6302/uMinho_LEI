package ficha2;

import java.util.Scanner;
//import java.util.Arrays;

public class Main {

    public static int[] lerArray(Scanner sc){
        System.out.print("Números a ler para o array: ");
        int n = sc.nextInt();

        int[] array = new int[n];
        System.out.print("Números:" );
        for (int i = 0; i < n; i++)
            array[i] = sc.nextInt();
        return array;
    }

    public static void main(String[] args){
        //Ex1
        // Scanner sc = new Scanner(System.in);
        // Ex1 ex1 = new Ex1();

        // int[] test = lerArray(sc);
        // ex1.recebeArray(test, test.length);

        // System.out.println(Arrays.toString(test));
        // System.out.println("Mínimo: " + ex1.minimo());
        // System.out.print("Intervalo para copyRange (start end): ");
        // int start = sc.nextInt();
        // int end = sc.nextInt();
        // System.out.println("copyRange: " + Arrays.toString(ex1.copyRange(start, end)));

        // int[] test2 = lerArray(sc);
        // ex1.recebeArray(test2, test2.length);
        // System.out.println("Elementos comuns: " + Arrays.toString(ex1.commonElements()));

        // sc.close();

        //Ex2
        //Ex2 = new Ex2();
    }
}
