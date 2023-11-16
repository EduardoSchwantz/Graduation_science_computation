public class Processos implements Comparable<Processos> {
    private String nome;
    private Integer time;


    public Processos(){
    }
    public Processos(String nome, Integer time) {
        this.nome = nome;
        this.time = time;
    }

    public String getNome() {
        return nome;
    }

    public Integer getTime() {
        return time;
    }

    @Override
    public int compareTo(Processos outroProcesso) {
        return this.time.compareTo(outroProcesso.time);
    }

    @Override
    public String toString() {
        return nome;
    }
}
