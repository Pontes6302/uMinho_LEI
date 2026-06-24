package ficha4;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

public class Encomenda {
    private String nome;
    private int nif;
    private String morada;
    private int num;
    private LocalDate data;
    private List<LinhaEncomenda> linhasEncomenda;

    private static int numEncomenda;

    public static int getNumEncomenda() {
        return numEncomenda;
    }

    public Encomenda(){
        this.nome = "";
        this.nif = 0;
        this.morada = "";
        this.data = LocalDate.now();
        numEncomenda++;
        this.num = numEncomenda;
        this.linhasEncomenda = new ArrayList<>();
    }

    public Encomenda(String nome, int nif, String morada, LocalDate data, List<LinhaEncomenda> linhasEncomenda){
        this.nome = nome;
        this.nif = nif;
        this.morada = morada;
        this.data = data;
        numEncomenda++;
        this.num = numEncomenda;
        List<LinhaEncomenda> l = new ArrayList<>(linhasEncomenda.size());
        for (LinhaEncomenda linha : linhasEncomenda)
            l.add(linha.clone());
        this.linhasEncomenda = l;
    }
    
    public Encomenda(Encomenda e){
        this.nome = e.getNome();
        this.nif = e.getNif();
        this.morada = e.getMorada();
        this.data = e.getData();
        this.num = e.getNum();
        List<LinhaEncomenda> l = new ArrayList<>(e.getLinhasEncomenda().size());
        for (LinhaEncomenda linha : e.getLinhasEncomenda())
            l.add(linha.clone());
        this.linhasEncomenda = l;
    }

    public String getNome(){
        return nome;
    }

    public int getNif() {
        return nif;
    }

    public String getMorada() {
        return morada;
    }

    public int getNum() {
        return num;
    }

    public LocalDate getData() {
        return data;
    }

    public List<LinhaEncomenda> getLinhasEncomenda() {
        List<LinhaEncomenda> l = new ArrayList<>(linhasEncomenda.size());
        for (LinhaEncomenda linha : this.linhasEncomenda)
            l.add(linha.clone());
        return l;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setNif(int nif) {
        this.nif = nif;
    }

    public void setMorada(String morada) {
        this.morada = morada;
    }

    public void setData(LocalDate data) {
        this.data = data;
    }

    public void setLinhasEncomenda(List<LinhaEncomenda> linhasEncomenda) {
        List<LinhaEncomenda> l = new ArrayList<>(linhasEncomenda.size());
        for (LinhaEncomenda linha : linhasEncomenda)
            l.add(linha.clone());
        this.linhasEncomenda = l;
    }

    public double calculaValorTotal() {
        double total = 0;
        for (LinhaEncomenda linha : this.linhasEncomenda)
            total += linha.calculaValorLinhaEnc();
        return total;
    }

    public double calculaValorDesconto() {
        double desconto = 0;
        for (LinhaEncomenda linha : this.linhasEncomenda)
            desconto += linha.calculaValorDesconto();
        return desconto;
    }

    public int numeroTotalProdutos() {
        int total = 0;
        for (LinhaEncomenda linha : this.linhasEncomenda)
            total += linha.getQuantidade();
        return total;
    }

    public boolean existeProdutoEncomenda(String refProduto) {
        for (LinhaEncomenda linha : this.linhasEncomenda)
            if (linha.getReferencia().equals(refProduto))
                return true;
        return false;
    }

    public void adicionaLinha(LinhaEncomenda linha){
        this.linhasEncomenda.add(linha.clone());
    }

    public void removeProduto(String codProd){
        this.linhasEncomenda.removeIf(linha -> linha.getReferencia().equals(codProd));
    }

    public Encomenda clone(){
        return new Encomenda(this);
    }
}
