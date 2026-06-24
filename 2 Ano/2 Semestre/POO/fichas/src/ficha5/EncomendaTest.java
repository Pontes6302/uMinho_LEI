package ficha5;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;
import java.time.LocalDate;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

public class EncomendaTest {
    LinhaEncomenda linha1 = new LinhaEncomenda("P1", "Produto 1", 10, 2, 0.23, 0.1);
    LinhaEncomenda linha2 = new LinhaEncomenda("P2", "Produto 2", 20, 1, 0.23, 0.05);

    Encomenda encomenda1 = new Encomenda("Cliente 1", 123456789, "Rua A", LocalDate.now(), Arrays.asList(linha1, linha2));
    Encomenda encomenda2 = new Encomenda();

    @Test
    public void testGetLinhas(){
        List<LinhaEncomenda> linhas = encomenda1.getLinhasEncomenda();

        assertAll(
            () -> assertEquals(2, encomenda1.getLinhasEncomenda().size()),
            () -> assertEquals(linha1, linhas.get(0)),
            () -> assertEquals(linha2, linhas.get(1))
        );
    }

    @Test
    public void testSetLinhas(){
        List<LinhaEncomenda> linhas = new ArrayList<>();
        linhas.add(linha1);
        linhas.add(linha1);
        encomenda2.setLinhasEncomenda(linhas);

        assertAll(
            () -> assertEquals(2, encomenda2.getLinhasEncomenda().size()),
            () -> assertEquals(linha1, linhas.get(0)),
            () -> assertEquals(linha1, linhas.get(1))
        );
    }

    @Test
    public void testAdcionaLinha(){
        encomenda2.adicionaLinha(linha1);
        encomenda2.adicionaLinha(linha2);

        assertAll(
            () -> assertTrue(encomenda2.getLinhasEncomenda().contains(linha1)),
            () -> assertTrue(encomenda2.getLinhasEncomenda().contains(linha2))
        );
    }

    @Test
    public void testRemoveProduto(){
        encomenda2.adicionaLinha(linha1);
        encomenda2.adicionaLinha(linha2);

        encomenda2.removeProduto("P1");

        assertAll(
            () -> assertFalse(encomenda2.getLinhasEncomenda().contains(linha1)),
            () -> assertEquals(1, encomenda2.getLinhasEncomenda().size()),
            () -> assertTrue(encomenda2.getLinhasEncomenda().contains(linha2))
        );
    }
}
