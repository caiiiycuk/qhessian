package name.caiiiycuk.test;

enum BananaSize {
	HUGE, LITTLE
}

public class Banana extends Fruit {

	private static final long serialVersionUID = 1180374660481214068L;
	
	private final BananaSize bananaSize;
	
	public Banana(float weight, BananaSize bananaSize) {
		super(weight);
		this.bananaSize = bananaSize;
	}
	
	public BananaSize getBananaSize() {
		return bananaSize;
	}

}
