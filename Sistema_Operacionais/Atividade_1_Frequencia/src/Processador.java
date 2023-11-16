import java.util.ArrayList;
import java.util.List;

class Processador {
    private String name;
    private int tempoTotal = 0;
    StringBuilder result = new StringBuilder("");
    public Processador(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public int getTempoTotal() {
        return tempoTotal;
    }

    public void executarProcesso(Processos processo) {
        result.append(processo);
        result.append(";" + tempoTotal);
        tempoTotal += processo.getTime();
        result.append(";" + tempoTotal + "\n");
    }

    @Override
    public String toString() {
        return result.toString();
    }
}