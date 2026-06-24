package ficha1;
import java.lang.Math;

public class Ficha1 {
    /**
     * EX1: Converte graus Celsius para Farenheit
     * @param graus Graus em Celsius
     * @return Graus em Farenheit
     */
    public double celsiusParaFarenheit(double graus){
        return (graus * 9/5) + 32;
    }

    /**
     * EX2: Devolve o máximo entre dois números inteiros
     * @param a Primeiro número inteiro
     * @param b Segundo número inteiro
     * @return Máximo entre a e b
    */
    public int maximoNumeros(int a, int b){
        return Math.max(a, b);
    }

    /**
     * EX3: Imprimir um texto com os valores obtidos na leitura.
     * @param nome Nome
     * @param saldo Saldo
     * @return Descrição da conta
     */
    public String criaDescricaoConta(String nome, double saldo){
        return "O titular " + nome + " tem " + saldo + " euros na sua conta.";
    }

    /**
     * EX4: Converte euros para libras
     * @param valor Valor em euros
     * @param taxaConversao Taxa de conversão de euros para libras
     * @return Valor em libras
     */
    public double eurosParaLibras(double valor, double taxaConversao){
        return valor * taxaConversao;
    }

    /**
     * EX5: Devolve o mínimo, máximo e a média entre dois números inteiros
     * @param a Primeiro número inteiro
     * @param b Segundo número inteiro
     * @return String com o mínimo, máximo e a média entre a e b
     */
    public String mimMaxMedia(int a, int b){
        return "mínimo: " + Math.min(a, b) + ", máximo: " + Math.max(a, b) + ", média: " + ((a + b) / 2.0);
    }

    /**
     * EX7: Calcula o tempo gasto a calcular o fatorial de 5000
     * @return Tempo gasto em milissegundos
     */
    public long tempoGasto(){
        long startTime = System.currentTimeMillis();
        factorial(5000);
        long endTime = System.currentTimeMillis();
        return endTime - startTime;
    }

    /**
     * EX6: Calcula o fatorial de um número inteiro
     * @param num Número inteiro
     * @return Fatorial do número
     */
    public long factorial(int num){
        if (num == 0) return 1;
        else return factorial(num - 1) * num;
    }
}
