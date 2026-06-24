package ficha6;

public class CarroCombustao extends Carro{
    private double deposito;
    private double consumoL100Km;
    private double custoPorL;

    public CarroCombustao() {
        super();
        this.deposito = 0;
        this.consumoL100Km = 0;
        this.custoPorL = 0;
    }

    public CarroCombustao(String matricula, String marca, String modelo, int ano, double velocidadeMedia, int autonomia,
            int totalKms, double deposito, double consumoL100Km, double custoPorL) {
        super(matricula, marca, modelo, ano, velocidadeMedia, autonomia, totalKms);
        this.deposito = deposito;
        this.consumoL100Km = consumoL100Km;
        this.custoPorL = custoPorL;
    }

    public CarroCombustao(CarroCombustao c) {
        super(c);
        this.deposito = c.getDeposito();
        this.consumoL100Km = c.getConsumoL100Km();
        this.custoPorL = c.getCustoPorL();
    }

    public double getDeposito() {
        return deposito;
    }

    public void setDeposito(double deposito) {
        this.deposito = deposito;
    }

    public double getConsumoL100Km() {
        return consumoL100Km;
    }

    public void setConsumoL100Km(double consumoL100Km) {
        this.consumoL100Km = consumoL100Km;
    }

    public double getCustoPorL() {
        return custoPorL;
    }

    public void setCustoPorL(double custoPorL) {
        this.custoPorL = custoPorL;
    }

    public double custoPorKm() {
        return (this.consumoL100Km / 100) * this.custoPorL;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(super.toString());
        sb.append(this.deposito).append("|");
        sb.append(this.consumoL100Km).append("|");
        sb.append(this.custoPorL).append("|");
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
        CarroCombustao that = (CarroCombustao) o;
        return super.equals(o) && this.deposito == that.deposito && this.consumoL100Km == that.consumoL100Km
                && this.custoPorL == that.custoPorL;
    }

    @Override
    public CarroCombustao clone() {
        return new CarroCombustao(this);
    }
}
