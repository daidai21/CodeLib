
public class UsingInterfaceExample {
    public static void main(String[] args) {
        Button button = new Button();
        ClickHandler clickHandler = new ClickHandler();
        button.onClick(clickHandler);

        Button button2 = new Button();
        button2.onClick(new ClickEventHandler() {
            @Override
            public void handleClick() {
                System.out.println("Button Clicked");
            }
        });
    }
}

interface ClickEventHandler {
    public void handleClick();
}

class ClickHandler implements ClickEventHandler {
    public void handleClick() {
        System.out.println("Clicked");
    }
}

class Button {
    public void onClick(ClickEventHandler clickHandler) {
        clickHandler.handleClick();
    }
}
