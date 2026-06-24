package ficha3;

public class LinhaEncomenda {
    private String ref;
    private String descricao;
    private double preco;
    private int quantidade;
    private double desconto;
    private double imposto;

    public LinhaEncomenda(){
        this.ref = "";
        this.descricao = "";
        this.preco = 0;
        this.quantidade = 0;
        this.desconto = 0;
        this.imposto = 0;
    }

    public LinhaEncomenda(String ref, String descricao, double preco, int quantidade, double desconto, double imposto){
        this.ref = ref;
        this.descricao = descricao;
        this.preco = preco;
        this.quantidade = quantidade;
        this.desconto = desconto;
        this.imposto = imposto;
    }

    public LinhaEncomenda(LinhaEncomenda le){
        this.ref = le.getRef();
        this.descricao = le.getDescricao();
        this.preco = le.getPreco();
        this.quantidade = le.getQuantidade();
        this.desconto = le.getDesconto();
        this.imposto = le.getImposto();
    }

    public String getRef() {
        return ref;
    }

    public String getDescricao() {
        return descricao;
    }

    public double getPreco() {
        return preco;
    }

    public int getQuantidade() {
        return quantidade;
    }

    public double getDesconto() {
        return desconto;
    }

    public double getImposto() {
        return imposto;
    }

    public void setRef(String ref) {
        this.ref = ref;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    public void setPreco(double preco) {
        this.preco = preco;
    }

    public void setQuantidade(int quantidade) {
        this.quantidade = quantidade;
    }

    public void setDesconto(double desconto) {
        this.desconto = desconto;
    }

    public void setImposto(double imposto) {
        this.imposto = imposto;
    }

    public double calculaValorLinhaEnc(){
        return this.quantidade * this.preco * (1 - this.desconto) * (1 + this.imposto);
    }

    public double calculaValorDesconto(){
        return this.quantidade * this.preco * this.desconto;
    }

    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(this.ref).append(" ").append(this.descricao).append(" ").append(this.preco).append
        (" ").append(this.quantidade).append(" ").append(this.desconto).append(" ").append(this.imposto);
        return sb.toString();
    }

    @Override
    public boolean equals(Object o){
        if (this == o)
            return true;
        if (o == null || this.getClass() != o.getClass())
            return false;
        LinhaEncomenda linha = (LinhaEncomenda) o;
        return this.preco == linha.getPreco() &&
                this.quantidade == linha.getQuantidade() &&
                this.desconto == linha.getDesconto() &&
                this.imposto == linha.getImposto() &&
                this.ref.equals(linha.getRef()) &&
                this.descricao.equals(linha.getDescricao());
    } 

    public LinhaEncomenda clone(){
        return new LinhaEncomenda(this);
    }
}
