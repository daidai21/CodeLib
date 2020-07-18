import java.lang.System;


// IOC: Inversion Of Control
/**
 * scene:
 *      buy fruit people (user)
 *      sell fruit people (business layer)
 *      fruit (persistence layer)
 */
public class IOCExample {
    public static void main(String[] args) {
        // Control permission in business layer
        System.out.println("Base:");
        BaseUserGetApple baseUserGetApple = new BaseUserGetApple();
        baseUserGetApple.getFruit();
        BaseUserGetBanana baseUserGetBanana = new BaseUserGetBanana();
        baseUserGetBanana.getFruit();

        // Control permission in user
        System.out.println("IOC:");
        IOCUser iocUser0 = new IOCUser();
        iocUser0.setBaseFruit(new BaseApple());
        iocUser0.getBaseFruit();
        IOCUser iocUser1 = new IOCUser();
        iocUser1.setBaseFruit(new BaseBanana());
        iocUser1.getBaseFruit();
    }
}


/**
 * Base
 */
interface BaseFruit {
    public void get();
}

class BaseApple implements BaseFruit {
    public void get() {
        System.out.println("get an apple");
    }
}

class BaseBanana implements BaseFruit {
    public void get() {
        System.out.println("get an banana");
    }
}

class BaseUserGetApple {
    private BaseFruit baseFruit = new BaseApple();

    public void getFruit() {
        this.baseFruit.get();
    }
}

class BaseUserGetBanana {
    private BaseFruit baseFruit = new BaseBanana();

    public void getFruit() {
        this.baseFruit.get();
    }
}


/**
 * IOC
 */
class IOCUser {
    private BaseFruit baseFruit;

    public void setBaseFruit(BaseFruit baseFruit) {
        this.baseFruit = baseFruit;
    }

    public void getBaseFruit() {
        this.baseFruit.get();
    }
}
