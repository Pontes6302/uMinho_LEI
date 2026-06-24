package ficha4;

import java.util.List;
import java.util.Set;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.time.LocalDate;


public class GestaoEncomendas {

    private List<Encomenda> encomendas;

    public GestaoEncomendas() {
        this.encomendas = new ArrayList<>();
    }

    public GestaoEncomendas(List<Encomenda> encomendas) {
        List<Encomenda> e = new ArrayList<>(encomendas.size());
        Iterator<Encomenda> it = encomendas.iterator();
        while (it.hasNext()){
            Encomenda encomenda = it.next();
            e.add(encomenda.clone());
        }
        this.encomendas = e;
    }

    public GestaoEncomendas(GestaoEncomendas ge) {
        this.encomendas = ge.getEncomendas();
    }

    public List<Encomenda> getEncomendas() {
        List<Encomenda> e = new ArrayList<>(this.encomendas.size());
        Iterator<Encomenda> it = this.encomendas.iterator();
        while (it.hasNext()){
            Encomenda encomenda = it.next();
            e.add(encomenda.clone());
        }
        return e;
    }

    public void setEncomendas(List<Encomenda> encomendas) {
        List<Encomenda> e = new ArrayList<>(encomendas.size());
        Iterator<Encomenda> it = encomendas.iterator();
        while (it.hasNext()){
            Encomenda encomenda = it.next();
            e.add(encomenda.clone());
        }
        this.encomendas = e;
    }

    public boolean equals(Object obj) {
        if(obj==this) 
           return true;
        if(obj==null || obj.getClass() != this.getClass()) 
           return false;
        GestaoEncomendas ge = (GestaoEncomendas) obj;
        return ge.getEncomendas().equals(this.encomendas);
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append("Encomendas: " + "\n");
        Iterator<Encomenda> it = this.encomendas.iterator();
        while (it.hasNext()){
            Encomenda encomenda = it.next();
            sb.append(encomenda.toString() + "\n");
        }
        return sb.toString();
    }

    public GestaoEncomendas clone() {
        return new GestaoEncomendas(this);
    }

    public void addEncomenda(Encomenda e) {
        this.encomendas.add(e.clone());
    }

    public Encomenda getEncomenda(Integer num){
        Iterator<Encomenda> it = this.encomendas.iterator();
        while (it.hasNext()){
            Encomenda encomenda = it.next();
            if (encomenda.getNum() == num)
                return encomenda.clone();
        }
        return null;
    }

    public void removeEncomenda(Integer num){
        this.encomendas.removeIf(encomenda -> encomenda.getNum() == num);
    }

    public Encomenda encomendaMaiorValor(){
        Encomenda maiorValor = null;
        Iterator<Encomenda> it = this.encomendas.iterator();
        while(it.hasNext()){
            Encomenda encomenda = it.next();
            if (maiorValor == null || encomenda.calculaValorTotal() > maiorValor.calculaValorTotal())
                maiorValor = encomenda;
        }
        return maiorValor.clone();
    }

    public Encomenda encomendaMaisProdutos(){
        Encomenda maisProdutos = null;
        Iterator<Encomenda> it = this.encomendas.iterator();
        while(it.hasNext()){
            Encomenda encomenda = it.next();
            if (maisProdutos == null || encomenda.numeroTotalProdutos() > maisProdutos.numeroTotalProdutos())
                maisProdutos = encomenda;
        }
        return maisProdutos.clone();
    }

    public Set<Integer> encomendaComProduto(String ref){
        Set<Integer> encomendasComProduto = new HashSet<>();
        Iterator<Encomenda> it = this.encomendas.iterator();
        while (it.hasNext()){
            Encomenda encomenda = it.next();
            if (encomenda.existeProdutoEncomenda(ref))
                encomendasComProduto.add(encomenda.getNum());
        }
        return encomendasComProduto;
    }

    public Set<Integer> encomendaAposData(LocalDate data){
        Set<Integer> encomendasAposData = new HashSet<>();
        Iterator<Encomenda> it = this.encomendas.iterator();
        while (it.hasNext()){
            Encomenda encomenda = it.next();
            if (encomenda.getData().isAfter(data))
                encomendasAposData.add(encomenda.getNum());
        }
        return encomendasAposData;
    }
}
