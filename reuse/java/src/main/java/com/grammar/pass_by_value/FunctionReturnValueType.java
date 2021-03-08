/**
 * 函数返回的是引用
 */
public class FunctionReturnValueType {
    public static void main(String[] args) {
        Parent parent = new Parent();
        parent.getSon().setVal(1);
        System.out.println(parent.getSon().getVal());
    }

}

class Parent {

    private Son son;

    public Parent(Son son) {
        this.son = son;
    }

    public Parent() {
        this.son = new Son();
    }

    public Son getSon() {
        return son;
    }

    public void setSon(Son son) {
        this.son = son;

    }
}

class Son {
    private Integer val;

    public Integer getVal() {
        return val;
    }

    public void setVal(Integer val) {
        this.val = val;
    }
}
