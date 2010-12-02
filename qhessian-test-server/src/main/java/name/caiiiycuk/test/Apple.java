package name.caiiiycuk.test;

enum AppleColor {
	RED,
	GREEN
}

public class Apple extends Fruit {

	private static final long serialVersionUID = 7908387468053290925L;
	

	private final AppleColor color;

	public Apple(float weight, AppleColor color) {
		super(weight);
		this.color = color;
	}
	
	public AppleColor getColor() {
		return color;
	}
	
}
