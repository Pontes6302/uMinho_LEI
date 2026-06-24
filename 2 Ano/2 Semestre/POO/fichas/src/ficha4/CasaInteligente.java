package ficha4;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;

import ficha4.Lampada.Modo;

public class CasaInteligente {
    private List<Lampada> lampadas;

    public CasaInteligente() {
        this.lampadas = new ArrayList<>();   
    }

    public CasaInteligente(List<Lampada> lampadas) {
        List<Lampada> l = new ArrayList<>(lampadas.size());
        Iterator<Lampada> it = lampadas.iterator();
        while (it.hasNext()){
            Lampada lampada = it.next();
            l.add(lampada.clone());
        }
        this.lampadas = l;
    }

    public CasaInteligente(CasaInteligente ci) {
        this.lampadas = ci.getLampadas();
    }

    public List<Lampada> getLampadas() {
        List<Lampada> l = new ArrayList<>(this.lampadas.size());
        Iterator<Lampada> it = this.lampadas.iterator();
        while (it.hasNext()){
            Lampada lampada = it.next();
            l.add(lampada.clone());
        }
        return l;
    }

    public void setLampadas(List<Lampada> lampadas) {
        List<Lampada> l = new ArrayList<>(lampadas.size());
        Iterator<Lampada> it = lampadas.iterator();
        while (it.hasNext()){
            Lampada lampada = it.next();
            l.add(lampada.clone());
        }
        this.lampadas = l;
    }

    public boolean equals(Object obj) {
        if(obj==this) 
           return true;
        if(obj==null || obj.getClass() != this.getClass()) 
           return false;
        CasaInteligente ci = (CasaInteligente) obj;
        return ci.getLampadas().equals(this.lampadas);
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append("Casa Inteligente: \n");
        for (Lampada lampada : this.lampadas) {
            sb.append(lampada.toString()).append("\n");
        }
        return sb.toString();
    }

    public CasaInteligente clone() {
        return new CasaInteligente(this);
    }

    public void addLampada(Lampada l) {
        this.lampadas.add(l.clone());
    }

    public void ligaLampadaNormal(int index){
        this.lampadas.get(index).lampON();
    }

    public void ligaLampadaEco(int index){
        this.lampadas.get(index).lampECO();
    }

    public int qtEmEco(){
        int count = 0;
        Iterator<Lampada> it = this.lampadas.iterator();
        while (it.hasNext()){
            Lampada lampada = (Lampada) it.next();
            if(lampada.getModo() == Modo.ECO) 
                count++;
        }
        return count;
    }

    public void removeLampada(int index){
        this.lampadas.remove(index);
    }

    public void ligaTodasEco(){
        Iterator<Lampada> it = this.lampadas.iterator();
        while (it.hasNext()){
            Lampada lampada = (Lampada) it.next();
            lampada.lampECO();
        }
    }

    public void ligaTodasMax(){
        Iterator<Lampada> it = this.lampadas.iterator();
        while (it.hasNext()){
            Lampada lampada = (Lampada) it.next();
            lampada.lampON();
        }
    }

    public double consumoTotal(){
        int total = 0;
        Iterator<Lampada> it = this.lampadas.iterator();
        while (it.hasNext()){
            Lampada lampada = (Lampada) it.next();
            total += lampada.totalConsumo();
        }
        return total;
    }

    public Lampada maisGastadora(){
        Lampada maisGastadora = null;
        Iterator<Lampada> it = this.lampadas.iterator();
        while (it.hasNext()){
            Lampada lampada = (Lampada) it.next();
            if(maisGastadora == null || lampada.totalConsumo() > maisGastadora.totalConsumo())
                maisGastadora = lampada;
        }
        return maisGastadora.clone();
    }

    public Set<Lampada> lampadasEmModoEco(){
        Set<Lampada> lampadasEco = new HashSet<>();
        Iterator<Lampada> it = this.lampadas.iterator();
        while (it.hasNext()){
            Lampada lampada = (Lampada) it.next();
            if(lampada.getModo() == Modo.ECO)
                lampadasEco.add(lampada.clone());
        }
        return lampadasEco;
    }

    public void reset(){
        Iterator<Lampada> it = this.lampadas.iterator();
        while (it.hasNext()){
            Lampada lampada = (Lampada) it.next();
            lampada.resetPeriodo();
        }
    }

    public Set<Lampada> podiumEconomia(){
        Set<Lampada> ordenadasAll = new TreeSet<>(Comparator.comparingDouble(Lampada::getConsumoTotal));
        ordenadasAll.addAll(this.lampadas);
        Set<Lampada> podium = new TreeSet<>(Comparator.comparingDouble(Lampada::getConsumoTotal));
        int count = 0;
        for (Lampada lampada : ordenadasAll) {
            if(count < 3){
                podium.add(lampada.clone());
                count++;
            } else
                break;
        }
        return podium;
    }
}
