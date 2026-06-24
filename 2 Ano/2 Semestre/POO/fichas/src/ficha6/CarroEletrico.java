package ficha6;

import java.util.Comparator;

public class CarroEletrico extends Carro {
    private double bateria;
    private double consumoKWh100Km;
    private double custoPorKWh;

    public CarroEletrico() {
        super();
        this.bateria = 0;
        this.consumoKWh100Km = 0;
        this.custoPorKWh = 0;
    }

    public CarroEletrico(String matricula, String marca, String modelo, int ano, double velocidadeMedia, int autonomia,
            int totalKms, double bateria, double consumoKWh100Km, double custoPorKWh) {
        super(matricula, marca, modelo, ano, velocidadeMedia, autonomia, totalKms);
        this.bateria = bateria;
        this.consumoKWh100Km = consumoKWh100Km;
        this.custoPorKWh = custoPorKWh;
    }

    public CarroEletrico(CarroEletrico c) {
        super(c);
        this.bateria = c.getBateria();
        this.consumoKWh100Km = c.getConsumoKWh100Km();
        this.custoPorKWh = c.getCustoPorKWh();
    }

    public double getBateria() {
        return bateria;
    }

    public void setBateria(double bateria) {
        this.bateria = bateria;
    }

    public double getConsumoKWh100Km() {
        return consumoKWh100Km;
    }

    public void setConsumoKWh100Km(double consumoKWh100Km) {
        this.consumoKWh100Km = consumoKWh100Km;
    }

    public double getCustoPorKWh() {
        return custoPorKWh;
    }

    public void setCustoPorKWh(double custoPorKWh) {
        this.custoPorKWh = custoPorKWh;
    }

    public double custoPorKm() {
        return (this.consumoKWh100Km / 100) * this.custoPorKWh;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(super.toString());
        sb.append(this.bateria).append("|");
        sb.append(this.consumoKWh100Km).append("|");
        sb.append(this.custoPorKWh).append("|");
        return sb.toString();
    }

    @Override
    public boolean equals(Object o) {
        if (this == o)
            return true;
        if (o == null || getClass() != o.getClass())
            return false;
        if (!super.equals(o))
            return false;
        CarroEletrico that = (CarroEletrico) o;
        return super.equals(o) && this.bateria == that.getBateria() && this.consumoKWh100Km == that.getConsumoKWh100Km()
                && this.custoPorKWh == that.getCustoPorKWh();
    }

    @Override
    public CarroEletrico clone() {
        return new CarroEletrico(this);
    }

    public int compareTo(CarroEletrico c){
        Comparator<CarroEletrico> comparator = Comparator.comparingInt(CarroEletrico::getTotalKms)
                .thenComparingDouble(CarroEletrico::getBateria)
                .reversed();
        return comparator.compare(this, c);
    }
}
