import org.springframework.stereotype.Service;
import org.springframework.beans.factory.annotation.Qualifier;  // TODO


import javax.annotation.Resource;


public class ATResourceExample {
    public static void main(String[] args) {
        @Resource(name = "WeixinPay")
        Pay aliPay;
        aliPay.pay();
    }
}

interface Pay {
    public void pay();
}

@Service("WeixinPay")
class WeixinPay implements Pay {
    @Override
    public void pay() {
        System.out.println("WeixinPay.pay()");
    }
}

@Service("AliPay")
class AliPay implements Pay {
    @Override
    public void pay() {
        System.out.println("AliPay.pay()");
    }
}

// TODO: run
