package name.caiiiycuk.test;

import java.util.ArrayList;
import java.util.List;

import com.caucho.hessian.server.HessianServlet;

public class FruitServiceImpl extends HessianServlet implements FruitService {

	private static final long serialVersionUID = -2806833665964787615L;

	@Override
	public List<Fruit> getFruits() {
		List<Fruit> fruitPack = new ArrayList<Fruit>();
		
		fruitPack.add(new Apple(1.0f, AppleColor.RED));
		fruitPack.add(new Apple(2.0f, AppleColor.GREEN));
		fruitPack.add(new Banana(5.0f, BananaSize.HUGE));
		fruitPack.add(new Banana(2.5f, BananaSize.LITTLE));
		fruitPack.add(new PlasticApple(0.2f, AppleColor.GREEN));
		fruitPack.add(new PlasticApple(0.2f, AppleColor.RED));
		
		return fruitPack;
	}

}
