package name.caiiiycuk.test;

import com.caucho.hessian.server.HessianServlet;

public class NullServiceImpl extends HessianServlet implements NullService {

	private static final long serialVersionUID = -519256252845385966L;

	@Override
	public boolean readNull(TypeWithNull tNull) {
		return 
			tNull.b != null && tNull.bNull == null &&
			tNull.i != null && tNull.iNull == null &&
			tNull.l != null && tNull.lNull == null &&
			tNull.d != null && tNull.dNull == null &&
			tNull.t != null && tNull.tNull == null &&
			tNull.s != null && tNull.sNull == null &&
			tNull.listNull == null && 
			tNull.mapNull == null &&
			tNull.oNull == null &&
			tNull.coNull == null;
	}

}
