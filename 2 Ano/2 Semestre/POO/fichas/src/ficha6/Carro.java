package ficha6;

public abstract class Carro {
    private String matricula;
    private String marca;
    private String modelo;
    private int ano;
    private double velocidadeMedia;
    private int autonomia;
    private int totalKms;

    public Carro() {
        this.matricula = "";
        this.marca = "";
        this.modelo = "";
        this.ano = 0;
        this.velocidadeMedia = 0;
        this.autonomia = 0;
        this.totalKms = 0;
    }

    public Carro(String matricula, String marca, String modelo, int ano, double velocidadeMedia, int autonomia,
            int totalKms) {
        this.matricula = matricula;
        this.marca = marca;
        this.modelo = modelo;
        this.ano = ano;
        this.velocidadeMedia = velocidadeMedia;
        this.autonomia = autonomia;
        this.totalKms = totalKms;
    }

    public Carro(Carro c) {
        this.matricula = c.getMatricula();
        this.marca = c.getMarca();
        this.modelo = c.getModelo();
        this.ano = c.getAno();
        this.velocidadeMedia = c.getVelocidadeMedia();
        this.autonomia = c.getAutonomia();
        this.totalKms = c.getTotalKms();
    }

    public String getMatricula() {
        return matricula;
    }

    public void setMatricula(String matricula) {
        this.matricula = matricula;
    }

    public String getMarca() {
        return marca;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public String getModelo() {
        return modelo;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public int getAno() {
        return ano;
    }

    public void setAno(int ano) {
        this.ano = ano;
    }

    public double getVelocidadeMedia() {
        return velocidadeMedia;
    }

    public void setVelocidadeMedia(double velocidadeMedia) {
        this.velocidadeMedia = velocidadeMedia;
    }

    public int getAutonomia() {
        return autonomia;
    }

    public void setAutonomia(int autonomia) {
        this.autonomia = autonomia;
    }

    public int getTotalKms() {
        return totalKms;
    }

    public void setTotalKms(int totalKms) {
        this.totalKms = totalKms;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();

        sb.append(this.matricula).append("|");
        sb.append(this.marca).append("|");
        sb.append(this.modelo).append("|");
        sb.append(this.ano).append("|");
        sb.append(this.velocidadeMedia).append("|");
        sb.append(this.autonomia).append("|");
        sb.append(this.totalKms).append("|");

        return sb.toString();
    }

    public boolean equals(Object o) {
        if (this == o)
            return true;
        if (o == null || this.getClass() != o.getClass())
            return false;

        Carro c = (Carro) o;

        return this.matricula.equals(c.getMatricula()) && this.marca.equals(c.getMarca())
                && this.modelo.equals(c.getModelo()) && this.ano == c.getAno()
                && this.velocidadeMedia == c.getVelocidadeMedia() && this.autonomia == c.getAutonomia()
                && this.totalKms == c.getTotalKms();
    }

    public abstract Carro clone();

    public abstract double custoPorKm();
}
