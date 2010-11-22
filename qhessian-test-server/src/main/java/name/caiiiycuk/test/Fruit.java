package name.caiiiycuk.test;

import java.io.Serializable;

public class Fruit implements Serializable {

	private static final long serialVersionUID = 6697223799952319341L;
	
	private final float  weight;
	
	public Fruit(float weight) {
		this.weight = weight;
	}
	
	public float getWeight() {
		return weight;
	}
	
}
