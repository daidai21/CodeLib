public class VariableParametersExample {
    public static void main(String[] args) {
        Group0 g0 = new Group0();
        g0.setNames("Xiao Ming", "Xiao Hong", "Xiao Jun");
        g0.setNames("Xiao Ming", "Xiao Hong");
        g0.setNames();

        Group1 g1 = new Group1();
        g1.setNames(new String[] {"Xiao Ming", "Xiao Hong", "Xiao Jun"});
        g1.setNames(new String[] {"Xiao Ming", "Xiao Hong"});
        g1.setNames(null);
    }
}


class Group0 {
    private String[] names;

    public void setNames(String... names) {
        this.names = names;
    }
}


class Group1 {
    private String[] names;

    public void setNames(String[] names) {
        this.names = names;
    }
}
