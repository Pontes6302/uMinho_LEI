package ficha4;

import java.time.LocalDate;


public class Main {
    public static void main(String[] args) {
        LocalDate data = LocalDate.of(2024, 1, 1);
        LinhaEncomenda linha1 = new LinhaEncomenda("ref1", "desc1", 10, 2, 0.23, 0.1);
        LinhaEncomenda linha2 = new LinhaEncomenda("ref2", "desc2", 20, 1, 0.23, 0.05);
        LinhaEncomenda linha3 = new LinhaEncomenda("ref3", "desc3", 5, 5, 0.23, 0);
        LinhaEncomenda linha4 = new LinhaEncomenda("ref4", "desc4", 15, 3, 0.23, 0.2);
        Encomenda encomenda1 = new Encomenda("Cliente1", 123456789, "Rua A", java.time.LocalDate.now(), java.util.Arrays.asList(linha1, linha2));
        Encomenda encomenda2 = new Encomenda("Cliente2", 987654321, "Rua B", java.time.LocalDate.now(), java.util.Arrays.asList(linha3, linha4));
        GestaoEncomendas gestao = new GestaoEncomendas(java.util.Arrays.asList(encomenda1, encomenda2));
        System.out.println(gestao.toString());
        System.out.println("Existe Produto ref1 " + gestao.encomendaComProduto("ref1"));
        System.out.println("Datas após " + data + ": " + gestao.encomendaAposData(data));
    }
}
