package name.caiiiycuk.test;

import com.caucho.hessian.server.HessianServlet;

public class StringServiceImpl extends HessianServlet implements StringService {

	private static final long serialVersionUID = 897818244336158508L;

	@Override
	public boolean argRussianString(String string) {
		if (replyRussianString().equals(string)) {
			return true;
		}
		
		return false;
	}

	@Override
	public String replyRussianString() {
		return "Мама мыла раму. Съешь этих мягких BULOK.";
	}

}
