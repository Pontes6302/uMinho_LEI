package ficha5;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class LinhaEncomendaTest {

    LinhaEncomenda linha1 = new LinhaEncomenda("P1", "Produto 1", 10, 2, 0.23, 0.1);
    LinhaEncomenda linha2 = new LinhaEncomenda();

    @Test
    public void testGetReferencia() {
        assertAll(
            () -> assertEquals("P1", linha1.getReferencia()),
            () -> assertEquals("", linha2.getReferencia())
        );
    }

    @Test
    public void testSetReferencia() {
        linha2.setReferencia("P2");
        assertEquals("P2", linha2.getReferencia());
    }

    @Test
    public void testCalculaValorLinhaEnc() {
        assertEquals(22.14, linha1.calculaValorLinhaEnc(), 0.01);
        assertEquals(0, linha2.calculaValorLinhaEnc(), 0.01);
    }
}
