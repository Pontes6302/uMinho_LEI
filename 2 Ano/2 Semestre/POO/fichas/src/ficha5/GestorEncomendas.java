package ficha5;

import java.util.*;
import java.util.stream.Collectors;
import java.time.LocalDate;

public class GestorEncomendas {

    private Map<Integer,Encomenda> encomendas;

    public GestorEncomendas() {
        this.encomendas = new HashMap<>();
    }

    public GestorEncomendas(Map<Integer,Encomenda> encomendas){
        this.encomendas = encomendas.entrySet().stream().
                                    collect(Collectors.toMap(a -> a.getKey(), a-> a.getValue().clone()));
    }

    public GestorEncomendas(GestorEncomendas ge){
        this.encomendas = ge.getEncomendas();
    }

    public Map<Integer,Encomenda> getEncomendas(){
        return this.encomendas.entrySet().stream()
                          .collect(Collectors.toMap(Map.Entry::getKey, e -> e.getValue().clone()));
    }

    public void setEncomendas(Map<Integer,Encomenda> encomendas){
        this.encomendas = encomendas.entrySet().stream()
                            .collect(Collectors.toMap(Map.Entry::getKey, e -> e.getValue().clone()));
    }

    public String toString(){
        StringBuffer sb = new StringBuffer();

        this.encomendas.values().forEach(a -> sb.append(a.toString()));

        return sb.toString();
    }

    public GestorEncomendas clone(){
        return new GestorEncomendas(this);
    }

    public boolean equals(Object o){
        if(this == o)
            return true;

        if(o==null || this.getClass() != o.getClass())
            return false;

        GestorEncomendas gestor = (GestorEncomendas) o;

        return this.encomendas.equals(gestor.getEncomendas());
    }

    //----------------------

    public Set<Integer> todosCodigosEnc(){
        return this.encomendas.keySet();
    }

    public void addEncomenda(Encomenda enc){
        encomendas.put(enc.getNum(), enc.clone());
    }

    public Encomenda getEncomenda(Integer codEnc){
        if (!this.encomendas.containsKey(codEnc)) return null;
        return this.encomendas.get(codEnc).clone();
    }

    public void removeEncomenda(Integer codEnc){
        this.encomendas.remove(codEnc);
    }

    public Integer encomendaComMaisProdutos(){
        return this.encomendas.values().stream()
                .max(Comparator.comparingInt(Encomenda :: numeroTotalProdutos))
                .map(Encomenda :: getNum)
                .orElse(null);
    }

    public Set<Integer> encomendasComProduto(String codProd){
        return this.encomendas.values().stream()
                .filter(e -> e.existeProdutoEncomenda(codProd))
                .map(Encomenda :: getNum)
                .collect(Collectors.toSet());
    }

    public Set<Integer> encomendasAposData(LocalDate d){
        return this.encomendas.values().stream()
                .filter(encomenda -> encomenda.getData().isAfter(d))
                .map(Encomenda :: getNum)
                .collect(Collectors.toSet());
    }

    public Encomenda encomendaMaiorValor(){
        return this.encomendas.values().stream()
                .max(Comparator.comparingDouble(Encomenda :: calculaValorTotal))
                .map(Encomenda :: clone)
                .orElse(null);
    }

    public Set<Encomenda> encomendasOrdenadasPorQtProdutos(){
        Comparator<Encomenda> c = Comparator.comparingInt(Encomenda :: numeroTotalProdutos);

        return this.encomendas.values().stream()
                .map(Encomenda :: clone)
                .sorted(c)
                .collect(Collectors.toCollection(LinkedHashSet::new));
    }

    public Set<Encomenda> encomendasValorDecrescente(){
        Comparator<Encomenda> c = Comparator.comparingDouble(Encomenda :: calculaValorTotal).thenComparing(Encomenda :: getNum).reversed();

        return this.encomendas.values().stream()
                .map(Encomenda :: clone)
                .sorted(c)
                .collect(Collectors.toCollection(() -> new TreeSet<>(c)));
    }

    public Map<String,List<Integer>> encomendasDeProduto(){
        Map<String, List<Integer>> mapa = new HashMap<>();

        this.encomendas.values()
            .forEach(encomenda -> encomenda.getLinhasEncomenda()
                .forEach( linha ->
                    mapa.computeIfAbsent(linha.getReferencia(), encomendas -> new ArrayList<>())
                    .add(encomenda.getNum())
                )
            );
        return mapa;
    }
}