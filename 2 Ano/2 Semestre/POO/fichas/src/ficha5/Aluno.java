package ficha5;

public class Aluno implements Comparable<Aluno> {

    private String nome;
    private int curso;
    private String numero;
    private double nota;

    public String getName(){
        return this.nome;
    }

    public String getNumero() {
        return this.numero;
    }

    @Override
    public Aluno clone() {
        try {
            return (Aluno) super.clone();
        } catch (CloneNotSupportedException e) {
            throw new AssertionError(); // Should not happen since we implement Cloneable
        }
    }

    public int hashCode() {
        int hash = 7;
        hash = 31* hash + (this.nome != null ? this.nome.hashCode() : 0);
        hash = 31* hash + (this.curso != 0 ? Integer.hashCode(this.curso    ) : 0);
        hash = 31* hash + (this.numero != null ? this.numero.hashCode() : 0);
        hash = 31* hash + (int) this.nota;
        return hash;
    }

    public int compareTo(Aluno a) {
        return this.nome.compareTo(a.nome);
    }

}
