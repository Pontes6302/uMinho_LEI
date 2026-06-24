package ficha1;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        // HelloWorld hello = new HelloWorld();

        // System.out.print("Nome: ");
        // String nome = sc.nextLine();

        // System.out.println(hello.greet(nome));

        Ficha1 f1 = new Ficha1();

        //ex1
        // System.out.print("Graus Celsius: ");
        // double graus = sc.nextDouble();
        // System.out.println(f1.celsiusParaFarenheit(graus));

        //ex2
        // System.out.print("Número 1: ");
        // int a = sc.nextInt();
        // System.out.print("Número 2: ");
        // int b = sc.nextInt();
        // System.out.println("Máximo: " + f1.maximoNumeros(a, b));

        //ex3
        // System.out.print("Nome: ");
        // String nome = sc.nextLine();
        // System.out.print("Saldo: ");
        // double saldo = sc.nextDouble();
        // System.out.println(f1.criaDescricaoConta(nome, saldo));

        // //ex4
        // System.out.print("Valor em euros: ");
        // double valor = sc.nextDouble();
        // System.out.print("Taxa de conversão (euros -> libras): ");
        // double taxa = sc.nextDouble();
        // System.out.println("Valor em libras: " + f1.eurosParaLibras(valor, taxa));

        // //ex5
        // System.out.print("Número 1: ");
        // int a = sc.nextInt();
        // System.out.print("Número 2: ");
        // int b = sc.nextInt();
        // System.out.println(f1.mimMaxMedia(a, b));

        // //ex6
        // System.out.print("Número inteiro para calcular o fatorial: ");
        // int num = sc.nextInt();
        // System.out.println("Fatorial: " + f1.factorial(num));

        //ex7
        System.out.println("Tempo gasto a calcular o fatorial de 5000: " + f1.tempoGasto() + " ms");

        //ex8
        // Calculadora calc = new Calculadora();
        // System.out.print("Operando 1: ");
        // double op1 = sc.nextDouble();
        // System.out.print("Operando 2: ");
        // double op2 = sc.nextDouble();
        // System.out.println("Soma: " + calc.soma(op1, op2));
        // System.out.println("Subtração: " + calc.subtracao(op1, op2));
        // System.out.println("Multiplicação: " + calc.multiplicar(op1, op2));
        // System.out.println("Divisão: " + calc.dividir(op1, op2));

        sc.close();
    }
}
