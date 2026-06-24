package ficha5;
import java.util.Collection;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;
import java.util.TreeSet;
import java.util.stream.Collectors;

public class Turma {

    private String nomeTurma;
    private String uc;
    private Map<String,Aluno> alunos;


    public Turma(){
        this.nomeTurma="";
        this.uc = "";
    }

    public Turma(String nomeTurma, String uc){
        this.nomeTurma = nomeTurma;
        this.uc = uc;
        this.alunos = new HashMap<>();
    }

    public Turma(String nomeTurma, String uc, Map<String,Aluno> alunos){
        this.nomeTurma = nomeTurma;
        this.uc = uc;
        this.alunos = alunos.entrySet().stream().
                        collect(Collectors.toMap(a -> a.getKey(), a-> a.getValue().clone()));
    }

    public String getNomeTurma() {
        return this.nomeTurma;
    }

    public void setNomeTurma(String nomeTurma) {
        this.nomeTurma = nomeTurma;
    }

    public String getUc() {
        return this.uc;
    }

    public void setUc(String uc) {
        this.uc = uc;
    }

    public Map<String, Aluno> getAlunos() {
        return this.alunos.entrySet().stream()
                          .collect(Collectors.toMap(Map.Entry::getKey, e -> e.getValue().clone()));
    }

    public void setAlunos(Map<String, Aluno> alunos) {
        this.alunos = alunos.entrySet().stream()
                            .collect(Collectors.toMap(Map.Entry::getKey, e -> e.getValue().clone()));
    }

    public boolean equals(Object o){
        if (this==o)
            return true;

        if (o==null || this.getClass() != o.getClass())
            return false;

        Turma turma = (Turma) o;

        return this.nomeTurma == turma.nomeTurma &&
                this.uc == turma.uc &&
                this.alunos.equals(turma.alunos);
    }

    public String toString() {
        StringBuffer sb = new StringBuffer();
        sb.append(this.uc + "\n");
        sb.append(this.nomeTurma + "\n");
        this.alunos.values().forEach(a -> sb.append(a.toString()));

        return sb.toString();
    }

    public void addAluno(Aluno a){
        alunos.put(a.getName(), a.clone());
    }

    public Set<Aluno> alunosOrdenados(){
        return this.alunos.values().stream()
                .map(Aluno::clone)
                .collect(Collectors.toCollection(TreeSet::new));
    }

    public Aluno getAluno(String numero){
        if (!this.alunos.containsKey(numero)) return null;
        return this.alunos.get(numero).clone();
    }

    public void removeAluno(String numero){
        this.alunos.remove(numero);
    }

    public Set<String> numeros(){
        return this.alunos.keySet();
    }

    public int qtsAlunos(){
        return this.alunos.size();
    }

    public Collection<Aluno> alunosOrdemAlfabetica(){
        return this.alunos.values().stream()
                .map(Aluno::clone)
                .sorted((a1, a2) -> a1.getName().compareTo(a2.getName()))
                .collect(Collectors.toList());
    }

    public Set<Aluno> alunosOrdemDescrescenteNumero(){
        Comparator<Aluno> comparador = (a1, a2) -> a2.getNumero().compareTo(a1.getNumero());
        
        return this.alunos.values().stream()
                .map(Aluno::clone)
                .collect(Collectors.toCollection(() -> new TreeSet<>(comparador)));
    }

}
