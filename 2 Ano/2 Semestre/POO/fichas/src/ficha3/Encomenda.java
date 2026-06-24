package ficha3;

import java.time.LocalDate;

public class Encomenda {
    private String nome;
    private int nif;
    private String morada;
    private int num;
    private LocalDate data;
    private LinhaEncomenda[] linhas;

    public Encomenda(){
        this.nome = "";
        this.nif = 0;
        this.morada = "";
        this.num = 0;
        this.data = LocalDate.now();
        this.linhas = new LinhaEncomenda[10];
    }

    public Encomenda(String nome, int nif, String morada, int num, LocalDate data, LinhaEncomenda[] linhasEncomenda){
        this.nome = nome;
        this.nif = nif;
        this.morada = morada;
        this.num = num;
        this.data = data;
        for (int i = 0; i < linhas.length; i++)
            this.linhas[i] = linhasEncomenda[i].clone();
    }

    public String getNome() {
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

    public LinhaEncomenda[] getLinhas() {
        LinhaEncomenda[] copy = new LinhaEncomenda[linhas.length];
        int i = 0;
        for (LinhaEncomenda le : linhas)
            copy[i++] = le.clone();
        return copy;
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

    public void setNum(int num) {
        this.num = num;
    }

    public void setData(LocalDate data) {
        this.data = data;
    }

    public void setLinhas(LinhaEncomenda[] linhasEnc) {
        LinhaEncomenda[] linhas = new LinhaEncomenda[linhasEnc.length];
        for (int i = 0; i < linhasEnc.length; i++)
            linhas[i] = linhasEnc[i].clone();
        this.linhas = linhas;
    }

}
