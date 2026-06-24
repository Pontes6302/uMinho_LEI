package ficha6;

import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;
import java.util.TreeSet;
import java.util.stream.Collectors;

public class CarRental {
    private String nome;
    private String morada;
    private Map<String, Carro> carros;

    public CarRental() {
        this.nome = "";
        this.morada = "";
        this.carros = new HashMap<>();
    }

    public CarRental(String nome, String morada, Map<String, Carro> carros) {
        this.nome = nome;
        this.morada = morada;
        this.carros = carros.entrySet().stream()
                .collect(Collectors.toMap(entry -> entry.getKey(), entry -> entry.getValue().clone()));
    }

    public CarRental(CarRental c) {
        this.nome = c.getNome();
        this.morada = c.getMorada();
        this.carros = c.getCarros();
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getMorada() {
        return morada;
    }

    public void setMorada(String morada) {
        this.morada = morada;
    }

    public Map<String, Carro> getCarros() {
        return this.carros.entrySet().stream()
                .collect(Collectors.toMap(entry -> entry.getKey(), entry -> entry.getValue().clone()));
    }

    public void setCarros(Map<String, Carro> carros) {
        this.carros = carros.entrySet().stream()
                .collect(Collectors.toMap(entry -> entry.getKey(), entry -> entry.getValue().clone()));
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.nome + "|");
        sb.append(this.morada + "|");
        sb.append(this.carros.size() + "|");
        this.carros.values().forEach(c -> sb.append(c.toString() + "|"));
        return sb.toString();
    }

    public boolean equals(Object o) {
        if (this == o)
            return true;
        if (o == null || this.getClass() != o.getClass())
            return false;

        CarRental cr = (CarRental) o;

        return this.nome.equals(cr.getNome()) && this.morada.equals(cr.getMorada())
                && this.carros.equals(cr.getCarros());
    }

    public CarRental clone() {
        return new CarRental(this);
    }

    // FASE 1
    public boolean existeCarro(String matricula) {
        return this.carros.containsKey(matricula);
    }

    public int quantos() {
        return this.carros.size();
    }

    public Carro getCarro(String cod) {
        if (!this.carros.containsKey(cod))
            return null;
        return this.carros.get(cod).clone();
    }

    public void adiciona(Carro v) {
        this.carros.put(v.getMatricula(), v.clone());
    }

    public void adiciona(Set<Carro> vs) {
        vs.forEach(v -> this.carros.put(v.getMatricula(), v.clone()));
    }

    public void registarViagem(String codCarro, int numKms) {
        if (!this.carros.containsKey(codCarro))
            return;
        Carro c = this.carros.get(codCarro);
        c.setTotalKms(c.getTotalKms() + numKms);
        this.carros.put(codCarro, c);
    }

    public Carro obterCarroMaisEconomico() {
        return this.carros.values().stream()
                .min((c1, c2) -> Double.compare(c1.custoPorKm(), c2.custoPorKm()))
                .orElse(null)
                .clone();
    }

    public Set<CarroEletrico> comBateriaDe(int nivelMinimo) {
        return this.carros.values().stream()
                .filter(carro -> carro instanceof CarroEletrico)
                .map(carro -> (CarroEletrico) carro)
                .filter(carroEletrico -> carroEletrico.getBateria() >= nivelMinimo)
                .map(carro -> carro.clone())
                .collect(Collectors.toSet());
    }

    // FASE 2
    public Carro carroComMaisKms() {
        Comparator<Carro> comparator = Comparator.comparingInt(Carro::getTotalKms)
                .reversed()
                .thenComparing(Carro::getMatricula);
        return this.carros.values().stream()
                .max(comparator)
                .orElse(null)
                .clone();
    }

    public Set<CarroEletrico> carroElectricos(){
        return this.carros.values().stream()
                .filter(carro -> carro instanceof CarroEletrico)
                .map(carro -> (CarroEletrico) carro)
                .map(carro -> carro.clone())
                .collect(Collectors.toCollection(TreeSet::new));
    }
}
