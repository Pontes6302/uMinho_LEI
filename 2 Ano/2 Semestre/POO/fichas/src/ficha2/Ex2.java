package ficha2;

import java.time.LocalDate;
import java.time.temporal.ChronoUnit;

public class Ex2 {
    private LocalDate[] datas = new LocalDate[10];
    private int size = 0;

    public void insereData(LocalDate data){
        if (size < datas.length)
            datas[size++] = data;
    }

    public LocalDate dataMaisProxima(LocalDate data){
        LocalDate closest = null;
        long minDiff = Long.MAX_VALUE;
        for (int i = 0; i < size; i++) {
            long diff = Math.abs(ChronoUnit.DAYS.between(data, datas[i]));
            if (diff < minDiff) {
                minDiff = diff;
                closest = datas[i];
            }
        }
        return closest;
    }
}
