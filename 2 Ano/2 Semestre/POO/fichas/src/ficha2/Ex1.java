package ficha2;

import java.util.Arrays;

public class Ex1 {
    private int[] numeros_a;
    private int[] numeros_b;

    /**
     * Recebe um array de inteiros e seu tamanho, e armazena esse array em um dos arrays internos da classe (numeros_a ou numeros_b).
     * @param array O array de inteiros a ser armazenado.
     * @param n O tamanho do array a ser armazenado.
     */
    public void recebeArray(int[] array, int n){
        if (this.numeros_a != null)
            this.numeros_b = Arrays.copyOf(array, n);
        else 
            this.numeros_a = Arrays.copyOf(array, n);
    }

    /**
     * Percorre o array interno e retorna o valor mínimo encontrado.
     * @return O valor mínimo do array interno.
     */
    public int minimo(){
        int min = Integer.MAX_VALUE;
        for (int num : this.numeros_a) {
            if (num < min)
                min = num;
        }
        return min;
    }

    /**
     * Retorna um novo array contendo os elementos do array interno no intervalo especificado por "start" e "end".
     * @param start O índice inicial do intervalo (inclusive).
     * @param end O índice final do intervalo (exclusive).
     * @return Um novo array contendo os elementos do array interno no intervalo especificado.
     */
    public int[] copyRange(int start, int end) {
        if (start < 0 || end > this.numeros_a.length || start >= end)
            return null;
        return Arrays.copyOfRange(this.numeros_a, start, end);
    }

    /**
    * Compara os elementos dos dois arrays internos e retorna um novo array contendo os elementos comuns entre eles.
    * @return Um novo array contendo os elementos comuns entre os dois arrays internos.
    */
    public int[] commonElements(){
        if (this.numeros_a == null || this.numeros_b == null)
            return null;
        int[] res = new int[Math.min(this.numeros_a.length, this.numeros_b.length)];
        int index = 0;
        for (int numA : this.numeros_a) {
            for (int numB : this.numeros_b) {
                if (numA == numB){
                    res[index++] = numA;
                    break;
                }
            }
        }
        return res;
    }

}
